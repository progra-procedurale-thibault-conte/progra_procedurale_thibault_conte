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
    Project projPuis4 = {.sName = "puissance 4", .language = langC, .year = 2024, .status = FINISHED};

    // code

    leaveProg = false;

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
                //competence technique / langage
                break;
            case 3:
                //Projets
                break;
            case 4:
                // qqs statistiques
                break;

            default:
                fprintf(stderr, "Erreur après le choix du menu");
                exit(EXIT_FAILURE);
    
       }   

    }
    return 0;
}