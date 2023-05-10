#define _CRT_SECURE_NO_WARNINGS
#include "Login.h"
Login::Login()
{
    hiex::SetCustomIcon(MAKEINTRESOURCE(IDI_ICON1), MAKEINTRESOURCE(IDI_ICON1));
    LoginScreen.Create(WindowWidth, WindowHeight, EX_NOMINIMIZE, L"��¼");
    LoginCanva.InIt(WindowWidth, WindowHeight, WHITE);//���û�����ز���
    LoginScreen.BindCanvas(&LoginCanva);//�����ںͻ�����
    putimage(0, 0, &LoginCanva);//�������������������
    CreateEdit();
    CreatButton();
    LoginGIF();

    int i = 0;
    while (IfAlive())
    {
        LoginCanva.PutImageIn_Alpha(0, 0, &LoginGIFImg[i]);
        LoginScreen.Redraw();// �ػ洰��
        Sleep(100);
        i++;
        if (i == GIFFramesNum)
        {
            i = 0;
        }  
        if (LoginButton.IsClicked())
        {
            UserName = UserNameEdit.GetText();
            Password = PasswordEdit.GetText();
            if (UserName == AdministratorName && Password == AdministratorPassword)
            {
                IfLoginSuccess = true;
                MessageBox(GetHandle(), L"����Ա123456\n��¼��", L"��ʾ", MB_OK | MB_ICONASTERISK);
                LoginScreen.CloseWindow();
                break;
            }
            else
            {
                MessageBox(GetHandle(), L"�������", L"��ʾ", MB_OK | MB_ICONERROR);
            }
        }
    }
    if (!IfAlive() && !IfLoginSuccess)
    {
        exit(0);
    }

}

HWND Login::GetHandle()
{
    return LoginScreen.GetHandle();
}

bool Login::IfAlive()
{
    return LoginScreen.IsAlive();
}

Login::~Login()
{

}


void Login::CreateEdit()
{
    const int Uy = LeftTopY + EditHeight;
    const int Py = LeftTopY + (2 * EditHeight) + (EditHeight / 2);

    UserNameEdit.PreSetStyle(EditStyle);
    PasswordEdit.PreSetStyle(EditStyle);//��ʽ����

    UserNameEdit.Create(LoginScreen.GetHandle(), LeftTopX, Uy, EditWidth, EditHeight, L"");
    PasswordEdit.Create(LoginScreen.GetHandle(), LeftTopX, Py, EditWidth, EditHeight, L"");

    PasswordEdit.Password(true);//����Ϊ�����

    UserNameEdit.SetFont(FontSize, 0, Font);
    PasswordEdit.SetFont(FontSize, 0, Font);//�ֺţ���������

    UserNameEdit.SetMaxTextLength(UserNameMaxLen);
    PasswordEdit.SetMaxTextLength(PasswordMaxLen);//������볤������
    //edit.NumberOnly(if_only_number);//�Ƿ������

    const int PromptUserNameWidth = textwidth(PromptUserName);//�û�����ʾ���ֿ��
    int Tx = LeftTopX - PromptUserNameWidth;

    setbkmode(TRANSPARENT);//�������ֱ���ɫ͸��
    LoginCanva.SetTextStyle(20, 0, L"΢���ź�", 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE);

    LoginCanva.OutTextXY(Tx, Uy, PromptUserName, true, RGB(18, 183, 245));
    LoginCanva.OutTextXY(Tx, Py, PromptPassword, true, RGB(18, 183, 245));//ָ��λ�û�������
    LoginScreen.Redraw();// �ػ洰��
}

void Login::LoginGIF()
{
    for (int i = 0; i < GIFFramesNum; i++)
    {
        loadimage(&LoginGIFImg[i], L"PNG", MAKEINTRESOURCE(i + IDB_PNG1), WindowWidth, 130);
    }
}

void Login::CreatButton()
{
    LoginButton.Create(GetHandle(), LoginButtonX, LoginButtonY, LoginButtonW, LoginButtonH);//������ť
    int LoginButtonCanvaW = LoginButtonW - 6;
    int LoginButtonCanvaH = LoginButtonH - 6;
    LoginButtonCanva.InIt(LoginButtonCanvaW, LoginButtonCanvaH, RGB(6, 187, 252));//���ð�ť������ز���

    const int LoginButtonTextW = textwidth(LoginButtonText);//��¼��ť��ʾ���ֿ��
    const int LoginButtonTextH = textheight(LoginButtonText);//��¼��ť��ʾ���ָ߶�
    const int Tx = (LoginButtonCanvaW - LoginButtonTextW - 10) / 2;
    const int Ty = (LoginButtonCanvaH - LoginButtonTextH - 6) / 2;

    setbkmode(TRANSPARENT);//�������ֱ���ɫ͸��
    LoginButtonCanva.SetTextStyle(25, 0, L"΢���ź�", 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE);
    LoginButtonCanva.OutTextXY(Tx, Ty, LoginButtonText, true, WHITE);
    LoginButton.Image(true, &LoginButtonCanva, false);


}
