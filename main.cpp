﻿#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "move.hpp"
#include <vector>
#include <chrono>
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
    lol::npc npc (30, 450, 36, 82, "npc.png", 1);
    lol::cat cat (1200, 500, 74, 120, "bananacat.png");




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
    text.setCharacterSize(70);
    text.setPosition(155, 680);


    sf::Text text3;
    text3.setFont(font);
    text3.setString(L"Мэршон");
    text3.setCharacterSize(70);
    text3.setPosition(155, 680);

    sf::Text text1;
    text1.setFont(font);
    text1.setString(L"ertalalla");

    text1.setCharacterSize(55);
    text1.setPosition(200, 800);





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
            npc.npc_sprite.setPosition(-205, -30);
            cat.npc1_sprite.setPosition(-205, -30);

        }
        if (boy.granics(80, 800)) {
            texture.loadFromFile("assets/Fon.png");
            Fon.setTexture(texture);
            window.clear();
            window.draw(Fon);
            window.draw(boy.sprite);
            npc.npc_sprite.setPosition(30, 450);
            window.draw(npc.npc_sprite);
            cat.npc1_sprite.setPosition(787, 500);
            window.draw(cat.npc1_sprite);
        }
        lol::Textbox Box(100, 500, 800, 300, "Box1.png", "HELP ME");
        vector<string> talk = { "Hello", "...", "Im not Fine",  "Why", "Matan"};
    
        float k = 0;
        if ((Keyboard::isKeyPressed(Keyboard::E))&& (boy.m_x<=npc.npc_x+50)&& (boy.m_y <= npc.npc_y + 50)) {
 
            window.draw(Box.textbox_sprite);
            window.draw(text);
            window.display();
            while ((k<5)) {
                window.draw(Box.textbox_sprite);
                window.draw(text);
                if (1 <= k < 2) {
                    window.draw(Box.textbox_sprite);
                    window.draw(text3);
                    
                }
                if (Keyboard::isKeyPressed(Keyboard::Q)) {
                  
                    cout << k << endl;
                    text1.setString(talk[k]);
                    window.draw(text1);
                    window.display();
                    k = k + 0.045;
                }
            }
        }
        float t = 0;
        vector<string> talk2 = { "Cat?", "Cute....?"};
        if((Keyboard::isKeyPressed(Keyboard::E)) && ((cat.npc_x2 + 100) >= boy.m_x >= (cat.npc_x2 - 100)) && ((cat.npc_y2 + 50) >= boy.m_y )) {
            cat.said("meow.wav");
            cout << cat.npc_x2 << endl;
            cout << cat.npc_y2 << endl;
            cout << boy.m_x << endl;
            window.draw(Box.textbox_sprite);
            window.draw(text);
            window.display();
            while ((t <= 2)) {
                window.draw(Box.textbox_sprite);
                window.draw(text);
                if (Keyboard::isKeyPressed(Keyboard::Q)) {
                    cout << t << endl;
                    text1.setString(talk2[t]);
                    window.draw(text1);
                    window.display();
                    t = t + 0.25;
                    
                }
            }
        }

       



        window.clear();
        window.draw(Fon);
        window.draw(npc.npc_sprite);
        window.draw(boy.sprite);
        window.draw(cat.npc1_sprite);
        window.display();
    }
    return 0;
}