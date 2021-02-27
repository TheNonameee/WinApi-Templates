#include <winapifamily.h>

#include <windows.h>
#include <winuser.h>

#include <wincrypt.h>

int WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hConsole = GetConsoleWindow();
    ShowWindow(hConsole, SW_HIDE);

    LPARAM screenStatus = 2;

    //Screen statuses:
    // -1 - display is powering on
    // 1 - display is going low power
    // 2 - display is being shut off

    // When you debug this program - press ALT + F4 to disable this!!!

    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, screenStatus);

    return 0;
}
