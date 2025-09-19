
#include <stdio.h>

#include "API.h"
#include "Map.h"


void log(const char* text) {
    fprintf(stderr, "%s\n", text);
    fflush(stderr);
}

int main(int argc, char* argv[]) {
//now we're going to run the general "flow" I guess and print it all out and see how it works and looks
//
//We will first create the mouse and insert the starting position as the bottom left corner with an orientation of 90
//Then we will call detnestW to detect and establish the surroudning walls 
//then we use the tilArMO to get a move queue established. 
//then we determine the best node out of the movequeue and orient the mouse to travel to the tile
//we now travel to the new tile. 
//we now repeat this process
//
//At some point we will stop being able to progress due to a mixture of walls in the way and manhattan tiles that are
//not optimal (I need to establish a check for if there IS a lowest man val so in a false situation I can have a 
//initiation process for fFill to begin)
//
//NOw that ffill has started the method will just run on it's own (internal while loop) 

    struct Map* thing = createMap();
    
    showMap(thing);

    showManValues(thing);

    deleteMap(thing);
}

/*    log("Running...");
    API_setColor(0, 0, 'G');
    API_setText(0, 0, "abc");
    while (1) {
        if (!API_wallLeft()) {
            API_turnLeft();
        }
        while (API_wallFront()) {
            API_turnRight();
        }
        API_moveForward();
    }
}*/
