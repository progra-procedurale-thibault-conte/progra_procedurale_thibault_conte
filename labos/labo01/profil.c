#include <stdio.h>
#include "profil.h"

void printBold(char *text)
{
    printf_s("\033[1m%s\033[0m\n", text);
}

void printUnderline(char *text)
{
    printf_s("\033[4m%s\033[0m\n", text);
}

void printProfile()
{
    printBold("\t\t/// MON PROFIL \\\\\\ \n");
    puts("\t\t  Thibault CONTE");
    puts("\t\t Né le 18/12/1988\n");

    printUnderline("Formation médicale:");
    puts("2013: Diplômé de l'Université de Liège en Médecine");
    puts("2015: Réussite assistanat en médecine générale et\ncertificat en médecine du sport\n");

    printUnderline("Formation informatique:");
    puts("2024: BAC développement d'applications (anciennement Gestion)");
    puts(" =>   Début formation à l'ISL (Institut Saint-Laurent)");

    puts("2026: BAC orientation réseau et télécom");
    puts(" =>   Début formation à l'ITLg\n");

    printUnderline("Lien vers le dépôt GitHub:");
    puts("https://github.com/Mezdoc18");
}