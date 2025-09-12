#include "Node.h"
#include "Tile.h"
#include <stdio.h>
#include <stdlib.h>

//This implementation of queue will have to be done with pointers 
//instead of an array as the objects that will populate will be user
//defined and not primitive

struct TileQueue {
   struct Node* head;
   struct Node* rear; 
   int size;
};

struct TileQueue* createQueue();

//add a new node to the end
bool enqueue(struct TileQueue* qThing, struct Tile* thing);

//pop a node off the front
struct Tile* dequeue();

void deleteQueue(struct TileQueue* QThing);
