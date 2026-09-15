#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
#endif
#include <stdbool.h>

#include "profil.h"
#include "progra.h"
#include "compat.h"

#define NBOFUSERCHOICES 5
#define NBOFLANGUAGES 9
#define NBOFPROJECTS 4
#define MAXSKILLLEVEL 10


int main (void)
{
    #ifdef _WIN32
    // permet d'afficher les accents,... via encodage UTF8
        SetConsoleOutputCP(CP_UTF8);
    #endif

    // declaration
    bool leaveProg;
    unsigned short int userChoice;

    // si ajout d'un langage => incrémenter la macro NBOFLANGUAGES 
    Language langC = {.sName = "C", .knowledgeLvl = 7};
    Language langCPP = {.sName = "C++", .knowledgeLvl = 6};
    Language langCSharp = {.sName = "C#", .knowledgeLvl = 4};
    Language langMySQL = {.sName = "MySQL", .knowledgeLvl = 8};
    Language langSQLite = {.sName = "SQLite", .knowledgeLvl = 6};
    Language langBash = {.sName = "Bash", .knowledgeLvl = 4};
    Language langHTML = {.sName = "HTML", .knowledgeLvl = 4};
    Language langCSS = {.sName = "CSS", .knowledgeLvl = 4};
    Language langRayLib = {.sName = "RayLib (Librairie C)", .knowledgeLvl = 0}; 

    Language allKnownLang[NBOFLANGUAGES] = { langC, langCPP, langCSharp, langMySQL, langSQLite, langBash, langHTML, langCSS, langRayLib};

    // si ajout d'un projet => incrémenter la macro NBOFPROJECTS
    Project projPuis4 = {.sName = "Puissance 4",
                         .language = {langC},
                         .languageArrayLength = 1,
                         .year = 2024,
                         .status = FINISHED,
                         .sLienGitHub = ""};

    Project projCandy = {.sName = "Candy crush",
                         .language = {langC},
                         .languageArrayLength = 1,
                         .year = 2025,
                         .status = FINISHED,
                         .sLienGitHub = ""};

    Project projJeuLangue = {.sName = "Jeu traduction multi-langues",
                             .language = {langCSharp, langMySQL, langSQLite},
                             .languageArrayLength = 3,
                             .year = 2026,
                             .status = FINISHED,
                             .sLienGitHub = ""};

    Project projToucheCoule = {.sName = "Touché Coulé",
                               .language = {langC, langRayLib},
                               .languageArrayLength = 2,
                               .year = 2026,
                               .status = ACTIVE,
                               .sLienGitHub = "https://github.com/Mezdoc18/bataille_navale"};

    Project allProjects [NBOFPROJECTS] = {projPuis4, projCandy, projJeuLangue, projToucheCoule};

    // code

    leaveProg = false;

    printBeginProg();

    // MENU PRINCIPAL
    while (!leaveProg)
    {   
        printMainMenu();
        userChoice = getUserChoice(NBOFUSERCHOICES);      

       switch (userChoice)
       {
            case 0:
                puts("\nMerci pour votre attention\n");
                leaveProg = true;
                break;
            case 1:
                printProfile();
                break;
            
            case 2: 
                printTechSkills(allKnownLang, NBOFLANGUAGES);
                break;
            case 3:
                puts("Quelle niveau minimal de tech afficher? (0-10)");
                userChoice = getUserChoice(MAXSKILLLEVEL);
                printTechSkillsMinLvl(allKnownLang, NBOFLANGUAGES, userChoice);
                break;
            case 4:
                printProjectsList(allProjects, NBOFPROJECTS);
                break;
             case 5:
                // qqs statistiques
                printStat(allKnownLang, allProjects, NBOFLANGUAGES, NBOFPROJECTS);
                break;

            default:
                fprintf(stderr, "Erreur après le choix du menu");
                break;
    
       }   

    }
    return EXIT_SUCCESS;
}