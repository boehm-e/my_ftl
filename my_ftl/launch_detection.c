#include "headers/ftl.h"

t_freight	*init_freight()
{
  t_freight	*freight;
  char		*bonus;

  bonus = get_random_bonus();
  my_printf(bonus);

  my_printf("\n BONUS FOUND : %s !\n", bonus);
  // if ((freight = malloc(sizeof(t_freight))) == NULL)
  //   return 0;
    freight = malloc(sizeof(*freight));
  freight->item = bonus;
  freight->next = NULL;
  freight->prev = NULL;
  return freight;
}

int		launch_detection(t_ship *ship, t_ennemy *ennemy)
{
  int            i;
  t_freight      *freight;

  ennemy = ennemy;
  if (ship->can_detect == true && navigation_tools_system_check(ship) == 1) {
    i = 0;
    while (i<10) {
      freight = init_freight();
      add_freight_to_container(ship, freight);
      i++;
    }
    my_printf("\n\n");
  }
  else if (navigation_tools_system_check(ship) != 1)
    {
      my_printf("NAVIGATION TOOLS OFFLINE !\n");
      if (ship->navigation->sector < 10)
        lose_game(ship,  "NAVIGATION SYSTEM DEAD && LVL < 100 :'( \n'");
      else
        win_game(ship, "VOUS AVEZ GAGNE\n");
    }
  else
    my_printf("DETECTION DEJA EFFECTUEE !\n");
  ship->can_detect = false;
  return 0;

}
