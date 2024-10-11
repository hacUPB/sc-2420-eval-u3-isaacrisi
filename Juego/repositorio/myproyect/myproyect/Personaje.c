#include <stdio.h>
#include "Entity.h" 
#include "Personaje.h"

int isAlive = TRUE;
int isJumping = FALSE;
int jumpSpeed = -15;
int gravity;


typedef struct {
    Entity personaje;
} Personaje;




void inicializarPersonaje(Personaje* p, int width, int height, int xpos, int ypos, int velx, int vely) 
{
    inicializarEntity(&p->personaje, width, height, xpos, ypos, velx, vely);
}
/*
void mostrarPersonaje(const Personaje* p) {
    mostrarEntity(&p->personaje);
}
*/

int main() {
    Personaje p;
    inicializarPersonaje(&p, 30, 30, 20, 250, 0, 0);
    //mostrarPersonaje(&p);

    return 0;
}

void jump(Personaje* p) 
{
    if (!isJumping) { // Compara usando != o simplemente si es falso
        p->personaje.vely = jumpSpeed; // Cambia la velocidad en Y
        isJumping = TRUE; // Marca que ahora está saltando
    }
