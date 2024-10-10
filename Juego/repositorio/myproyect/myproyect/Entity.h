#ifndef ENTITY_H
#define ENTITY_H


typedef struct {
    int width;
    int height;
    int xpos;
    int ypos;
    int velx;
    int vely;
} Entity;

void inicializarEntity(Entity* e, int width, int height, int xpos, int ypos, int velx, int vely);
//void mostrarEntity(const Entity* e);

#endif // ENTITY_H
