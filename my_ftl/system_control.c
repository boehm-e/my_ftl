#include "headers/ftl.h"

int ftl_drive_system_check(t_ship* ship)
{
  my_printf(DRIVE_CHECK);
  if (my_strcmp(ship->drive->system_state, "online") == 0)
  {
    my_printf(DRIVE_ONLINE);
    return 1;
  }
  else
  {
    my_printf(DRIVE_OFFLINE);
    return 0;
  }
}

int navigation_tools_system_check(t_ship* ship)
{
  my_printf(NAVIGATION_CHECK);
  if (my_strcmp(ship->navigation->system_state, "online") == 0)
  {
    my_printf(NAVIGATION_ONLINE);
    return 1;
  }
  else
  {
    my_printf(NAVIGATION_OFFLINE);
    return 0;
  }
}

int weapon_system_check(t_ship* ship)
{
  my_printf(WEAPON_CHECK);
  if (my_strcmp(ship->weapon->system_state, "online") == 0)
  {
    my_printf(WEAPON_ONLINE);
    return 1;
  }
  else
  {
    my_printf(WEAPON_OFFLINE);
    return 0;
  }
}

void system_control(t_ship* ship)
{
  ftl_drive_system_check(ship);
  navigation_tools_system_check(ship);
  weapon_system_check(ship);
}
