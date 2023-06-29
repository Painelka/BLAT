#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "move.hpp"
using namespace sf;
float kadr = 1; // кадр анимации

int main(){
    setlocale(LC_ALL, "Russian");
    RenderWindow window(VideoMode(1920, 1080), "Lire");
    Texture texture; // фон
    Sprite Fon;
    texture.loadFromFile("assets/Fon.png");
    Fon.setTexture(texture);

    lol::player boy(200, 450, 48, 80, "player.png", 1, "Лирэ");
    
    Texture textbox_texture;
    Sprite textbox_sprite;
    textbox_texture.loadFromFile("text/Box.png");
    textbox_sprite.setTexture(textbox_texture);

    sf::Font font;
    if (!font.loadFromFile("text/thin_pixel-7.ttf")) {
        // Обработка ошибки при загрузке шрифта
        return -1;
    }


    sf::Text text;
    text.setFont(font);
    text.setString(L"Лирэ");
    text.setCharacterSize(55);
    text.setPosition(200, 700);










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
        lol::Textbox Box(100, 500, 800, 300, "Box1.png");
        bool flak = false;
        
        if (Keyboard::isKeyPressed(Keyboard::E)) {
            int k = 0;
            flak = true;
            window.draw(Box.textbox_sprite);
            window.draw(text);
            window.display();
            while ((flak) &&(k<2)) {
                window.draw(Box.textbox_sprite);
                window.draw(text);
                
                if (Keyboard::isKeyPressed(Keyboard::Q)) {
                    k = k + 1;
                    Text text1;
                    text1.setString(L"Lalalalalalla");
                    window.draw(text1);
                    

                }
            }
          
           
        }
        window.clear();
        window.draw(Fon);
        window.draw(boy.sprite);
        
        /*window.draw(Box.textbox_sprite);*/
        window.display();
    }
    return 0;
}