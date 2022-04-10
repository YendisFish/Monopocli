#ifndef MONOPOCLI_H
#define MONOPOCLI_H

struct Player{
    int Money;
    int Location;
};

struct Board{
    struct Property *properties;
    int players;
    struct Player *playerlist;
};

struct Property{
    char name[100];
    int cost;
    int rent;
    struct Player *owner;
};

#endif