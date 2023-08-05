#include <conio.h>
#include <cstring>
#include <windows.h>
#include <cstdio>
#include <ctime>
#include <iostream>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
const double timer = 1.5; // clear time left after press '/'
clock_t sta, last;        // clear time record
int once;                 // if rise up
bool ji;                  // if '/' rise up
POINT wind;               // mouse position
const int killlen = 20;   // How many to kill
const char taskname[killlen + 1][100] = {
    "",
    "chrome.exe",                       // 1
    "wget2.exe",                        // 2
    "vlc.exe",                          // 3
    "winrar.exe",                       // 4
    "IDMan.exe",                        // 5
    "Notepad.exe",                      // 6
    "code.exe",                         // 7
    "java.exe",                         // 8
    "",                                 // 9 occupied
    "Motrix.exe",                       // 10
    "hysteria-tun-windows-6.0-386.exe", // 11
    "ShadowsocksR.exe",                 // 12
    "v2free.exe",                       // 13
    "v2ray.exe",                        // 14
    "v2rayN.exe",                       // 15
    "clash.meta-windows-386.exe"        // 16
    "naive.exe"                         // 17
    "psiphon3.exe"                      // 18
    "sing-box.exe"                      // 19
    "xray.exe"                          // 20
};
const int killsequence[10][20] = {
    {},
    {1, 4, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, // 1
    {2, 4},                                         // 2
    {3, 4},                                         // 3
    {4},                                            // 4
    {5, 10},                                        // 5
    {6, 4},                                         // 6
    {7},                                            // 7
    {8, 4},                                         // 8
};
const char killorder[] = "taskkill /t /f /im ";
inline void getmouse() // get mouse position
{
    GetCursorPos(&wind);
}
inline void res() // reset the light condition
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
inline void kill(int pos)
{
    keybd_event(20, 0, 0, 0); // signal
    keybd_event(20, 0, KEYEVENTF_KEYUP, 0);
    char com[50];
    if (pos == 0)
    {
        for (int i = 1; i < killlen; i++)
        {
            if ((i != 3 && i != 8) || !(GetKeyState(VK_NUMLOCK) && 0x001))
            {
                strcpy(com, killorder);
                strcat(com, taskname[i]);
                system(com);
            }
        }
        res();
    }
    else
    {
        for (int i = 0; killsequence[pos][i]; i++)
        {
            strcpy(com, killorder);
            strcat(com, taskname[killsequence[pos][i]]);
            system(com);
        }
    }
}
const char delpath[3][40] = {
    "D:\\XXH\\Camera\\Canon-SX200IS\\Go2\\",
    "D:\\XXH\\Camera\\Canon-SX200IS\\Go3\\"};
const char delord[3][15][20] = {
    {"del ", "*.cmd", "*.vbs", "*.rar", "*.exe"},
    {"rmdir /s /q ", "Browser", "clash.meta", "clashB", "hysteria", "naiveproxy", "psiphon", "Xray", "singbox", "v2go", "v2ray", "v2rayB"},
};
inline void d_web()
{
    system("rmdir /s /q C:\\Users\\XuXixi\\Downloads");
    system("md C:\\users\\XuXixi\\Downloads");
    char ord[100];
    for (int i = 0; delord[i][0][0]; i++)
    {
        for (int j = 0; delpath[j][0]; j++)
        {
            for (int z = 1; delord[i][z][0]; z++)
            {
                strcpy(ord, delord[i][0]);
                strcat(ord, delpath[j]);
                strcat(ord, delord[i][z]);
                system(ord);
            }
        }
    }
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
    kill(0);
    d_web();
    keybd_event(20, 0, 0, 0);
    keybd_event(20, 0, KEYEVENTF_KEYUP, 0);
    res();
}
int main()
{
    printf("Successfully loaded!");
    Sleep(500);
    HWND hwnd = ::FindWindow("ConsoleWindowClass", NULL);
    if (hwnd)
    {
        ::ShowWindow(hwnd, SW_HIDE);
    }
    while (1)
    {
        if (GetKeyState(VK_SCROLL) && 0x001)
        {
            if (KEY_DOWN(191)) // '/'
            {
                dabao();
                return 0;
            }
            if (KEY_DOWN(66)) // 'B'
            {
                kill(0);
                once = 3;
            }
            if (KEY_DOWN(9)) // TAB
            {
                getmouse();
                once = 3;
            }
            if (KEY_DOWN(78)) //'N'
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
            if (KEY_DOWN(65)) //'A'
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
            if (KEY_DOWN(83)) // 'S'
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
            if (KEY_DOWN(188)) //'<'
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
            if (KEY_DOWN(190)) //'>'
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
            if (KEY_DOWN(90)) // 'Z'
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
                    once = 3;
                }
                continue;
            }
            if (KEY_DOWN(57)) //'9'
            {
                if (!once)
                {
                    d_web();
                    once = 3;
                }
            }
            for (int i = 0; i <= 8; i++)
            {
                if (KEY_DOWN(i + 48) && !once)
                {
                    kill(i);
                    once = 3;
                }
            }
            if (KEY_DOWN(20) || KEY_DOWN(192)) // Caps Lock / '`'
            {
                if (!once)
                {
                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                    once = 1;
                }
                continue;
            }
            if (KEY_DOWN(88)) //'X'
            {
                if (!once)
                {
                    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
                    once = 2;
                }
                continue;
            }
        }
        else
        {
            if (KEY_DOWN(191)) //'/'
            {
                if (!ji)
                {
                    ji = 1;
                    sta = clock();
                }
                else
                {
                    double tt = (double)(clock() - sta) / CLOCKS_PER_SEC;
                    if (tt > timer)
                    {
                        if (GetKeyState(VK_NUMLOCK) && 0x001)
                        {
                            keybd_event(144, 0, 0, 0);
                            keybd_event(144, 0, KEYEVENTF_KEYUP, 0);
                        }
                        dabao();
                        return 0;
                    }
                }
                continue;
            }
            if (KEY_DOWN(56) && !(GetKeyState(VK_NUMLOCK) && 0x001)) //'8'
            {
                if (!once)
                {
                    kill(8);
                    once = 3;
                    continue;
                }
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
        }
    }
}