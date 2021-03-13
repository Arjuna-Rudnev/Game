#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Player
{
private:
	

	Vector2f player_position;
	bool Left_pressed = false;
	bool Right_pressed = false;
	bool Up_pressed = false;
	bool Down_pressed = false;

public:
	Sprite player_sprite;
	Texture player_texture;
	Texture player_movement1_texture;
	Texture player_movement2_texture;
	Vector2f player_speed;
	Player();
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
	int stop();
	void update(float elapsedTime);
};