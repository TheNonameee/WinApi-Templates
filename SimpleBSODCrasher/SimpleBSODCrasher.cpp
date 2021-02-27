#include <winapifamily.h>

#include <windows.h>
#include <winuser.h>

#include <wincrypt.h>

#include <stdio.h>
#include <tchar.h>

int WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hConsole = GetConsoleWindow();
    ShowWindow(hConsole, SW_HIDE);

    for(int counter = 0; counter < 100; counter++)
    {
        HANDLE hFile = NULL;

        hFile = CreateFileW(L"C:\\$MFT\\SomeFile", FILE_READ_ATTRIBUTES, 0, NULL, OPEN_EXISTING, 0, NULL);

        CloseHandle(hFile);
    }

    return 0;
}
