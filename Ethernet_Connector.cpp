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

    printf("������ �¼��� ���Ե� ���� �Է����ּ���!\n");
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
								sprintf(commands,"netsh interface ipv4 set address name=\"�̴���\" static %s 255.255.254.0 10.26.29.254",address_ip);

								printf("IP�� �Ҵ��ϴ� ���Դϴ�..\n\n");


								system(commands);

								printf("�� DNS ������ �����ϴ� ���Դϴ�..\n\n");

								sprintf(commands2,"netsh interface ipv4 set dnsservers name=\"�̴���\" static 168.126.63.1 primary");
								system(commands2); 

								/* printf("���� DNS ������ �����ϴ� ���Դϴ�.. \n\n");

								sprintf(commands2,"netsh interface ipv4 set dnsservers name="""�̴���"" static 210.220.16.6 both");
								system(commands2);
								*/
								printf("�Ϸ�Ǿ����ϴ�. \n");
	}
	else{
								system("@echo off");
								
								sprintf(commands, "netsh interface ipv4 set address name=\"���� ���� ����\" static %s 255.255.254.0 10.26.29.254", address_ip);
								printf("IP�� �Ҵ��ϴ� ���Դϴ�..\n\n");

								system(commands);

								printf("�� DNS ������ �����ϴ� ���Դϴ�..\n\n");
								sprintf(commands2,"netsh interface ipv4 set dnsservers name=\"���� ���� ����\" static 168.126.63.1 primary");
								system(commands2);

								/* printf("���� DNS ������ �����ϴ� ���Դϴ�.. \n\n");

								sprintf(commands2,"netsh interface ipv4 set dnsservers name=""""���� ���� ����" static 210.220.16.6 second");
								system(commands2);
								*/
								printf("�Ϸ�Ǿ����ϴ�. \n");

	}

	free(commands2);
	free(commands);
	
	system("pause");


    return 0;
} 
