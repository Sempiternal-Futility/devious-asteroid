#ifndef MOVE_H
#define MOVE_H

short detect_kill(short *posY, short *posX, short *posYfoe, short *posXfoe); // Detects if the projectile has hit the asteroid(returns 0 if so)
void move_player(short *posY, short *posX, short *posYfoe, short *posXfoe, short *kills); // Moves the player
void fall_asteroid(short *posYfoe, short *posXfoe); // Makes the asteroid fall down
bool detect_kill_asteroid(short *posX, short *posYfoe, short *posXfoe); // Detects if the asteroid hit the player
short detect_asteroid_bottom(short *posYfoe, short *posXfoe); // Detects if an asteroid fell at the bottom of the screen

#endif
