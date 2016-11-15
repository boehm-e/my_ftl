#include "headers/ftl.h"

void		init_ship(t_ship *ship)
{
  ship->weapon = NULL;
  ship->drive = NULL;
  ship->navigation = NULL;
  ship->hull = 50;
  ship->alive = true;
  ship->can_detect = true;
}

t_ship*		create_ship()
{
  t_ship	*ship;
  if ((ship = malloc(sizeof(t_ship))) == NULL)
  {
    return NULL;
  }

  init_ship(ship);
  if (ship)
  {
    return ship;
  }
  else
  {
    return NULL;
  }
}
