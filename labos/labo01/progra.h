#ifndef PROGRA_H
#define PROGRA_H

// nouveaux types
typedef enum //: unsigned char
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

// statistiques

// niveau moyen de connaissance dans les technologies
float averageLvl(Language temp[], unsigned short int arrayLength);
float averageEndedProjects(Project temp[], unsigned short int arrayLength);
Language bestMasteredLanguage (Language temp[], unsigned short int arrayLength);

// Affichage
void printLanguage(Language *temp);
void printProject(Project *temp);


#endif