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
    unsigned short int knowledgeLvl; // choix : max à 10 
}Language;

typedef struct
{
    const char sName[100];
    Language language[4];
    unsigned short int languageArrayLength;
    unsigned short int year;
    PROJECT_STATUS status;
    const char sLienGitHub[200]; 

}Project;


void printLanguage(Language *temp);
void printProject(Project *temp);

#endif