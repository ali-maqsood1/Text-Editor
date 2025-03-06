#include "main.h"

void getRowColbyLeftClick(int& rpos, int& cpos) {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Events;
    INPUT_RECORD InputRecord;
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT |
        ENABLE_EXTENDED_FLAGS);
    do {
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);
        if (InputRecord.Event.MouseEvent.dwButtonState ==
            FROM_LEFT_1ST_BUTTON_PRESSED) {
            cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
            rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            break;
        }
    } while (true);
}

void gotoRowCol(int rpos, int cpos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}

void color(int k) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}

void hideConsoleCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void printLine(int rpos1, int cpos1, int rpos2, int cpos2, char sym) {
    for (float i = 0; i < 1; i += 0.001) {
        int r = rpos1 * i + rpos2 * (1 - i);
        int c = cpos1 * i + cpos2 * (1 - i);
        gotoRowCol(r, c);
        std::cout << sym;
    }
}

void boundary() {
    char sym = -37;
    color(WHITE);
    printLine(25, 0, 25, 120, sym);
    printLine(25, 0, 25, 10, sym);
    color(BLACK);
    printLine(24, 3, 24, 120, sym);

    int r = 0, c = 0;
    gotoRowCol(26, 0);
    color(LIGHT_BLUE);
    std::cout << "[Cipher] @editor:~# ";
}
