#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H
#include <string>
#include "cpputils/graphics/image.h"

class GameElement {
 public:
  GameElement() : x_(0), y_(0), kWidth_(50), kHeight_(50) {}
  GameElement(int x, int y, int kWidth, int kHeight)
      : x_(x), y_(y), kWidth_(kWidth), kHeight_(kHeight) {}

  virtual void Draw(graphics::Image& image) = 0;  // draws 5x5 black square
  // Create a Move pure virtual function that accepts a reference to a
  // graphics::Image object
  virtual void Move(const graphics::Image& image) = 0;
  // Modify the IntersectsWith member function to receive a GameElement pointer
  // instead of a constant reference. As a result you will need to modify the
  // code to use pointers.
  bool IntersectsWith(GameElement* element);
  // IsOutOfBounds member function thact accepts a reference to a
  // graphics::Image object and returns a boolean value
  bool IsOutOfBounds(const graphics::Image& image);

  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }
  void SetIsActive(bool isActive) {
    is_active = isActive;
  }  // set active or not active obj
  bool GetIsActive() const { return is_active; }
  int GetX() const { return x_; }
  int GetY() const { return y_; }
  int GetWidth() const { return kWidth_; }
  int GetHeight() const { return kHeight_; }

 protected:
  bool is_active = true;
  int x_;
  int y_;
  int kWidth_;
  int kHeight_;
};

#endif
