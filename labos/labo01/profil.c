#include <stdio.h>
#include "profil.h"
#include "compat.h"



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

unsigned short int getUserChoice(unsigned short int maxValue)
{
    char buffer[20];
    unsigned short int userChoice;

    while((fgets(buffer, sizeof(buffer), stdin) == NULL) ||
          (sscanf_s(buffer, "%hu", &userChoice) != 1)     || 
          (userChoice > maxValue))
    {
        fprintf(stderr, "Format attendu: 1 chiffre compris entr 0 et %hu", maxValue);
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
