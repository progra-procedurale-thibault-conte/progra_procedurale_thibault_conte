#ifndef PROGRA_H
#define PROGRA_H

typedef enum : unsigned char
{
    ACTIVE = 0,
    FINISHED,
    ABANDONED
}PROJECT_STATUS;


typedef struct
{
    char sName[40];
    unsigned short int knownledgeLvl; // choix : max à 10 
}Language;

typedef struct
{
    char sName[100];
    Language language;
    unsigned short int year;
    PROJECT_STATUS status;  

}Project;


void printLanguage(Language *temp);
void printProject(Project *temp);

#endif