#include <stdio.h>
#include <stdlib.h>
#include "API.h"
#include "Map.h"
#include "MoveQueue.h"
struct Mouse {
    int x;
    int y;
    int i;
    int j;

    int orientation;
}
//the x and y coordinates along with the array position
struct Mouse* createMouse(int x, int y, int i, int j, int orientation);

void adjustLocation(struct Mouse* thing, int x, int y, int i, int j);

void adjustDirection(struct Mouse* thing, int orientation);

void wrapOrientation(struct* Mouse thing);

void moveForward(struct* Mouse thing);

// +90 degrees
void turnLeft(struct* Mouse thing);

//-90 degrees
void turnRight(struct* Mouse thing);

//90 degrees
bool sensorLeft();

//-90 degrees
bool sensorRight();


//0 degrees
bool sensorHead();

//detect and establish walls DET - N - EST - W
void detnestW(struct Mouse* thing);

void destroyMouse(struct Mouse* thing);

void tilArMo(struct Mouse* moThing, struct Map* mThing, struct MoveQueue* moveTo);
