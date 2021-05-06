#include "game_element.h"
#include <vector>
#include "cpputils/graphics/image.h"

void GameElement::Draw(graphics::Image& image) {
  // image.Initialize(50, 50);
  image.DrawRectangle(GetX(), GetY(), 5, 5, 0, 0, 0);
  /*
  if (x_ >= 0 && x_ <= image.GetWidth() && y_ >= 0 && y_ <= image.GetHeight()) {
    for (int i = 0; i < opponentImage.GetWidth(); i++) {
      for (int j = 0; j < opponentImage.GetHeight(); j++) {
        //  int XX = i + (x_ - opponentImage.GetWidth() /2 );
        // int YY = j + (y_ - opponentImage.GetHeight() / 2 );
        image.SetColor(x_ + i, y_ + j, opponentImage.GetColor(i, j)); */
}

bool GameElement::IntersectsWith(GameElement* element) {
  return !(GetX() > element->GetX() + element->GetWidth() ||
           element->GetX() > GetX() + GetWidth() ||
           GetY() > element->GetY() + element->GetHeight() ||
           element->GetY() > GetY() + GetHeight());
}

bool GameElement::IsOutOfBounds(const graphics::Image& image) {
  if (GetX() + GetWidth() >
          image
              .GetWidth() ||  // right wall of the element, right wall of screen
      GetY() + GetHeight() >
          image.GetHeight() ||  // left wall of element, top wall of screen
      GetX() < 0 ||
      GetY() < 0)

  {
    return true;
  } else {
    return false;
  }
}
