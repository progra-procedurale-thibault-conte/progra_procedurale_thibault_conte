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
    puts("\n");
    printUnderline("Afficher:\n");
    puts("[1] Le profil");
    puts("[2] Les compétences techniques / langages");
    puts("[3] Les projets");
    puts("[4] Quelques statistiques");
    putc('\n',stdout);
    puts("[0] Quitter le programme");
}

void printProfile()
{
    printStarsLine();

    printBold("\n\t\t/// MON PROFIL \\\\\\ \n");
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
    printStarsLine();
    putc('*', stdout);
    printBold("\n\t\t/// COMPETENCES \\\\\\ \n");

    for (unsigned short int i = 0; i < arrayLength; i++)
    printLanguage(&temp[i]);

    printBold("\t\t\\\\\\             ///\n");
    putc('*', stdout);
    printStarsLine();
}