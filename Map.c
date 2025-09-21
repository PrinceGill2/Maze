#include "Map.h"

struct Map* createMap() { 
    struct Map* thing = (struct Map*)malloc(sizeof(struct Map));
    if (thing == NULL) { 
        printf("null pointer\n");
        exit(EXIT_FAILURE);
    }

    int tempcent[4][2] = {{7,8},//0
                           {8,8},//1
                           {7,7},//2
                           {8,7}};//3  
    
   memcpy(thing->centralTiles, tempcent, sizeof(tempcent)); 
    //establishing the tile map
    //TILE MAP--TILE MAP--TILE MAP--TILE MAP--...
    int x = 0;
    int y = 15;
    //the "y-axis"
    for(int i = 0; i < 16; i++) {
        //the "x-axis"
        for(int j =0; j < 16; j++) {
            //I'm passing the array position for quick searching purposes and for nice and 
            //easy math
            thing->tileMap[i][j] = createTile(x, y, i, j); 
           //this line will determine which corner (closest center piece
           int quadrant = whichquadrant(x, y);
           int value = abs(thing->centralTiles[quadrant][0] - x) + abs(thing->centralTiles[quadrant][1] - y);
           /*this section is temporary for debuggin purposes
            if(quadrant == topLeft) {
           char tempStr[3] = "TL";
           memcpy(thing->tileMap[i][j]->corner, tempStr, sizeof(tempStr));
                   }
            else if(quadrant == topRight) {
           char tempStr[3] = "TR";
           memcpy(thing->tileMap[i][j]->corner, tempStr, sizeof(tempStr));
                   }
            else if(quadrant == bottomLeft) {
           char tempStr[3] = "BL";
           memcpy(thing->tileMap[i][j]->corner, tempStr, sizeof(tempStr));
                   }
            else if(quadrant == bottomRight) {
           char tempStr[3] = "BR";
           memcpy(thing->tileMap[i][j]->corner, tempStr, sizeof(tempStr));
                   }
           */
           adjustSingularManhatVal(thing, value, i, j);
          
           x++;
        }
        y--;
        x = 0;
    }

   //WALL MAP-- WALL MAP--WALL MAP--WALL MAP--WALL MAP--WALL MAP--WALL MAP
    x = 0;
    y = 16;
    //the "y-axis"
    for(int i = 0; i < 17; i++) {
        //the "x-axis"
        for(int j =0; j < 17; j++) {
            thing->wallMap[i][j] = createWall(x, y, i, j); 
            x++;
        }
        y--;
        x = 0;
    }


    return thing;
}
//Will go through our Map struct's arrays and deallocate the memory of all the tiles and walls
//created
void deleteMap(struct Map* thing) { 
        for(int i = 0; i < 16; i++) {
                for(int j =0; j < 16; j++) {
            deleteTile(thing->tileMap[i][j]);
                }  
    }
    for(int i = 0; i < 17; i++) {
        for(int j =0; j < 17; j++) {
           destroyWall(thing->wallMap[i][j]);
        }
    
    }
    free(thing);
}

void adjustSingularManhatVal(struct Map* thing, int val, int i, int j) { 
    thing->tileMap[i][j]->manhattanValue = val;
}

int whichquadrant(int x, int y){
    if(x < 8) { 
        if (y < 8) {
        return bottomLeft;
              }
        else {
        return topLeft;
        }
    }
    else { 
        if(y < 8) { 
        return bottomRight;
        }
        else {
       return topRight; 
        }
    }
}
/* int tempcent[4][2] = {{8,7},//0
                           {7,7},//1
                           {7,8},//2
                           {8,8}};//3
*/
void showMap(struct Map* thing) {
    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {
            //WIll print out every coordinate of every tile in the 
            //approximate position that the tile would me in 
            printf("[%d, %d]", thing->tileMap[i][j]->x, thing->tileMap[i][j]->y);
        }
       printf("\n");
    }
}

void showManValues(struct Map* thing)  {
    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {
            //will bring out the manhattan value of every tile in the position that the
            //tile would be.
            //this next line is for debugging purposes
           // printf("[%d, %s]", thing->tileMap[i][j]->manhattanValue, thing->tileMap[i][j]->corner); 
            printf("[%d]", thing->tileMap[i][j]->manhattanValue); 
        }
       printf("\n"); 
    }
}

bool wallHereRIGHT(struct Map* thing, int i, int j){
    if(thing->wallMap[i][j]->checkedR) {
            if(thing->wallMap[i][j]->right){
            return true;
            }
    }
    return false;
}

bool wallHereDOWN(struct Map* thing, int i, int j){
    if(thing->wallMap[i][j]->checkedD) {
            if(thing->wallMap[i][j]->down){
            return true;
            }
    }
    return false;
}
//The wall is less being "put" here more like we're putting down an indicator that the wall exists
//essentially just adding it to the wall map
void putWallHERER(struct Map* thing, int i, int j, bool right) {
    establishWallR(thing->wallMap[i][j], right);
}

void putWallHERED(struct Map* thing, int i, int j, bool down) {
    establishWallD(thing->wallMap[i][j], down);
}

void putDownWall(struct Map* thing, struct Mouse* mThing, int direction, bool ToF) {
    if(direction == 90) {
        putWallHERER(thing, mThing->i, mThing->j, ToF);
    }
    else if(direction == 180) {
        putWallHERED(thing, mThing->i, mThing->j, ToF);
    }
    //not on the same tile so array location is adjusted
    else if(direction == 270) {
        putWallHERER(thing, mThing->i, mThing->j, ToF);
    }
    else if(direction == 360 || direction == 0) {
        putWallHERED(thing, mThing->i, mThing->j, ToF);
    }
}
