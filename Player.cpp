#include "Player.h"

void Player::playerMove(float& time)
{
    if (Keyboard::isKeyPressed(Keyboard::A)) { //�����
        x -= (speed * time);
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) { //������
        x += (speed * time);
    }
    
    sprite.setPosition(x, y);
}