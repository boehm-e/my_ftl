#include "includes.h"

void prepare_ship(t_ship *ship)
{
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
}

void prepare_global(t_global *global)
{
  global->WIDTH = 1920;
  global->HEIGHT = 1080;
  global->SMALL_WIDTH = 960;
  global->SMALL_HEIGHT = 540;
  global->IS_FULLSCREEN = true;
  global->ratio = 0.5;
  global->move = 0;
  global->ecran = SDL_SetVideoMode(global->SMALL_WIDTH, global->SMALL_HEIGHT, 32, 1);
}

int main()
{
  t_ship *ship;
  t_global *global;

  srand(time(NULL));
  ship = malloc(sizeof(t_ship));
  global = malloc(sizeof(t_global));
  ship = create_ship();

  prepare_ship(ship);
  // my_printf("\n\n\n\nSECTOR : %i\n", ship->navigation->sector);
  prepare_global(global);


  init(global);
  launch_websocket(global, ship);
  // start_game(global, ship);
  SDL_Quit();

  return EXIT_SUCCESS;
}
