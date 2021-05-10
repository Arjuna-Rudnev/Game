#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "wall.h"
#include "Object.h"
#include <string>
using namespace sf;

class Engine
{
private:
	RenderWindow m_window;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	Sprite m_inventorySprite;
	Texture m_inventoryTexture;
	Player m_player;
	All_Objects Objects;
	Vector2f inventory;
	Cursor m_cursor;
	int inventory_is_open = 0;
	void input();
	void update(float dtAsSeconds);
	void collision();
	void animation(float dtAsSeconds);
	void draw();
	sf::Event event;
public:
	Engine();
	//The start function will call all private functions
	void start();
};