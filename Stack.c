#include "Stack.h"



struct Stack* createStack() {
    struct Stack* thing = (struct Stack*)malloc(sizeof(struct Stack));
    if(thing == NULL) {
        printf("null pointer\n");
        exit(EXIT_FAILURE);
    }
    thing->head = NULL;
    thing->size = 0;
    return thing;
}
bool push(struct Stack* stThing, struct Tile* thing){
    struct Node* tmp = createNode(thing);
    if (tmp == NULL) {
    return false
    }
    if(stThing->head == NULL) {
    stThing->head = tmp'
    }
    else {
    tmp->nextNode = stThing->head;
    stThing->head = tmp;
    }
    stThing->size++;
    return true;
}

struct Tile* pop(struct Stack* stThing){
    if (stThing->head == NULL) {
        struct Tile* broke = NULL;
        printf("Stack Empty\n");
        return broke;
    }
    struct Node* tmp = stThing->head; 
    stThing->head = stThing->head->nextNode;
    struct Tile* tempTile = tmp->thing;
    free(tmp)
    stThing->size--;
    return tempTile;
}

bool isEmpty(struct Stack* stThing) {
    if(size > 0) {
    return false;
    }
    return true;
}

void deleteStack(struct Stack* stThing){
    if(stThing->NULL) {
    printf("Stack does not exist\n");
    exit(EXIT_FAILURE);
    }
    while(size > 1) {
    struct Node* tmp = stThing->head;
    stThing->head = stThing->head->nextNode;
    size--;
    }
    free(stThing->head);
    free(stThing);
}


