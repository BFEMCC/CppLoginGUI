
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

	hiex::Window mainmeu(640, 480, 4, L"������");

    hiex::SysButton btn;
    btn.Create(mainmeu.GetHandle(), 260, 185, 100, 30, L"�˳�");
    btn.SetFont(30 - 10, 0, L"΢���ź�");//����������ֺ�

    while (mainmeu.IsAlive())
    {
        Sleep(100);
        if (btn.IsClicked())
        {
            if (MessageBox(mainmeu.GetHandle(), L"�Ƿ�ȷ���˳�", L"��ʾ", MB_OKCANCEL | MB_ICONEXCLAMATION) == IDOK)
            {
                return 0;
            }
            continue;
        }
    }

}