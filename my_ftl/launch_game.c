#include "headers/ftl.h"

static const t_game_loop	game_command[] =
{
  {"jump", jump},
  {"attack", attack},
  {"detect", launch_detection},
  {"bonus", get_bonus},
  {"stats", display_stats},
  {NULL, NULL}
};

void				init_ennemy2(t_ennemy *ennemy)
{
  ennemy->pv = 20;
  ennemy->damage = 10;
  ennemy->lvl = 0;
}

void				handle_keyboard(t_ship *ship, t_ennemy *ennemy)
{
  int				cpt;
  bool				found;
  char*				keyboard;

  cpt = 0;
  found = false;
  my_printf("player@ftl ~ $ ");
  keyboard = readline();
  check_win(ship);
  if (keyboard != NULL)
  {
    while (game_command[cpt].str != NULL)
    {
      if (my_strcmp(game_command[cpt].str, keyboard) == 0)
      {
        found = true;
        game_command[cpt].ptr(ship, ennemy);
      }
      cpt++;
    }
    if (!found)
    my_printf(READLINE_NOT_FOUND);
    cpt = 0;
  }
}

int				launch_game(t_ship *ship)
{
  t_ennemy			*ennemy;
  if ((ennemy = malloc(sizeof(t_ennemy))) == NULL)
  return -1;

  init_ennemy2(ennemy);
  while (ship->alive == true)
  {
    handle_keyboard(ship, ennemy);
    ennemy_attack(ship, ennemy);
  }
  return 0;
}
