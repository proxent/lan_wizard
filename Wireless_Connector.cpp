#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996) 
int main(int argc, char *argv[])
{
	srand(time(NULL));


	OSVERSIONINFO osvi;
	BOOL bIsWindows8orLater;

	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx(&osvi);

	char *commands;
	char *commands2;
	char *commands3;

	commands = (char *)malloc(sizeof(char *)* 128);
	commands2 = (char *)malloc(sizeof(char *)* 128);
	commands3 = (char *)malloc(sizeof(char *)* 128);

	bIsWindows8orLater = (

		((osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion >= 2))

		);

	if (bIsWindows8orLater){
		printf("���� ������ �����ϴ� ���Դϴ�...\n");
			system("netsh wlan delete profile name=\"Hana\"");
		printf("������ ������ �����ϴ� ���Դϴ�....\n");
		sprintf(commands, "netsh wlan add profile filename=\"Wi-Fi-Hana.xml\" interface=\"Wi-Fi\" user=current");
		system(commands);
		printf("���� ��Ʈ��ũ ������ �׽�Ʈ�ϴ� ���Դϴ�...\n");

		sprintf(commands2, "netsh wlan connect name=Hana ssid=Hana interface=\"Wi-Fi\" ");
		printf("���� ������ ����Ĩ�ϴ�.\n\n\t���� \'Hana\'�� �����غ�����.\n\n");
		system(commands2);
	}

	else{
		printf("���� ������ �����ϴ� ���Դϴ�...\n");
		system("netsh wlan delete profile name=\"Hana\"");
		printf("������ ������ �����ϴ� ���Դϴ�....\n");
		sprintf(commands, "netsh wlan add profile filename=\"Wi-Fi-Hana.xml\" interface=\"���� ��Ʈ��ũ ����\" user=current");
		system(commands);
		printf("���� ��Ʈ��ũ ������ �׽�Ʈ�ϴ� ���Դϴ�...\n");
		sprintf(commands2, "netsh wlan connect name=Hana ssid=Hana interface=\"���� ��Ʈ��ũ ����\" ");
		system(commands2);
		printf("���� ������ ����Ĩ�ϴ�.\n\n\t���� \'Hana\'�� �����غ�����.\n\n");

	}

	free(commands);
	free(commands2);
	free(commands3);
	system("pause");


	return 0;
}