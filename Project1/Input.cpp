#include "Engine.h"
#include "Player.h"
#include "Object.h"
#include <iostream>
#include <SFML/Graphics.hpp>
void Engine::input()
{
    // Escape
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        m_window.close();
    //inventory
   // sf::Event event;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) == true )
    {
        inventory_is_open += 1;
    }
    // movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (m_player.stop())
        {
                m_player.player_sprite.setTexture(m_player.player_movement1_texture);
                m_player.animation_number = 1;
        }
        m_player.moveLeft();
    }
    else
        m_player.stopLeft();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (m_player.stop())
            {
                m_player.player_sprite.setTexture(m_player.player_movement2_texture);
                m_player.animation_number = 2;
            }
            m_player.moveRight();
        }
        else
            m_player.stopRight();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (m_player.stop())
            {
                m_player.player_sprite.setTexture(m_player.player_movement1_texture);
                m_player.animation_number = 1;
            }
            m_player.moveUp();
        }
        else
            m_player.stopUp();
 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (m_player.stop())
            {
                m_player.player_sprite.setTexture(m_player.player_movement1_texture);
                m_player.animation_number = 1;
            }
            m_player.moveDown();
        }
        else
            m_player.stopDown();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            m_player.run();
        }
        else
            m_player.stoprun();
        //interaction
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            if(m_player.distance(Objects.Apple1) <= 200)
                m_player.add_item_to_inventory(Objects.Apple1);
            if (m_player.distance(Objects.Apple2) <= 200)
                m_player.add_item_to_inventory(Objects.Apple2);
        }
}
