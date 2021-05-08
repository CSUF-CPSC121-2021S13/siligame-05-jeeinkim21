#include <iostream>
#include <string>
#include <vector>
#include "cpputils/graphics/image.h"
#include "cpputils/graphics/image_event.h"  //needed for animations
#include "opponent.h"
#include "player.h"
 
#ifndef GAME_H
#define GAME_H
 
class Game : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 private:
  int score_ = 0;               // keep track of score
  bool lost_ = false;           // if player is still playing/has lost
  graphics::Image background_;  // represent game screen
  std::vector<std::unique_ptr<Opponent>> opponents_;  // vector of unique ptrs
  std::vector<std::unique_ptr<OpponentProjectile>>
      opponent_projectiles_;  // represent opp projectiles
  std::vector<std::unique_ptr<PlayerProjectile>>
      player_projectiles_;  // represent player projectiles
  Player player;
  Player playerUpgrade; 
 
  bool toggle = false; //to switch player images
 
 public:
 
  Game() : Game(800, 600) {}  // sets the game screen to 800x600.
  Game(int width, int height) {
    background_.Initialize(width, height);
    background_.Load("sandboxBackground.bmp");
    lost_ = false;
  }  // nondefault accepts width/height param to change size of game screen
     // according to user input access objects by reference
  graphics::Image& GetGameScreen() { return background_; }
  void LaunchProjectiles();
  void CreateOpponents();
  void Init();
  void UpdateScreen();
  void RemoveInactive();
  void Start();
  void MoveGameElements();
  void FilterIntersections();
  void OnAnimationStep() override;
  void OnMouseEvent(const graphics::MouseEvent& event) override;
 
  std::vector<std::unique_ptr<Opponent>>& GetOpponents() { return opponents_; }
  std::vector<std::unique_ptr<OpponentProjectile>>& GetOpponentProjectiles() {
    return opponent_projectiles_;
  }
  std::vector<std::unique_ptr<PlayerProjectile>>& GetPlayerProjectiles() {
    return player_projectiles_;
  }
  Player& GetPlayer() { return player; }
  int GetScore() const { return score_; }
 
  bool HasLost() { return lost_; }
};
 
#endif
