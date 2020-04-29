#ifndef __PROBLEM_CPP__
#define __PROBLEM_CPP__


#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

class Problem{

	private:
		int initial_state[3][3];
		int goal_state[3][3];

		int operators[4] = {1,2,3,4} //operators are move up, down, left, right respectiely
	public:
		Problem(){
			srand(time(NULL)); //seed random for no repetition
			vector<int> visited; //used for no repetition in initial state

			int count = 1;
			for (int i = 0; i < 3; i++){ 
        			for (int j = 0; j < 3; j++){ 
            				goal_state[i][j] = count;
					count++; 
        			}			 
    			}


			for (int i = 0; i < 3; i++){ 
        			for (int j = 0; j < 3; j++){
					initial_state[i][j]  
        			} 
    			}  

		}



};

#endif
