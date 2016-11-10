#ifndef                 _FTL_H_
# define                _FTL_H_

#include <stdlib.h>
#include <time.h> // FOR
#include "../headers/strings.h"
#include "../my_printf/lib_printf.h"

typedef                 int bool;
#define                 true 1
#define                 false 0

typedef struct          s_ftl_drive
{
    char*               system_state;
    int                 energy;
} t_ftl_drive;

typedef struct          s_weapon
{
    char*               system_state;
    int                 damage;
} t_weapon;

typedef struct s_navigation_tools
{
    char*               system_state;
    int                 sector;
    int                 evade;
    bool                alive_ennemy;
} t_navigation_tools;

typedef struct s_freight t_freight;

struct                  s_freight
{
    char*               item;
    t_freight*          prev;
    t_freight*          next;
};

typedef struct          s_container
{
    int                 nb_elem;
    t_freight*          first;
    t_freight*          last;
} t_container;

typedef struct          s_ship
{
    int                 hull;
    bool                alive;
    bool                can_detect;
    t_weapon*           weapon;
    t_ftl_drive*        drive;
    t_navigation_tools* navigation;
    t_container*        container;
} t_ship;

typedef struct          s_launch
{
    char*               str;
    void                (*ptr)(t_ship* s);
} t_launch_ptr;

typedef struct          s_repair_command
{
    char*               str;
    int                 (*ptr)(t_ship* s);
} t_repair_command;

typedef struct          s_ennemy
{
  int                   pv;
  int                   damage;
  int                   lvl;
} t_ennemy;

typedef struct s_game_loop
{
    char*               str;
    int                 (*ptr)(t_ship* s, t_ennemy *ennemy);
} t_game_loop;

char* my_strdup(char* str);
int add_container_to_ship(t_ship* ship);
int add_navigation_tools_to_ship(t_ship* ship);
int add_weapon_to_ship(t_ship* ship);
int add_ftl_drive_to_ship(t_ship* ship);
int add_navigation_tools_to_ship(t_ship* ship);
void add_freight_to_container(t_ship* ship, t_freight* freight);
void del_freight_from_container(t_ship* ship, t_freight* freight);
int get_bonus(t_ship* ship, t_ennemy *ennemy);
int ftl_drive_system_check(t_ship* ship);
int navigation_tools_system_check(t_ship* ship);
int weapon_system_check(t_ship* ship);
void system_control(t_ship* ship);
int ftl_drive_system_repair(t_ship* ship);
int navigation_tools_system_repair(t_ship* ship);
int weapon_system_repair(t_ship* ship);
char* readline(void);
int system_repair(t_ship* ship);
int			my_strcmp(const char *s1, const char *s2);
t_ship* create_ship();
int lose_game(t_ship *ship, char *msg);
int win_game(t_ship *ship, char *msg);
int display_stats(t_ship *ship, t_ennemy *ennemy);
int calculate_ennemy_states(int lvl, int begin);
char *get_random_bonus();
int launch_detection(t_ship *ship, t_ennemy *ennemy);
int attack(t_ship *ship, t_ennemy *ennemy);
int ship_breakdown(t_ship *ship);
int ennemy_attack(t_ship *ship, t_ennemy *ennemy);
int jump(t_ship *ship, t_ennemy *ennemy);
void check_win(t_ship *ship);
int launch_game(t_ship *ship);
void attackbonus(t_ship* ship);
void evadebonus(t_ship* ship);
void energy(t_ship* ship);
void scrap(t_ship* ship);

#endif                   /* !_FTL_H_ */
