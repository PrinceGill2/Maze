#include "fFill.h"

struct fFill* createFF() {
    struct fFill* fThing = (struct fFill*)malloc(sizeof(struct fFill));
    if (fThing == NULL) {
        printf("null pointer\n");
        exit(EXIT_FAILURE);
    }
    fThing->theMap = createMap(); //creates tile and wall map
    fThing->theMouse = createMouse(0, 0, 15, 0, 0);
}

void performFF(struct fFIll* fThing, struct Mouse* moThing, struct Map* mThing) {
   struct Stack* stThing = createStack();
   int i = moThing->i;
   int j = moThing->j;
   push(stThing, mThing->tileMap[i][j]);
   while(!isEmpty(stThing)) {
   struct Tile* check = pop(stThing);
   //we first check to see if we can increase the manhattan value we will check accounting for walls
 struct MoveQueue* MQ = createMQ();
   const double PI = 4.0 * atan(1.0);
    double angle = 0;
    for(int i = 0; i < 4 ;i++) {
        angle = i * (PI/2);
        double transJ = cos(angle);
        double transI = sin(angle);
        if(abs(transJ) == 1 || abs(transI) == 1) {
            if(angle == PI/2) {
            enqueue(MQ->bQueue, mThing->tileMap[i][j]);
            }
            if(angle == PI) {
            enqueue(MQ->bQueue, mThing->tileMap[i][j]);
            }
            if(angle == 3*(PI/2)) {
            enqueue(MQ->bQueue, mThing->tileMap[i][j]);
            }
            if(angle == 2*PI) {
            enqueue(MQ->bQueue, mThing->tileMap[i][j]);
            }
         }
    }
    //Check to see if the current cell's distance is less than the surrounding 
    //we can update it if that is the case essentially elevating the cell 
    //making it possible for the "water" to travel to the other cells
    if(check->manhattanValue - 1 < lowestManVal(MQ)->thing->manhattanValue) {
      check->manhattanValue = lowestManValWALL(MQ, moThing, mThing) + 1;
      addToTheStack(MQ, stThing);
    }
  
   //iff we can then we will do so and add the surrounding tiles (wall or not) to the stack
   
   //if we cannot then we move on to the next tile
   //
   //MAKE SURE TO DELETE THE MOVEQUEUE BETWEEN ITERATIONS
   }
}

void destroyFF(struct fFILL* fThing){
    deleteMap(fThing->theMap);
    destroyMouse(fThing->theMouse);
    free(fThing);
}
