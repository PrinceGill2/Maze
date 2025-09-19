#include "TileQueue.h"
#include <stdbool.h>
//this is for specifically choosing the next location (tile) in the moveable vicinity to locate to
//I'll need to destroy it (the queue) and create a new queue with each movement 
struct MoveQueue {
    struct TileQueue* bQueue;

};
//Will look through the queue for the tile with the lowest man value 
//to determine the next location to travel to.

struct MoveQueue* createMQ();

struct Node* lowestManVal(struct MoveQueue* mQ);


int lowestManValWALL(struct MoveQueue* mQ, struct Mouse* mThing, struct Map* mapThing);

//Combs through the move queue to add to the stack, this is for the sake of simplicity.
void addToTheStack(struct MoveQueue* mQ. struct Stack* stThing);

void destroyMQ(struct MoveQueue mQ);
