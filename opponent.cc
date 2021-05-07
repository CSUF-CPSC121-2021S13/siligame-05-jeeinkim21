#include "opponent.h"
#include <vector>
#include "cpputils/graphics/image.h"
#include "game.h"
#include "game_element.h"

void Opponent::Draw(graphics::Image &image) {
  graphics::Image opponentImage;
  opponentImage.Initialize(GetWidth(), GetHeight());
  opponentImage.Load("opponent.bmp");
  for (int i = 0; i < opponentImage.GetWidth(); i++) {
    for (int j = 0; j < opponentImage.GetHeight(); j++) {
      //  int XX = i + (x_ - opponentImage.GetWidth() /2 );
      // int YY = j + (y_ - opponentImage.GetHeight() / 2 );
      image.SetColor(GetX() + i, GetY() + j, opponentImage.GetColor(i, j));
    }
  }
}

std::unique_ptr<OpponentProjectile>
Opponent::LaunchProjectile() {  // not sure check later

  if (counter == 10) {
    std::unique_ptr<OpponentProjectile> unique_oppProjectile =
        std::make_unique<OpponentProjectile>(Opponent::GetX(),
                                             Opponent::GetY());
    counter = 0;
    return unique_oppProjectile;
  } else {
    counter++;
    return nullptr;
  }
}

void Opponent::Move(const graphics::Image &image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() + 3);
    SetX(GetX() + 3);
  } else {
    SetIsActive(false);
  }
}

void OpponentProjectile::Draw(graphics::Image &image) {
  graphics::Image opponentPImage(10, 10);
  opponentPImage.Load("opponent_projectile.bmp");
  for (int i = 0; i < opponentPImage.GetWidth(); i++) {
    for (int j = 0; j < opponentPImage.GetHeight(); j++) {
      image.SetColor(GetX() + i, GetY() + j, opponentPImage.GetColor(i, j));
    }
  }
}

void OpponentProjectile::Move(const graphics::Image &image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() - 3);
    SetX(GetX() - 3);
  } else {
    SetIsActive(false);
  }
}
