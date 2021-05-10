#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
using namespace sf;
class Player
{
private:
	bool Left_pressed = false;
	bool Right_pressed = false;
	bool Up_pressed = false;
	bool Down_pressed = false;
	bool Run_pressed = false;
public:
	Player();
	Sprite player_sprite;
	Texture player_texture;
	Texture player_movement1_texture;
	Texture player_movement2_texture;
	Vector2f player_position;
	Vector2f player_speed;
	Object inventory[10][4];
	Sprite getSprite();
	int animation_number = 0; // 0 - stop, 1 - player_movement1_texture, 2 - player_movement2_texture
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	void run();
	void stoprun();
	int stop();
	void update(float elapsedTime);
	void add_item_to_inventory(Object &item);
	void delete_item_from_inventory(int i, int j);
	float distance(Object item);
};