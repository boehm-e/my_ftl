#include "includes.h"

void display_text (int x, int y, TTF_Font* font, SDL_Surface* text, SDL_Surface* destination)
{
  SDL_Rect offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface (text, NULL, destination, &offset);
}
