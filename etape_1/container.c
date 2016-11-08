#include "headers/ftl.h"
typedef int bool;
#define true 1
#define false 0


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
    freight->next = NULL;
    if (ship->container->last == NULL /*|| ship->container->nb_elem == 0*/)
    {
      freight->prev = NULL;
      ship->container->first = freight;
      ship->container->last = freight;
    }
    else
    {
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
    if (ship->container->first == freight && ship->container->last == freight) {
      ship->container->first = NULL;
      ship->container->last = NULL;
    } else if (ship->container->first == freight) {
      freight->next->prev = NULL;
      ship->container->first = freight->next;
    } else if (ship->container->last == freight){
      freight->prev->next = NULL;
      ship->container->last = freight->prev;
    } else {
      freight->prev->next = freight->next;
      freight->next->prev = freight->prev;
    }
    ship->container->nb_elem--;
    free(freight);
  }
}

void attackbonus(t_ship *ship) {
  ship->weapon->damage += 5;
}

void evadebonus(t_ship *ship) {
  ship->navigation->evade += 3;
}

void energy(t_ship *ship) {
  ship->drive->energy += 1;
}

void scrap(t_ship *ship) {
  ship = ship;
  my_putstr("just do nothing!\n");
}



t_launch_ptr t_launch_cmd[] = {
  {"attackbonus", attackbonus},
  {"evadebonus", evadebonus},
  {"energy", energy},
  {"scrap", scrap},
  {NULL, NULL}
};


void get_bonus(t_ship *ship) {
  my_putstr("get_bonus\n\n\n");
  int cpt;
  t_freight *start;

  start = ship->container->first;
  while(start != NULL) {
    cpt = 0;
    my_putstr("start->item\n");
    while (t_launch_cmd[cpt].str != NULL) {
      if (my_strcmp(t_launch_cmd[cpt].str, start->item) == 0) {
        t_launch_cmd[cpt].ptr(ship);
      }
      cpt++;
    }
    del_freight_from_container(ship, start);
    my_putstr("here\n");
    start = ship->container->first;
  }
  my_putstr("\nNOMBRE : ");
  my_put_nbr(ship->container->nb_elem);
  my_putstr("\n\n");
  // del_freight_from_container(ship, start->prev);
}
