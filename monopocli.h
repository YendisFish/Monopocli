#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#ifndef PLAYER_H
#define PLAYER_H

struct Player{
    int Money;
    int Location;
};

#endif

#ifndef PROPERTY_H
#define PROPERTY_H

struct Property{
    char name[100];
    int cost;
    int rent;
    struct Player *owner;
};

#endif

#ifndef BOARD_H
#define BOARD_H

struct Board{
    struct Property *properties;
    int players;
    struct Player *playerlist;
};

#endif