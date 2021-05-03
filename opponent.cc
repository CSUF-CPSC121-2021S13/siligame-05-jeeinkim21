#include "opponent.h"
#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"

std::unique_ptr<OpponentProjectile> Opponent::LaunchProjectile() { //not sure check later 
    int counter = 0; 
    for (int i = 0; i < opponents_.size(); i++) {
    std::unique_ptr<OpponentProjectile> unique_oppProjectile = std::make_unique<OpponentProjectile>(); 
    if ( counter % 10 == 0 && counter < 200) {
      return std::move(unique_oppProjectile); 
      counter+=1;
     }
    else {
      return nullptr; 
     }
    }
}

void Opponent::Draw(graphics::Image &image) {
  graphics::Image opponentImage;
  opponentImage.Initialize(GetWidth(), GetHeight());
  opponentImage.Load("opponent.bmp");

  for (int i = 0; i < opponentImage.GetWidth(); i++) {
    for (int j = 0; j < opponentImage.GetHeight(); j++) {
      if (opponentImage.GetColor(i, j) != graphics::Color(255, 255, 255)) {
        image.SetColor(GetX() + i, GetY() + j, opponentImage.GetColor(i, j));
      }
    }
  }
}

void Opponent::Move(const graphics::Image &image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() - 3);
    SetX(GetX() - 3);
  } else {
    SetIsActive(false);
  }
}

void OpponentProjectile::Draw(graphics::Image &image) {
  graphics::Image opponentProjectileImage;
  opponentProjectileImage.Initialize(GetWidth(), GetHeight());
  opponentProjectileImage.Load("opponent_projectile.bmp");
  if (GetX() >= 0 && GetX() <= image.GetWidth() && GetY() >= 0 &&
      GetY() <= image.GetHeight()) {
    for (int i = 0; i < opponentProjectileImage.GetWidth(); i++) {
      for (int j = 0; j < opponentProjectileImage.GetHeight(); j++) {
        //  int XX = i + (x_ - opponentImage.GetWidth() /2 );
        // int YY = j + (y_ - opponentImage.GetHeight() / 2 );
        image.SetColor(GetX() + i, GetY() + j,
                       opponentProjectileImage.GetColor(i, j));
      }
    }
  }
  return;
}

void OpponentProjectile::Move(const graphics::Image &image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() - 3);
    SetX(GetX() - 3);
  } else {
    SetIsActive(false);
  }
}
