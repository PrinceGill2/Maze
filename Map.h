#pragma once 
#include "Tile.h"
#include "Wall.h"
#include "Mouse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum corner { 
    topLeft = 0,
    topRight = 1,
    bottomLeft = 2,
    bottomRight = 3,
};

struct Map {
    //The 17th tile is for the walls, it is not an actual movable tile 
    struct Tile* tileMap[16][16];  
	struct Wall* wallMap[17][17];
    int centralTiles[4][2];
        

};
//Will use a for loop to go through the two maps to establish them
//creates a new and fresh map with no walls and basic tile values
struct Map* createMap();

void adjustSingularManhatVal(struct Map* thing, int val, int i, int j);

int whichquadrant(int x, int y);

void showMap(struct Map* thing);

void showManValues(struct Map* thing);

//this is dependent on what tile the mouse is at. it will know what tile it is at ((x,y) and (i,j)) and use
//that to determine wall location and whether it exists and if it doesnt how to approach that as well
bool wallHereRIGHT(struct Map* thing, int i, int j);

bool wallHereDOWN(struct Map* thing, int i, int j);

void putWallHERER(struct Map* thing, int i, int j, bool right);

void putWallHERED(struct Map* thing, int i, int j, bool down);

void putDownWall(struct Map* thing, struct Mouse* mThing, int direction, bool ToF);

void deleteMap(struct Map* thing);
