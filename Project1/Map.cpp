#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include "Engine.h"
using namespace std;
void Map::read(std::string path_to_file)
{
    int i = 0;
    ifstream inFile;
    inFile.open(path_to_file);
    if(inFile)
    {
        cout << "File " << path_to_file << " opened\n";
        for (int j = 0; j < 10; j++)
        {
            for (int i = 0; i < 60; i++)
            {
                string number;
                getline(inFile, number, ',');
                if (i < 10 && j < 10)
                    tile_array[i][j].add_number(std::stoi(number));
            }
        }  
    }
    else
        cout << "File not opened\n";
    
    BaseChip_pipo.loadFromFile("[Base]BaseChip_pipo.png");
    WaterFall_pipo.loadFromFile("[A]WaterFall_pipo.png");
    Grass_pipo.loadFromFile("[A]Grass_pipo.png");
    Water_pipo.loadFromFile("[A]Water_pipo.png");
    Flower_pipo.loadFromFile("[A]Flower_pipo.png");
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
                        if (tile_array[i][j].sprite_number < 577 && tile_array[i][j].sprite_number > 0)
            {
                tile_array[i][j].sprite.setTexture(WaterFall_pipo);
                tile_array[i][j].sprite.setTextureRect(sf::IntRect((tile_array[i][j].sprite_number - 1) % 32 * 32,
                    (tile_array[i][j].sprite_number - 1) / 32 * 32, 32, 32));
                tile_array[i][j].sprite.setPosition(i * 32, j * 32);
            }
            else
                if (tile_array[i][j].sprite_number < 1641 && tile_array[i][j].sprite_number > 0)
                {
                    tile_array[i][j].sprite.setTexture(BaseChip_pipo);
                    tile_array[i][j].sprite.setTextureRect(sf::IntRect(
                        (tile_array[i][j].sprite_number - 577) % 8 * 32, (tile_array[i][j].sprite_number - 577) / 8 * 32, 32, 32));
                    tile_array[i][j].sprite.setPosition(i * 32, j * 32);
                }
                else if (tile_array[i][j].sprite_number < 2169 && tile_array[i][j].sprite_number > 0)
                {
                    tile_array[i][j].sprite.setTexture(Grass_pipo);
                    tile_array[i][j].sprite.setTextureRect(sf::IntRect(
                        (tile_array[i][j].sprite_number - 1641) % 8 * 32, (tile_array[i][j].sprite_number - 1641) / 8 * 32, 32, 32));
                    tile_array[i][j].sprite.setPosition(i * 32, j * 32);
                }
                else  if (tile_array[i][j].sprite_number < 5241 && tile_array[i][j].sprite_number > 0)
                {
                    tile_array[i][j].sprite.setTexture(Water_pipo);
                    tile_array[i][j].sprite.setTextureRect(sf::IntRect(
                        (tile_array[i][j].sprite_number - 2169) % 8 * 32, (tile_array[i][j].sprite_number - 2169) / 8 * 32, 32, 32));
                    tile_array[i][j].sprite.setPosition(i * 32, j * 32);
                }
                else if(tile_array[i][j].sprite_number > 0)
                {
                    tile_array[i][j].sprite.setTexture(Flower_pipo);
                    tile_array[i][j].sprite.setTextureRect(sf::IntRect((tile_array[i][j].sprite_number - 5241) % 8 * 32, (tile_array[i][j].sprite_number - 5241) / 8 * 32, 32, 32));
                    tile_array[i][j].sprite.setPosition(i * 32, j * 32);
                }
        }
    }
}

