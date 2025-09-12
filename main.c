
#include <stdio.h>

#include "API.h"
#include "Map.h"


void log(const char* text) {
    fprintf(stderr, "%s\n", text);
    fflush(stderr);
}

int main(int argc, char* argv[]) {
//now we're going to run the general "flow" I guess and print it all out and see how it works and looks
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
