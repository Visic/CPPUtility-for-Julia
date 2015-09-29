#include "Common.h"
#include <Windows.h>
#include <stdlib.h>

//ccall((:getKeyState, "C:/Users/andrew/Dropbox/Projects/Julia/Julia-C-Cpp interop/CPPUtility/x64/Release/CPPUtility.dll"), Int8, (Int32,), 0x14)
short getKeyState(int keyCode) {
    return GetKeyState(keyCode);
}

//ccall((:getAsyncKeyState, "C:/Users/andrew/Dropbox/Projects/Julia/Julia-C-Cpp interop/CPPUtility/x64/Release/CPPUtility.dll"), Int8, (Int32,), 0x14)
short getAsyncKeyState(int keyCode) {
    return GetAsyncKeyState(keyCode);
}

//ccall((:setCursorPos, "C:/Users/andrew/Dropbox/Projects/Julia/Julia-C-Cpp interop/CPPUtility/x64/Release/CPPUtility.dll"), Int32, (Int16, Int16), 0x00, 0x00)
int setCursorPos(short x, short y) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    return SetConsoleCursorPosition(handle, coord);
}

//ccall((:getLastError, "C:/Users/andrew/Dropbox/Projects/Julia/Julia-C-Cpp interop/CPPUtility/x64/Release/CPPUtility.dll"), Int64, ())
long getLastError() {
    return GetLastError();
}

//ccall((:clearScreen, "C:/Users/andrew/Dropbox/Projects/Julia/Julia-C-Cpp interop/CPPUtility/x64/Release/CPPUtility.dll"), Int32, ())
int clearScreen() {
    return system("cls");
}

//ccall((:setConsoleCursorVisibility, "C:/Users/andrew/Dropbox/Projects/Julia/Julia-C-Cpp interop/CPPUtility/x64/Release/CPPUtility.dll"), Int32, (Int32,))
int setConsoleCursorVisibility(int visible) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = visible; // set the cursor visibility
    return SetConsoleCursorInfo(out, &cursorInfo);
}