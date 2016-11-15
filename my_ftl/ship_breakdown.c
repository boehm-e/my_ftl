#include "headers/ftl.h"

int	ship_breakdown(t_ship *ship)
{
  int	random;
  char	*offline;

  random = rand() % 3;
  offline = my_strdup("offline");
  if (random == 0)
    {
      ship->weapon->system_state = offline;
      my_printf("WEAPONS DOWN!\n");
    }
  else if (random == 1)
    {
      ship->navigation->system_state = offline;
      my_printf("NAVIGATION DOWN!\n");
    }
  else
    {
      ship->drive->system_state = offline;
      my_printf("DRIVE DOWN!\n");
      lose_game(ship, "YOU LOSED BEAUCAUSE YOUR DRIVE IS DOWN\n");
    }
  return 0;
}
