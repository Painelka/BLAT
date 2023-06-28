#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;
namespace lol {
    class player { //класс персонажа
    public:
        float m_x, m_y, m_w, m_h, m_vx, m_vy, m_speed = 0;
        int dir = 0;
        int m_location = 0;
        String m_name;
        Texture texture;
        Sprite sprite;
        player(int x, int y, int w, int h, String name) {
            m_x = x;
            m_y = y;
            m_w = w;
            m_h = h;
            m_name = name;

            texture.loadFromFile("assets/" + name);
            sprite.setTexture(texture);
            sprite.setTextureRect(IntRect(0, 0, m_w, m_h));
            sprite.setPosition(m_x, m_y);
        }
        bool flag = false;
        bool perehod(int y, int h) {
            cout << flag << endl;
            if ((m_y <= 0) && (Keyboard::isKeyPressed(Keyboard::W))&& (flag)) {
                m_y = 1000;
                flag = true;
                cout << flag << endl;
                return true;
                
            }
            else { 
                flag = false;
                return false;
            }
        }

        bool granics(int y, int h) {
            if ((m_y + m_h >= 1080) && (Keyboard::isKeyPressed(Keyboard::S))&& (flag == true)) {
                m_y = 200;
                flag = false;
                cout << flag << endl;
                return true;
            }
            else {
                flag = true;
                return true;
            }
        }

        void update(float time) {
            switch (dir) {
            case 0: m_vx = -m_speed; m_vy = 0; break;
            case 1: m_vx = m_speed; m_vy = 0; break;
            case 2: m_vx = 0; m_vy = -m_speed; break;
            case 3: m_vx = 0; m_vy = m_speed; break;
            }
            m_x = m_x + m_vx * time;
            m_y = m_y + m_vy * time;
            m_speed = 0;
            sprite.setPosition(m_x, m_y);
        }
        void stopped(int x, int w, int y, int h) {
            if ((m_x + m_w >= 1920) && (Keyboard::isKeyPressed(Keyboard::D))) {
                m_speed = 0;
            }
            if ((m_x <= 0) && (Keyboard::isKeyPressed(Keyboard::A))) {
                m_speed = 0;
            }

            if ((m_y + m_h >= 1080) && (Keyboard::isKeyPressed(Keyboard::S)) && (flag ==false)) {
                m_speed = 0;
            }
            if ((m_y <= 0) && (Keyboard::isKeyPressed(Keyboard::W)) && (flag == true)) {
                m_speed = 0;
            }
        }
    };

}


