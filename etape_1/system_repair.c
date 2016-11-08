#include "headers/ftl.h"

static const t_repair_command	repair_command[] =
{
  {"ftl_drive", ftl_drive_system_repair},
  {"navigation_tools", navigation_tools_system_repair},
  {"weapon", weapon_system_repair},
  {NULL, NULL}
};


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

void system_repair(t_ship *ship) {
  my_putstr("repair_system~>\n");
  char *keyboard;
  int cpt;
  bool found;
  found = false;
  cpt = 0;
  keyboard = readline();
  if (keyboard != NULL) {
    while (repair_command[cpt].str != NULL) {
      if (my_strcmp(repair_command[cpt].str, keyboard) == 0) {
        found = true;
        repair_command[cpt].ptr(ship);
      }
      cpt++;
    }
    if (!found) {
      my_putstr(READLINE_NOT_FOUND);
    }
  } else {
    my_putstr(READLINE_FAIL);
  }
}
