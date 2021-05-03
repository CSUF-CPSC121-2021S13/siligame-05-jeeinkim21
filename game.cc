#include "game.h"
#include <vector>
#include <stdlib.h>

#include "cpputils/graphics/image.h"

void Game::LaunchProjectiles(){
 for (int i = 0; i < opponents_.size(); i++) {
   std::unique_ptr<OpponentProjectile> opponentUniquePtr = opponents_[i]->LaunchProjectile(); 
   std::unique_ptr<OpponentProjectile> different_opponentUniquePtr = std::move(opponentUniquePtr); 
   if (opponents_[i]->LaunchProjectile() != nullptr) {
     opponents_.push_back(different_opponentUniquePtr); 
   }
 }
}

void Game::CreateOpponents() {
  int x = rand() % 700 + 1; 
  int y = rand() % 300 + 1; 
  std::unique_ptr<Opponent> opponent = std::make_unique<Opponent>(x,y); 
  opponents_.push_back(opponent);
  return;
}

void Game::CreateOpponentProjectiles() {
  int x = 100;
  int y = 100; 
  std::unique_ptr<Opponent> opponent_p = std::make_unique<Opponent>(x,y); 
  opponent_projectiles_.push_back(opponent_p);
  return;
}

void Game::CreatePlayerProjectiles() {
  int x = 150; 
  int y = 150;
  std::unique_ptr<Opponent> player_p = std::make_unique<Opponent>(x,y); 
  player_projectiles_.push_back(player_p);
  return;
}

void Game::Init() {
  player.SetX(10);
  player.SetY(10); //skip and come back later ******** 
  background_.AddMouseEventListener(*this);
  background_.AddAnimationEventListener(*this);

  return;
}

void Game::UpdateScreen() {
  background_.DrawRectangle(0, 0, background_.GetWidth(),
                            background_.GetHeight(), 255, 255, 255);
  if (player.GetIsActive()) {
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
  return;
}

void Game::Start() {
  background_.ShowUntilClosed();
  return;
}

void Game::MoveGameElements() {
  //Modify the MoveGameElements member function to dereference the std::unique_ptr in the vector before calling their Move and GetIsActive functioin. Accessing an element of a vector returns a referene to the std::unique_ptr it contains.

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
    if (player.IntersectsWith(opponents_[i].get()) {
      opponents_[i]->SetIsActive(false);
      player.SetIsActive(false);
      lost_ = true; 
    }
  }

  for (int i = 0; i < player_projectiles_.size(); i++) {
    for (int j = 0; j < opponents_.size(); j++) {
      if (player_projectiles_[i]->IntersectsWith(opponents_[j].get()) {
        player_projectiles_[i]->SetIsActive(false);
        opponents_[j]->SetIsActive(false);
        lost_= false; 
        score_ += 1;
      }
    }
  }
  for (int i = 0; i < opponent_projectiles_.size(); i++) {
    if (opponent_projectiles_[i]->IntersectsWith(player)) {
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
  UpdateScreen();
  background_.Flush();
}

void Game::OnMouseEvent(const graphics::MouseEvent& event) {
  // Whenever the function is called, check whether the graphics::MouseEvent
  // object's action is graphics::MouseAction::kMoved or
  // graphics::MouseAction::kDragged. Take note of the x and y location of the
  // mouse whenever it moves or is dragged. Change the x and y location of your
  // player so that the center of the player object aligns with the mouse
  // location. See the sample image below.
  if (event.GetX() > 0 && event.GetX() < background_.GetWidth() &&
      event.GetY() > 0 && event.GetY() < background_.GetHeight()) {
    player.SetX(event.GetX() - player.GetWidth() / 2);
    player.SetY(event.GetY() - player.GetWidth() / 2);
  }
}
