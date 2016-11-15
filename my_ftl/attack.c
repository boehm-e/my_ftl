#include "headers/ftl.h"

void		check_ennemy_hp(t_ship *ship, t_ennemy *ennemy)
{
  int		random;

  random = rand() % 100 + 1;
  if (ennemy->pv <=0)
    {
      ship->navigation->alive_ennemy = false;
      my_printf("VOUS AVEZ VAINCU VOTRE ENNEMIE!\n");
      if (ship->navigation->sector >= 10)
	{
	  win_game(ship, "VOUS AVEZ GAGNE\n");
	}
      if (random < 50)
	{
	  my_printf("VOUS PERDEZ 1 POINT D'ENERGIE !\n");
	  ship->drive->energy -= 1;
	}
    }
  else
    {
      my_printf("ENNEMY HP : %i\n", ennemy->pv);
    }
}

int attack(t_ship *ship, t_ennemy *ennemy)
{
  if (ennemy != NULL &&
      ship->navigation->alive_ennemy == true &&
      weapon_system_check(ship) == 1)
    {
      ennemy->pv -= ship->weapon->damage;
      check_ennemy_hp(ship, ennemy);
      return 1;
    }
  else if (weapon_system_check(ship) == 0)
    return lose_game(ship, "Vous mourrez car WEAPONS est down !\n");
  else {
    my_printf("pas d'ennemie\n");
    return 0;
  }
}
