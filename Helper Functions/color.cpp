//Program to print every color

#include<iostream>
#include<stdio.h> //for using printf
#include<windows.h>
using namespace std;

void color(int ForgC = 7, int BackC = 0){
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
               //Get the handle to the current output buffer...
 	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
 	SetConsoleTextAttribute(hStdOut, wColor);
}

int main(){
	color(6,1);
	cout<<"J";
	color(1,6);
	cout<<"A";
	color();
	cout<<endl;
	color(); //Resets to default
	
	cout<<endl<<"Default"<<endl;
	
	return 0;
}
