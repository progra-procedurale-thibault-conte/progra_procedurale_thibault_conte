#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "profil.h"
#include "progra.h"

int main (void)
{
    // permet d'afficher les accents,... via encodage UTF8
    SetConsoleOutputCP(CP_UTF8);

    printProfile();

    return 0;
}