#pragma once
#include <stdbool.h> 

struct Wall { 
    int x;
    int y;
    int i;
    int j;
    
    bool checkedR;
    bool checkedD;
    bool right;
    bool down;

};

//establishes the x, y coordinates 
struct Wall* createWall(int x, int y, int i, int j);

//establishes if it exists and the directions
void establishWall(struct Wall* thing, bool right, bool down);

void establishWallR(struct Wall* thing, bool right);

void establishWallD(struct Wall* thing, bool down);

void destroyWall(struct Wall* thing);

