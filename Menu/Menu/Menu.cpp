#include "pch.h"
#include "Controladora.h"
#include "Hash.h"
using namespace System;

int main()
{
    Introduccion intro;
    //Controladora sistema;



    clearColor();

    setCursorVisible(false);

    intro.cambiarTamanoBuffer(120, 40);

    intro.pintarUPC();
    _getch();
    clear();
    Hash();
   // sistema.menu();
    
    return 0;

}
