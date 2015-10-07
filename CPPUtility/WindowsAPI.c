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

int setCursorPos(int x, int y) {
    return SetCursorPos(x, y);
}

Coord getCursorPos(int x, int y) {
    POINT result;
    if (!GetCursorPos(&result)) return (Coord) { x = -1, y = -1 };
    return (Coord) { x = result.x, y = result.y };
}

int setConsoleCursorVisibility(int visible) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    if(!GetConsoleCursorInfo(hStdOut, &cursorInfo)) return 0;
    cursorInfo.bVisible = visible;
    return SetConsoleCursorInfo(hStdOut, &cursorInfo);
}

unsigned int sendKeyDown(int keycode) {
    INPUT input;
    memset(&input, 0, sizeof(input));
    if (keycode <= 0x06 && keycode != 0x03) {
        MOUSEINPUT mouseInput;
        memset(&mouseInput, 0, sizeof(mouseInput));
        if (keycode == 0x01) mouseInput.mouseData = MOUSEEVENTF_LEFTDOWN;
        if (keycode == 0x02) mouseInput.mouseData = MOUSEEVENTF_RIGHTDOWN;
        if (keycode == 0x04) mouseInput.mouseData = MOUSEEVENTF_MIDDLEDOWN;
        if (keycode == 0x05) {
            mouseInput.dwFlags = MOUSEEVENTF_XDOWN;
            mouseInput.mouseData = XBUTTON1;
        }
        if (keycode == 0x06) {
            mouseInput.dwFlags = MOUSEEVENTF_XDOWN;
            mouseInput.mouseData = XBUTTON2;
        }

        input.mi = mouseInput;
        input.type = INPUT_MOUSE;
    } else {
        KEYBDINPUT keyboardInput;
        memset(&keyboardInput, 0, sizeof(keyboardInput));
        keyboardInput.wVk = keycode;

        input.ki = keyboardInput;
        input.type = INPUT_KEYBOARD;
    }
    SendInput(1, &input, sizeof(input));
}

unsigned int sendKeyUp(int keycode) {
    INPUT input;
    memset(&input, 0, sizeof(input));
    if (keycode <= 0x06 && keycode != 0x03) {
        MOUSEINPUT mouseInput;
        memset(&mouseInput, 0, sizeof(mouseInput));
        if (keycode == 0x01) mouseInput.mouseData = MOUSEEVENTF_LEFTUP;
        if (keycode == 0x02) mouseInput.mouseData = MOUSEEVENTF_RIGHTUP;
        if (keycode == 0x04) mouseInput.mouseData = MOUSEEVENTF_MIDDLEUP;
        if (keycode == 0x05) {
            mouseInput.dwFlags = MOUSEEVENTF_XUP;
            mouseInput.mouseData = XBUTTON1;
        }
        if (keycode == 0x06) {
            mouseInput.dwFlags = MOUSEEVENTF_XUP;
            mouseInput.mouseData = XBUTTON2;
        }

        input.mi = mouseInput;
        input.type = INPUT_MOUSE;
    } else {
        KEYBDINPUT keyboardInput;
        memset(&keyboardInput, 0, sizeof(keyboardInput));
        keyboardInput.wVk = keycode;
        keyboardInput.dwFlags = KEYEVENTF_KEYUP;

        input.ki = keyboardInput;
        input.type = INPUT_KEYBOARD;
    }

    SendInput(1, &input, sizeof(input));
}