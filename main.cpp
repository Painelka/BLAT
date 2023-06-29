#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "move.hpp"
using namespace sf;
float kadr = 1; // кадр анимации

int main(){
    RenderWindow window(VideoMode(1920, 1080), "DEAD!");
    Texture texture; // фон
    Sprite Fon;
    texture.loadFromFile("assets/Fon.png");
    Fon.setTexture(texture);
    Texture texture_box; // фон
    Sprite Textbox;
    texture.loadFromFile("text/Box.png");
    Textbox.setTexture(texture_box);
    lol::player boy(200, 450, 48, 80, "player.png", 1);
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
        boy.stopped(1000, 48,80, 800);
        boy.update(time);
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            boy.dir = 0;
            boy.m_speed = 0.3;
            kadr = kadr + 0.01 * time;
            if (kadr > 4) {
                kadr = kadr - 4;
            }
            boy.sprite.setTextureRect(IntRect(48 * int(kadr), 240, 48, 80));
        }
        else if (Keyboard::isKeyPressed(Keyboard::D)) {
            boy.dir = 1;
            boy.m_speed = 0.3;
            kadr = kadr + 0.01 * time;
            if (kadr > 4) {
                kadr = kadr - 4;
            }
            boy.sprite.setTextureRect(IntRect(48 * int(kadr), 160, 48, 80));
        }
        else if (Keyboard::isKeyPressed(Keyboard::W)) {
            boy.dir = 2;
            boy.m_speed = 0.3;
            kadr = kadr + 0.01 * time;
            if (kadr > 4) {
                kadr = kadr - 4;
            }
            boy.sprite.setTextureRect(IntRect(48 * int(kadr), 80, 48, 80));
        }
        else if (Keyboard::isKeyPressed(Keyboard::S)) {
            boy.dir = 3;
            boy.m_speed = 0.3;
            kadr = kadr + 0.01 * time;
            if (kadr > 4) {
                kadr = kadr - 4;
            }
            boy.sprite.setTextureRect(IntRect(48 * int(kadr), 0, 48, 80));
        }
        if (boy.perehod(80, 800)){
            Sprite Pink;
            texture.loadFromFile("assets/pink_2.png");
            Pink.setTexture(texture);
            window.clear();
            window.draw(Pink);
            window.draw(boy.sprite);
        }
        if (boy.granics(80, 800)) {
            texture.loadFromFile("assets/Fon.png");
            Fon.setTexture(texture);
            window.clear();
            window.draw(Fon);
            window.draw(boy.sprite);
        }

  
        window.clear();
        window.draw(Fon);
        window.draw(boy.sprite);
        window.draw(Textbox);
        window.display();
    }
    return 0;
}