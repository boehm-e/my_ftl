#include "headers/ftl.h"

int	 calculate_ennemy_states(int lvl, int begin)
{
  int	i;

  i = 0;
  while (i<lvl) {
    begin = begin + begin/2;
    i++;
  }
  return begin;
}
