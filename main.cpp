#include <iostream>
#include <cstdlib>
#include "Problem.cpp"
#include <queue>
#include <vector>

using namespace std;

//driver class
int main(){
	
	int choice;
	int puzzle[] = {1,2,0,4,5,3,7,8,6};

	cout << "Welcome to 861225171 8 puzzle solver." << endl << "Type 1 to use a default puzzle, or 2 to enter your own puzzle" << endl << endl;

	cin >> choice;
	Problem *p;
	if(choice == 1){
		p = new Problem(puzzle);
		cout << "Here is your puzzle" << endl;
		p->initial_state->print();
		
	}
	
	else if(choice == 2){
		cout << "Enter your puzzle, use a zero to represent a blank" << endl;
		cout << "Please press enter after each number entry" << endl;
		cout << "Numbers will be filled in from left to right, top to bottom";
		
		int entry;
		for (int i = 0; i < 9; i++){ 
			cin >> entry;
			puzzle[i] = entry;
		}

		p = new Problem(puzzle);
		
		cout << "Here is your puzzle" << endl;
		cout << endl << endl;
		p->initial_state->print();

	}

	int alg;
	
	cout << "Enter 1,2, or 3 for your choice of algorithm: " << endl;
	cout << "1 for Uniform Cost Search" << endl;
	cout << "2 for A* with Misplaced Tile Heuristic" << endl;
	cout << "3 for A* with Euclidean Distance Heuristic" << endl;

	cin >> alg;
	
	if(p->solve(alg)){
		cout << "success" << endl;
	}

	return 0;

}





