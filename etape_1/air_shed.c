#include "headers/ftl.h"
#include <string.h>


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
  char *online;
  online = my_strdup("online");
  t_weapon *weapon;
  weapon = malloc(sizeof(t_weapon));
  weapon->damage = 10;
  if (online != NULL) {
    weapon->system_state = online;
  } else {
    my_putstr("ERROR\n");
  }
  ship->weapon = weapon;
  if (weapon == ship->weapon) {
    my_putstr(ADD_WEAPONS_SUCCESS);
    // free(weapon);
    return 1;
  } else {
    // free(weapon);
    my_putstr(ADD_WEAPONS_FAIL);
    return 0;
  }
}

int add_ftl_drive_to_ship(t_ship *ship) {
  my_putstr(ADD_DRIVE);
  char *online;
  online = my_strdup("online");
  t_ftl_drive *drive;
  drive = malloc(sizeof(t_ftl_drive));
  drive->energy = 10;
  if (online != NULL) {
    drive->system_state = online;
  } else {
    my_putstr("ERROR\n");
  }
  ship->drive = drive;
  if (drive == ship->drive) {
    // free(drive);
    my_putstr(ADD_DRIVE_SUCCESS);
    return 1;
  } else {
    // free(drive);
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
    // free(navigation);
    my_putstr(ADD_NAVIGATION_SUCCESS);
    return 1;
  } else {
    return 0;
    // free(navigation);
    my_putstr(ADD_NAVIGATION_FAIL);
  }
}

int main() {
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
  abc->item = "TEST123\n";
  abc->next = NULL;
  abc->prev = NULL;
  add_freight_to_container(ship, abc);
  // my_putstr(ship->container->first->item);
  // my_putstr(ship->container->last->item);

  t_freight *def;
  def = malloc(sizeof(t_freight));
  def->item = "TEST456\n";
  def->next = NULL;
  def->prev = NULL;
  add_freight_to_container(ship, def);
  // my_putstr(ship->container->first->item);
  // my_putstr(ship->container->last->item);

  t_freight *ghi;
  ghi = malloc(sizeof(t_freight));
  ghi->item = "TEST789\n";
  ghi->next = NULL;
  ghi->prev = NULL;
  add_freight_to_container(ship, ghi);


  get_bonus(ship);
  system_control(ship);
  ftl_drive_system_repair(ship);

  system_repair(ship);

  free(ship);
  return 0;
}
