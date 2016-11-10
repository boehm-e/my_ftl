#include "headers/ftl.h"

int display_stats(t_ship *ship, t_ennemy *ennemy)
{
  ennemy = ennemy;
  my_printf("\n SHIP : \n");
  my_printf("    hull   : %i\n",ship->hull);
  my_printf("    damage : %i\n",ship->weapon->damage);
  my_printf("    energy : %i\n",ship->drive->energy);
  my_printf("    sector : %i\n",ship->navigation->sector);
  my_printf("    evade  : %i\n\n",ship->navigation->evade);
  return 0;
}
