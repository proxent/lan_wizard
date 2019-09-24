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
		printf("기존 설정을 제거하는 중입니다...\n");
			system("netsh wlan delete profile name=\"Hana\"");
		printf("프로필 파일을 적용하는 중입니다....\n");
		sprintf(commands, "netsh wlan add profile filename=\"Wi-Fi-Hana.xml\" interface=\"Wi-Fi\" user=current");
		system(commands);
		printf("무선 네트워크 연결을 테스트하는 중입니다...\n");

		sprintf(commands2, "netsh wlan connect name=Hana ssid=Hana interface=\"Wi-Fi\" ");
		printf("설정 적용을 끝마칩니다.\n\n\t이제 \'Hana\'에 접속해보세요.\n\n");
		system(commands2);
	}

	else{
		printf("기존 파일을 제거하는 중입니다...\n");
		system("netsh wlan delete profile name=\"Hana\"");
		printf("프로필 파일을 적용하는 중입니다....\n");
		sprintf(commands, "netsh wlan add profile filename=\"Wi-Fi-Hana.xml\" interface=\"무선 네트워크 연결\" user=current");
		system(commands);
		printf("무선 네트워크 연결을 테스트하는 중입니다...\n");
		sprintf(commands2, "netsh wlan connect name=Hana ssid=Hana interface=\"무선 네트워크 연결\" ");
		system(commands2);
		printf("설정 적용을 끝마칩니다.\n\n\t이제 \'Hana\'에 접속해보세요.\n\n");

	}

	free(commands);
	free(commands2);
	free(commands3);
	system("pause");


	return 0;
}