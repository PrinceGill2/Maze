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

int lowestManValWALL(struct MoveQueue* mQ. struct Mouse* mThing, struct Map* mapThing) {
	int lowestManVal = mQ->bQueue->head->thing->manhattanValue;
	for(int k = 0; k < 4; k++) {
	        angle = i * (PI/2);
        double transJ = cos(angle);
        double transI = sin(angle);
        if(abs(transJ) == 1 || abs(transI) == 1) {
            if(angle == PI/2) {
	    if(!(wallHereRIGHT(mapThing, i, j))) {
		if(mapThing->tileMap[i][j]->manhattanValue < lowestManVal) {
			lowestManVal = mapThing->tileMap[i][j]->manhattanValue;
			}
		}
            }
            if(angle == PI) {
	    if(!(wallHereDOWN(mapThing, i, j))) {
		if(mapThing->tileMap[i][j]->manhattanValue < lowestManVal) {
			lowestManVal = mapThing->tileMap[i][j]->manhattanValue;
			}
		}
            }
            if(angle == 3*(PI/2)) {
	    if(!(wallHereRIGHT(mapThing, i + 1, j))) {
		if(mapThing->tileMap[i][j]->manhattanValue < lowestManVal) {
			lowestManVal = mapThing->tileMap[i][j]->manhattanValue;
			}
		}
            }
            if(angle == 2*PI) {
	    if(!(wallHereDOWN(mapThing, i, j + 1))) {
		if(mapThing->tileMap[i][j]->manhattanValue < lowestManVal) {
			lowestManVal = mapThing->tileMap[i][j]->manhattanValue;
			}
		}
            }
         }
	}
    return lowestManVal;
}

void addToTheStack(struct MoveQueue* mQ. struct Stack* stThing){ 
    struct Node* currentNode = mQ->bQueue->head;
    for(int i = 0; i < 4; i++) {
        push(stThing, currentNode->thing);
        currentNode = currentNode->nextNode;
    } 
}

void destroyMQ(struct MoveQueue mQ){
    deleteQueue(mQ->bQueue);
    free(mQ);
}

