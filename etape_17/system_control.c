#include "headers/ftl.h"

void ftl_drive_system_check(t_ship* ship)
{
  my_putstr(DRIVE_CHECK);
  if (my_strcmp(ship->drive->system_state, "online") == 0)
  {
    my_putstr(DRIVE_ONLINE);
  }
  else
  {
    my_putstr(DRIVE_OFFLINE);
  }
}
void navigation_tools_system_check(t_ship* ship)
{
  my_putstr(NAVIGATION_CHECK);
  if (my_strcmp(ship->navigation->system_state, "online") == 0)
  {
    my_putstr(NAVIGATION_ONLINE);
  }
  else
  {
    my_putstr(NAVIGATION_OFFLINE);
  }
}

void weapon_system_check(t_ship* ship)
{
  my_putstr(WEAPON_CHECK);
  if (my_strcmp(ship->weapon->system_state, "online") == 0)
  {
    my_putstr(WEAPON_ONLINE);
  }
  else
  {
    my_putstr(WEAPON_OFFLINE);
  }
}

void system_control(t_ship* ship)
{
  ftl_drive_system_check(ship);
  navigation_tools_system_check(ship);
  weapon_system_check(ship);
}
