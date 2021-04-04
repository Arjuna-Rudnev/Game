#include "wall.h"
#include "Engine.h"
#include <iostream>
#include <random> 
#include <ctime>

using namespace std;
Wall::Wall()
{
    wall_texture.loadFromFile("wall.jpg");
    wall_texture.setRepeated(true);
    std::mt19937 engine;
    engine.seed(time(0));
    uniform_int_distribution<> dist_angle(58, 60);
    uniform_int_distribution<> dist_radius(480, 540);
    center.x = VideoMode::getDesktopMode().width / 2;
    center.y = VideoMode::getDesktopMode().height / 2;
    wall_radius_angle[5] = 360;
    for (int i = 0; i < 5; ++i)
        wall_radius_angle[i] = dist_angle(engine);
    for (int i = 0; i < 5; ++i)
        wall_radius_angle[5] -= wall_radius_angle[i];
    for (int i = 0; i < 6; ++i)
        wall_radius[i] = dist_radius(engine);
    int sum_of_angles = 0;
    for (int i = 0; i < 6; ++i)
    {
        sum_of_angles += wall_radius_angle[i];
        wall_corner[i].x = center.x + wall_radius[i]*1.7*cos(sum_of_angles / 57.2);
        wall_corner[i].y = center.y + wall_radius[i] * sin(sum_of_angles * 57.2);
    }
    for (int i = 0; i <6; i++) 
    {
        wall_sprite[i].setPosition(wall_corner[i]);
        wall_sprite[i].scale(sf::Vector2f(0.1f, 0.1f)); // absolute scale factor
        if (i == 0)
            wall_sprite[i].setRotation(atan((wall_corner[5].y - wall_corner[0].y) / (wall_corner[5].x - wall_corner[0].x)) * 57.2);
            
        else
            wall_sprite[i].setRotation(atan((wall_corner[i].y - wall_corner[i + 1].y) / (wall_corner[i].x - wall_corner[i + 1].x))*57.2);
        wall_sprite[i].setTexture(wall_texture);
    }
    std::cout << "center" << " " << center.x << " " << center.y << std::endl;
    for (int i = 0; i < 6; i++)
    {
        if (i == 5)
            std::cout << " i = " << i << " wall_corner( " << wall_corner[i].x << ", " << wall_corner[i].y << " )" << " wall_radius_angle = " << wall_radius_angle[i] << " wall_radius = "<< wall_radius[i]<< " atan((wall_corner[5].y - wall_corner[0].y) / (wall_corner[5].x - wall_corner[0].x)) * 57.2 = "<<atan((wall_corner[5].y - wall_corner[0].y) / (wall_corner[5].x - wall_corner[0].x)) * 57.2 << std::endl;
    else
        std::cout << " i = " << i << " wall_corner( " << wall_corner[i].x << ", " << wall_corner[i].y << " )"<< "  wall_radius_angle =" << wall_radius_angle[i] << " wall_radius = " << wall_radius[i] << " atan((wall_corner[i].y - wall_corner[i+1].y) / (wall_corner[i].x - wall_corner[i+1].x))* 57.2 = " << atan((wall_corner[i].y - wall_corner[i+1].y) / (wall_corner[i].x - wall_corner[i+1].x)) * 57.2 << std::endl;
    }
  
}
Sprite Wall::getSprite(int i)
{
    std::cout << " return wall_sprite" << i << std::endl;
        return wall_sprite[i];
}