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
    // free(container);
    my_putstr(ADD_CONTAINER_SUCCESS);
    return 1;
  } else {
    // free(container);
    my_putstr(ADD_CONTAINER_FAIL);
    return 0;
  }
}

void add_freight_to_container(t_ship *ship, t_freight *freight) {
  if (freight != NULL)
  {
    my_putstr("\n");
    freight->next = NULL;
    if (ship->container->last == NULL /*|| ship->container->nb_elem == 0*/)
    {
      my_putstr("PREV\n");
      freight->prev = NULL;
      ship->container->first = freight;
      ship->container->last = freight;
    }
    else
    {
      my_putstr("NEXT\n");
      // freight->next = ship->container->first;
      // freight->prev = NULL;
      // ship->container->first = freight;
      ship->container->last->next = freight;
      freight->prev = ship->container->last;
      ship->container->last = ship->container->last->next;
    }
    ship->container->nb_elem++;
  } else {
    my_putstr("INVALID FREIGHT\n");
  }
}

void del_freight_from_container(t_ship *ship, t_freight *freight) {
  if (freight != NULL) {
    printf("%p\n%p\n", ship->container->last, freight);
    if (ship->container->first == freight) {
      my_putstr("\n--FIRST\n");
      freight->next->prev = NULL;
    } else if (ship->container->last == freight){
      my_putstr("\n--LAST\n");
      freight->prev->next = NULL;
      ship->container->last = freight->prev;

    } else {
      my_putstr("\n--MIDDLE\n");
      freight->prev->next = freight->next;
      freight->next->prev = freight->prev;
    }
    ship->container->nb_elem--;
    free(freight);
  }
}
