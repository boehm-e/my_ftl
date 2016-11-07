// #ifndef
#include "headers/ftl.h"

t_ship *create_ship() {
  t_ship *ship = malloc(sizeof(t_ship));
  ship->hull = 50;
  if (ship) {
    return ship;
  }
  else {
    return NULL;
  }
}

int main(char *argc, char *argv) {
  t_ship *ship = create_ship();
  printf("%i", ship->hull);
  my_putstr("test");
  return 0;
}
