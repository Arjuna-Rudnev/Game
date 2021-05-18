#include "Engine.h"
#include "Player.h"
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <iostream>
void Engine::collision()
{
	if (m_player.player_position.x > VideoMode::getDesktopMode().width -300)
		m_player.player_position.x = VideoMode::getDesktopMode().width - 300;
	if (m_player.player_position.x < 100)
		m_player.player_position.x =  100;
	if (m_player.player_position.y > VideoMode::getDesktopMode().height - 400)
		m_player.player_position.y = VideoMode::getDesktopMode().height - 400;
	if (m_player.player_position.y < 0)
		m_player.player_position.y = 0;
}