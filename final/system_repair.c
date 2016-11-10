#include "headers/ftl.h"

static const t_repair_command	repair_command[] =
{
  {"ftl_drive", ftl_drive_system_repair},
  {"navigation_tools", navigation_tools_system_repair},
  {"weapon", weapon_system_repair},
  {NULL, NULL}
};

int ftl_drive_system_repair(t_ship* ship)
{
  my_printf(DRIVE_REPAIR);
  free(ship->drive->system_state);
  char* online;
  online = my_strdup("online");
  if (online != NULL)
  {
    my_printf(DRIVE_REPAIR_SUCCESS);
    ship->drive->system_state = online;
    return 1;
  }
  else
  {
    my_printf(DRIVE_REPAIR_FAIL);
    return 0;
  }
}

int navigation_tools_system_repair(t_ship* ship)
{
  my_printf(NAVIGATION_REPAIR);
  free(ship->navigation->system_state);
  char* online;
  online = my_strdup("online");
  if (online != NULL)
  {
    my_printf(NAVIGATION_REPAIR_SUCCESS);
    ship->navigation->system_state = online;
    return 1;
  }
  else
  {
    my_printf(NAVIGATION_REPAIR_FAIL);
    return 0;
  }
}

int weapon_system_repair(t_ship* ship)
{
  my_printf(WEAPON_REPAIR);
  free(ship->weapon->system_state);
  char* online;
  online = my_strdup("online");
  if (online != NULL)
  {
    my_printf(WEAPON_REPAIR_SUCCESS);
    ship->weapon->system_state = online;
    return 1;
  }
  else
  {
    my_printf(WEAPON_REPAIR_FAIL);
    return 0;
  }
}

int iterate_array(t_ship *ship, char *keyboard)
{
  int cpt;
  bool found;

  cpt = 0;
  found = false;

  while (repair_command[cpt].str != NULL)
  {
    if (my_strcmp(repair_command[cpt].str, keyboard) == 0)
    {
      found = true;
      repair_command[cpt].ptr(ship);
    }
    cpt++;
  }
  if (!found) {
    my_printf(READLINE_NOT_FOUND);
    return 0;
  }
  return 1;
}

int system_repair(t_ship* ship)
{
  my_printf("repair_system~>");
  char* keyboard;

  keyboard = readline();
  if (keyboard != NULL)
  {
    iterate_array(ship, keyboard);
  }
  else {
    my_printf(READLINE_FAIL);
    return 0;
  }
  return 1;
}
