#include <winapifamily.h>

#include <windows.h>
#include <winuser.h>

#include <wincrypt.h>

int WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    LPCSTR messageContent = "Some error content...";
    LPCSTR messageTitle = "Some error title...";

    UINT buttonsFlag = MB_OK;
    UINT iconsFlag = MB_ICONASTERISK;

    HWND hConsole = GetConsoleWindow();
    ShowWindow(hConsole, SW_HIDE);

    //Buttons:
    //  MB_OK: OK
    //  MB_ABORTRETRYIGNORE: Abort, Retry, Ignore
    //  MB_CANCELTRYCONTINUE: Cancel, Retry, Continue
    //  MB_HELP: Cancel, Help
    //  MB_YESNO: Yes, No
    //  MB_OKCANCEL: Ok, Cancel
    //  MB_RETRYCANCEL: Retry, Cancel
    //  MB_YESNOCANCEL: Yes, No, Cancel

    //Icons:
    //  MB_ICONEXCLAMATION: Warning Picture (!)
    //  MB_ICONWARNING: Warning Picture (!)
    //  MB_ICONINFORMATION: Information Picture (I)
    //  MB_ICONASTERISK Information Picture (I)
    //  MB_ICONSTOP: Stop Icon (-)
    //  MB_ICONERROR: Stop Icon (-)
    //  MB_ICONHAND: Stop Icon (-)

    while(true)
    {
        //SELECT ONE WINDOW
        MessageBox(NULL, messageContent, messageTitle, buttonsFlag);
        MessageBox(NULL, messageContent, messageTitle, iconsFlag);
    }

    return 0;
}
