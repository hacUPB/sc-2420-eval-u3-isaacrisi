#include <stdio.h>
#include "Entity.h" 
#include "Personaje.h"
#include "Obstacle.h"




void inicializarPersonaje(Personaje* p, int width, int height, int xpos, int ypos, int velx, int vely)
{
    inicializarEntity(&p->super, width, height, xpos, ypos, velx, vely);
}
/*
void mostrarPersonaje(const Personaje* p) {
    mostrarEntity(&p->personaje);
}
*/

int CheckIfIsAlive(Obstacle *o, Personaje* p)
{
    if (o->obstacle.xpos == p->super.xpos)
    {
        p->isAlive = FALSE;
        return p->isAlive;
    }
    else
    {
        p->isAlive = TRUE;
        return p->isAlive;
    }
    if (o->obstacle.ypos == p->super.ypos)
    {
        p->isAlive = FALSE;
        return p->isAlive;
    }
    else
    {
        p->isAlive = TRUE;
        return p->isAlive;
    }
}

int mainP() {
    Personaje p;
    inicializarPersonaje(&p, 30, 30, 20, 250, 0, 0);
    //mostrarPersonaje(&p);

    return 0;
}

void jump(Personaje* p)
{
    if (!p->isJumping) { // Compara usando != o simplemente si es falso
        p->super.vely = p->jumpSpeed; // Cambia la velocidad en Y
        p->isJumping = TRUE; // Marca que ahora est� saltando
    }
}
