//Maximizing a window in C++

#include<iostream>
#include<windows.h> //Required Header File
using namespace std;

void maximizeWindow(){
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}

int main(){
	maximizeWindow(); //Call this Function Before Any code Executes
	
//	ShowWindow(GetConsoleWindow() , SW_SHOWMAXIMIZED); 
// 	Direct Command to avoid Function call
	
	for(int i=1;i<=25;i++){
		for(int j=1;j<15;j++)
			cout<<0<<"\t";
		cout<<endl;
	}
	
	return 0;
}

