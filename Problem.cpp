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

/*struct CompareStates{
	bool operator()(State const& l, State const& r){
		return l.f_n > r.f_n;
	}
};*/

class Problem{

	public:
		State* initial_state;
		
		priority_queue <State, vector<State>, greater<State>  > frontier;
		
		Problem(){}
		
		//creates Problem and instntiates initial state
		Problem(int arr[]){

			initial_state = new State(arr);
			


		}
	
		//main algorithm that uses A*search
		bool solve(int search){
			vector<State> explored;//vecotr to store explored nodes
			initial_state->calcF_n(search);//calculates f_n for initial state
			
			frontier.push(*initial_state);
			vector<State> leaves;//vector to keep expanded nodes
			bool exp = false;//checking if node is in explored set
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
				delete temp;
				for(int i = 0; i < leaves.size(); i++){
					for(int j = 0; j < explored.size(); j++){
						if(leaves.at(i).compare(explored.at(j))){
							exp = false;
						}
						else{
							exp = true;
						}
					}
					if(exp){
						leaves.at(i).calcF_n(search);
						frontier.push(leaves.at(i));
					}
				
				}
				//clear nodes that were previously expanded
				leaves.clear();
				
				if(frontier.size() > max){
					max = frontier.size();
				}
								
			}

			cout << "FAILURE" << endl;
			return false;	
		}			
			


};

#endif
