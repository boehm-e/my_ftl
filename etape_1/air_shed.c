#include "headers/ftl.h"

t_ship *create_ship() {
  t_ship *ship = malloc(sizeof(t_ship));
  ship->weapon = NULL;
  ship->drive = NULL;
  ship->navigation = NULL;
  ship->hull = 50;
  if (ship) {
    return ship;
  }
  else {
    return NULL;
  }
}

int add_weapon_to_ship(t_ship *ship) {
  my_putstr(ADD_WEAPONS);
  t_weapon *weapon;
  weapon = malloc(sizeof(t_weapon));
  weapon->damage = 10;
  weapon->system_state = my_strdup("online");
  ship->weapon = weapon;
  if (weapon == ship->weapon) {
    my_putstr(ADD_WEAPONS_SUCCESS);
    free(weapon);
    return 1;
  } else {
    free(weapon);
    my_putstr(ADD_WEAPONS_FAIL);
    return 0;
  }
}

int add_ftl_drive_to_ship(t_ship *ship) {
  my_putstr(ADD_DRIVE);
  t_ftl_drive *drive;
  drive = malloc(sizeof(t_ftl_drive));
  drive->energy = 10;
  drive->system_state = my_strdup("online");
  ship->drive = drive;
  if (drive == ship->drive) {
    free(drive);
    my_putstr(ADD_DRIVE_SUCCESS);
    return 1;
  } else {
    free(drive);
    my_putstr(ADD_DRIVE_FAIL);
    return 0;
  }
}

int add_navigation_tools_to_ship(t_ship *ship) {
  my_putstr(ADD_NAVIGATION);
  t_navigation_tools *navigation;
  navigation = malloc(sizeof(t_navigation_tools));
  navigation->sector = 0;
  navigation->evade = 25;
  navigation->system_state = my_strdup("online");
  ship->navigation = navigation;
  if (navigation == ship->navigation) {
    free(navigation);
    my_putstr(ADD_NAVIGATION_SUCCESS);
    return 1;
  } else {
    return 0;
    free(navigation);
    my_putstr(ADD_NAVIGATION_FAIL);
  }
}

int main(char *argc, char *argv) {
  my_putstr(SHIP_BUILDING);
  t_ship *ship;
  ship = create_ship();
  my_putstr(SHIP_WELDING_FINISH);
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);


  t_freight *abc;
  abc = malloc(sizeof(t_freight));
  abc->item = "TEST1\n";
  abc->next = NULL;
  abc->prev = NULL;
  add_freight_to_container(ship, abc);
  my_putstr(ship->container->first->item);
  my_putstr(ship->container->first->item);
  abc->item = "TEST22\n";
  my_putstr(ship->container->first->item);
  my_putstr(ship->container->first->item);
  del_freight_from_container(ship, abc);

  free(ship);
  return 0;
}
