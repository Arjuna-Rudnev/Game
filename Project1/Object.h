#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
class Object
{
public:
	Sprite sprite;
	Texture texture;
	Vector2f position;
	int health_recovery;
	int stamina_recovery;
	int armor_units;
	int damage_units;
	int number;
	Object(std::string obj_texture = "Emptiness.png",int Number = 0, int Object_in_inventory = false, int position_x = 0, int positon_y = 0, int hr = 0, int sr = 0, int au = 0, int du = 0);
	Sprite Object_Sprite();
	Vector2f Object_Position();
	bool object_in_inventory;
	int Object_characteristics();
	bool empty()
	{
		if (number == 0)
			return true;
		else
			return false;
	}
};
class All_Objects
{
public:
	Object Apple1{ "Apple.png",1, false, 100, 100, 10, 0, 0, 0};
	Object Apple2{"Apple.png", 1, false, 800, 800, 10, 0, 0, 0};
	Object Emptiness;
};



