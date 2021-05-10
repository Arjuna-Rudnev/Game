#include <iostream>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include <string>
using namespace sf;
Object::Object( std::string obj_texture, int Number, int Object_in_inventory , int position_x, int positon_y , int hr, int sr, int au, int du)
{
	number = Number;
	object_in_inventory = Object_in_inventory;
	position.x = position_x;
	position.y = position_x;
	health_recovery = hr;
	stamina_recovery = sr;
	armor_units = au;
	damage_units = du;
	texture.loadFromFile(obj_texture);
	sprite.setTexture(texture);
	sprite.setPosition(position);
}
Sprite Object::Object_Sprite()
{
	return sprite;
}
Vector2f Object::Object_Position()
{
	return position;
}
int Object::Object_characteristics()
{
	return health_recovery, stamina_recovery, armor_units, damage_units;
}
