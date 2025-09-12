#include "Tile.h"
struct Tile* createTile(int x, int y, int i, int j) { 
    struct Tile* thing = (struct Tile*)malloc(sizeof(struct Tile));
    if(thing == NULL) {
    printf("null pointer\n");
    exit(EXIT_FAILURE);

    }
    thing->x = x;
    thing->y = y;
    //Array positio
    thing->i = i;
    thing->j = j;
    return thing;
}

void adjustManhattanValue(struct Tile* thing, int manhatVal) { 
    thing->manhattanValue = manhatVal;
}

void deleteTile(struct Tile* thing){
    free(thing);
}

//drmemory.exe -- c:/path/to/my/app
