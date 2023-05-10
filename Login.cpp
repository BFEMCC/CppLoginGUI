#define _CRT_SECURE_NO_WARNINGS
#include "Login.h"
Login::Login()
{
    hiex::SetCustomIcon(MAKEINTRESOURCE(IDI_ICON1), MAKEINTRESOURCE(IDI_ICON1));
    LoginScreen.Create(WindowWidth, WindowHeight, EX_NOMINIMIZE, L"登录");
    LoginCanva.InIt(WindowWidth, WindowHeight, WHITE);//设置画布相关参数
    LoginScreen.BindCanvas(&LoginCanva);//将窗口和画布绑定
    putimage(0, 0, &LoginCanva);//将画布内容输出到窗口
    CreateEdit();
    CreatButton();
    LoginGIF();

    int i = 0;
    while (IfAlive())
    {
        LoginCanva.PutImageIn_Alpha(0, 0, &LoginGIFImg[i]);
        LoginScreen.Redraw();// 重绘窗口
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
                MessageBox(GetHandle(), L"管理员123456\n登录！", L"提示", MB_OK | MB_ICONASTERISK);
                LoginScreen.CloseWindow();
                break;
            }
            else
            {
                MessageBox(GetHandle(), L"密码错误！", L"提示", MB_OK | MB_ICONERROR);
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
    PasswordEdit.PreSetStyle(EditStyle);//样式设置

    UserNameEdit.Create(LoginScreen.GetHandle(), LeftTopX, Uy, EditWidth, EditHeight, L"");
    PasswordEdit.Create(LoginScreen.GetHandle(), LeftTopX, Py, EditWidth, EditHeight, L"");

    PasswordEdit.Password(true);//设置为密码框

    UserNameEdit.SetFont(FontSize, 0, Font);
    PasswordEdit.SetFont(FontSize, 0, Font);//字号，字体设置

    UserNameEdit.SetMaxTextLength(UserNameMaxLen);
    PasswordEdit.SetMaxTextLength(PasswordMaxLen);//最大输入长度设置
    //edit.NumberOnly(if_only_number);//是否仅数字

    const int PromptUserNameWidth = textwidth(PromptUserName);//用户名提示文字宽度
    int Tx = LeftTopX - PromptUserNameWidth;

    setbkmode(TRANSPARENT);//设置文字背景色透明
    LoginCanva.SetTextStyle(20, 0, L"微软雅黑", 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE);

    LoginCanva.OutTextXY(Tx, Uy, PromptUserName, true, RGB(18, 183, 245));
    LoginCanva.OutTextXY(Tx, Py, PromptPassword, true, RGB(18, 183, 245));//指定位置绘制文字
    LoginScreen.Redraw();// 重绘窗口
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
    LoginButton.Create(GetHandle(), LoginButtonX, LoginButtonY, LoginButtonW, LoginButtonH);//创建按钮
    int LoginButtonCanvaW = LoginButtonW - 6;
    int LoginButtonCanvaH = LoginButtonH - 6;
    LoginButtonCanva.InIt(LoginButtonCanvaW, LoginButtonCanvaH, RGB(6, 187, 252));//设置按钮画布相关参数

    const int LoginButtonTextW = textwidth(LoginButtonText);//登录按钮提示文字宽度
    const int LoginButtonTextH = textheight(LoginButtonText);//登录按钮提示文字高度
    const int Tx = (LoginButtonCanvaW - LoginButtonTextW - 10) / 2;
    const int Ty = (LoginButtonCanvaH - LoginButtonTextH - 6) / 2;

    setbkmode(TRANSPARENT);//设置文字背景色透明
    LoginButtonCanva.SetTextStyle(25, 0, L"微软雅黑", 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE);
    LoginButtonCanva.OutTextXY(Tx, Ty, LoginButtonText, true, WHITE);
    LoginButton.Image(true, &LoginButtonCanva, false);


}
