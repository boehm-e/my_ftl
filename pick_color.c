#include "includes.h"

SDL_Color pickColor(int color)
{
  SDL_Color c;
  switch (color) {
    case 1:
    c.r = 255;
    c.g = 0;
    c.b = 0;
    break;
    case 2:
    c.r = 255;
    c.g = 0;
    c.b = 0;
    break;
    case 3:
    c.r = 255;
    c.g = 0;
    c.b = 0;
    break;
    case 4:
    c.r = 255;
    c.g = 255;
    c.b = 255;
    break;
  }
  return c;
}
