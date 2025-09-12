#include "Mouse.h" 

struct Mouse* createMouse(int x, int y, int i, int j, int orientation) {
    struct Mouse* thing = (struct Mouse*)malloc(sizeof(struct Mouse));
    if(thing == NULL) {
    printf("null pointer\n");
    exit(EXIT_FAILURE);
    }

    thing-x = x;
    thing->y = y;
    thing->i = i;
    thing -> = j;
    thing->orientation = orientation;
    return thing;
}



void adjustLocation(struct Mouse* thing, int x, int y, int i, int j) {
    thing->x = x;
    thing->y = y;
    thing->i = i;
    thing->j = j;

}

void adjustDirection(struct Mouse* thing, int orientation) {
    thing->orientation = orientation;
}

void wrapOrientaion(struct* Mouse thing) {
    thing->orientation =% 360;
}

void moveForward(struct* Mouse thing){
    API_moveForward();
    if(thing->orientation = 0) {
        thing->y += 1;
        thing->i -= 1'
    }
    else if(thing->orientation = 90) {
        thing->x -= 1;
        thing->j -= 1;
    }
    else if(thing->orientation = 180) {
        thing->y -= 1;
        thing->i -= 1;
    }
    else if(thing->orientation = 270) {
        thing->x += 1;
        thing->j += 1;
    }
}

// +90 degrees
void turnLeft(struct* Mouse thing){
    API_turnLeft();
    thing->orientation += 90;
}

//-90 degrees
void turnRight(struct* Mouse thing){
    API_turnRight();
    thing->orientation += -90
}

//90 degrees
bool sensorLeft(){
    if(API_wallLeft()){
    return true;
    }
    return false;
}

//-90 degrees
bool sensorRight(){
    if(API_wallRight()){
    return true;
    }
    return false;
}


//0 degrees
bool sensorHead(){
    if(API_wallFront()){
    return true;
    }
    return false;
}

//detect and establish walls DET - N - EST - W
//will just check around the mouse and adjust the map as needed
void detnestW(struct Mouse* moThing, struct Map* mThing){
    //This section is for making walls true
    wrapOrientation(thing);
    if(sensorHead()) {
        int direction = orientation;
        putDownWall(mThing, moThing, direction, true);
    }
    if(sensorLeft()) {
        int direction = orientation + 90;
        putDownWall(mThing, moThing, direction, true);

    }
    if(sensorRight()) {
        int direction = orientation - 90;
        putDownWall(mThing, moThing, direction, true);
    }
    //this section for making walls false
    if(!(sensorHead())) {
        int direction = orientation;
        putDownWall(mThing, moThing, direction, false);
    }
    if(!(sensorLeft())) {
        int direction = orientation + 90;
        putDownWall(mThing, moThing, direction, false);
    }
    if(!(sensorRight())) {
        int direction = orientation - 90;
        putDownWall(mThing, moThing, direction, false);
    }
    
}

//this is ran once after the mouse arrives at a tile and after that tile has been checked for walls
struct MoveQueue* tilArMo(struct Mouse* moThing, struct Map* mThing, struct MoveQueue* moveTo){
    //array calculations 
    int i = moThing->i;
    int j = moThing->j;
    
    const double PI = 4.0 * atan(1.0);
    double angle = 0;
    for(int i = 0; i < 4 ;i++) {
        angle = i + (PI/2);
        double transJ = cos(angle);
        double transI = sin(angle);
        if(abs(transJ) == 1 || abs(transI) == 1) {
            if(angle == PI/2) {
                if(wallHereRIGHT(mThing, i, j)!) {
                      enqueue(moveTo->bQueue, mThing->tileMap[i + transI][j]);
               }
            }
            if(angle == PI) {
                if(wallHereDOWN(mThing, i, j)!) {
                      enqueue(moveTo->bQueue, mThing->tileMap[i][j + transJ]);
               }
            }
            if(angle == 3*(PI/2)) {
                if(wallHereRIGHT(mThing, i + transI, j)!) {
                      enqueue(moveTo->bQueue, mThing->tileMap[i + transI][j]);
               }
            }
            if(angle == PI*2) {
                if(wallHereDOWN(mThing, i, j + transJ)!) {
                      enqueue(moveTo->bQueue, mThing->tileMap[i][j + transJ]);
               }
            }
        }
    }
}




void destroyMouse(struct Mouse* thing); {
    free(thing);
}
