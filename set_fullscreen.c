#include "includes.h"

void setFullscreen(bool fs, t_global *global)
{
  if (fs) {
    global->ecran = SDL_SetVideoMode(global->WIDTH, global->HEIGHT, 32, SDL_FULLSCREEN);
    global->IS_FULLSCREEN = true;
    global->ratio = 1;
    init(global);
  } else {
    global->ecran = SDL_SetVideoMode(global->SMALL_WIDTH, global->SMALL_HEIGHT, 32, 1);
    global->IS_FULLSCREEN = false;
    global->ratio = 0.5;
    init(global);
  }
}
