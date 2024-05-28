#include "Player.h"

void Player::playerMove(float& time)
{
    if (Keyboard::isKeyPressed(Keyboard::A)) { //Влево
        x -= (speed * time);
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) { //Вправо
        x += (speed * time);
    }
    
    sprite.setPosition(x, y);
}