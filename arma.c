#include "arma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Arma* Arma_crear( const char* nombre, int damage, int alcance) {
    Arma* nueva_arma = (Arma*)malloc(sizeof(Arma));
    if (!nueva_arma) return NULL;
    //nuevo_personaje->nombre = strdup(nombre);
    strcpy_s(nueva_arma->nombre, 30, nombre);
    nueva_arma->damage = damage;
    nueva_arma->alcance = alcance;
    return nueva_arma;
}

void Arma_destruir(Arma* this) {
    if (this) {
        //free(this->nombre);
        free(this);
    }
}
char* get_wepon(Arma* this)
{
    return this->nombre;
}
void mostrar_info(char* nombre, int damage, int alcance)
{

}