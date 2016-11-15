#include "headers/ftl.h"

char	*get_random_bonus()
{
  int	random;
  char	*bonus;

  random = rand() % 100 + 1;
  if (random >= 30)
    bonus = "scrap";
  else if (random < 10)
    bonus = "energy";
  else if (random < 20)
    bonus = "evadebonus";
  else
    bonus = "attackbonus";
  return bonus;
}
