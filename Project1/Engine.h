#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "wall.h"
#include "Object.h"
#include <string>
#include "Map.h"
using namespace sf;

class Engine
{
public:
	RenderWindow m_window;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	Sprite m_inventorySprite;
	Texture m_inventoryTexture;
	Player m_player;
	All_Objects Objects;
	Vector2f inventory;
	Cursor m_cursor;
	Map ground;
	Map grass;
	Map farm;
	Map farm_up;
	Map water;
	Map water_grass;
	Map building;
	Map building_up;
	Map tree;
	int inventory_is_open = 0;
	
	void input();
	void update(float dtAsSeconds);
	void collision();
	void animation(float dtAsSeconds);
	void draw();
	sf::Event event;
	Engine();
	void start();
};