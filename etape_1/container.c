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

void add_freight_to_container(t_ship *ship, t_freight *freight) {
  if (freight != NULL) {
    freight->next = NULL;
    if (ship->container->last == NULL /*|| ship->container->nb_elem == 0*/) {
      freight->prev = NULL;
      ship->container->first = freight;
      ship->container->last = freight;
    } else {
      ship->container->last->next = freight;
      freight->prev = ship->container->last;
      ship->container->last = freight;
    }
    ship->container->nb_elem++;
  } else {
    my_putstr("INVALID FREIGHT\n");
  }
}

void del_freight_from_container(t_ship *ship, t_freight *freight) {
  if (freight != NULL) {
    if (ship->container->first == freight) {
      freight->next->prev = NULL;
    } else if (ship->container->last == freight){
      freight->prev->next = NULL;
    } else {
      freight->prev->next = freight->next;
    }
    free(freight);
  }
}

void get_bonus(t_ship *ship) {
}
