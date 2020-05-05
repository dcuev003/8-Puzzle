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
		
		vector<State> explored;
		
		priority_queue <State, vector<State>, greater<State> > frontier;
		
		int operators[4];//operators are move up, down, left, right respectiely

		Problem(){}

		Problem(int arr[9]){

			initial_state = new State(arr);
			


		}

		bool solve(int search){
			initial_state->calcF_n(search);
			frontier.push(*initial_state);
			vector<State> leaves;
			bool exp = false;
			int max = frontier.size();
			int expandedNodes = 0;
			while(!frontier.empty()){
				State *temp = new State(frontier.top());
				frontier.pop();
				if(temp->checkGoal()){
					temp->print();
					cout << "GOAL!!!" << endl << endl;
					cout << "Algorithm expanded a total of : " << expandedNodes << " nodes." << endl;
					cout << "The maximum number of nodes in the queue at any one time: " << max << "." << endl;
					return true;
				}
				explored.push_back(*temp);
				cout << "The best state to expand with g(n) = " << temp->g_n << " and h(n) = " << temp->h_n << " is..." << endl;
				temp->print();
				leaves = temp->expand();
				++expandedNodes;
				for(int i = 0; i < leaves.size(); i++){
					for(int j = 0; j < explored.size(); j++){
						if(leaves.at(i) != explored.at(j)){
							exp = true;
						}
						else{
							exp = false;
						}
					}
					if(exp){
						leaves.at(i).calcF_n(search);
						frontier.push(leaves.at(i));
					}
				
				}
				if(frontier.size() > max){
					max = frontier.size();
				}
								
			}

			cout << "FAILURE" << endl;
			return false;
			
		}			
			


};

#endif
