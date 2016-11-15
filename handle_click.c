#include "includes.h"

void handle_click(SDL_Event event, t_global *global, t_ship *ship, t_ennemy *ennemy)
{
  int width = global->WIDTH;
  float ratio = global->ratio;
  // SDL_Rect container = {global->WIDTH*global->ratio/2+5,  (260 + y)*global->ratio, global->WIDTH*global->ratio/4-15, 100*global->ratio};
  if (event.button.x >= ratio*width/2 && event.button.x <= ratio*(3*width/4)) {
    if (event.button.y >= ratio*250 && event.button.y<= ratio*250+75) {
      my_printf("JUMP\n");
      jump(ship, ennemy);
    }
    if (event.button.y >= ratio*250 + 75 && event.button.y<= ratio*250+155) {
      my_printf("DETECT\n");
      launch_detection(ship, ennemy);
    }
    if (event.button.y >= ratio*250 + 155 && event.button.y<= ratio*250+230) {
      my_printf("GET BONUS\n");
      get_bonus(ship, ennemy);
    }
    if (event.button.y >= ratio*250 + 230 && event.button.y<= ratio*250+290) {
      my_printf("ATTACK\n");
      attack(ship, ennemy);
    }
    if (event.button.y >= ratio*250 + 290 && event.button.y<= ratio*250+350) {
      my_printf("SYSTEM REPAIR\n");
      ftl_drive_system_repair(ship);
      navigation_tools_system_repair(ship);
      weapon_system_repair(ship);
    }
    ennemy_attack(ship, ennemy);
  }
}
