#pragma once
#include "Windows.h"

using namespace System;

// va a una posicion x o y;
void gotoxy(unsigned short int x, unsigned short int y) {

	Console::SetCursorPosition(x, y);

}

//Setea la visibilidad del cursor
void setCursorVisible(bool isVisible) {

	Console::CursorVisible = isVisible;

}

enum Colors {
    BLACK,
    DARK_RED,
    DARK_GREEN,
    DARK_YELLOW,
    DARK_BLUE,
    DARK_MAGENTA,
    DARK_CYAN,
    DARK_WHITE,
    BRIGHT_BLACK,
    BRIGHT_RED,
    BRIGHT_GREEN,
    BRIGHT_YELLOW,
    BRIGHT_BLUE,
    BRIGHT_MAGENTA,
    BRIGHT_CYAN,
    WHITE
};
int _WINCOLOR_[] = { 0, 4, 2, 6, 1, 5, 3, 7, 8, 12, 10, 14, 9, 13, 11, 15 };

//Pinta una parte de la consola (background)
void background(int color) {
    color = _WINCOLOR_[color];
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, color << 4);
}

//Limpia el color y lo devuelve al color default de consola
void clearColor() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 7);
}

//Pinta el color de la letra con un numero int, o enum de colors
void color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//Limpia la pantalla con system("cls")
void clear() {

    system("cls");

}

//Limpia la pantalla con system("cls") y clearColor()
void clearAll() {

    clearColor();
    system("cls");

}

