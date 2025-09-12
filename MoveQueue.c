#include "MoveQueue.h"

struct MoveQueue* createMQ()  {
    struct MoveQueue* mQ = (struct MoveQueue*)malloc(sizeof(struct MoveQueue));
    if(mQ == NULL) {
        printf("null pointer\n");
        exit(EXIT_FAILURE);
    }
    mQ->bQueue = createQueue();

    return mQ;
}

struct Node* lowestManVal(struct MoveQueue* mQ) {
    bool lowest = false;
    int counter = 0;
    struct Node* bestTile = mQ->bQueue->head;
    while(!lowest) {
       if(bestTile->thing->manhattanValue > bestTile->nextNode->thing->manhattanValue) {
            bestTile = bestTile->nextNode;

       } 
       counter++
       if(counter == mQ->bQueue->size) {
            lowest = true;
       }

    
    }
    return bestTile;
}
