#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <stdbool.h>
#include <pthread.h>


void player_func(short *param[]); // Handles everything regarding the player


int main()
{
   setlocale(LC_ALL, "");
   initscr();
   noecho();
   curs_set(0);

   // These vars exists only because the pointers need to point to a variable
   short numY = LINES -4;
   short numX = 50;
   short numYfoe = LINES /4 -4;
   short numXfoe = 30;
   short numkill = 0;

   short *posY = &numY; // Position Y
   short *posX = &numX; // Position X
   short *posYfoe = &numYfoe; // Position Y of the asteroids
   short *posXfoe = &numXfoe; // Position X of the asteroids
   short *kills = &numkill; // Number of asteroids destroyed


   draw_player(posY, posX);
   draw_enemy_randompos(posYfoe, posXfoe);


   short *param[100]; // This array is used as an paramameter to create a thread
   param[0] = posY;
   param[1] = posX;
   param[2] = posYfoe;
   param[3] = posXfoe;
   param[4] = kills;

   pthread_t thread_one; // Creates the player thread
   pthread_create(&thread_one, NULL, &player_func, param);


   bool quit = false;
   short times_fell = 0; // Times an asteroid fell at the bottom of the screen
   while(quit == false  &&  times_fell < 3) // I don't know why, but "&&" works but "||" doesn't :/
   {
      fall_asteroid(posYfoe, posXfoe, posY);
      times_fell += detect_asteroid_bottom(posYfoe, posXfoe); // "detect_asteroid_bottom" returns 1 if an asteroid has fallen
      quit = detect_kill_asteroid(posX, posYfoe, posXfoe);
   }

   pthread_cancel(thread_one); 
   quit_message();
   endwin();

   return 0;
}


void player_func(short *param[])
{
   short numY = LINES -4;
   short numX = 50;
   short numYfoe = LINES /4 -4;
   short numXfoe = 30;
   short numkills = 0;

   short *posY = &numY;
   short *posX = &numX;
   short *posYfoe = &numYfoe;
   short *posXfoe = &numXfoe;
   short *kills = &numkills;

   posY = param[0];
   posX = param[1];
   posYfoe = param[2];
   posXfoe = param[3];
   kills = param[4];

   while(1 > 0)
   {
      update_killcount(kills);
      move_player(posY, posX, posYfoe, posXfoe, kills);
   }

}
