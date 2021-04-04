#include "Engine.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
void Engine::collision()
{
	if (m_player.player_position.x > VideoMode::getDesktopMode().width -300)
		m_player.player_position.x = VideoMode::getDesktopMode().width - 300;
}