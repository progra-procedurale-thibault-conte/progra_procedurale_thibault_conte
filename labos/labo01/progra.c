#include <stdio.h>
#include <string.h>

#include "progra.h"
#include "compat.h"
#include "profil.h"


// fcts statistiques

float averageLvl(Language temp[], unsigned short int arrayLength)
{
    if (temp == NULL || arrayLength == 0)
    {
        fprintf(stderr, "Erreur: tableau NULL ou taille de 0 dans averageLvl\n");
        return 0.0f;
    }

    float averageLvl = 0.0f;

    for (unsigned short int i = 0; i < arrayLength; i++)
        averageLvl += temp[i].knowledgeLvl;

    return averageLvl / (float) arrayLength;
}

float averageEndedProjects(Project temp[], unsigned short int arrayLength)
{
    if (temp == NULL || arrayLength == 0)
    {
        fprintf(stderr, "Erreur: tableau NULL ou taille de 0 dans averageEndedProjects\n");
        return 0.0f;
    }

    float averageEndProj = 0.0f;

    for (unsigned short int i = 0; i < arrayLength; i++)
    {
        if (temp[i].status == FINISHED)
            averageEndProj++; 
    }

    return averageEndProj / (float) arrayLength;
}
// d'après l'IA retourner une struct en dessous de 64 octets à du sens
// contrairement à la struct project où un pointeur output serait plus efficient
Language bestMasteredLanguage (Language temp[], unsigned short int arrayLength)
{
    if (temp == NULL || arrayLength == 0)
    {
        fprintf(stderr, "Erreur: tableau NULL ou taille de 0 dans bestMasteredLanguage\n");
        return (Language){0};
    }

    Language result = {0};
    unsigned short int bestIndex = 0;

    // quel index correspond au meilleur score de connaissance
    for (unsigned short int i = 1; i < arrayLength; i++)
    {
        if(temp[i].knowledgeLvl > temp[bestIndex].knowledgeLvl)            
                bestIndex = i;            
    }

    // creation de la structure à retourner avec les para
    snprintf(result.sName, sizeof(result.sName), "%s", temp[bestIndex].sName);
    result.knowledgeLvl = temp[bestIndex].knowledgeLvl;

    return result;
}

// Affichage
void printLanguage(Language *temp)
{
    if (temp == NULL)
    {
        fprintf(stderr, "Erreur: pointeur NULL dans printLanguage\n");
        return;
    }

    printf_s("Langage : %s, niveau : %u/10\n\n", temp->sName,temp->knowledgeLvl);
}

void printProject(Project *temp)
{
    if (temp == NULL)
    {
        fprintf(stderr, "Erreur: pointeur NULL dans printProject\n");
        return;
    }

    char nameTemp[100];

    //strcpy(nameTemp, temp->sName);
    // snprintf plus secure que strcpy car pas de dépassement de mémoire, troncature auto si dépassement
    // max taille sizeof - 1 
    if ((snprintf(nameTemp, sizeof(nameTemp), "%s", temp->sName)) >= sizeof(nameTemp))
    {
        fprintf(stderr, "Erreur dans snprintf lors de la copie du nom du projet dans printProject");
        return;
    }
    

    printUnderline(nameTemp);
    puts("Langage(s) utilisé(s):");
    for (unsigned short int i = 0; i < temp->languageArrayLength; i++)
    {
        printf_s("- %s\n", temp->language[i].sName);
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
        puts("Pas de lien GitHub");
}

