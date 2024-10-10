#include <stdio.h>
#include "Entity.h" 
#include "Personaje.h"
#include "lvl.h"

Personaje p;
int lvlLenght = 800;



void inicializarLvl(Lvl* l, int width, int height, int xpos, int ypos, int velx, int vely)
{
    inicializarEntity(&l->lvl, width, height, xpos, ypos, velx, vely);
}


int mainL() {
    Personaje p;
    Lvl l;
    inicializarPersonaje(&p, 30, 30, 20, 250, 0, 0);
    inicializarLvl(&l, lvlLenght, 300, 0, 300, 0, 0);
    //mostrarPersonaje(&p);

    return 0;
}

