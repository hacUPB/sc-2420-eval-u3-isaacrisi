#include <stdio.h>
#include <SDL.h>
#include "Constants.h"
#include "Entity.h"
#include "Personaje.h"
#include "lvl.h"
#include "Obstacle.h"


SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int game_is_running = NULL;

int last_frame_time = 0;

int velx = VELOCIDADX;
int vely = VELOCIDADY;
r = 0;
g = 100;
b = 200;
int is_jumping = 0;  // 0 si no est� saltando, 1 si est� saltando
int jump_speed = -15; // Velocidad inicial del salto (negativa para saltar hacia arriba)
int gravity = 30;     // Aceleraci�n que simula la gravedad


Personaje p; // Declaración del personaje
Lvl l; 
Obstacle o;






int initialize_window(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error initializing SDL \n");
		return FALSE;

	}
	window = SDL_CreateWindow(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_BORDERLESS
	);
	if (!window)
	{
		fprintf(stderr, "Error creating SDL window \n");
		return FALSE;

	}

	renderer = SDL_CreateRenderer(
		window,
		-1,
		0
	);

	if (!renderer)
	{
		fprintf(stderr, "Error creating renderer \n");
		return FALSE;

	}

	return TRUE;
}



void process_input()
{
	
	SDL_Event event;
	SDL_PollEvent(&event);



	switch (event.type)
	{
	case SDL_QUIT:
		game_is_running = FALSE;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE)
		{
			game_is_running = FALSE;
		}
		else if (event.key.keysym.sym == SDLK_w)
		{
			jump(&p);
			printf("Personaje saltando\n");
		}
		break;


	default:
		break;
	}
}
void setup()
{
	p.isAlive = TRUE;

}
void update()
{

	int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

	if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
	{
		SDL_Delay(time_to_wait);
	}

	float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;

	last_frame_time = SDL_GetTicks();
	p.super.xpos += p.super.velx * delta_time;
	p.super.ypos += p.super.vely * delta_time;
	//rect.width += 1;
	//rect.height += 1;
	l.lvl.xpos += l.lvl.velx * delta_time;
	l.lvl.ypos += l.lvl.vely * delta_time;


	float second_half_x = l.lvl.xpos + l.lvl.width / 2;
	o.obstacle.xpos = second_half_x + (l.lvl.width / 4) - o.obstacle.width / 2;  // Centrado en la mitad de la segunda mitad
	o.obstacle.ypos = l.lvl.ypos;


	//colision con las paredes
	/*if (rect.x >= WINDOW_WIDTH)
	{
		rect.velx = -rect.velx;
	}
	if (rect.y >= WINDOW_HEIGHT)
	{
		rect.vely = -rect.vely;
	}
	if (rect.x < 0)
	{
		rect.velx = VELOCIDADX;
	}
	if (rect.y < 0)
	{
		rect.vely = VELOCIDADY;

	}*/

	if (l.lvl.ypos >= WINDOW_HEIGHT)
	{
		l.lvl.vely = -l.lvl.vely;
	}
	if (l.lvl.xpos < -800)
	{
		l.lvl.xpos = 0;
	}
	if (l.lvl.ypos < 0)
	{
		l.lvl.vely = VELOCIDADY;

	}


	//ciclo de colores
	r++;
	g++;
	b++;
	//colisiones entre figurar
	if (p.super.ypos == 300)
	{
		p.super.vely = 0;
	}
	// Verificar colisi�n entre el cuadrado (rect) y el suelo (rect2)
	if (p.super.ypos + p.super.height >= l.lvl.ypos &&       // El borde inferior del cuadrado toca el borde superior del suelo
		p.super.xpos + p.super.width >= l.lvl.xpos &&        // El borde derecho del cuadrado est� dentro del suelo
		p.super.xpos <= l.lvl.xpos + l.lvl.width) {       // El borde izquierdo del cuadrado est� dentro del suelo
		p.super.ypos = l.lvl.ypos - p.super.height;          // Ajusta la posici�n del cuadrado para que no atraviese el suelo
		p.super.vely = 0;                           // Detiene el movimiento vertical (ca�da) del cuadrado
	}

	CheckIfIsAlive(&o, &p);

	if (p.isAlive == FALSE)
	{
		game_is_running = FALSE;
	}

}
void render()
{

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_Rect ball_rect = {
		(int)p.super.xpos,
		(int)p.super.ypos,
		(int)p.super.width,
		(int)p.super.height
	};
	SDL_Rect ball_rect2 = {
		(int)l.lvl.xpos,
		(int)l.lvl.ypos,
		(int)l.lvl.width,
		(int)l.lvl.height
	};
	SDL_Rect ball_rect3 = {
		(int)o.obstacle.xpos,
		(int)o.obstacle.ypos,
		(int)o.obstacle.width,
		(int)o.obstacle.height
	};

	// Dibuja el rect�ngulo
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &ball_rect);

	SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
	SDL_RenderFillRect(renderer, &ball_rect2);

	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &ball_rect3);


	SDL_RenderPresent(renderer);
}
void destroy_window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


int main(int argc, char* args[])
{

	game_is_running = initialize_window();

	setup();

	while (game_is_running)
	{
		process_input();
		update();
		render();
	}

	destroy_window();

	return 0;
}