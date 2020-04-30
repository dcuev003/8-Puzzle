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

		int operators[4];//operators are move up, down, left, right respectiely
	public:
		Problem(int arr[]){

			int count = 1;
			for (int i = 0; i < 3; i++){ 
        			for (int j = 0; j < 3; j++){ 
            				goal_state[i][j] = count;
					count++; 
        			}			 
    			}
			goal_state[2][2] = 0;
		
			int num = 0;
			for (int i = 0; i < 3; i++){ 
        			for (int j = 0; j < 3; j++){
					initial_state[i][j] = arr[num];
					num++;  
        			} 
    			}

			for(int i = 0; i < 4; i++){
				operators[i] = i+1;
			}  

		}

		void print_initial(){
			for (int i = 0; i < 3; i++){
                                for (int j = 0; j < 3; j++){
                                        cout << initial_state[i][j] << " ";
                                }
				cout << endl;
                        }
		}



};

#endif
