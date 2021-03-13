#include "Engine.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
void Engine::animation()
{

	float movement_animation_timeAsSecond = m_player.player_speed.x / 250;
	Time dt_Animation;
	Clock clock;
	std::cout << m_player.stop() << std::endl;
	if (m_player.stop() == 1)
	{
		m_player.player_sprite.setTexture(m_player.player_texture);
		clock.restart();
	}
	else
		{
		dt_Animation = clock.getElapsedTime();
		std::cout << dt_Animation.asSeconds() << std::endl;
		if ((m_player.animation_number != 1) && (movement_animation_timeAsSecond > dt_Animation.asSeconds()))
		{
			m_player.player_sprite.setTexture(m_player.player_movement2_texture);
			clock.restart();
		}
		else
			if ((m_player.animation_number != 2) && (movement_animation_timeAsSecond > dt_Animation.asSeconds()))
			{
				m_player.player_sprite.setTexture(m_player.player_movement1_texture);
				clock.restart();
			}
		}
}
