#include "game_element.h"
#include <vector>
#include "cpputils/graphics/image.h"



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
