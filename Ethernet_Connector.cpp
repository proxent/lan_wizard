#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
int main(int argc, char *argv[])
{
    srand(time(NULL));


    OSVERSIONINFO osvi;
    BOOL bIsWindowsXPorLater;

    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

    GetVersionEx(&osvi);
	
	int randomical,b;
    int i;

    randomical=0;

    char *commands;
    char *commands2;
	char *address_ip;

    commands=(char *)malloc(sizeof(char *)*256);
    commands2=(char *)malloc(sizeof(char *)*256);
	address_ip=(char *)malloc(sizeof(char *)*256);

    printf("도서관 좌석에 기입된 값을 입력해주세요!\n");
	printf("IP:");
	scanf("%s",address_ip);
 /*   randomical=rand()%120;
    randomical+=51;


    if(randomical==114)
    {
                        while(randomical==114)
                       {
                                             randomical=rand()%120;
                                             randomical+=51;
                       }
    }

	*/
    bIsWindowsXPorLater =(
       ( (osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion >= 2) )
                          );

    if(bIsWindowsXPorLater){
								system("@echo off");
								sprintf(commands,"netsh interface ipv4 set address name=\"이더넷\" static %s 255.255.254.0 10.26.29.254",address_ip);

								printf("IP를 할당하는 중입니다..\n\n");


								system(commands);

								printf("주 DNS 서버를 설정하는 중입니다..\n\n");

								sprintf(commands2,"netsh interface ipv4 set dnsservers name=\"이더넷\" static 168.126.63.1 primary");
								system(commands2); 

								/* printf("보조 DNS 서버를 설정하는 중입니다.. \n\n");

								sprintf(commands2,"netsh interface ipv4 set dnsservers name="""이더넷"" static 210.220.16.6 both");
								system(commands2);
								*/
								printf("완료되었습니다. \n");
	}
	else{
								system("@echo off");
								
								sprintf(commands, "netsh interface ipv4 set address name=\"로컬 영역 연결\" static %s 255.255.254.0 10.26.29.254", address_ip);
								printf("IP를 할당하는 중입니다..\n\n");

								system(commands);

								printf("주 DNS 서버를 설정하는 중입니다..\n\n");
								sprintf(commands2,"netsh interface ipv4 set dnsservers name=\"로컬 영역 연결\" static 168.126.63.1 primary");
								system(commands2);

								/* printf("보조 DNS 서버를 설정하는 중입니다.. \n\n");

								sprintf(commands2,"netsh interface ipv4 set dnsservers name=""""로컬 영역 연결" static 210.220.16.6 second");
								system(commands2);
								*/
								printf("완료되었습니다. \n");

	}

	free(commands2);
	free(commands);
	
	system("pause");


    return 0;
} 
