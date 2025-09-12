#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#
//we assign the next node in the actual queue
struct Node* createNode(struct Tile* thing) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("null pointer\n");
        exit(EXIT_FAILURE);    
    }
    newNode->thing = thing;
    newNode->nextNode = NULL;

    return newNode;
}
