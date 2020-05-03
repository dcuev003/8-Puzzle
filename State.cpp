#ifndef __STATE_CPP_
#define __STATE_CPP_

#include <iostream>
#include <cstdlib>

using namespace std;

class State{
	int current[3][3];
	int g_n;
	int h_n;
	
	
	State(int arr[]){

		g_n = 0;
		h_n = 0;
		
		int num = 0;

		for(int i = 0; i < 3; i++){ 
        		for (int j = 0; j < 3; j++){
				current[i][j] = arr[num];
				num++;  
        		} 
    		}
	}

	


};
#endif
