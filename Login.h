#pragma once
#include"HiEasyX.h"
#include "resource.h"

class Login
{
public:
	Login();
	HWND GetHandle();
	bool IfAlive();
	~Login();
private:

	hiex::Window LoginScreen;															//登录窗口
	const int WindowWidth = 430;														//窗口宽度
	const int WindowHeight = 300;														//窗口高度

	hiex::Canvas LoginCanva;															//登录窗口画布

	hiex::SysEdit UserNameEdit;															//用户名文本框
	hiex::SysEdit PasswordEdit;															//密码文本框
	const int UserNameMaxLen = 10;														//用户名文本框最大输入长度限制
	const int PasswordMaxLen = 16;														//密码文本框最大输入长度限制
	const LPCTSTR PromptUserName = L"用户名";											//用户名提示文字
	const LPCTSTR PromptPassword = L"密  码";											//密码提示文字

	/*-------------文本框公共属性(用户名文本框和密码文本框相对位置固定)----------------*/
	const int EditWidth = 240;															//用户名文本框 宽度
	const int EditHeight = 25;															//用户名文本框 高度
	const int LeftTopX = ((WindowWidth - EditWidth) / 2);								//用户名文本框 左上X坐标
	const int LeftTopY = (WindowHeight - (3 * EditHeight)) / 2;							//用户名文本框 左上Y坐标
	const int FontSize = 20;															//用户名文本框 字体大小
	const hiex::SysEdit::PreStyle EditStyle{ false, false, false, false, false, true };	//文本框样式//bool参数含义：多行文本、文本居中、拥有垂直滚动条、自动垂直滚动、拥有水平滚动条、自动水平滚动
	const std::wstring Font = L"微软雅黑";												//字体
	
	/*---------------------------------------------------------------------------------*/
	hiex::SysButton LoginButton;														//登录按钮
	int LoginButtonX = LeftTopX;														//登录按钮左上X坐标
	int LoginButtonY = 245;																//登录按钮左上Y坐标
	int LoginButtonW = EditWidth;														//登录按钮宽度
	int LoginButtonH = 35;																//登录按钮高度
	hiex::Canvas LoginButtonCanva;														//登录按钮画布
	LPCTSTR LoginButtonText = L"登 录";													//登录按钮文字

	hiex::SysButton RegisterButton;														//注册按钮

	const int Registerkey = 32119;														//注册许可密钥
	static const int GIFFramesNum = 12;													//GIF拆帧图片数量
	IMAGE LoginGIFImg[GIFFramesNum];														//登录背景动图
	bool IfLoginSuccess = false;														//是否成功登录
	
	/*----------------------------------私有成员函数-----------------------------------*/
	void CreateEdit();																	//创建文本框
	void LoginGIF();																		//加载动图
	void CreatButton();																	//创建按钮

protected:
	std::wstring UserName;																//用户名
	std::wstring Password;																//密码
	std::wstring AdministratorName = L"123456";											//管理员用户名
	std::wstring AdministratorPassword = L"123456";										//管理员密码
};

