#include "CPPUtility.h"
#include <Windows.h>
#include <stdlib.h>

short getKeyState(int keycode) {
    return GetKeyState(keycode);
}

short getAsyncKeyState(int keycode) {
    return GetAsyncKeyState(keycode);
}

int setConsoleCursorPos(short x, short y) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleCursorPosition(hStdOut, (COORD) { x, y });
}

Coord getConsoleCursorPos() {
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!GetConsoleScreenBufferInfo(hStdOut, &screenBufferInfo)) {
        return (Coord) { -1, -1 };
    }
    return (Coord) { screenBufferInfo.dwCursorPosition.X, screenBufferInfo.dwCursorPosition.Y };
}

Coord getConsoleDims() {
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!GetConsoleScreenBufferInfo(hStdOut, &screenBufferInfo)) {
        return (Coord) { -1, -1 };
    }

    return (Coord) { 
        screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1, 
        screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1
    };
}

long getLastError() {
    return GetLastError();
}

int clearScreen() {
    return system("cls");
}

int setConsoleCursorVisibility(int visible) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    if(!GetConsoleCursorInfo(hStdOut, &cursorInfo)) return 0;
    cursorInfo.bVisible = visible;
    return SetConsoleCursorInfo(hStdOut, &cursorInfo);
}

unsigned int sendKeyDown(int keycode) {
    KEYBDINPUT keyboardInput;
    keyboardInput.wVk = keycode;

    INPUT input;
    input.ki = keyboardInput;
    input.type = INPUT_KEYBOARD;

    SendInput(1, &input, sizeof(input));
}

unsigned int sendKeyUp(int keycode) {
    KEYBDINPUT keyboardInput;
    keyboardInput.wVk = keycode;
    keyboardInput.dwFlags = KEYEVENTF_KEYUP;

    INPUT input;
    input.ki = keyboardInput;
    input.type = INPUT_KEYBOARD;

    SendInput(1, &input, sizeof(input));
}