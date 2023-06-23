#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "header.hpp"
using namespace sf;
float kadr = 1; // кадр анимации


int main(){
    RenderWindow window(VideoMode(1920, 1080), "DEAD!");

    Texture texture; // фон
    Sprite Fon;
    texture.loadFromFile("assets/Fon.png");
    Fon.setTexture(texture);

    SoundBuffer hello; // музыка
    hello.loadFromFile("assets/hello.wav");
    Sound sound(hello);
    sound.setVolume(30.f);

    lol::player boy(200, 450, 48, 80, "player.png");
    Clock clock;
    while (window.isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 1500;
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
       /* boy.stopped(1000, 350);*/
        boy.update(time);
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            boy.dir = 0;
            boy.m_speed = 0.5;
            kadr = kadr + 0.02 * time;
            if (kadr > 4) {
                kadr = kadr - 4;
            }
            boy.sprite.setTextureRect(IntRect(48 * int(kadr), 240, 48, 80));
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            boy.dir = 1;
            boy.m_speed = 0.5;
            kadr = kadr + 0.02 * time;
            if (kadr > 4) {
                kadr = kadr - 4;
            }
            boy.sprite.setTextureRect(IntRect(48 * int(kadr), 160, 48, 80));
        }
        if (Keyboard::isKeyPressed(Keyboard::F)) {
            sound.play();
        }
        window.clear();
        window.draw(Fon);
        window.draw(boy.sprite);
        window.display();
    }
    return 0;
}