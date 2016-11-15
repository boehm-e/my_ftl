#include "includes.h"
#include "my_ftl/headers/ftl.h"

void init(t_global *global) {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  global->font = TTF_OpenFont("fonts/Roboto-Bold.ttf", 50*global->ratio);
  SDL_WM_SetCaption("my_FTL", NULL);
  if (global->font == NULL) {
    printf("ISSUE LOADING FONT!\n\n");
  }

  // MAKE INTERFACE
  SDL_Rect body = {0,  250*global->ratio, global->WIDTH*global->ratio, (global->HEIGHT*global->ratio)-(250*global->ratio)};
  SDL_FillRect(global->ecran, &body, SDL_MapRGB(global->ecran->format, 255, 255, 255));
  SDL_Rect split = {global->WIDTH * global->ratio / 2 - 10*global->ratio,0, 10*global->ratio, global->HEIGHT * global->ratio};
  SDL_FillRect(global->ecran, &split, SDL_MapRGB(global->ecran->format, 240, 240, 240));
  SDL_Rect split2 = {3*global->WIDTH * global->ratio / 4 - 10*global->ratio,0, 10*global->ratio, global->HEIGHT * global->ratio};
  SDL_FillRect(global->ecran, &split2, SDL_MapRGB(global->ecran->format, 240, 240, 240));
  SDL_Rect head = {0,  0, global->WIDTH*global->ratio, 250*global->ratio};
  SDL_FillRect(global->ecran, &head, SDL_MapRGB(global->ecran->format, 62, 81, 181));
  // make_text(25,125,"SECTOR", global);
  make_text(20,100,"SECTOR :", global);
  make_picture("assets/ship_container.png", 0, 250 + ((global->HEIGHT-250-540)/2), global);
  make_button(0, "JUMP", global);
  make_button(150, "DETECT", global);
  make_button(300, "GET BONUS", global);
  make_button(450, "ATTACK", global);
  make_button(600, "REPAIR SYSTEM", global);
}
