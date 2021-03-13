#include "Engine.h"
#include "Player.h"
#include <iostream>
void Engine::draw()
{
    // ������� ���������� ����
    m_window.clear(Color::White);

    m_window.draw(m_BackgroundSprite);
    m_window.draw(m_player.getSprite());

    // ���������� ���, ��� ����������
    m_window.display();
}
