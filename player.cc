#include "player.h"
#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"

void Player::Draw(graphics::Image& image) {
  graphics::Image playerImage;
  playerImage.Initialize(GetWidth(), GetHeight());
  playerImage.Load("player.bmp");
  if (GetX() >= 0 && GetX() <= image.GetWidth() && GetY() >= 0 &&
      GetY() <= image.GetHeight()) {
    for (int i = 0; i < playerImage.GetWidth(); i++) {
      for (int j = 0; j < playerImage.GetHeight(); j++) {
        //  int XX = i + (x_ - opponentImage.GetWidth() /2 );
        // int YY = j + (y_ - opponentImage.GetHeight() / 2 );
        image.SetColor(GetX() + i, GetY() + j, playerImage.GetColor(i, j));
      }
    }
  }
}

void PlayerProjectile::Draw(graphics::Image& image) {
  graphics::Image playerProjectileImage;
  playerProjectileImage.Initialize(GetWidth(), GetHeight());
  playerProjectileImage.Load("player_projectile.bmp");
  if (GetX() >= 0 && GetX() <= image.GetWidth() && GetY() >= 0 &&
      GetY() <= image.GetHeight()) {
    for (int i = 0; i < playerProjectileImage.GetWidth(); i++) {
      for (int j = 0; j < playerProjectileImage.GetHeight(); j++) {
        //  int XX = i + (x_ - opponentImage.GetWidth() /2 );
        // int YY = j + (y_ - opponentImage.GetHeight() / 2 );
        image.SetColor(GetX() + i, GetY() + j,
                       playerProjectileImage.GetColor(i, j));
      }
    }
  }
}

void Player::Move(const graphics::Image& image) {}

void PlayerProjectile::Move(const graphics::Image& image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() - 3);
    SetX(GetX() - 3);
  } else {
    SetIsActive(false);
  }
}
