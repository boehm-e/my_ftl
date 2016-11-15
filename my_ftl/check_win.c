#include "headers/ftl.h"

void check_win(t_ship *ship)
{
  if( ship->navigation->sector >= 10 )
  {
    ship->alive = false;
    win_game(ship, "YOU HAVE WIN\n\n");
  }
}
