#ifndef MAGO_H
#define MAGO_H

#include "PERSONAJE.h"

typedef struct Mago {
    Personaje inicial;
    int mana;
} Mago;

Mago* Mago_crear(const char* nombre, int vida, int nivel, int fuerza);
void Mago_destruir(Mago* this);

#endif // GUERRERO_H

