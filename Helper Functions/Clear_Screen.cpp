//Clear Screen in C++

#include<iostream>
#include<stdlib.h> //Required Library 

using namespace std;

int main(){
	cout<<"This is a test window"<<endl;
	
	int input;
	cin>>input;
	
	if(input > 0)
		system("CLS");
	
	return 0;
}
