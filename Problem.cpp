#ifndef __PROBLEM_CPP__
#define __PROBLEM_CPP__


#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "State.cpp"
#include <queue>
using namespace std;

class Problem{

	public:
		State* initial_state;
		State* goal_state;
		vector<State> explored;
		
		priority_queue <State, vector<State>, greater<State> > frontier;
		
		int operators[4];//operators are move up, down, left, right respectiely

		Problem(int arr[]){
			int goal[] = {1,2,3,4,5,6,7,8,0};

			initial_state = new State(arr);
			
			goal_state = new State(goal);			

			for(int i = 0; i < 4; i++){
				operators[i] = i+1;
			}  

		}


		int solve(int search){
			initial_state->calcF_n(search);
			frontier.push(*initial_state);
			State *temp;
			vector<State> 

			vector<State> leaves;
			while(!frontier.empty()){
				temp = new State(frontier.top());
				temp->calcF_n(search);
				frontier.pop();
				if(temp->checkGoal()){
					cout << "GOAL!!!" << endl;
					return 1;
				}
				explored.push_back(*temp);										
	


			}
			cout << "FAILURE" << endl;
			return -1;
			
		}			
			


};

#endif
