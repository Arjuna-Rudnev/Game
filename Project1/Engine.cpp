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
    ground.read("gnd.txt");
    grass.read("grass.txt");
    farm.read("farm.txt");
    farm_up.read("farm_up");
    water.read("water.txt");
    water_grass.read("water_grass.txt");
    building.read("building.txt");
    building_up.read("building_up");
    tree.read("tree.txt");
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

