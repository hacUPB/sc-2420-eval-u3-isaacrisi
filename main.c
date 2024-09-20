#include <stdio.h>
#include "PERSONAJE.h"
#include "arma.h"

int main(void)
{
	Personaje* Paladin;
	Paladin = Personaje_crear("vengence", 8, 1);

	printf("el nombre del personaje %s\n", get_name(Paladin));

	Personaje_destruir(Paladin);

	Arma* florete;
	florete = Arma_crear("florete", 3, 5);

	printf("el arma es un %s\n", get_wepon(florete));

	Arma_destruir(florete);

	
}