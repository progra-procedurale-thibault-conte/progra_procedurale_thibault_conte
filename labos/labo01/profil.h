#ifndef PROFIL_H
#define PROFIL_H

#include "progra.h"

// Mise en forme
void printBold(char *text);
void printUnderline(char *text);

// Getters
short int getUserChoice();

// Affichage
void printBeginStarsLine();
void printStarsLine();

void printBeginProg();
void printMainMenu();
void printProfile();
void printTechSkills(Language temp[], unsigned short int arrayLength);
printProjectsList(Project temp[],unsigned short int arrayLength );


#endif