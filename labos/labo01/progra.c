#include <stdio.h>
#include "progra.h"
#include "compat.h"

void printLanguage(Language *temp)
{
    printf_s("Langage : %s, niveau : %u/10\n\n", temp->sName,temp->knowledgeLvl);
}

void printProject(Project *temp)
{
    printf_s("Projet: %s\n", temp->sName);
    puts("Langage(s) utilisé(s):");
    for (unsigned short int i = 0; i < temp->languageArrayLength; i++)
    {
        printf_s("[%d] ", i+ 1);
        printf_s("%s\n", temp->language[i].sName);
    }

    printf_s("Année: %u\n", temp->year);
    printf_s("Statut: ");

    switch (temp->status)
    {
        case ACTIVE: 
            puts("en cours de développement");
            break;
        case FINISHED:
            puts("fini");
            break;
        case ABANDONED:
            puts("abandonné");
            break;
        default:
            puts("Erreur dans le status du projet");
            break;
    }
    if(temp->sLienGitHub[0] != '\0')
        printf_s("Lien: %s\n", temp->sLienGitHub);
    else
        puts("Pas sur GitHub");
}

