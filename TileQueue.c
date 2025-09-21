#include "TileQueue.h"

struct TileQueue* createQueue(){
    struct TileQueue* qThing = (struct TileQueue*)malloc(sizeof(struct TileQueue));
    if(qThing == NULL) {
        printf("null pointer\n");
        exit(EXIT_FAILURE);
    }
    qThing->head = NULL;
    qThing->rear = NULL;
    qThing->size = 0;
    return qThing;
}

bool enqueue(struct TileQueue* qThing, struct Tile* thing) {
    struct Node* tmp = createNode(thing);
    //redundancy
    if (tmp == NULL)
        return false;
    if(qThing->rear != NULL) {
    qThing->rear->nextNode = tmp;
    }
    qThing->rear = tmp; //just swapping ownership of pointers (right now shared)

    if(qThing->head == NULL) {
        qThing->head = tmp;
    }
    qThing->size++;
    return true;

}
//take off of the front, first in first out paradigm
struct Tile* dequeue(struct TileQueue* qThing) { 
    if(qThing->head == qThing->rear) {
       struct Tile* broke = NULL;
       printf("Queue Empty");
       return broke;     
    }
    //move the head down a level while making sure to 
    //free our previous head
    struct Node* tmp = qThing->head;
    struct Tile* tempTile = tmp->thing;

    qThing->head = qThing->head->nextNode;
    free(tmp);
    qThing->size--;
    return tempTile;
}

void deleteQueue(struct TileQueue* qThing) {
	if(qThing->head == NULL) {
	printf("Queue does not exist\n");
	exit(EXIT_FAILURE);
}
	while(qThing->head != qThing->rear) {
	struct Node* tmp = qThing->head;
	qThing->head = qThing->head->nextNode;
	free(tmp);
	}
	qThing->rear = NULL;
	free(qThing->head);
    free(qThing);
}

