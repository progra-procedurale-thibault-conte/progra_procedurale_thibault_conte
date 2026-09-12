#include <stdio.h>
#include "progra.h"

void printLanguage(Language *temp)
{
    printf_s("Langage : %s\n", temp->sName);
    printf_s("Connaissance: %u/10\n\n", temp->knownledgeLvl);
}

void printProject(Project *temp)
{
    printf_s("Projet: %s\n", temp->sName);
    printf_s("Langage utilisé: %s\n", temp->language.sName);
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
}