#pragma once
#ifdef EXPORT
    #define DLLINTERFACE __declspec(dllexport)
#else
    #define DLLINTERFACE// __declspec(dllimport)
#endif

DLLINTERFACE short getKeyState(int keycode); 
DLLINTERFACE short getAsyncKeyState(int keycode);
DLLINTERFACE int setCursorPos(short x, short y);
DLLINTERFACE long getLastError();
DLLINTERFACE int clearScreen();
DLLINTERFACE int setConsoleCursorVisibility(int visible);