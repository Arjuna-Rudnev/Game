#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class Wall
{
private:
	Vector2f center;
	int wall_radius_angle[6];
	int wall_radius[6];
	Sprite wall_sprite[11];
	Texture wall_texture;
	
public:
	Sprite getSprite(int i);
	Vector2f wall_corner[6];

	Wall();
};