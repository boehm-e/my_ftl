#include "headers/ftl.h"

void init_ennemy(t_ennemy *ennemy) {
  ennemy->pv = calculate_ennemy_states(ennemy->lvl, 20);
  ennemy->damage = calculate_ennemy_states(ennemy->lvl, 10);
  ennemy->lvl++;
}

void ennemy_spawn(t_ship *ship, t_ennemy *ennemy)
{
  my_printf("\nUN ENNEMIE EST APPARUE !\n");
  init_ennemy(ennemy);
  ship->navigation->alive_ennemy = true;
}

int jump(t_ship *ship, t_ennemy *ennemy)
{
  int random = rand() % 100 + 1;

  if (ship->navigation->alive_ennemy == true)
  {
    my_printf("\nVOUS NE POUVEZ PAS JUMP SI DES ENNEMIES SONT EN VIE\n");
    return 0;
  }
  else if (navigation_tools_system_check(ship) != 1)
  {
    if (ship->navigation->sector < 10)
      return lose_game(ship, "Vous etes mort");
    else
      return win_game(ship, "VOUS AVEZ GAGNE\n");
  }
  else
  ship->navigation->sector += 1;

  if (random <= 30)
    ennemy_spawn(ship, ennemy);
  else
    my_printf("NO ENNMY FOUND\n");

  ship->can_detect = true;
  return 1;
}
