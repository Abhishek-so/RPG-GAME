#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>

//--------------------------------------Normalize vector_________________________________
sf::Vector2f NormalizedVector(sf::Vector2f vector) {
    float mag = sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / mag;
    normalizedVector.y = vector.y / mag;
    return normalizedVector;
}
int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML shapes", sf::Style::Default, sf::State::Windowed, settings);

    


    //---------------------------LOAD----------------------------------//
    sf::Texture texture("Assets/Player/Textures/ship.png");
    sf::Sprite playerSprite(texture);
    sf::Texture enemyTexture("Assets/wolf/Texture/Alien-Mothership2.png");
    sf::Sprite enemySprite(enemyTexture);
    playerSprite.setPosition(sf::Vector2f(1700, 700));


    //-----------------------BULLET-----------------------------------
   // sf::RectangleShape bullet(sf::Vector2f(25, 25));
   // sf::Vector2f position = playerSprite.getPosition();
   // bullet.setPosition(position);
    float bulletSpeed = 1.f;
    std::vector<sf::RectangleShape> bullets;
    
    
    //Main game loop 
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
 
        sf::Vector2f position1 = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            
            playerSprite.setPosition(position1 + sf::Vector2f(0, -2));
        }
 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            
            playerSprite.setPosition(position1 + sf::Vector2f(2, 0));
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            playerSprite.setPosition(position1 + sf::Vector2f(0.0, 2));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            playerSprite.setPosition(position1 + sf::Vector2f(-2, 0));
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(20, 10)));
            int lastElement = bullets.size() - 1;
            bullets[lastElement].setPosition(playerSprite.getPosition());
        }
        for (size_t i = 0; i < bullets.size(); i++)
        {
            sf::Vector2f bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
            bulletDirection = NormalizedVector(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
        }
       
      
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.draw(enemySprite);
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);

        }
        window.display();
    }
}