#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
class Tile
{
public:
	int sprite_number;
	Sprite sprite;
	bool collision;
	Vector2f position;
	void add_number(int number)
	{
		sprite_number = number;
	}
};
class Map
{
public:
	Texture BaseChip_pipo;
	Texture WaterFall_pipo;
	Texture Grass_pipo;
	Texture Water_pipo;
	Texture Flower_pipo;
	Tile tile_array[50][50];
	void read(std::string path_to_file);
};
