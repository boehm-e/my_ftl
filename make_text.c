#include "includes.h"

void make_text(int x, int y, char *text, t_global *global)
{
  SDL_Surface* surf = NULL;
  surf = TTF_RenderText_Solid (global->font, text, pickColor(4));
  display_text (x*global->ratio, y*global->ratio, global->font, surf, global->ecran);
}
