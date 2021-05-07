#include "player.h"
#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"

void Player::Draw(graphics::Image& image) {
  if (score_ <= 50) {
  graphics::Image playerImage(50, 50);
  playerImage.Load("player.bmp");
  for (int i = 0; i < playerImage.GetWidth(); i++) {
    for (int j = 0; j < playerImage.GetHeight(); j++) {
      image.SetColor(GetX() + i, GetY() + j, playerImage.GetColor(i, j));
    }
  }
  }
  else {
    graphics::Image playerImage(50,50);
    playerImage.Load("playerAdvanced.bmp");
    for (int i = 0; i < playerImage.GetWidth(); i++) {
    for (int j = 0; j < playerImage.GetHeight(); j++) {
      image.SetColor(GetX() + i, GetY() + j, playerImage.GetColor(i, j));
    }
  }
  }
}

void PlayerProjectile::Draw(graphics::Image& image) {
  graphics::Image playerProjectileImage(10, 10);
  playerProjectileImage.Load("player_projectile.bmp");
  for (int i = 0; i < playerProjectileImage.GetWidth(); i++) {
    for (int j = 0; j < playerProjectileImage.GetHeight(); j++) {
      image.SetColor(GetX() + i, GetY() + j,
                     playerProjectileImage.GetColor(i, j));
    }
  }
}

void Player::Move(const graphics::Image& image) {}

void PlayerProjectile::Move(const graphics::Image& image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() - 3);
  } else {
    SetIsActive(false);
  }
}
