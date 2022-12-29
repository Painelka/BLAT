#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
class player { //класс персонажа
public:
    float m_x, m_y, m_w, m_h, m_vx, m_vy, m_speed = 0;
    int dir = 0;
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
    void update(float time) {
        switch (dir) {
        case 0: m_vx = -m_speed; m_vy = 0; break;
        case 1: m_vx = m_speed; m_vy = 0; break;
        }
        m_x = m_x + m_vx * time;
        m_y = m_y + m_vy * time;
        m_speed = 0;
        sprite.setPosition(m_x, m_y);
    }
    void stopped(int x, int w) {
        if ((m_x + m_w >= 1920) && (Keyboard::isKeyPressed(Keyboard::D))) {
            m_speed = 0;
        }
        if ((m_x <= 0) && (Keyboard::isKeyPressed(Keyboard::A))) {
            m_speed = 0;
        }
    }
};

