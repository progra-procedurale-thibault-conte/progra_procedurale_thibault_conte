#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#include "profil.h"
#include "progra.h"

int main (void)
{
    // permet d'afficher les accents,... via encodage UTF8
    SetConsoleOutputCP(CP_UTF8);

    // declaration
    bool leaveProg;
    unsigned short int userChoice;

    Language langC = {.sName = "C", .knownledgeLvl = 7};
    Language langCPP = {.sName = "C++", .knownledgeLvl = 6};
    Language langCSharp = {.sName = "C#", .knownledgeLvl = 4};
    Language langMySQL = {.sName = "MySQL", .knownledgeLvl = 8};
    Language langSQLite = {.sName = "SQLite", .knownledgeLvl = 6};
    Language langBash = {.sName = "Bash", .knownledgeLvl = 4};
    Language langHTML = {.sName = "HTML", .knownledgeLvl = 4};
    Language langCSS = {.sName = "CSS", .knownledgeLvl = 4};
    Language langRayLib = {.sName = "RayLib (Librairie C)", .knownledgeLvl = 0}; 

    Language allKnownLang[9] = { langC, langCPP, langCSharp, langMySQL, langSQLite, langBash, langHTML, langCSS, langRayLib};

    Project projPuis4 = {.sName = "Puissance 4", .language = {langC}, .languageArrayLength = 1, .year = 2024, .status = FINISHED};
    Project projCandy = {.sName = "Candy crush", .language = {langC}, .languageArrayLength = 1, .year = 2025, .status = FINISHED};
    Project projJeuLangue = {.sName = "Jeu traduction multi-langues", 
                             .language[0] = langCSharp, 
                             .language[1] = langMySQL, 
                             .language[2] = langSQLite, 
                             .languageArrayLength = 3,  
                             .year = 2026, 
                             .status = FINISHED};
    Project projToucheCoule = {.sName = "Touché Coulé", 
                               .language[0] = langC, 
                               .language[1] = langRayLib,
                               .languageArrayLength = 2,                               
                               .year = 2026, 
                               .status = ACTIVE};

    Project allProjects [4] = {projPuis4, projCandy, projJeuLangue, projToucheCoule};
    // code

    leaveProg = false;

    printBeginProg();

    // MENU PRINCIPAL
    while (!leaveProg)
    {   
        printMainMenu();
        userChoice = getUserChoice();      

       switch (userChoice)
       {
            case 0:
                puts("Merci pour votre attention");
                leaveProg = true;
                break;
            case 1:
                printProfile();
                break;
            
            case 2: 
                printTechSkills(allKnownLang, 9);
                break;
            case 3:
                printProjectsList(allProjetcts, 4);
                break;
            case 4:
                // qqs statistiques
                break;

            default:
                fprintf(stderr, "Erreur après le choix du menu");
                exit(EXIT_FAILURE);
    
       }   

    }
    return EXIT_SUCCESS;
}