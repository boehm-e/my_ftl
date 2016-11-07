#include "headers/ftl.h"

int add_container_to_ship(t_ship *ship) {
  my_putstr(ADD_CONTAINER);
  t_container *container;
  container = malloc(sizeof(t_container));
  container->first = NULL;
  container->last = NULL;
  container->nb_elem = 0;
  ship->container = container;

  if (container == ship->container) {
    free(container);
    my_putstr(ADD_CONTAINER_SUCCESS);
    return 1;
  } else {
    free(container);
    my_putstr(ADD_CONTAINER_FAIL);
    return 0;
  }
}
