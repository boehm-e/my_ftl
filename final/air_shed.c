// #include <string.h>
#include "headers/ftl.h"

int add_weapon_to_ship(t_ship* ship)
{
  my_printf(ADD_WEAPONS);
  char* online;
  online = my_strdup("online");
  t_weapon* weapon;
  if ((weapon = malloc(sizeof(t_weapon))) == NULL)
  return 0;
  weapon->damage = 10;
  if (online != NULL)
  weapon->system_state = online;
  else
  my_printf("ERROR\n");
  ship->weapon = weapon;
  if (weapon == ship->weapon)
  {
    my_printf(ADD_WEAPONS_SUCCESS);
    return 1;
  }
  else
  {
    my_printf(ADD_WEAPONS_FAIL);
    return 0;
  }
}

int add_ftl_drive_to_ship(t_ship* ship)
{
  my_printf(ADD_DRIVE);
  char* online;
  online = my_strdup("online");
  t_ftl_drive* drive;
  if ((drive = malloc(sizeof(t_ftl_drive))) == NULL)
  return 0;
  drive->energy = 10;
  if (online != NULL)
  drive->system_state = online;
  ship->drive = drive;
  if (drive == ship->drive)
  {
    my_printf(ADD_DRIVE_SUCCESS);
    return 1;
  }
  else
  {
    my_printf(ADD_DRIVE_FAIL);
    return 0;
  }
}

int add_navigation_tools_to_ship(t_ship* ship)
{
  my_printf(ADD_NAVIGATION);
  t_navigation_tools* navigation;
  if ((navigation = malloc(sizeof(t_navigation_tools))) == NULL)
  return 0;
  navigation->sector = 0;
  navigation->evade = 25;
  navigation->system_state = my_strdup("online");
  ship->navigation = navigation;
  ship->navigation->alive_ennemy = false;
  if (navigation == ship->navigation)
  {
    my_printf(ADD_NAVIGATION_SUCCESS);
    return 1;
  }
  else
  {
    return 0;
    my_printf(ADD_NAVIGATION_FAIL);
  }
}

int main()
{
  srand(time(NULL));
  my_printf(SHIP_BUILDING);
  t_ship* ship;
  ship = create_ship();
  my_printf(SHIP_WELDING_FINISH);
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);

  launch_game(ship);

  free(ship);
  return 0;
}
