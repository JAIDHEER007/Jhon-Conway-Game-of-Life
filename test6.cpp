//test6
//Screen Clear, keybordwait and program sleep

#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<thread>
#include<chrono>

using namespace std;

typedef vector<vector<bool>> vvb;

vvb current_gen;
vvb next_gen;
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
			cout<<((current_gen[i][j])?("1"):(" "));
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

bool rules(int i, int j){
	int lives = liveNeighbours(i,j); //Number of Live Neighbours around (i,j)
	
	if(current_gen[i][j]){ //Live Cell
		if((lives > 3) || (lives < 2))
			return false;
		else 
			return true;
	}else
		return (lives == 3);
}

void generationUpdate(){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			next_gen[i][j] = rules(i,j);
	}
	current_gen = next_gen;
}


int main(){
	ShowWindow(GetConsoleWindow() , SW_SHOWMAXIMIZED);
	
	row = 25;
	col = 130;
	
//	cin>>row>>col; //Row Max: 25 and Col Max: 15
	
	vvb arr;
	
	for(int i=0;i<row;i++){
		vector<bool> row;
		srand(time(0) * i);
		for(int j=0;j<col;j++){
			row.push_back((rand() % 2));
//			row.push_back(false);
		}
		arr.push_back(row);
	}
	
//	for(int i=5;i<=15;i+=2)
//		for(int j=10;j<=100;j++)
//			arr[i][j] = true; 
//	
	
	current_gen = next_gen = arr;
	
	print_gap();
	
	for(;;){
		generationUpdate();
//		getchar();
		this_thread::sleep_for(chrono::milliseconds(50));
		system("CLS");
		print_gap();
	}
	
	return 0;
}

