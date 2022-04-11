#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Running in home...\n");
    system("cd ~");

    printf("\nAttempt to delete old install... \n");
    system("rm -rf Monopocli");

    printf("\nCreating install file...\n");
    system("mkdir Monopocli");
    system("cd Monopocli");

    printf("\nGetting source from git...\n");
    system("git clone https://github.com/YendisFish/Monopocli .");

    printf("\nBuilding file\n");
    system("make run");

    return 0;
}