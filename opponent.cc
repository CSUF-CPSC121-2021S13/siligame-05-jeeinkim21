#include "opponent.h"
#include "game.h"
#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"

void Opponent::Draw(graphics::Image &player2) {
  // player2.DrawRectangle(17, 0, 14, 8, 102, 0, 0);
  // player2.DrawRectangle(14, 2, 20, 2, 102, 0, 0);
  // player2.DrawRectangle(11, 3, 25, 18, 102, 0, 0);
  // player2.DrawRectangle(12, 19, 23, 5, 102, 0, 0);
  // player2.DrawRectangle(18, 23, 13, 8, 0, 0, 102);      // end of head
  // player2.DrawRectangle(16, 8, 15, 5, 64, 64, 64);      // grey headband
  // player2.DrawRectangle(16, 10, 15, 1, 160, 160, 160);  // grey headband
  // player2.DrawRectangle(37, 21, 3, 1, 64, 64, 64);      // grey sword
  player2.DrawRectangle(36, 22, 3, 1, 64, 64, 64);
  player2.DrawRectangle(35, 23, 3, 1, 64, 64, 64);
  player2.DrawRectangle(34, 24, 3, 1, 64, 64, 64);
  player2.DrawRectangle(33, 25, 3, 1, 64, 64, 64);
  player2.DrawRectangle(32, 26, 3, 1, 64, 64, 64);
  player2.DrawRectangle(31, 27, 3, 1, 64, 64, 64);
  player2.DrawRectangle(30, 28, 3, 2, 64, 64, 64);      // end sword
  player2.DrawRectangle(14, 13, 19, 5, 255, 204, 204);  // head peach part
  player2.DrawRectangle(15, 18, 17, 2, 255, 204, 204);
  player2.DrawRectangle(16, 14, 5, 4, 255, 255, 255);  // left eye white
  player2.DrawRectangle(17, 15, 3, 2, 0, 0, 0);        // left eye black
  player2.DrawRectangle(26, 14, 5, 4, 255, 255, 255);  // right eye
  player2.DrawRectangle(27, 15, 3, 2, 0, 0, 0);        // right eye
  player2.DrawRectangle(12, 12, 6, 2, 0, 0, 0);        // left
  player2.DrawRectangle(16, 13, 5, 2, 0, 0, 0);        // r eyebrow
  player2.DrawRectangle(28, 12, 6, 2, 0, 0, 0);        // right eyebrow
  player2.DrawRectangle(26, 13, 5, 2, 0, 0, 0);        // r eyebrow
  // player2.DrawRectangle(16, 23, 15, 16, 0, 0, 0);      // black background
  player2.DrawRectangle(16, 27, 6, 4, 102, 0, 0);      // left arm
  player2.DrawRectangle(22, 27, 1, 3, 255, 204, 204);  // left hand
  player2.DrawRectangle(25, 27, 6, 4, 102, 0, 0);      // right arm
  player2.DrawRectangle(25, 27, 1, 3, 255, 204, 204);  // right hand
  player2.DrawRectangle(19, 33, 4, 5, 102, 0, 0);      // left leg
  player2.DrawRectangle(25, 33, 4, 5, 102, 0, 0);      // right leg
  player2.DrawRectangle(19, 37, 4, 3, 64, 64, 64);     // left shoe
  player2.DrawRectangle(25, 37, 4, 3, 64, 64, 64);     // right shoe
}

std::unique_ptr<OpponentProjectile> Opponent::LaunchProjectile() { //not sure check later 
    
    if (counter == 10) {
    std::unique_ptr<OpponentProjectile> unique_oppProjectile = std::make_unique<OpponentProjectile>(Opponent::GetX(), Opponent::GetY());
    counter = 0; 
    return unique_oppProjectile; 
     }
    else {  
      counter++;
      return nullptr; 
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

void OpponentProjectile::Draw(graphics::Image &oProjectile) {
  oProjectile.DrawRectangle(0, 0, 2, 1, 102, 0, 0);
  oProjectile.DrawRectangle(0, 1, 3, 1, 102, 0, 0);
  // oProjectile.DrawRectangle(1, 2, 3, 1, 102, 0, 0);
  oProjectile.DrawRectangle(2, 3, 6, 1, 102, 0, 0);
  oProjectile.DrawRectangle(2, 4, 2, 1, 102, 0, 0);
  oProjectile.DrawRectangle(3, 5, 1, 1, 102, 0, 0);
  oProjectile.DrawRectangle(6, 4, 2, 1, 102, 0, 0);
  oProjectile.DrawRectangle(6, 5, 1, 1, 102, 0, 0);
  oProjectile.DrawRectangle(6, 2, 3, 1, 102, 0, 0);
  oProjectile.DrawRectangle(7, 1, 3, 1, 102, 0, 0);
  oProjectile.DrawRectangle(8, 0, 2, 1, 102, 0, 0);
  oProjectile.DrawRectangle(2, 6, 6, 1, 102, 0, 0);
  oProjectile.DrawRectangle(1, 7, 3, 1, 102, 0, 0);
  oProjectile.DrawRectangle(6, 7, 3, 1, 102, 0, 0);
  oProjectile.DrawRectangle(0, 8, 3, 1, 102, 0, 0);
  oProjectile.DrawRectangle(7, 8, 3, 1, 102, 0, 0);
  oProjectile.DrawRectangle(0, 9, 2, 1, 102, 0, 0);
  oProjectile.DrawRectangle(8, 9, 2, 1, 102, 0, 0);
  // oProjectile.SaveImageBmp("opponent_projectile.bmp");
  // graphics::Image opponentProjectileImage;
  // opponentProjectileImage.Initialize(GetWidth(), GetHeight());
  // opponentProjectileImage.Load("opponent_projectile.bmp");
  // if (GetX() >= 0 && GetX() <= image.GetWidth() && GetY() >= 0 &&
  //     GetY() <= image.GetHeight()) {
  //   for (int i = 0; i < opponentProjectileImage.GetWidth(); i++) {
  //     for (int j = 0; j < opponentProjectileImage.GetHeight(); j++) {
  //       //  int XX = i + (x_ - opponentImage.GetWidth() /2 );
  //       // int YY = j + (y_ - opponentImage.GetHeight() / 2 );
  //       image.SetColor(GetX() + i, GetY() + j,
  //                      opponentProjectileImage.GetColor(i, j));
  //     }
  //   }
  // }
  // return;
}

void OpponentProjectile::Move(const graphics::Image &image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() - 3);
    SetX(GetX() - 3);
  } else {
    SetIsActive(false);
  }
}
