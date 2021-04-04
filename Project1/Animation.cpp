#include "Engine.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
float Animation_timer = 0;
void Engine::animation(float dtAsSeconds)
{
	//time for one picture
	float movement_animation_timeAsSecond = 1.5;

	//check picture's number
	if (m_player.stop() == 1)
	{
		m_player.player_sprite.setTexture(m_player.player_texture);
		Animation_timer = 0;
		m_player.animation_number = 0;
	}
	else
	{
		Animation_timer += 10*dtAsSeconds;
		if ((m_player.animation_number != 1) && (movement_animation_timeAsSecond < Animation_timer))
		{
			m_player.player_sprite.setTexture(m_player.player_movement1_texture);
			m_player.animation_number = 1;
			Animation_timer = 0;
		}
		else
			if ((m_player.animation_number != 2) && (movement_animation_timeAsSecond < Animation_timer))
			{
				m_player.player_sprite.setTexture(m_player.player_movement2_texture);
				m_player.animation_number = 2;
				Animation_timer = 0;
			}
	}
}
