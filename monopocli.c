#include "monopocli.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Board createBoard();
void propConst(char *name, int cost, int rent, struct Property *location);
int GenRand();

int main() {
    struct Board board = createBoard();

    //Set RNG seed
    srand(time(NULL));
    fflush(stdout);

    while(1) {
        for(int i = 0; i < board.players; i++) {
            if(board.playerlist[i].Location == 0) {
                board.playerlist[i].Money = board.playerlist[i].Money + 200;
            }

            printf("It is your turn player ");
            printf("%d", i + 1);
            printf("... type ready and press enter to roll > ");

            char typed[5];
            scanf("%s", typed);

            int roll = GenRand();

            printf("You rolled \n%d\n", roll + board.playerlist[i].Location);

            if(roll + board.playerlist[i].Location > 8) {
                int over = (roll + board.playerlist[i].Location) - 8;
                board.playerlist[i].Location = 0 + over;

                if(board.properties[board.playerlist[i].Location].owner == NULL) {
                    fflush(stdout);

                    printf("Do you want to buy %s for %d > ", board.properties[board.playerlist[i].Location].name, board.properties[board.playerlist[i].Location].cost);

                    char dobuy[3];
                    scanf("%s", dobuy);

                    if(strcmp(dobuy, "yes") == 0) {
                        board.properties[board.playerlist[i].Location].owner = &board.playerlist[i];
                        board.playerlist[i].Money = board.playerlist[i].Money - board.properties[board.playerlist[i].Location].cost;

                        fflush(stdout);

                        printf("Your new balance: %d\n", board.playerlist[i].Money);
                    }
                } else {
                    fflush(stdout);
                    printf("This place is owned! You must pay %d\n", board.properties[board.playerlist[i].Location].rent);

                    board.properties[board.playerlist[i].Location].owner->Money = board.properties[board.playerlist[i].Location].owner->Money - board.properties[board.playerlist[i].Location].rent;

                    fflush(stdout);
                    printf("New Balance %d\n", board.playerlist[i].Money);
                }
            } else {
                board.playerlist[i].Location = board.playerlist[i].Location + roll;
                
                if(board.properties[board.playerlist[i].Location].owner == NULL) {
                    fflush(stdout);

                    printf("Do you want to buy %s for %d > ", board.properties[board.playerlist[i].Location].name, board.properties[board.playerlist[i].Location].cost);

                    char dobuy[3];
                    scanf("%s", dobuy);

                    if(strcmp(dobuy, "yes") == 0) {
                        board.properties[board.playerlist[i].Location].owner = &board.playerlist[i];
                        board.playerlist[i].Money = board.playerlist[i].Money - board.properties[board.playerlist[i].Location].cost;

                        fflush(stdout);

                        printf("Your new balance: %d\n", board.playerlist[i].Money);
                    }
                } else {
                    fflush(stdout);
                    printf("This place is owned! You must pay %d\n", board.properties[board.playerlist[i].Location].rent);

                    board.properties[board.playerlist[i].Location].owner->Money = board.properties[board.playerlist[i].Location].owner->Money - board.properties[board.playerlist[i].Location].rent;

                    fflush(stdout);
                    printf("New Balance %d\n", board.playerlist[i].Money);
                }
            }
        }
    }

    return 0;
}

int GenRand() {
    int dice1 = (rand() % 8);
    return dice1;
}

struct Board createBoard() {
    struct Board *board = malloc(sizeof(struct Board));

    printf("How many players will there be > ");
    scanf("%d", &board->players);

    //Player creation section
    struct Player *plrs = malloc(board->players * sizeof(struct Player));

    for(int i = 0; i < board->players; i++) {
        plrs[i].Money = 500;
        plrs[i].Location = 0;
    }

    board->playerlist = plrs;

    //Property initialization section
    struct Property *loc = malloc(8 * sizeof(struct Property));

    propConst("house 1", 100, 20, loc + 0);
    propConst("house 2", 150, 30, loc + 1);
    propConst("house 3", 200, 40,  loc + 2);
    propConst("house 4", 250, 50, loc + 3);
    propConst("house 5", 300, 60, loc + 4);
    propConst("house 6", 350, 70, loc + 5);
    propConst("house 7", 400, 80, loc + 6);
    propConst("house 8", 450, 90, loc + 7);

    board->properties = loc;

    return *board;
}

void propConst(char *name, int cost, int rent, struct Property *location) {
    strncat(location->name, name, 10);
    location->cost = cost;
    location->rent = rent;
    location->owner = NULL;
}