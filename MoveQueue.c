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
	int lowestNode = mQ->bQueue->head
	struct Node* currentNode = mQ->bQueue->head;
	for(int i = 0; i < 4; i++) {
	if(lowestNode->thing->manhattanValue > currentNode->nextNode->thing->manhattanValue) {
		lowestVal = currentNode->nextNode;
		
		}
	currentNode = currentNode->nextNode;
	}
	return lowestNode;
}
