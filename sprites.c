// THIS SCRIPT DRAWS THE SPRITES

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <stdbool.h>


void draw_player(short *posY, short *posX); // Draws the player
void erase_player(short *posY, short *posX); // Erases the player from the screen
void shoot(short *posY, short *posX, short *posYfoe, short *posXfoe, short *kills); // Draws the projectile
void draw_enemy(short *posYfoe, short *posXfoe); // Draws the enemy
void draw_enemy_randompos(short *posYfoe, short *posXfoe); // Draws the enemy at a random position
void erase_enemy(short *posYfoe, short *posXfoe); // Erases the enemy from the screen
void quit_message(); // Says something nice to the player before quitting :)
void update_killcount(short *kills); // Updates the kill count at the left-top corner of the screen


void draw_player(short *posY, short *posX)
{
   move(*posY, *posX);

   printw("\u2587"); 
   printw("\u2587"); 
   printw("\u2587");

   move(*posY -1, *posX +1);
   printw("\u2584");
}


void erase_player(short *posY, short *posX)
{
   move(*posY, *posX);
   printw("   "); 

   move(*posY -1, *posX);
   printw("   ");
}


void shoot(short *posY, short *posX, short *posYfoe, short *posXfoe, short *kills)
{
   // Check if these 2 lines of code has any purpose at all lol
   //move(*posY -1, *posX +1);
   //printw(" ");

   bool enemy_killed = false;
   for(short i = 0; i < LINES -4; i++)
   {
      move(*posY -i, *posX +1);
      printw("\u2584");

      refresh(); 
      system("sleep 0.02s");
      
      move(*posY -i, *posX +1);
      printw(" "); // Erases


      if(i == 0) // Fixes bug that the whole player sprite gets erased when shooting
         draw_player(posY, posX);

      *posY = *posY -i; // This is here so that the function "detect_kill" gets the shooting position, instead of the player one
      if(detect_kill(posY, posX, posYfoe, posXfoe) == 0) // "detect_kill" returns 0 if an enemy is killed
      {
         i = LINES; // Breaks the loop
         enemy_killed = true;
      }

      *posY = LINES -4; // After passing the value to the function, the value returns to normal
   }

   if(enemy_killed == true)
   {
      *kills += 1;
      draw_enemy_randompos(posYfoe, posXfoe);
   }
}


void draw_enemy(short *posYfoe, short *posXfoe)
{
   move(*posYfoe, *posXfoe);
   printw("\u2588"); printw("\u2588");
}


void draw_enemy_randompos(short *posYfoe, short *posXfoe)
{
   srand(time(0));
   *posXfoe = rand() % COLS -5 + 1;
   *posYfoe = rand() % LINES /4 + LINES - LINES + 6;
   
   draw_enemy(posYfoe, posXfoe);
}


void erase_enemy(short *posYfoe, short *posXfoe)
{
   move(*posYfoe, *posXfoe);
   printw("   ");

   move(*posYfoe +1, *posXfoe);
   printw("   ");
}


void update_killcount(short *kills)
{
   move(1, 1);
   printw("    "); // Erases the previous kill count

   move(1, 1);
   printw("%d", *kills); // Prints the kill count to the screen

   refresh();
}


void quit_message()
{
   clear();

   move(LINES /2 -6, COLS /2 -22);
   printw("████████      ████      ████  ████   █████ ");

   move(LINES /2 -5, COLS /2 -22);
   printw("██    ██     ██  ██     ██  ██  ██   ██    ");

   move(LINES /2 -4, COLS /2 -22);
   printw("██          ████████    ██  ██  ██   █████ ");

   move(LINES /2 -3, COLS /2 -22);
   printw("██   ███   ██      ██   ██  ██  ██   ██    ");

   move(LINES /2 -2, COLS /2 -22);
   printw("████████   ██      ██   ██  ██  ██   █████ ");

   move(LINES /2 -1, COLS /2 -22);
   printw("");

   move(LINES /2, COLS /2 -22);
   printw("");

   move(LINES /2 +1, COLS /2 -22);
   printw("████████   ██     ██   █████   ██████    ██");

   move(LINES /2 +2, COLS /2 -22);
   printw("██    ██    ██   ██    ██      ██  ██    ██");

   move(LINES /2 +3, COLS /2 -22);
   printw("██    ██     ██ ██     █████   ████      ██");

   move(LINES /2 +4, COLS /2 -22);
   printw("██    ██     ██ ██     ██      ██  ██      ");

   move(LINES /2 +5, COLS /2 -22);
   printw("████████      ███      █████   ██   ██   ██");

   getch();
}
