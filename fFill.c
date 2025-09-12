#include "fFill.h"

struct fFill* createFF() {
    struct fFill* fThing = (struct fFill*)malloc(sizeof(struct fFill));
    (fThing == NULL) {
        printf("null pointer\n");
        exit(EXIT_FAILURE);
    }
    fThing->theMap = createMap(); //creates tile and wall map
    fThing->theMouse = createMouse(0, 0, 15, 0, 0);
}

void performFF(struct fFIll* fThing, struct Mouse* moThing, struct Map* mThing) {
    
}

void destroyFF(struct fFILL* fThing){
    deleteMap(fThing->theMap);
    destroyMouse(fThing->theMOuse);
}
