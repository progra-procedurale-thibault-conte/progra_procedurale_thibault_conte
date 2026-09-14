#ifndef PROFIL_H
#define PROFIL_H

#include "progra.h"

// Mise en forme
void printBold(char *text);
void printUnderline(char *text);

// Getters
unsigned short int getUserChoice(unsigned short int maxValue);

// Affichage
void printBeginStarsLine();
void printStarsLine();

void printBeginProg();
void printMainMenu();
void printProfile();
void printTechSkills(Language temp[], unsigned short int arrayLength);
void printTechSkillsMinLvl(Language temp[], unsigned short int arrayLength, unsigned short int minSkillLvl);
void printProjectsList(Project temp[],unsigned short int arrayLength);

void printStat(Language allLang[], Project allProj[], unsigned short int nbOfLang, unsigned short int nbOfProj);


#endif