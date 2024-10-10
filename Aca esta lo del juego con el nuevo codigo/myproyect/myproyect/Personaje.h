#ifndef PERSONAJE_H
#define PERSONAJE_H
#define TRUE 1
#define FALSE 0

typedef struct {
    Entity personaje;
} Personaje;

void inicializarPersonaje(Personaje* p, int width, int height, int xpos, int ypos, int velx, int vely);

int mainP();

void jump(Personaje* p);


#endif