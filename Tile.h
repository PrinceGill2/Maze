#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//labeling of a wall is rea+ltive to starting location; 
//What ever direction the mouse is facing upon startup is considred the wall 
//to the "front" everything else follows and the direction of the mouse just has to be accounted for 
struct Tile {
    //x,y posiiton (for sim)
	int x; 
	int y;
    
    //actual array position
    int i; //y
    int j; //x

	int manhattanValue;

    char corner[3];

    bool visited;

};
//The location and manhattanValue 
struct Tile* createTile(int x, int y, int i, int j);

//Adjusts the manhatVal of a Tile, for readability
void adjustManhattanValue(struct Tile* thing, int manhatVal);

void deleteTile(struct Tile* thing);
