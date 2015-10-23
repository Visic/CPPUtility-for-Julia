#include "CPPUtility.h"
#include <stdlib.h>

short getKeyState(int keycode) {
    return GetKeyState(keycode);
}

short getAsyncKeyState(int keycode) {
    return GetAsyncKeyState(keycode);
}

int setConsoleCursorPos(short x, short y) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x, y };
    return SetConsoleCursorPosition(hStdOut, coord);
}

HWND getActiveWindow() {
    return GetActiveWindow();
}

HWND setActiveWindow(void* hwnd) {
    SetActiveWindow((HWND)hwnd);
}

HWND findWindow(LPCSTR className, LPCSTR windowName) {
    return FindWindow(className, windowName);
}

Coord getConsoleCursorPos() {
	Coord result;
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!GetConsoleScreenBufferInfo(hStdOut, &screenBufferInfo)) {
		result.X = -1;
		result.Y = -1;
        return result;
    }
	result.X = screenBufferInfo.dwCursorPosition.X;
	result.Y = screenBufferInfo.dwCursorPosition.Y;
    return result;
}

Coord getConsoleDims() {
	Coord result;
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!GetConsoleScreenBufferInfo(hStdOut, &screenBufferInfo)) {
        result.X = -1;
		result.Y = -1;
        return result;
    }
    result.X = screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1;
    result.Y = screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1;
	return result;
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
	Coord result;
    POINT pos;
    if (!GetCursorPos(&pos)) {
		result.X = -1;
		result.Y = -1;
        return result;
	}
	result.X = pos.x;
	result.Y = pos.y;
    return result;
}

int setConsoleCursorVisibility(int visible) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    if(!GetConsoleCursorInfo(hStdOut, &cursorInfo)) return 0;
    cursorInfo.bVisible = visible;
    return SetConsoleCursorInfo(hStdOut, &cursorInfo);
}

unsigned int sendKeyboardKeysDown(int keycode) {
    INPUT input;
    KEYBDINPUT keyboardInput;
    memset(&input, 0, sizeof(input));
    memset(&keyboardInput, 0, sizeof(keyboardInput));
    keyboardInput.dwFlags = KEYEVENTF_SCANCODE;
    keyboardInput.wScan = MapVirtualKey(keycode, MAPVK_VK_TO_VSC);

    input.ki = keyboardInput;
    input.type = INPUT_KEYBOARD;
    return SendInput(1, &input, sizeof(input));
}

unsigned int sendKeyboardKeysUp(int keycode) {
    INPUT input;
    KEYBDINPUT keyboardInput;
    memset(&input, 0, sizeof(input));
    memset(&keyboardInput, 0, sizeof(keyboardInput));
    keyboardInput.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    keyboardInput.wScan = MapVirtualKey(keycode, MAPVK_VK_TO_VSC);

    input.ki = keyboardInput;
    input.type = INPUT_KEYBOARD;
    return SendInput(1, &input, sizeof(input));
}

unsigned int sendMouseKeysDown(int keycode) {
    INPUT input;
    MOUSEINPUT mouseInput;
    memset(&input, 0, sizeof(input));
    memset(&mouseInput, 0, sizeof(mouseInput));
    if (keycode == 0x01) mouseInput.dwFlags = MOUSEEVENTF_LEFTDOWN;
    if (keycode == 0x02) mouseInput.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    if (keycode == 0x04) mouseInput.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
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
    return SendInput(1, &input, sizeof(input));
}

unsigned int sendMouseKeysUp(int keycode) {
    INPUT input;
    MOUSEINPUT mouseInput;
    memset(&input, 0, sizeof(input));
    memset(&mouseInput, 0, sizeof(mouseInput));
    if (keycode == 0x01) mouseInput.dwFlags = MOUSEEVENTF_LEFTUP;
    if (keycode == 0x02) mouseInput.dwFlags = MOUSEEVENTF_RIGHTUP;
    if (keycode == 0x04) mouseInput.dwFlags = MOUSEEVENTF_MIDDLEUP;
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
    return SendInput(1, &input, sizeof(input));
}