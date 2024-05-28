#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;
using namespace std;

class Cars
{
private:
    Texture texture;
    const int windowHeight = 900;
    const int windowWidth = 700;
public:

    struct coordinates {
        int x, y;
    };
    vector <coordinates> cars;

    Sprite sprite;
    float gravity;
    bool loser = false;

    Cars(float initialX, float initialY, const string& TextureFile) : gravity(1.0f) {
        texture.loadFromFile(TextureFile);
        sprite.setTexture(texture);
        sprite.setPosition(initialX, initialY);

        coordinates car;
        car.x = 225;
        car.y = 10;
        cars.push_back(car);
    }

    void update(Player& player, RenderWindow& window, float& time);
};