#include "Mago.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void mostrar_estado_impl(const Personaje* this) {
    Mago* mago = (Mago*)this;
    printf("Guerrero: %s | Vida: %d | Nivel: %d | Fuerza: %d\\n", this->nombre, this->vida, this->nivel, mago->mana);
}

Mago* Mago_crear(const char* nombre, int vida, int nivel, int mana) {
    Mago* nuevo_mago = (Mago*)malloc(sizeof(Mago));
    if (!nuevo_mago) return NULL;
    //nuevo_guerrero->base.nombre = strdup(nombre);
    strcpy_s(nuevo_mago->inicial.nombre, 30, nombre);
    nuevo_mago->inicial.vida = vida;
    nuevo_mago->inicial.nivel = nivel;
    nuevo_mago->mana = mana;
    nuevo_mago->inicial.mostrar_estado = mostrar_estado_impl;
    return nuevo_mago;
}

void Mago_destruir(Mago* this) {
    if (this) {
        //free(this->base.nombre);
        free(this);
    }
}



