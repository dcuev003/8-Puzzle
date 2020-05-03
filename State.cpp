#ifndef __STATE_CPP_
#define __STATE_CPP_

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

class State{
	public:

	int current[3][3];
	double g_n;
	double h_n;
	double f_n;
		
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
		
	
	double euclideanDistance(double v1, double v2, double v3, double v4){
		double f = v3 - v1;
		double g = v4 - v2;
		double d;
		d = pow(f,2) + pow(g,2);
		d = sqrt(d);

		return d;
	}
		
	void calcF_n(int search){
		int goal[] = {1,2,3,4,5,6,7,8,0};
		int eucl[3][3] = {{1,2,3}{4,5,6}{7,8,0}};
		if(search == 1){
			h_n = 0;
		}
		else if(search == 2){
			int num = 0;
			for(int i = 0; i < 3; i++){ 
        			for (int j = 0; j < 3; j++){
					if((current[i][j] != 0) && (current[i][j] != goal[num])){
						h_n++;
					}
					num++;  
        			}	 
    			}
		}
		else{
			double x1,x2,y1,y2,val;
			bool check = false;
			for(int i = 0; i < 3; i++){ 
        			for (int j = 0; j < 3; j++){
					if((current[i][j] != 0) && (current[i][j] != eucl[i][j])){
						val = current[i][j];
						x1 = i;
						y1 = j;
	  					for(int f = 0; f < 3; f++){ 
        						for (int h = 0; h < 3; h++){
								if(eucl[f][h] == val){
									check = true;
									x2 = f;
									y2 = h;
									break;
								}
        						}
							if(check){break;} 
    						}
						h_n += euclideanDistance(x1,y1,x2,y2);
					}
        			}	 
    			}
		}
		
		f_n = g_n + h_n;	
				 
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
