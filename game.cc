#include "game.h"
#include <stdlib.h>
#include <string>
#include <vector>

#include "cpputils/graphics/image.h"

void Game::CreateOpponents() {
  int x = rand() % 700 + 1;
  int y = rand() % 300 + 1;
  std::unique_ptr<Opponent> opponent = std::make_unique<Opponent>(x, y);
  opponents_.push_back(std::move(opponent));
  return;
}

void Game::LaunchProjectiles() {
  for (int i = 0; i < opponents_.size(); i++) {
    std::unique_ptr<OpponentProjectile> opponentUniquePtr =
        opponents_[i]->LaunchProjectile();
    if (opponentUniquePtr != nullptr) {
      opponent_projectiles_.push_back(std::move(opponentUniquePtr));
    }
  }
}

void Game::Init() {
  player.SetX(10);
  player.SetY(10);  // skip and come back later ********
  background_.AddMouseEventListener(*this);
  background_.AddAnimationEventListener(*this);

  return;
}

void Game::RemoveInactive() {
  for (int i = opponents_.size() - 1; i >= 0; i--) {
    if (opponents_[i]->GetIsActive() == false) {
      opponents_.erase(opponents_.end() - (opponents_.size() - i));
    }
  }
  for (int i = opponent_projectiles_.size() - 1; i >= 0; i--) {
    if (opponent_projectiles_[i]->GetIsActive() == false) {
      opponent_projectiles_.erase(opponent_projectiles_.end() -
                                  (opponent_projectiles_.size() - i));
    }
  }
  for (int i = player_projectiles_.size() - 1; i >= 0; i--) {
    if (player_projectiles_[i]->GetIsActive() == false) {
      player_projectiles_.erase(player_projectiles_.end() -
                                (player_projectiles_.size() - i));
    }
  }
}

void Game::UpdateScreen() {
  background_.DrawRectangle(0, 0, background_.GetWidth(),
                            background_.GetHeight(), 255, 255, 255);

  std::string scoreMsg = "SCORE: " + std::to_string(score_);
  background_.DrawText(1, 1, scoreMsg, 25, 0, 0, 0);

  if (player.GetIsActive() == true) {
    player.Draw(background_);
  }

  for (int i = 0; i < opponents_.size(); i++) {
    if (opponents_[i]
            ->GetIsActive()) {  // you want you iterate through the vector then
                                // check if each opp is active
      opponents_[i]->Draw(background_);
    }
  }

  for (int i = 0; i < opponent_projectiles_.size(); i++) {
    if (opponent_projectiles_[i]->GetIsActive()) {
      opponent_projectiles_[i]->Draw(background_);
    }
  }

  for (int i = 0; i < player_projectiles_.size(); i++) {
    if (player_projectiles_[i]->GetIsActive()) {
      player_projectiles_[i]->Draw(background_);
    }
  }
  if (HasLost()) {
    background_.DrawRectangle(0,0, background_.GetWidth(), background_.GetHeight(), 255,255,255); 
    std::string gameOverMessage = "GAME OVER\n  Score: " + std::to_string(score_); 
    background_.DrawText(210, 250, gameOverMessage, 90, 255, 0, 0);
  }
}

void Game::Start() {
  background_.ShowUntilClosed();
  return;
}

void Game::MoveGameElements() {
  for (int i = 0; i < opponents_.size(); i++) {
    if (opponents_[i]->GetIsActive()) {
      opponents_[i]->Move(background_);
    }
  }

  for (int i = 0; i < opponent_projectiles_.size(); i++) {
    if (opponent_projectiles_[i]->GetIsActive()) {
      opponent_projectiles_[i]->Move(background_);
    }
  }

  for (int i = 0; i < player_projectiles_.size(); i++) {
    if (player_projectiles_[i]->GetIsActive()) {
      player_projectiles_[i]->Move(background_);
    }
  }
}

void Game::FilterIntersections() {
  for (int i = 0; i < opponents_.size(); i++) {
    if (opponents_[i]->IntersectsWith(&player) &&
        opponents_[i]->GetIsActive() && player.GetIsActive()) {
      lost_ = true;
      player.SetIsActive(false);
      opponents_[i]->SetIsActive(false);
    } else {
      for (int j = 0; j < player_projectiles_.size(); j++) {
        if (player_projectiles_[j]->IntersectsWith(opponents_[i].get()) &&
            player_projectiles_[j]->GetIsActive() &&
            opponents_[i]->GetIsActive()) {
          player_projectiles_[j]->SetIsActive(false);
          opponents_[i]->SetIsActive(false);
          lost_ = false;

          if (player.GetIsActive()) {
            score_++;
          }
        }
      }
    }
  }

  for (int i = 0; i < opponent_projectiles_.size(); i++) {
    if (opponent_projectiles_[i]->IntersectsWith(&player) &&
        opponent_projectiles_[i]->GetIsActive() && player.GetIsActive()) {
      opponent_projectiles_[i]->SetIsActive(false);
      player.SetIsActive(false);
      lost_ = true;
    }
  }
}

void Game::OnAnimationStep() {
  if (opponents_.size() == 0) {
    CreateOpponents();
  }
  MoveGameElements();
  LaunchProjectiles();
  FilterIntersections();
  RemoveInactive();
  UpdateScreen();
  background_.Flush();
}

void Game::OnMouseEvent(const graphics::MouseEvent& event) {
  // boundaries check
  if ((event.GetMouseAction() == graphics::MouseAction::kMoved ||
       event.GetMouseAction() == graphics::MouseAction::kDragged) &&
      (event.GetX() > 0 && event.GetX() < background_.GetWidth()) &&
      (event.GetY() > 0 && event.GetY() < background_.GetHeight())) {
    player.SetX(event.GetX() - player.GetWidth() / 2 );
    player.SetY(event.GetY() - player.GetWidth() / 2);
  }
  if (event.GetMouseAction() == graphics::MouseAction::kDragged ||
      event.GetMouseAction() == graphics::MouseAction::kPressed) {
    std::unique_ptr<PlayerProjectile> playerProjectilePtr =
        std::make_unique<PlayerProjectile>( event.GetX() , event.GetY() );
    player_projectiles_.push_back(std::move(playerProjectilePtr));
  }
}
