#ifndef OBSTACLE_H
#define OBSTACLE_H

typedef struct {
  Entity obstacle;
} Obstacle;

void inicializarObstacle(Obstacle* o, int width, int height, int xpos, int ypos, int velx, int vely);

int mainO();

#endif
