#include "includes.h"

void make_button(int y, char *name, t_global *global)
{
  SDL_Rect container = {global->WIDTH*global->ratio/2+5,  (260 + y)*global->ratio, global->WIDTH*global->ratio/4-15, 100*global->ratio};
  SDL_FillRect(global->ecran, &container, SDL_MapRGB(global->ecran->format, 2,136,209));
  make_text((int)(global->WIDTH/2 + 25), (280 + y), name, global);
}
