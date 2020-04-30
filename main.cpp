#include <iostream>
#include <cstdlib>
#include "Problem.cpp"

using namespace std;

int main(){

	
	int choice;
	int puzzle[9] = {1,3,0,2,4,7,5,6,8};

	cout << "Welcome to 861225171 8 puzzle solver." << endl << "Type 1 to use a default puzzle, or 2 to enter your own puzzle" << endl << endl;

	cin >> choice;

	if(choice == 1){
		Problem *p = new Problem(puzzle);
		cout << "Here is your puzzle" << endl;
		p->print_initial();
	}
	
	else if(choice == 2){
		cout << "Enter your puzzle, use a zero to represent a blank" << endl;
		cout << "Please press enter after each number entry" << endl;
		cout << "Numbers will be filled in from left to right, top to bottwom" << endl;
		
		int entry;
		for (int i = 0; i < 9; i++){ 
			cin >> entry;
			puzzle[i] = entry;
		}

		Problem *p = new Problem(puzzle);
		
		cout << "Here is your puzzle" << endl;
		p->print_initial();

	}
	int alg;
	cout << "Enter 1,2, or 3 for your choice of algorithm: " << endl;
	cout << "1 for Uniform Cost Search" << endl;
	cout << "2 for A* with Misplaced Tile Heuristic" << endl;
	cout << "3 for A* with Euclidean Distance Heuristic" << endl;


	return 0;

}
