#include <SFML/Graphics.hpp>
using namespace sf;
float kadr = 0; // кадр анимации

class player {
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
        if ((m_x + m_w >= 1920)&&(Keyboard::isKeyPressed(Keyboard::D)) ) {
            m_speed = 0;
        }
        if ((m_x <= 0) && (Keyboard::isKeyPressed(Keyboard::A))) {
            m_speed = 0;
        }

       
    }
};
class fon {

};
int main(){
    RenderWindow window(VideoMode(1920, 1080), "DEAD!");

    Texture texture;
    Sprite Fon;
    texture.loadFromFile("assets/Fon.png");
    Fon.setTexture(texture);


    player boy(1000, 450, 350, 620, "boy.png");
    Clock clock;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 1500;
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        boy.stopped(1000, 350);
        boy.update(time);
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            boy.dir = 0;
            boy.m_speed = 0.5;
            kadr = kadr + 0.01 * time;
            if (kadr > 4) {
                kadr = kadr - 4;
            }
            boy.sprite.setTextureRect(IntRect(375 * int(kadr), 600, 350, 620));
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            boy.dir = 1;
            boy.m_speed = 0.5;
            kadr = kadr + 0.01 * time;
            if (kadr > 4) {
                kadr = kadr - 4;
            }
            boy.sprite.setTextureRect(IntRect(370 * int(kadr), 0, 350, 620));
        }



        window.clear();
        window.draw(Fon);
        window.draw(boy.sprite);
        window.display();
    }

    return 0;
}