// test.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include "stdio.h"  
#include <string.h>
#define UseDebugView
#ifdef UseDebugView
#include "windows.h"
char g_Debug[256];
#endif 
void OutputDebugPrintf(const char * strOutputString, ...);
void OutputDebugPrintf(const char * strOutputString, ...)
{
	char strBuffer[4096] = { 0 };
	va_list vlArgs;
	va_start(vlArgs, strOutputString);
	_vsnprintf_s(strBuffer, sizeof(strBuffer) - 1, strOutputString, vlArgs);
	va_end(vlArgs);
	OutputDebugStringA(strBuffer);
}

int main()
{
	OutputDebugPrintf("DEBUG_INFO | %d %s", 600019, "tangxg");
	int sum = 0;
	#ifdef UseDebugView
		sprintf_s(g_Debug, 256, "test---��ѭ����͡�[In]\n");
		OutputDebugStringA("�ҽ����ӽ�");
	#endif
	for (int i = 0; i < 5; i++)
	{
		sum += i; 
	}
	#ifdef UseDebugView
		sprintf_s(g_Debug, 256, "test--��ѭ����͡�[Out]\n");
		OutputDebugStringA("�ҽ����ӽ�");
	#endif 
	return 0;
}



