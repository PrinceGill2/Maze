#include "Tile.h"
//Though this node technically has the ability to manage the 
//lifetime of a Tile* it shoudn't as the Tile* is present in the map which
//will handle the objects lifetime
struct Node {
    struct Tile* thing;
    struct Node* nextNode;
};

struct Node* createNode(struct Tile* thing);
