#include <iostream>
#include <cstdlib>
#include "Problem.cpp"
#include <queue>

using namespace std;

//driver class
int main(){

	

	/*int arr[] = {8,7,6,5,4,3,2,1,0};
	int arr2[] = {1,3,2,4,5,6,7,8,0};
	int arr3[] = {1,2,4,3,5,6,7,8,0}; 
	State n(arr);
	State m(arr2);
	State o(arr3);
	
	n.calcF_n(3);
	m.calcF_n(3);
	o.calcF_n(3);

	cout << n.f_n << endl;
	cout << m.f_n << endl;
	cout << o.f_n << endl << endl;

	priority_queue <State, vector<State>, greater<State> > frontier;

	frontier.push(o);
	frontier.push(n);
	frontier.push(m);

	cout << frontier.top().f_n << endl;
	frontier.pop();
	cout << frontier.top().f_n << endl;	
	frontier.pop();
	cout << frontier.top().f_n << endl;*/

	int choice;
	int puzzle[9] = {1,3,0,2,4,7,5,6,8};

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





