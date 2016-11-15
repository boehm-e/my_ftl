#include "headers/ftl.h"

int lose_game(t_ship *ship, char *msg)
{
  ship->alive = false;
  my_printf(msg);
  return 0;
}
