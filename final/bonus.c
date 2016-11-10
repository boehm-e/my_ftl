#include "headers/ftl.h"

void attackbonus(t_ship* ship)
{
  ship->weapon->damage += 5;
}

void evadebonus(t_ship* ship)
{
  ship->navigation->evade += 3;
}

void energy(t_ship* ship)
{
  ship->drive->energy += 1;
}

void scrap(t_ship* ship)
{
  ship = ship;
}
