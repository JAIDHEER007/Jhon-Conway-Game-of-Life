//Testing Font Size
#include<iostream>
#include<windows.h>
using namespace std;

//Valid Sizes
/*
4:6
6:8
8:8
16:8
5:12
7:12
16:12
12:16
10:18
*/
void setFontSize(int x=10, int y=18){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);  
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
  	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
  	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
  	lpConsoleCurrentFontEx->dwFontSize.X = x;  
  	lpConsoleCurrentFontEx->dwFontSize.Y = y;  
  	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
}

int main(){
	setFontSize(5,12);
	cout<<"This is a test"<<endl;

	return 0;
}

