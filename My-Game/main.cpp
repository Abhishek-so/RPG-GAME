#include <SFML/Graphics.hpp>
#include<iostream>

int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML shapes", sf::Style::Default, sf::State::Windowed, settings);
    //---------------------------LOAD----------------------------------//
    
    sf::Texture texture("Assets/Player/Textures/ship.png");
    sf::Sprite playerSprite(texture);
    
    //Main game loop 
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {

            sf::Vector2f position1 = playerSprite.getPosition();
            playerSprite.setPosition(position1 + sf::Vector2f(0, -0.1));
        }
 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            sf::Vector2f position2 = playerSprite.getPosition();
            playerSprite.setPosition(position2 + sf::Vector2f(0.1, 0));

        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            sf::Vector2f position3 = playerSprite.getPosition();
            playerSprite.setPosition(position3 + sf::Vector2f(0.0,0.1));

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            sf::Vector2f position4 = playerSprite.getPosition();

            playerSprite.setPosition(position4 + sf::Vector2f(-0.1, 0));
        }
       
      
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();
    }
}