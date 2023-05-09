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

	hiex::Window LoginScreen;															//��¼����
	const int WindowWidth = 430;														//���ڿ��
	const int WindowHeight = 300;														//���ڸ߶�

	hiex::Canvas LoginCanva;															//��¼���ڻ���

	hiex::SysEdit UserNameEdit;															//�û����ı���
	hiex::SysEdit PasswordEdit;															//�����ı���
	const int UserNameMaxLen = 10;														//�û����ı���������볤������
	const int PasswordMaxLen = 16;														//�����ı���������볤������
	const LPCTSTR PromptUserName = L"�û���";											//�û�����ʾ����
	const LPCTSTR PromptPassword = L"��  ��";											//������ʾ����

	/*-------------�ı��򹫹�����(�û����ı���������ı������λ�ù̶�)----------------*/
	const int EditWidth = 240;															//�û����ı��� ���
	const int EditHeight = 25;															//�û����ı��� �߶�
	const int LeftTopX = ((WindowWidth - EditWidth) / 2);								//�û����ı��� ����X����
	const int LeftTopY = (WindowHeight - (3 * EditHeight)) / 2;							//�û����ı��� ����Y����
	const int FontSize = 20;															//�û����ı��� �����С
	const hiex::SysEdit::PreStyle EditStyle{ false, false, false, false, false, true };	//�ı�����ʽ//bool�������壺�����ı����ı����С�ӵ�д�ֱ���������Զ���ֱ������ӵ��ˮƽ���������Զ�ˮƽ����
	const std::wstring Font = L"΢���ź�";												//����
	
	/*---------------------------------------------------------------------------------*/
	hiex::SysButton LoginButton;														//��¼��ť
	int LoginButtonX = LeftTopX;														//��¼��ť����X����
	int LoginButtonY = 245;																//��¼��ť����Y����
	int LoginButtonW = EditWidth;														//��¼��ť���
	int LoginButtonH = 35;																//��¼��ť�߶�
	hiex::Canvas LoginButtonCanva;														//��¼��ť����
	LPCTSTR LoginButtonText = L"�� ¼";													//��¼��ť����

	hiex::SysButton RegisterButton;														//ע�ᰴť

	const int Registerkey = 32119;														//ע�������Կ
	static const int GIFFramesNum = 12;													//GIF��֡ͼƬ����
	IMAGE LoginGIFImg[GIFFramesNum];														//��¼������ͼ
	bool IfLoginSuccess = false;														//�Ƿ�ɹ���¼
	
	/*----------------------------------˽�г�Ա����-----------------------------------*/
	void CreateEdit();																	//�����ı���
	void LoginGIF();																		//���ض�ͼ
	void CreatButton();																	//������ť

protected:
	std::wstring UserName;																//�û���
	std::wstring Password;																//����
	std::wstring AdministratorName = L"123456";											//����Ա�û���
	std::wstring AdministratorPassword = L"123456";										//����Ա����
};

