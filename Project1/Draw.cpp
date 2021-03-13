#include "Engine.h"
#include "Player.h"
#include <iostream>
void Engine::draw()
{
    // Стираем предыдущий кадр
    m_window.clear(Color::White);

    m_window.draw(m_BackgroundSprite);
    m_window.draw(m_player.getSprite());

    // Отображаем все, что нарисовали
    m_window.display();
}
