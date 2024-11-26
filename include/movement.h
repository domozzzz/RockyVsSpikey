#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "game.h"

void get_movement(struct player *player, struct player *player2);
void handle_movement(struct player *player, struct screen* screen);
void handle_collisions(struct player *player,struct player *player2, struct screen* screen);
void clear_movement(struct player *player);

#endif