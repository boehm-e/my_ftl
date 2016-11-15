#include "headers/ftl.h"

int	ennemy_attack(t_ship *ship, t_ennemy *ennemy)
{
  int	random = rand() % 100 + 1;

  if (ennemy!=NULL && ship->navigation->alive_ennemy == true)
    {
      if (random >= ship->navigation->evade)
	{
	  ship->hull -= ennemy->damage;
	  my_printf("VOUS PREDEZ %i POINTS DE VIE\n", ennemy->damage);
	  if (ship->hull <= 0)
	    lose_game(ship, "Un ennemie a eu raison de vous !\n");
	}
      else
	{
	  my_printf("L'ENNEMIE VOUS A RATE!\n");
	}
      if (random <= 20)
	ship_breakdown(ship);
    }
  return 0;
}
