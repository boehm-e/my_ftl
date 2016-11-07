// multiple inclusion handling
#ifndef FTL_H
#define FTL_H

#include <stdlib.h>
//TODO: remove stdio.h
#include <stdio.h>
#include "../libs/libmy.h"
#include "../headers/strings.h"

char			*my_strdup(char *str);

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

// SHIP STRUCTURE
typedef struct s_ship {
  int           hull;
  t_weapon      *weapon;
  t_ftl_drive   *drive;
} t_ship;


#endif
