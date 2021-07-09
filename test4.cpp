//test4
//Counting the live neighbours

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

bool inline isValidPoint(int i, int j){
	return (((i >= 0) && (i < row)) && ((j >= 0) && (j < col)));
}

int liveNeighbours(int i, int j){
	int lives = 0;
	for(int m=-1;m<=1;m++){
		for(int n=-1;n<=1;n++)
			if(isValidPoint((i+m),(j+n)))
				lives += (current_gen[(i+m)][(j+n)]);
	}
	return (lives - current_gen[i][j]);
}

void print_live_neighbours(){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			cout<<liveNeighbours(i, j)<<" ";
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
	
	print_live_neighbours();
	
	return 0;
}

