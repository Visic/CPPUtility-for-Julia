#pragma once
#include <Windows.h>

#ifdef EXPORT
    #define DLLINTERFACE __declspec(dllexport)
#else
    #define DLLINTERFACE// __declspec(dllimport)
#endif

DLLINTERFACE typedef struct _Coord {
    short X, Y;
} Coord;

DLLINTERFACE short getKeyState(int keycode); 
DLLINTERFACE short getAsyncKeyState(int keycode);
DLLINTERFACE int setConsoleCursorPos(short x, short y);
DLLINTERFACE Coord getConsoleCursorPos();
DLLINTERFACE Coord getConsoleDims();
DLLINTERFACE int setCursorPos(int x, int y);
DLLINTERFACE Coord getCursorPos();
DLLINTERFACE long getLastError();
DLLINTERFACE int clearScreen();
DLLINTERFACE int setConsoleCursorVisibility(int visible);
DLLINTERFACE unsigned int sendKeyboardKeysDown(int keycode);
DLLINTERFACE unsigned int sendKeyboardKeysUp(int keycode);
DLLINTERFACE unsigned int sendMouseKeysDown(int keycode);
DLLINTERFACE unsigned int sendMouseKeysUp(int keycode);
DLLINTERFACE HWND getActiveWindow();
DLLINTERFACE HWND setActiveWindow(void* hwnd);
DLLINTERFACE HWND findWindow(LPCSTR className, LPCSTR windowName);