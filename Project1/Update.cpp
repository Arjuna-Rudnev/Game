#include "Engine.h"
#include <iostream>
using namespace sf;

void Engine::update(float dtAsSeconds)
{
    m_player.update(dtAsSeconds);

}