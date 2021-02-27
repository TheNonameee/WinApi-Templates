#include <winapifamily.h>

#include <windows.h>
#include <winuser.h>

#include <wincrypt.h>

int screenWidth = 0;
int screenHeight = 0;

int meltingInterval = 100;

LRESULT CALLBACK Melting(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_CREATE:
        {
            HDC desktop = GetDC(HWND_DESKTOP);
            HDC window = GetDC(hWnd);

            BitBlt(window, 0, 0, screenWidth, screenHeight, desktop, 0, 0, SRCCOPY);

            ReleaseDC(hWnd, window);
            ReleaseDC(HWND_DESKTOP, desktop);

            SetTimer(hWnd, 0, meltingInterval, 0);

            ShowWindow(hWnd, SW_SHOW);

            break;
        }
        case WM_PAINT:
        {
            ValidateRect(hWnd, 0);

            break;
        }
        case WM_TIMER:
        {
            HDC wndw = GetDC(hWnd);

            int moveX = (rand() % screenWidth) - (200 / 2);
            int moveY = (rand() % 15);

            int width = (rand() % 200);

            BitBlt(wndw, moveX, moveY, width, screenHeight, wndw, moveX, 0, SRCCOPY);

            ReleaseDC(hWnd, wndw);

            break;
        }
        case WM_DESTROY:
        {
            KillTimer(hWnd, 0);

            PostQuitMessage(0);

            break;
        }

        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}

int APIENTRY main(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    screenHeight = GetSystemMetrics(SM_CYSCREEN);

    WNDCLASS wndClass = {0, Melting, 0, 0, hInst, 0, LoadCursorW(0, IDC_ARROW), 0, 0, (LPCTSTR)"ScreenMelting"};

    if(RegisterClass(&wndClass))
    {
        HWND hWnd = CreateWindowExA(WS_EX_TOPMOST, "ScreenMelting", 0, WS_POPUP, 0, 0, screenWidth, screenHeight, HWND_DESKTOP, 0, hInst, 0);

        if(hWnd) {
            srand(GetTickCount());

            MSG message = { 0 };

            while(message.message != WM_QUIT)
            {
                if(PeekMessage(&message, 0, 0, 0, PM_REMOVE))
                {
                    TranslateMessage(&message);

                    DispatchMessage(&message);
                }
            }
        }
    }
}
