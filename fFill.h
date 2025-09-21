#pragma once
#include "Map.h"
#include "TileQueue.h"
#include "Node.h"
#include "MoveQueue.h"
#include "Mouse.h"
#include "Stack.h"
#include <math.h>

struct fFill {
    struct Map* theMap;
    struct Mouse* theMouse;
     
};

struct fFill* createFF();

void performFF(struct fFill* fThing, struct Mouse* moThing, struct Map* mThing);

void destroyFF(struct fFill* fThing);

//This will help which tile/cell to move to next

    



