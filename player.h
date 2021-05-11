#include <string>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"
 
 
#ifndef PLAYER_H
#define PLAYER_H
 
class Player : public GameElement {
 public:
  Player() : Player(0, 0) {}
  Player(int x, int y) : GameElement(x, y, 50, 50) {}
  void Move(
      const graphics::Image& image) override;  // inherits from game_element
 
  void Draw(graphics::Image& player1) override;

  void Helper(graphics::Image& playerImage,graphics::Image& image); //for draw function
 
  void Draw2(graphics::Image& image);
 
  void Draw3(graphics::Image& image);

  void Draw4(graphics::Image& image);

  private:
  graphics::Image playerImage;
  graphics::Image playerImage2; 
  bool toggleSwitch = true; //for animation effect 
  bool toggleImage = false; 
 
  //   bool IntersectsWith(Opponent& opponent_obj);
  //   bool IntersectsWith(OpponentProjectile& opponent_projectile_obj);
};
 
class PlayerProjectile : public GameElement {
 public:
  PlayerProjectile() : PlayerProjectile(0, 0) {}
  PlayerProjectile(int x, int y) : GameElement(x, y, 10, 10) {}  // inheritance
  void Move(
      const graphics::Image& image) override;  // inherits from game_element
 
  void Draw(graphics::Image& pProjectile) override;
 
  //   bool IntersectsWith(Opponent& opp);
};
 
#endif
