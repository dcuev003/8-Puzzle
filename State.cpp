#ifndef __STATE_CPP_
#define __STATE_CPP_

#include <iostream>
#include <cstdlib>

using namespace std;

class State{
	public:

	int current[3][3];
	int g_n;
	int h_n;
	
	bool op1;
	bool op2;
	bool op3;
	bool op4;
	
	State(int arr[]){

		g_n = 0;
		h_n = 0;
		op1 = true;
		op1 = true;
		op1 = true;
		op1 = true;
		
		int num = 0;

		for(int i = 0; i < 3; i++){ 
        		for (int j = 0; j < 3; j++){
				current[i][j] = arr[num];
				num++;  
        		} 
    		}
	}

	
	void checkMoves(){
		int i2;
		int j2;
		bool end = false;
		for (int i = 0; i < 3; i++){ 
        		for (int j = 0; j < 3; j++){
				if(current[i][j] = 0){
					end = true;
					i2 = i;
					j2 = j;
					break;
        			} 
    			}
			if(end){
				break;
			}
		}

		if(i2 = 0){
			op1 = false;
		}
		if(i2 = 2){
			op2 = false;
		}
		if(j2 = 0){
			op3 = false;
		}
		if(j2 = 2){
			op4 = false;
		}
	}
	
		

	void print(){
		for(int i = 0; i < 3; i++){
                	for (int j = 0; j < 3; j++){
                        	cout << current[i][j] << " ";
                        }
			cout << endl;
                }	
	}



};
#endif
