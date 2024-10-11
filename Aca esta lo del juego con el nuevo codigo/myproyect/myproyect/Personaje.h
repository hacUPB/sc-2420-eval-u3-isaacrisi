#ifndef PERSONAJE_H
#define PERSONAJE_H
#define TRUE 1
#define FALSE 0
#include "Entity.h"
#include "Obstacle.h"

typedef struct {
    Entity super;
    int isAlive ;
    int isJumping;
    int jumpSpeed;
    int gravity;
    Obstacle *o;
} Personaje;


void inicializarPersonaje(Personaje* p, int width, int height, int xpos, int ypos, int velx, int vely);

int mainP();

void jump(Personaje* p);

int CheckIfIsAlive(Obstacle* o, Personaje* p);

#endif