#include <stdio.h>
#include "Entity.h" 
#include "Obstacle.h"




void inicializarObstacle(Obstacle* o, int width, int height, int xpos, int ypos, int velx, int vely)
{
    inicializarEntity(&o->obstacle, width, height, xpos, ypos, velx, vely);
}


int mainO() {
    Obstacle o;
    //mostrarPersonaje(&p);
    inicializarPersonaje(&o, 30, 30, 20, 250, 0, 0);

    return 0;
}

