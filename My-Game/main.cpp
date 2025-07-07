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
        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) 
            playerSprite.setPosition(position + sf::Vector2f(0, -0.1));
 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
            playerSprite.setPosition(position + sf::Vector2f(0.1, 0));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) 
            playerSprite.setPosition(position + sf::Vector2f(0.0,0.1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) 
            playerSprite.setPosition(position + sf::Vector2f(-0.1, 0));
       
      
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();
    }
}