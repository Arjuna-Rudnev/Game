#include "Engine.h"
#include "Player.h"
#include "Object.h"
#include <iostream>
void Engine::draw()
{
    // Стираем предыдущий кадр
    m_window.clear(Color::White);
    if ((inventory_is_open/4) % 2 == 0)
    {
        
           for (int j = 0; j <50; j++)
            {
                for (int i = 0; i < 50; i++)
                {
                    m_window.draw(m_map.tile_array[i][j].sprite);
                }
            }
        m_window.draw(m_player.getSprite());
        /*
         m_window.draw(m_BackgroundSprite);
        m_window.draw(m_player.getSprite());
        if(Objects.Apple1.object_in_inventory == 0)
            m_window.draw(Objects.Apple1.sprite);
        if (Objects.Apple2.object_in_inventory == 0)
            m_window.draw(Objects.Apple2.sprite);
        */
       
    }
    else
    {
        m_window.draw(m_inventorySprite);
        if (Objects.Apple1.object_in_inventory)
            m_window.draw(Objects.Apple1.sprite);
        if (Objects.Apple2.object_in_inventory)
            m_window.draw(Objects.Apple2.sprite);
    }
    m_window.display();  
}
