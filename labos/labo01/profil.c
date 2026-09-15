#include <stdio.h>
#include <stdlib.h>
#include "profil.h"
#include "compat.h"



//*************************//
//      Mise en forme
//*************************//
void printBold(char *text)
{
    if (text == NULL)
    {
        fprintf(stderr, "Erreur: pointeur NULL dans printBold\n");
        return;
    }

    printf_s("\033[1m%s\033[0m\n", text);
}

void printUnderline(char *text)
{
    if (text == NULL)
    {
        fprintf(stderr, "Erreur: pointeur NULL dans printUnderline\n");
        return;
    }

    printf_s("\033[4m%s\033[0m\n", text);
}

//*************************//
//      Getters
//*************************//

unsigned short int getUserChoice(unsigned short int maxValue)
{
    char buffer[20];
    unsigned short int userChoice;

    while((fgets(buffer, sizeof(buffer), stdin) == NULL) ||
          (sscanf_s(buffer, "%hu", &userChoice) != 1)     || 
          (userChoice > maxValue))
    {
        // conseil sécurité IA vérifier si stdin fermé sinon boucle infinie
        if (feof(stdin))
        {
            fprintf(stderr,"Fin de flux d'entrée\n");
            exit(EXIT_FAILURE);
        }
        fprintf(stderr, "Format attendu: 1 chiffre compris entr 0 et %hu\n", maxValue);
    }
    return userChoice;
}

//*************************//
//      Affichage
//*************************//
void printBeginStarsLine()
{
   printf_s("\t\t*****************************"); 
}

void printStarsLine()
{
    printf_s("\t\t******************");
}

void printBeginProg()
{
    putc('\n', stdout);
    printBeginStarsLine();  
    printf_s("\n\t\t");
    printBold("Bienvenue sur mon profil DEV");
    printBeginStarsLine();  
}

void printMainMenu()
{
    // si ajout de choix utilisateurs, modifier la macro NBOFUSERCHOICES
    puts("\n");
    printUnderline("Afficher:\n");
    puts("[1] Le profil");
    puts("[2] Les compétences techniques / langages");
    puts("[3] Les compétences techniques / langages avec un niveau minimum");
    puts("[4] Les projets");
    puts("[5] Quelques statistiques");
    putc('\n',stdout);
    puts("[0] Quitter le programme");
}

void printProfile()
{
    printStarsLine();

    printBold("\n\n\t\t/// MON PROFIL \\\\\\ \n");
    puts("\t\t  Thibault CONTE");
    puts("\t\t Né le 18/12/1988\n");

    printUnderline("Formation informatique:");
    puts("2024: BAC développement d'applications (anciennement Gestion)");
    puts(" =>   Institut Saint-Laurent");

    puts("2026: BAC orientation réseau et télécom");
    puts(" =>   Institut Technologie de Liège\n");

    printUnderline("Lien vers le dépôt GitHub:");
    puts("https://github.com/Mezdoc18\n");

    printBold("\t\t\\\\\\            ///\n");
    printStarsLine();
}

void printTechSkills(Language temp[], unsigned short int arrayLength)
{
    if (temp == NULL || arrayLength == 0)
    {
        fprintf(stderr, "Erreur: tableau NULL ou taille de 0 dans printTechSkills\n");
        return;
    }

    printStarsLine();
    putc('*', stdout);
    printBold("\n\n\t\t/// COMPETENCES \\\\\\ \n");

    for (unsigned short int i = 0; i < arrayLength; i++)
        printLanguage(&temp[i]);

    printBold("\t\t\\\\\\             ///\n");    
    printStarsLine();
    putc('*', stdout);
}

void printTechSkillsMinLvl(Language temp[], unsigned short int arrayLength, unsigned short int minSkillLvl)
{
    if (temp == NULL || arrayLength == 0)
    {
        fprintf(stderr, "Erreur: tableau NULL ou taille de 0 dans printTechSkillsMinLvl\n");
        return;
    }

    printStarsLine();
    putc('*', stdout);
    printBold("\n\n\t\t/// COMPETENCES \\\\\\ \n");

    for (unsigned short int i = 0; i < arrayLength; i++)
    {
        if(temp[i].knowledgeLvl >= minSkillLvl)
            printLanguage(&temp[i]);
    }
        

    printBold("\t\t\\\\\\             ///\n");    
    printStarsLine();
    putc('*', stdout);
}

void printProjectsList(Project temp[],unsigned short int arrayLength)
{
    if (temp == NULL || arrayLength == 0)
    {
        fprintf(stderr, "Erreur: tableau NULL ou taille de 0 dans printProjectsList\n");
        return;
    }

    printStarsLine();
    printBold("\n\n\t\t /// PROJETS \\\\\\ \n");

    for (unsigned short int i = 0; i < arrayLength; i++)
    {
        printProject(&temp[i]);
        putc('\n',stdout);
    }
    printBold("\t\t\\\\\\             ///\n");
    printStarsLine();
}

void printStat(Language allLang[], Project allProj[], unsigned short int nbOfLang, unsigned short int nbOfProj)
{
    if (allLang == NULL || allProj == NULL || nbOfLang == 0 || nbOfProj == 0)
    {
        fprintf(stderr, "Erreur: tableau NULL ou taille de 0 dans printStat\n");
        return;
    }

    printStarsLine();
    puts("****");
    printBold("\n\t\t/// QUELQUES STATS \\\\\\ \n");

    printf_s("\nNombre de technologies connues: %hu\n", nbOfLang);
    printf_s("Niveau moyen : %.2f/10\n", averageLvl(allLang, nbOfLang));
    printf_s("Pourcentage de projets terminés: %.2f %% \n", 
        100 * averageEndedProjects(allProj, nbOfProj));
    Language Best = bestMasteredLanguage(allLang, nbOfLang);
    printf_s("Technologie la mieux maitrisée: %s\n\n", Best.sName);

    printBold("\t\t\\\\\\                ///\n");    
    printStarsLine();
    puts("****");
}