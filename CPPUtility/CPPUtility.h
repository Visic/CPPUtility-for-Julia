#pragma once
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
DLLINTERFACE long getLastError();
DLLINTERFACE int clearScreen();
DLLINTERFACE int setConsoleCursorVisibility(int visible);