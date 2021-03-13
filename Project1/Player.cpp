#include "Player.h"
#include "Engine.h"
#include <iostream>
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

int Player::stop()
{
	if (Player::Left_pressed == false && Player::Right_pressed == false && Player::Up_pressed == false && Player::Down_pressed == false)
		return 1;
	else
		return 0;
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

	player_sprite.setPosition(player_position);
}







