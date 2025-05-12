#include "pch.h"
#include "Controladora.h"
using namespace System;

int main()
{
    Introduccion intro;
    Controladora sistema;



    clearColor();

    setCursorVisible(false);

    intro.cambiarTamanoBuffer(120, 40);

    intro.pintarUPC();
    _getch();
    clear();
    sistema.menu();
    
    return 0;

}
