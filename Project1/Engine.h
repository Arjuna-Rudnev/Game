#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;

class Engine
{
private:
	RenderWindow m_window;

	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	//Instance player
	Player m_player;

	void input();
	void update(float dtAsSeconds);
	void draw();
	void animation(float dtAsSeconds);
	sf::Event event;
public:
	Engine();
	//The start function will call all private functions
	void start();
};