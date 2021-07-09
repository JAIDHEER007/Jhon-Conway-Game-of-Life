//Bool Array 
//Random Function
//Added print with gaps function

#include<iostream>
#include <windows.h>
#include<stdlib.h>
#include<time.h>
#include<vector>

using namespace std;

typedef vector<vector<bool>> vvb;

vvb current_gen;
int row;
int col; 

void print(){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			cout<<current_gen[i][j]<<" ";
		cout<<endl;
	}
}

void print_gap(){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			cout<<((current_gen[i][j])?("1"):(" "))<<" ";
		cout<<endl;
	}
}

int main(){
	ShowWindow(GetConsoleWindow() , SW_SHOWMAXIMIZED);
	
	cin>>row>>col; //Row Max: 25 and Col Max: 15
	
	vvb arr;
	
	for(int i=0;i<row;i++){
		vector<bool> row;
		srand(time(0) * i);
		for(int j=0;j<col;j++)
			row.push_back((rand() % 2));
		arr.push_back(row);
	}
	
	current_gen = arr;
	
	print();
	
	cout<<endl<<endl;
	
	print_gap();
	
	return 0;
}

