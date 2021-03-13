#include "Engine.h"
#include "Player.h"
#include <iostream>
void Engine::input()
{
        // Escape
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            m_window.close();

        // movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            m_player.moveLeft();
        else
            m_player.stopLeft();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            m_player.moveRight();
        else
            m_player.stopRight();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            m_player.moveUp();
        else
            m_player.stopUp();
 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            m_player.moveDown();
        else
            m_player.stopDown();
}
