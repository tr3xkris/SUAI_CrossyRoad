#include "Cars.h"

void Cars::update(Player& player, RenderWindow& window, float& time)
{
    int cooRoad[10] = {225, 355, 595, 730, 880, 1110, 1230, 1445, 1565, 1710};
    for (coordinates& car : cars) {
        //Collision
        if (player.x <= car.x + 60 &&
            player.x >= car.x - 60 &&
            player.y < car.y + 60 &&
            player.y > car.y - 60)
        {
            loser = true;
        }

        //Spawns
        if (cars[cars.size() - 1].y > 360)
        {
            int a = rand() % 10;
            coordinates newCar1;
            newCar1.x = cooRoad[a];
            newCar1.y = -100;
            cars.push_back(newCar1);
        }
        if (cars[cars.size() - 1].y > 270)
        {
            int a = rand() % 10;
            coordinates newCar2;
            newCar2.x = cooRoad[a];
            newCar2.y = -100;
            cars.push_back(newCar2);
        }
        if (cars[cars.size() - 1].y > 120)
        {
            int a = rand() % 10;
            coordinates newCar3;
            newCar3.x = cooRoad[a];
            newCar3.y = -100;
            cars.push_back(newCar3);
        }

        for (vector<coordinates>::iterator it = cars.begin(); it != cars.end(); ++it)
        {
            if (player.y < car.y - 320)
            {
                cars.erase(it);
                break;
            }
        }

        car.y += (gravity * time);
        sprite.setPosition(car.x, car.y);
        window.draw(sprite);
    }
}