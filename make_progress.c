#include "includes.h"

void make_progress(char *name, int percent_begin, int percent_end, int y, TTF_Font *font, t_global *global)
{
  int r=255;
  int g = 0;
  int b = 0;
  int col = 4;
  if (percent_begin > 100)
  percent_begin = 100;
  if (percent_begin <= 0)
  percent_begin = 3;
  if (percent_begin < 50 && percent_begin > 25)
  g = 141;
  else if(percent_begin <= 100 && percent_begin >= 50) {
    r = 0;
    g = 255;
  }
  if (my_strcmp(name, "CLEAR") == 0) {
    SDL_Rect container = {3*global->WIDTH*global->ratio/4+5,  (250 + y)*global->ratio, global->WIDTH*global->ratio/4-5, 100*global->ratio};
    SDL_FillRect(global->ecran, &container, SDL_MapRGB(global->ecran->format, 255, 255, 255));
  }
  else
  {
    SDL_Rect container = {3*global->WIDTH*global->ratio/4+5,  (250 + y)*global->ratio, global->WIDTH*global->ratio/4-5, 100*global->ratio};
    SDL_FillRect(global->ecran, &container, SDL_MapRGB(global->ecran->format, 0, 0, 0));

    SDL_Rect perct = {3*global->WIDTH*global->ratio/4+10,  (250 + y)*global->ratio+5, (global->WIDTH*global->ratio/4)*percent_begin/percent_end-15, 100*global->ratio-10};
    SDL_FillRect(global->ecran, &perct, SDL_MapRGB(global->ecran->format, r,g,b));

    SDL_Surface* text = NULL;
    text = TTF_RenderText_Solid (global->font, name, pickColor(4));
    display_text (3*global->WIDTH*global->ratio/4+15,  (250 + y)*global->ratio+10, global->font, text, global->ecran);
  }
}
