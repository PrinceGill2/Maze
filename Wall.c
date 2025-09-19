#include "Wall.h"
#include <stdio.h>
#include <stdlib.h>

//THough called wall this is more of a half block, it is composed of the top left most point
//and an infinitely thin wall originating from this point to the right and down.
struct Wall* createWall(int x, int y, int i, int j) {
    struct Wall* thing = (struct Wall*)malloc(sizeof(struct Wall));	
    if (thing == NULL) {
        printf("null pointer\n");
        exit(EXIT_FAILURE);

    }
    thing->x = x;
    thing->y = y;
    thing->i = i;
    thing->j = j;
    thing->checkedD = false;
    thing->checkedR = false;
    return thing;
}

void establishWall(struct Wall* thing, bool right, bool down) {
    thing->checkedR = true;
    thing->checkedD = true;
    thing->right = right;
    thing->down = down;

}

void establishWallR(struct Wall* thing, bool right){
    thing->right = right;
}

void establishWallD(struct Wall* thing, bool down){
    thing->down = down;
}

/*     struct someObject* thing = malloc(sizeof(struct someObject));
    if (thing == NULL) {
        printf("null pointer\n");
        exit(EXIT_FAILURE);
    }
    thing->x = x;
    thing->y = y;
    return thing;*/

void destroyWall(struct Wall* thing) { 
    free(thing);
}


