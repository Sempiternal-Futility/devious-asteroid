#ifndef SPRITES_H
#define SPRITES_H

void draw_player(short *posY, short *posX); // Draws the player
void erase_player(short *posY, short *posX); // Erases the player from the screen
void shoot(short *posY, short *posX, short *posYfoe, short *posXfoe, short *kills); // Draws the projectile
void draw_enemy(short *posYfoe, short *posXfoe); // Draws the enemy
void draw_enemy_randompos(short *posYfoe, short *posXfoe); // Draws the enemy at a random position
void erase_enemy(short *posYfoe, short *posXfoe); // Erases the enemy from the screen
void quit_message(); // Says something nice to the player before quitting :)
void update_killcount(short *kills); // Updates the kill count at the left-top corner of the screen

#endif