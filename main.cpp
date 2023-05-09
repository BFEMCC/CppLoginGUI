
#include <winsock2.h>
#include <ws2tcpip.h>
#include <Windows.h>
#include <iostream>
#include "HiEasyX.h"
#include "resource.h"
#include "Login.h"
#pragma comment(lib,"ws2_32.lib")

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdLine, _In_ int nCmdShow)
{
	Login login;

	hiex::Window mainmeu(640, 480, 4, L"主界面");

    hiex::SysButton btn;
    btn.Create(mainmeu.GetHandle(), 260, 185, 100, 30, L"退出");
    btn.SetFont(30 - 10, 0, L"微软雅黑");//设置字体和字号

    while (mainmeu.IsAlive())
    {
        Sleep(100);
        if (btn.IsClicked())
        {
            if (MessageBox(mainmeu.GetHandle(), L"是否确认退出", L"提示", MB_OKCANCEL | MB_ICONEXCLAMATION) == IDOK)
            {
                return 0;
            }
            continue;
        }
    }

}