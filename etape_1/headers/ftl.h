// multiple inclusion handling
#ifndef FTL_H
#define FTL_H

#include <stdlib.h>
//TODO: remove stdio.h
#include <stdio.h>
#include "../libs/libmy.h"
#include "../headers/strings.h"



// DRIVE STRUCTURE
typedef struct s_ftl_drive {
  char          *system_state;
  int           energy;
} t_ftl_drive;

// WEAPON STRUCTURE
typedef struct s_weapon {
  char          *system_state;
  int           damage;
} t_weapon;

//  NAVIGATION STRUCTURE
typedef struct s_navigation_tools {
  char          *system_state;
  int           sector;
  int           evade;
} t_navigation_tools;

// FREIGHT STRUCTURE
typedef struct s_freight t_freight;
struct s_freight {
  char          *item;
  t_freight     *prev;
  t_freight     *next;
};

// CONTAINER STRUCTURE
typedef struct s_container {
  int           nb_elem;
  t_freight     *first;
  t_freight     *last;
} t_container;

// SHIP STRUCTURE
typedef struct s_ship {
  int           hull;
  t_weapon      *weapon;
  t_ftl_drive   *drive;
  t_navigation_tools  *navigation;
  t_container         *container;
} t_ship;


char			*my_strdup(char *str);
int add_container_to_ship(t_ship *ship);
int add_navigation_tools_to_ship(t_ship *ship);
int add_weapon_to_ship(t_ship *ship);
int add_ftl_drive_to_ship(t_ship *ship);
int add_navigation_tools_to_ship(t_ship *ship);
void add_freight_to_container(t_ship *ship, t_freight *freight);
void del_freight_from_container(t_ship *ship, t_freight *freight);
#endif
