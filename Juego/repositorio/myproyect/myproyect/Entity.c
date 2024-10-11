#include <stdio.h>
#include "Entity.h" 


void inicializarEntity(Entity* e, int width, int height, int xpos, int ypos, int velx, int vely) {
    e->width = width;
    e->height = height;
    e->xpos = xpos;
    e->ypos = ypos;
    e->velx = velx;
    e->vely = vely;
}
/*
void mostrarEntity(const Entity* e) {
    printf("Entity - Width: %d, Height: %d, X: %d, Y: %d\n", e->width, e->height, e->xpos, e->ypos);
}
*/
