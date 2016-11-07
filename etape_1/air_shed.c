// #ifndef
#include "headers/ftl.h"

t_ship *create_ship() {
  t_ship *ship = malloc(sizeof(t_ship));
  ship->weapon = NULL;
  ship->drive = NULL;
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
    return 1;
  } else {
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
    my_putstr(ADD_DRIVE_SUCCESS);
    return 1;
  } else {
    my_putstr(ADD_DRIVE_FAIL);
    return 0;
  }
}

int main(char *argc, char *argv) {
  my_putstr(SHIP_BUILDING);
  t_ship *ship;
  ship = create_ship();
  my_putstr(SHIP_WELDING_FINISH);
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  return 0;
}
