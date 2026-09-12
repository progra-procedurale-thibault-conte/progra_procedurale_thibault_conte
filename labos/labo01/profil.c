#include <stdio.h>
#include "profil.h"

//*************************//
//      Mise en forme
//*************************//
void printBold(char *text)
{
    printf_s("\033[1m%s\033[0m\n", text);
}

void printUnderline(char *text)
{
    printf_s("\033[4m%s\033[0m\n", text);
}

//*************************//
//      Getters
//*************************//

short int getUserChoice()
{
    char buffer[20];
    unsigned short int userChoice;

    while((fgets(buffer, sizeof(buffer), stdin) == NULL) ||
          (sscanf_s(buffer, "%u", &userChoice) != 1)     || 
          (userChoice > 4))
    {
        fprintf(stderr, "Format attendu: 1 chiffre inférieur à 4");
        continue;
    }

    return userChoice;
}

//*************************//
//      Affichage
//*************************//

void printMainMenu()
{
    puts("\n\n");
    printf_s("\t\tBienvenue sur le profil DEV de ");
    printBold("Thibault Conte");

    printUnderline("Afficher:");
    puts("[1] Le profil");
    puts("[2] Les compétences techniques / langages");
    puts("[3] Les projets");
    puts("[4] Quelques statistiques");
    putc('\n',stdout);
    puts("[0] Quitter le programme");
}

void printProfile()
{
    printBold("\t\t/// MON PROFIL \\\\\\ \n");
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
}