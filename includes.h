#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <libwebsockets.h>
#include "my_ftl/headers/ftl.h"

#define KGRN "\033[0;32;32m"
#define KCYN "\033[0;36m"
#define KRED "\033[0;32;31m"
#define KYEL "\033[1;33m"
#define KBLU "\033[0;32;34m"
#define KCYN_L "\033[1;36m"
#define KBRN "\033[0;33m"
#define RESET "\033[0m"


typedef int bool;
#define true 1
#define false 0

typedef struct s_global
{
  int WIDTH;
  int HEIGHT;
  int SMALL_WIDTH;
  int SMALL_HEIGHT;
  bool IS_FULLSCREEN;
  float ratio;
  int move;
  SDL_Rect ship_position;
  TTF_Font *font;
  SDL_Surface *ecran;
} t_global;

SDL_Color pickColor(int color);
void init();
void make_button(int y, char *name, t_global *global);
SDL_Color pickColor(int color);
void display_text (int x, int y, TTF_Font* font, SDL_Surface* text, SDL_Surface* destination);
void make_button(int y, char *name, t_global *global);
void make_text(int x, int y, char *text, t_global *global);
SDL_Rect make_picture(char *name, int x, int y, t_global *global);
void make_progress(char *name, int percent_begin, int percent_end, int y, TTF_Font *font, t_global *global);
void setFullscreen(bool fs, t_global *global);
void handle_click(SDL_Event event, t_global *global, t_ship *ship, t_ennemy *ennemy);
void start_game(t_global *global, t_ship *ship, struct libwebsocket_context *context, t_ennemy *ennemy);
int launch_websocket(t_global *global, t_ship *ship);
