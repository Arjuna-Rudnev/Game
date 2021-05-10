#include "Player.h"
#include "Engine.h"
#include "Object.h"
#include <iostream>
#include <cmath>
using namespace sf;

Player::Player()
{
	//start speed
	player_speed.x = 400;
	player_speed.y = 400;
	//set player's texture
	player_texture.loadFromFile("player.png");
	player_movement1_texture.loadFromFile("player_movement1.png");
	player_movement2_texture.loadFromFile("player_movement2.png");
	//set player's starting position
	player_position.x = 500;
	player_position.y = 500;
	Object Emptiness;
	for (int j = 0; j < 4; j++)
		for (int i = 0; i < 10; i++)
			inventory[i][j] = Emptiness;
			
}
Sprite Player::getSprite() {
	return player_sprite;
}

void Player::moveLeft()
{
	Left_pressed = true;
}

void Player::moveRight()
{
	Right_pressed = true;
}

void Player::moveUp()
{
	Up_pressed = true;
}

void Player::moveDown()
{
	Down_pressed = true;
}

void Player::run()
{
	Run_pressed = true;
}
void Player::stopLeft()
{
	Left_pressed = false;
}

void Player::stopRight()
{
	Right_pressed = false;
}

void Player::stopUp()
{
	Up_pressed = false;
}

void Player::stopDown()
{
	Down_pressed = false;
}
void Player::stoprun()
{
	Run_pressed = false;
}
int Player::stop()
{
	if (Player::Left_pressed == false && Player::Right_pressed == false && Player::Up_pressed == false && Player::Down_pressed == false)
		return 1;
	else
		return 0;
}
float Player::distance(Object item)
{
	return sqrt((player_position.x - item.position.x) * (player_position.x - item.position.x) + (player_position.y - item.position.y) * (player_position.y - item.position.y));
}
void Player::add_item_to_inventory(Object &item)
{
	for (int j = 0; j < 4; j++)
	{
		for(int i =0 ; i < 10; i++ )
		if (inventory[i][j].empty() && distance(item) <= 200)
		{
			inventory[i][j] = item;
			item.position.x = 70 + i*200;
			item.position.y = 425 + j*100;
			item.object_in_inventory = true;
			item.sprite.setPosition(item.position);
			std::cout << "item is in inventory" << std::endl;
			break;
		}
	}
}
void  Player::delete_item_from_inventory(int i, int j)
{
	Object Eptiness;
	inventory[i][j] = Eptiness;
	inventory[i][j].object_in_inventory = false;
}
void Player::update(float elapsedTime)
{
	if (Right_pressed)
		player_position.x += player_speed.x * elapsedTime;

	if (Left_pressed)
		player_position.x -= player_speed.x * elapsedTime;
	if (Up_pressed)
		player_position.y -= player_speed.y * elapsedTime;

	if (Down_pressed)
		player_position.y += player_speed.y * elapsedTime;

	if (Right_pressed && Run_pressed)
		player_position.x += player_speed.x * elapsedTime * 2;

	if (Left_pressed && Run_pressed)
		player_position.x -= player_speed.x * elapsedTime * 2;

	if (Up_pressed && Run_pressed)
		player_position.y -= player_speed.y * elapsedTime * 2;

	if (Down_pressed && Run_pressed)
		player_position.y += player_speed.y * elapsedTime * 2;
	player_sprite.setPosition(player_position);
}







