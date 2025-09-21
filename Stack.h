#pragma once
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
struct Stack {
    struct Node* head;

    int size;
};

struct Stack* createStack();

bool push(struct Stack* stThing, struct Tile* thing);

struct Tile* pop(struct Stack* stThing);

bool isEmpty(struct Stack* stThing);

void deleteStack(struct Stack* stThing);


