#ifndef LVL_H
#define LVL_H
#define TRUE 1
#define FALSE 0

typedef struct {
    Entity lvl;
} Lvl;

void inicializarLvl(Lvl* l, int width, int height, int xpos, int ypos, int velx, int vely);

int mainL();

#endif
