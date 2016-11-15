#include "includes.h"

void init_progress(int val, t_global *global) {
}

int handle_events(SDL_Event event, t_global *global, int continuer, t_ship *ship, t_ennemy *ennemy)
{
  if (event.type == SDL_KEYDOWN)
  { // KEY DOWN
    switch(event.key.keysym.sym) {
      case 113: // q
      continuer = 0;
      break;
      case 27:
      setFullscreen(false, global);
      break;
      case 292:
      setFullscreen(true, global);
      break;
      default: // escape
      break;
    }
  } else if (event.type == SDL_MOUSEBUTTONUP) { // KEY UP
    handle_click(event, global, ship, ennemy);
    SDL_Flip(global->ecran);
    if (ship->hull <= 0)
    make_picture("assets/broken_screen.png", 0, 0, global);
  }
  return continuer;
}

void start_game(t_global *global, t_ship *ship, struct libwebsocket_context *context, t_ennemy *ennemy)
{
  int continuer = 1;
  SDL_Event event;
  time_t rawtime;
  int start_time =  time(&rawtime);
  int val;
  // t_ennemy			*ennemy;
  //
  // if ((ennemy = malloc(sizeof(t_ennemy))) == NULL)
  // return -1;

  init_ennemy2(ennemy);

  while (continuer) {
    time ( &rawtime );
    if (rawtime-start_time <= 3) {
      val = 3;
    } else {
      val = rawtime - start_time;
    }

    // LAUNCH WEBSOCKET
    libwebsocket_service(context, 5);

    make_progress("HULL", ship->hull, 50, 200, global->font, global);
    make_progress("PROGRESS", ship->navigation->sector, 10, 350, global->font, global);
    if (ship->navigation->alive_ennemy == true)
      make_progress("ENNEMY", ennemy->pv, calculate_ennemy_states(ennemy->lvl, 10) , 500, global->font, global);
    else
      make_progress("CLEAR", 0, calculate_ennemy_states(ennemy->lvl, 10) , 500, global->font, global);

    SDL_Flip(global->ecran);

    if (SDL_PollEvent(&event))
      continuer = handle_events(event, global, continuer, ship, ennemy);
  }
}
