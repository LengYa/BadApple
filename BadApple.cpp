// BadApple.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

#pragma comment(lib,"winmm.lib")
int main()
{
	string filename = "BadApple.txt";
	string outdata;
	ifstream openfile;
	openfile.open(filename);
	if (!openfile.is_open())
	{
		cout << "Failed to open the file" << endl;
		return 0;
	}
	PlaySound(L"Apple.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //循环播放背景音乐 

	unsigned int col = 0;            //绘制到窗口多少信息，由它决定
	while (!openfile.eof())
	{
		system("cls");
		col = 0;
		while (col<35)
		{
			getline(openfile, outdata, '\n');
			cout <<outdata <<endl;
			++col;
		}
		Sleep(70);                 //延时一会,0.07s
	}
	return 0;
}
