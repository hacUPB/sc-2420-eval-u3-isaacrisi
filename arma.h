#ifndef ARMA_H
#define ARMA_H

typedef struct Arma {
    char nombre[30];
    int damage;
    int alcance;
} Arma;

Arma* Arma_crear( const char* nombre, int damage, int alcance);
void Arma_destruir(Arma* this);
static char* get_wepon(Arma* this);
void mostrar_info(char* nombre, int damage, int alcance);

#endif 