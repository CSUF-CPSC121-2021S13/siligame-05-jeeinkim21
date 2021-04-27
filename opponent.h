// siligame 3
#include <string>
#include "cpputils/graphics/image.h"
#include "game_element.h"

#ifndef OPPONENT_H
#define OPPONENT_H

class Opponent : public GameElement {
 public:
  Opponent() : Opponent(0, 0) {}
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}  // inheritance
  void Move(const graphics::Image &image) override;

  void Draw(graphics::Image &image) override;
};

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() : OpponentProjectile(0, 0) {}
  OpponentProjectile(int x, int y)
      : GameElement(x, y, 10, 10) {}  // inheritance
  void Move(const graphics::Image &image) override;

  void Draw(graphics::Image &image) override;
};

#endif
