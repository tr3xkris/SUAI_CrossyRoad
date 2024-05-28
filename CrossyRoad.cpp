#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Cars.h"

using namespace sf;

enum class Game {
    game,
    win,
    lose
};

bool startGame() {
    //Window
    float winWidth = 900.0f;
    float winHeight = 600.0f;

    RenderWindow window(VideoMode(winWidth, winHeight), "Crossy Road 2D!");

    //10 питерских дорог
    Texture textLvl1;
    textLvl1.loadFromFile("Image/lvl1.png");
    RectangleShape lvl1(Vector2f(2000, 600));
    lvl1.setTexture(&textLvl1);

    //Победа
    Texture textWin;
    textWin.loadFromFile("Image/youWin.png");
    RectangleShape gamingWin(Vector2f(900, 600));
    gamingWin.setTexture(&textWin);
    //Поражение
    Texture textLose;
    textLose.loadFromFile("Image/youLose.png");
    RectangleShape gamingLose(Vector2f(900, 600));
    gamingLose.setTexture(&textLose);

    //Player и Carsвф
    Player player(50, 300, "Image/pers.png");
    Cars cars(225, -50, "Image/car.png");

    Clock clock;
    Game state = Game::game;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds(); //Время 
        time /= 400;
        clock.restart();

        if (Keyboard::isKeyPressed(Keyboard::Tab)) {
            return true;
        }

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        switch (state)
        {
        case Game::game:
            if (player.x >= 1800) {
                state = Game::win;
            }
            if (cars.loser) {
                state = Game::lose;
                cars.loser = false;
            }
            window.setView(View(FloatRect(player.x - winHeight / 3, 0, winWidth, winHeight))); //Камера
            window.clear(Color::Green);
            window.draw(lvl1);
            player.playerMove(time);
            window.draw(player.sprite);
            cars.update(player, window, time);
            window.display();
            break;

        case Game::win:
            if (Keyboard::isKeyPressed(Keyboard::R)) {
                player.sprite.setPosition(50, 300);
                state = Game::game;
            }
            window.clear(Color::Green);
            gamingWin.setPosition(player.x - 200, 0);
            window.draw(gamingWin);
            window.display();
            break;

        case Game::lose:
            if (Keyboard::isKeyPressed(Keyboard::R)) {
                player.sprite.setPosition(50, 300);
                state = Game::game;
            }
            window.clear(Color::Green);
            gamingLose.setPosition(player.x - 200, 0);
            window.draw(gamingLose);
            window.display();
            break;
        }
    }

    return 0;
}

void gameRunning() {
    if (startGame()) {
        gameRunning();
    }
}

int main()
{
    gameRunning();

}