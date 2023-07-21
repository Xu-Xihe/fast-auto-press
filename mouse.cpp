#include <conio.h>
#include <cstring>
#include <windows.h>
#include <cstdio>
#include <ctime>
#include <iostream>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
#define lefta 192
#define leftb 45
#define right 19
const double timer = 1.5;
clock_t sta, last;
int once;
bool ji, down;
POINT wind;
inline void getmouse()
{
    GetCursorPos(&wind);
}
inline void res()
{
    if (GetKeyState(VK_SCROLL) && 0x001)
    {
        keybd_event(145, 0, 0, 0);
        keybd_event(145, 0, KEYEVENTF_KEYUP, 0);
    }
    if (!GetKeyState(VK_NUMLOCK) && 0x001)
    {
        keybd_event(144, 0, 0, 0);
        keybd_event(144, 0, KEYEVENTF_KEYUP, 0);
    }
}
inline void kill()
{
    if (!(GetKeyState(VK_NUMLOCK) && 0x001))
    {
        system("taskkill /t /f /im WsaClient.exe");
        system("taskkill /t /f /im WsaService.exe");
        system("taskkill /t /f /im GSKServer.exe");
        system("taskkill /t /f /im vlc.exe");
        //system("taskkill /t /f /im msedge.exe");
    }
    system("taskkill /t /f /im chrome.exe");
    system("taskkill /t /f /im hysteria-tun-windows-6.0-386.exe");
    system("taskkill /t /f /im wget2.exe");
    system("taskkill /t /f /im Notepad.exe");
    system("taskkill /t /f /im code.exe");
    system("taskkill /t /f /im ShadowsocksR.exe");
    system("taskkill /t /f /im lantern.exe");
    system("taskkill /t /f /im youku.exe");
    system("taskkill /t /f /im v2free.exe");
    system("taskkill /t /f /im v2ray.exe");
    system("taskkill /t /f /im v2rayN.exe");
    system("taskkill /t /f /im clash-windows-386.exe");
    system("taskkill /t /f /im winrar.exe");
    system("taskkill /t /f /im IDMan.exe");
    system("taskkill /t /f /im Motrix.exe");
    system("taskkill /t /f /im v2rayN.exe");
    system("taskkill /t /f /im wgc.exe");
    system("taskkill /t /f /im WorldOfWarships64.exe");
}
inline void d_web()
{
    system("del D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\*.cmd");
    system("del D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\*.vbs");
    system("del D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\*.rar");
    system("del D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\*.exe");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\Browser");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\clash");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\clashB");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\hysteria");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\psiphon");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\SSR");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\SS-plugin");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\v2go");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\v2ray");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\v2rayB");
    //
    system("del D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\*.cmd");
    system("del D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\*.vbs");
    system("del D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\*.rar");
    system("del D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\*.exe");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\Browser");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\clash");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\clashB");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\hysteria");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\psiphon");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\SSR");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\SS-plugin");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\v2go");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\v2ray");
    system("rmdir /s /q D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\v2rayB");
}
inline void dabao()
{
    keybd_event(20, 0, 0, 0);
    keybd_event(20, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(17, 0, 0, 0);
    keybd_event(91, 0, 0, 0);
    keybd_event(37, 0, 0, 0);
    keybd_event(37, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(91, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
    kill();
    system("del C:\\Users\\XuXixi\\Downloads /q /s");
    system("del C:\\Users\\XuXixi\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\360.cn /q /s");
    system("md C:\\users\\XuXixi\\Downloads");
    d_web();
    keybd_event(20, 0, 0, 0);
    keybd_event(20, 0, KEYEVENTF_KEYUP, 0);
    res();
}
inline void copybd(std::string TempBin)
{
    HGLOBAL hMemBin = NULL;
    PCHAR LockBin = NULL;
    OpenClipboard(NULL);
    EmptyClipboard();
    hMemBin = GlobalAlloc(GMEM_MOVEABLE, TempBin.size() + 1);
    LockBin = (PCHAR)GlobalLock(hMemBin);
    RtlMoveMemory(LockBin, TempBin.c_str(), TempBin.size() + 1);
    GlobalUnlock(hMemBin);
    LockBin = NULL;
    SetClipboardData(CF_TEXT, hMemBin);
    CloseClipboard();
}
int main()
{
    printf("Successfully loaded!");
    Sleep(500);
    HWND hwnd;
    if (hwnd = ::FindWindow("ConsoleWindowClass", NULL))
    {
        ::ShowWindow(hwnd, SW_HIDE);
    }
    while (1)
    {
        if (KEY_DOWN(191) && !(GetKeyState(VK_SCROLL) && 0x001))
        {
            if (!ji)
            {
                ji = 1;
                sta = clock();
            }
            else
            {
                double tt = (double)(clock() - sta) / CLOCKS_PER_SEC;
                printf("clear time left:%.2fsec\n", timer - tt > 0 ? timer - tt : 0);
                if (tt > timer)
                {
                    dabao();
                    return 0;
                }
            }
            continue;
        }
        if (KEY_DOWN(222) && !(GetKeyState(VK_NUMLOCK) && 0x001))
        {
            if (!once)
            {
                keybd_event(17, 0, 0, 0);
                keybd_event(91, 0, 0, 0);
                keybd_event(37, 0, 0, 0);
                keybd_event(37, 0, KEYEVENTF_KEYUP, 0);
                keybd_event(91, 0, KEYEVENTF_KEYUP, 0);
                keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
                res();
                if (GetKeyState(20) && 0x001)
                {
                    keybd_event(20, 0, 0, 0);
                    keybd_event(20, 0, KEYEVENTF_KEYUP, 0);
                }
                system("rundll32.exe powrprof.dll,SetSuspendState 0,1,0");
                once = 3;
            }
            continue;
        }
        if (KEY_DOWN(120) && !(GetKeyState(VK_NUMLOCK) && 0x001))
        {
            if (!once)
            {
                system("wget --no-check-certificate -O C:\\Users\\XuXixi\\Downloads\\ChromeGo.7z https://d2.v2rss.gq/ChromeGo.7z");
                system("cls");
                printf("Success!\n");
                keybd_event(144, 0, 0, 0);
                keybd_event(144, 0, KEYEVENTF_KEYUP, 0);
                once = 3;
            }
        }
        if (KEY_DOWN(leftb) && KEY_DOWN(right))
        {
            res();
            return 0;
        }
        if (KEY_DOWN(lefta) || KEY_DOWN(leftb))
        {
            if (!once)
            {
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                once = 1;
            }
            continue;
        }
        if (KEY_DOWN(right))
        {
            if (!once)
            {
                mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
                once = 2;
            }
            continue;
        }
        if (GetKeyState(VK_SCROLL) && 0x001)
        {
            if (KEY_DOWN(191))
            {
                dabao();
                return 0;
            }
            if (KEY_DOWN(66))
            {
                kill();
                once = 3;
                system("cls");
                res();
            }
            if (KEY_DOWN(18))
            {
                getmouse();
                once = 3;
            }
            if (KEY_DOWN(68))
            {
                if (!once)
                {
                    SetCursorPos(wind.x, wind.y);
                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                    once = 3;
                }
                continue;
            }
            if (KEY_DOWN(65))
            {
                if (!once)
                {
                    keybd_event(18, 0, 0, 0);
                    keybd_event(9, 0, 0, 0);
                    keybd_event(9, 0, KEYEVENTF_KEYUP, 0);
                    keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
                    once = 3;
                }
                continue;
            }
            if (KEY_DOWN(83))
            {
                if (!once)
                {
                    keybd_event(32, 0, 0, 0);
                    Sleep(100);
                    keybd_event(32, 0, KEYEVENTF_KEYUP, 0);
                    keybd_event(18, 0, 0, 0);
                    keybd_event(9, 0, 0, 0);
                    keybd_event(9, 0, KEYEVENTF_KEYUP, 0);
                    keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
                    once = 3;
                }
                continue;
            }
            if (KEY_DOWN(188))
            {
                if (!once)
                {
                    keybd_event(17, 0, 0, 0);
                    keybd_event(91, 0, 0, 0);
                    keybd_event(37, 0, 0, 0);
                    Sleep(100);
                    keybd_event(37, 0, KEYEVENTF_KEYUP, 0);
                    keybd_event(91, 0, KEYEVENTF_KEYUP, 0);
                    keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
                    once = 3;
                }
                continue;
            }
            if (KEY_DOWN(190))
            {
                if (!once)
                {
                    keybd_event(17, 0, 0, 0);
                    keybd_event(91, 0, 0, 0);
                    keybd_event(39, 0, 0, 0);
                    Sleep(100);
                    keybd_event(39, 0, KEYEVENTF_KEYUP, 0);
                    keybd_event(91, 0, KEYEVENTF_KEYUP, 0);
                    keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
                    once = 3;
                }
                continue;
            }
            if (KEY_DOWN(90))
            {
                if (!once)
                {
                    keybd_event(32, 0, 0, 0);
                    Sleep(100);
                    keybd_event(32, 0, KEYEVENTF_KEYUP, 0);
                    Sleep(100);
                    keybd_event(17, 0, 0, 0);
                    keybd_event(91, 0, 0, 0);
                    keybd_event(37, 0, 0, 0);
                    keybd_event(37, 0, KEYEVENTF_KEYUP, 0);
                    keybd_event(91, 0, KEYEVENTF_KEYUP, 0);
                    keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
                }
                continue;
            }
            if (KEY_DOWN(20))
            {
                if (!once)
                {
                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                    once = 1;
                }
                continue;
            }
            if (KEY_DOWN(88))
            {
                if (!once)
                {
                    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
                    once = 2;
                }
                continue;
            }

            if (KEY_DOWN(71))
            {
                if (!once)
                {
                    copybd("chrome --incognito --window-position=100,820 --window-size=20,50");
                    once = 3;
                }
                continue;
            }
            if (KEY_DOWN(72))
            {
                if (!once)
                {
                    copybd("chrome --incognito --window-position=800,820 --window-size=20,50");
                    once = 3;
                }
                continue;
            }
        }
        if (once == 1)
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        if (once == 2)
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
        once = 0;
        if (ji)
        {
            ji = 0;
            system("cls");
        }
    }
}