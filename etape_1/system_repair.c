#include "headers/ftl.h"

void ftl_drive_system_repair(t_ship *ship) {
  my_putstr(DRIVE_REPAIR);
  free(ship->drive->system_state);
  char *online;
  online = my_strdup("online");
  if (online != NULL) {
    my_putstr(DRIVE_REPAIR_SUCCESS);
    ship->drive->system_state = online;
  } else {
    my_putstr(DRIVE_REPAIR_FAIL);
  }
}

void navigation_tools_system_repair(t_ship *ship) {
  my_putstr(NAVIGATION_REPAIR);
  free(ship->navigation->system_state);
  char *online;
  online = my_strdup("online");
  if (online != NULL) {
    my_putstr(NAVIGATION_REPAIR_SUCCESS);
    ship->navigation->system_state = online;
  } else {
    my_putstr(NAVIGATION_REPAIR_FAIL);
  }
}

void weapon_system_repair(t_ship *ship) {
  my_putstr(WEAPON_REPAIR);
  free(ship->weapon->system_state);
  char *online;
  online = my_strdup("online");
  if (online != NULL) {
    my_putstr(WEAPON_REPAIR_SUCCESS);
    ship->weapon->system_state = online;
  } else {
    my_putstr(WEAPON_REPAIR_FAIL);
  }
}
