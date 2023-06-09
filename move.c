// THIS SCRIPT HANDLES ALL MOVEMENT

#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <stdbool.h>


short detect_kill(short *posY, short *posX, short *posYfoe, short *posXfoe); // Detects if the projectile has hit the asteroid(returns 0 if so)
void move_player(short *posY, short *posX, short *posYfoe, short *posXfoe, short *kills); // Moves the player
void fall_asteroid(short *posYfoe, short *posXfoe); // Makes the asteroid fall down
bool detect_kill_asteroid(short *posX, short *posYfoe, short *posXfoe); // Detects if the asteroid hit the player
short detect_asteroid_bottom(short *posYfoe, short *posXfoe); // Detects if an asteroid fell at the bottom of the screen


void move_player(short *posY, short *posX, short *posYfoe, short *posXfoe, short *kills)
{
   char input = getch();


   if(input == 'd'  ||  input == 'l'  &&  *posX < COLS -4)
   {

      erase_player(posY, posX);
      *posX += 1;
      move(*posY, *posX);
      draw_player(posY, posX);
      
   }

   else if(input == 'a'  ||  input == 'h'  &&  *posX > 1)
   {
   
      erase_player(posY, posX);
      *posX -= 1;
      move(*posY, *posX);
      draw_player(posY, posX);
   
   }

   else if(input == 32)
      shoot(posY, posX, posYfoe, posXfoe, kills);

   else if(input == 'q')
   {
      clear();
      endwin();
      exit(0);
   }

}


short detect_kill(short *posY, short *posX, short *posYfoe, short *posXfoe)
{
   if(*posX == *posXfoe  ||  *posX == *posXfoe -1)
   {
      if(*posY == *posYfoe  ||  *posY == *posYfoe +1)
      {
         erase_enemy(posYfoe, posXfoe);
         return 0;
      }
   }

   else
      return 1;
}


void fall_asteroid(short *posYfoe, short *posXfoe)
{
   erase_enemy(posYfoe, posXfoe);
   *posYfoe += 1;
   draw_enemy(posYfoe, posXfoe);

   system("sleep 0.3s");
   refresh();
}


bool detect_kill_asteroid(short *posX, short *posYfoe, short *posXfoe)
{
      if(*posYfoe == LINES -4  &&  *posXfoe == *posX  ||  *posYfoe == LINES -4  &&  *posXfoe == *posX +1  ||  *posYfoe == LINES -4  &&  *posXfoe == *posX +2  ||  *posYfoe == LINES -4  &&  *posXfoe == *posX -1) // "LINES -4" is the player Y position
         return true;

      else
         return false;
}


short detect_asteroid_bottom(short *posYfoe, short *posXfoe)
{
   if(*posYfoe == LINES -1) // This is "LINES -1" instead of "LINES", because otherwise the asteroids wouldn't get erased from the screen
   {
      erase_enemy(posYfoe, posXfoe);
      draw_enemy_randompos(posYfoe, posXfoe);

      return 1;
   }

   else
      return 0;
}
