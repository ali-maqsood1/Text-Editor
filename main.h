#pragma once
#include <windows.h>
#include <iostream>

const int BLACK = 0;
const int WHITE = 15;
const int LIGHT_BLUE = 9;

void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);
void color(int k);
void hideConsoleCursor();
void printLine(int rpos1, int cpos1, int rpos2, int cpos2, char sym);
void boundary();
