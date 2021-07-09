//test7
//Added color and doubled the space
//But the number of cols are reduced by 2

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

void color(int ForgC = 7, int BackC = 0){
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
               //Get the handle to the current output buffer...
 	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
 	SetConsoleTextAttribute(hStdOut, wColor);
}

void print(){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			cout<<current_gen[i][j]<<" ";
		cout<<endl;
	}
}

void print_gap(){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(current_gen[i][j])
				color(15,15);
			cout<<"  ";
			color();
		}
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
	col = 65;
	//Row Max: 25 and Col Max: 65 for Font size of 16
	//Row Max: 100 and Col Max: 220 for Font size of 5
	
//	cin>>row>>col; 

	
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
	
//	for(int i=10;i<=15;i++)
//		for(int j=20;j<=22;j++)
//			arr[i][j] = true; 
	
	
	current_gen = next_gen = arr;
	
	print_gap();
	
	for(;;){
		generationUpdate();
		getchar();
//		this_thread::sleep_for(chrono::milliseconds(50));
		system("CLS");
		print_gap();
	}
	
	return 0;
}

