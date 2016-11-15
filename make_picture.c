#include "includes.h"

SDL_Rect make_picture(char *name, int x, int y, t_global *global)
{
  SDL_Surface *img;
  img = IMG_Load(name);
  img = rotozoomSurfaceXY(img, 0, global->ratio, global->ratio,1);


  SDL_Rect position;
  if (x >= 0 && y >= 0) {
    position.x = x*global->ratio;
    position.y = y*global->ratio;
  }
  SDL_BlitSurface(img, NULL, global->ecran, &position);
  return position;
}
