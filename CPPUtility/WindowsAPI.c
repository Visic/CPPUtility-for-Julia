#include "CPPUtility.h"
#include <Windows.h>
#include <stdlib.h>

short getKeyState(int keyCode) {
    return GetKeyState(keyCode);
}

short getAsyncKeyState(int keyCode) {
    return GetAsyncKeyState(keyCode);
}

int setConsoleCursorPos(short x, short y) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { x, y };
    return SetConsoleCursorPosition(handle, coord);
}

Coord getConsoleCursorPos() {
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!GetConsoleScreenBufferInfo(hStd, &screenBufferInfo)) {
        return (Coord) { -1, -1 };
    }
    return (Coord) { screenBufferInfo.dwCursorPosition.X, screenBufferInfo.dwCursorPosition.Y };
}

long getLastError() {
    return GetLastError();
}

int clearScreen() {
    return system("cls");
}

int setConsoleCursorVisibility(int visible) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = visible;
    return SetConsoleCursorInfo(out, &cursorInfo);
}