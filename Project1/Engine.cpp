#include "Engine.h"

Engine::Engine()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    m_window.create(VideoMode(resolution.x, resolution.y), "Simple Game Engine", Style::Fullscreen);
    m_BackgroundTexture.loadFromFile("background.jpg");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
    m_inventoryTexture.loadFromFile("inventory.png");
    m_inventorySprite.setTexture(m_inventoryTexture);
}

void Engine::start()
{
   // Timing
    Clock clock;
    while (m_window.isOpen())
    {
        m_window.setFramerateLimit(60); 
     
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        input();
        update(dtAsSeconds);
        collision();
        animation(dtAsSeconds);
        draw();
      
    }
}

