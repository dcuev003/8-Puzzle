#ifndef __STATE_CPP_
#define __STATE_CPP_

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>

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
	
	State(){}
	//default constructor
	State(int arr[9]){
		
		g_n = 0;
		h_n = 0;
		f_n = 0;

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

	//copy constructor
	State(const State &s){
		for(int i = 0; i < 3; i++){
                	for (int j = 0; j < 3; j++){
                        	this->current[i][j] = s.current[i][j];

                        }
                }

                this->g_n = s.g_n;
                this->h_n = s.h_n;
                this->f_n = s.f_n;

                this->op1 = s.op1;
                this->op2 = s.op2;
                this->op3 = s.op3;
                this->op4 = s.op4;
	}



	//overload assignment operator
	State& operator=(const State &s){
		if(this != &s){
			for(int i = 0; i < 3; i++){ 
        			for (int j = 0; j < 3; j++){
					current[i][j] = s.current[i][j];
					  
        			} 
    			}

        		this->g_n = s.g_n;
        		this->h_n = s.h_n;
        		this->f_n = s.f_n;

        		this->op1 = s.op1;
        		this->op2 = s.op2;
        		this->op3 = s.op3;
        		this->op4 = s.op4;
		}

		return *this;
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

		int eucl[3][3] = {{1,2,3},{4,5,6},{7,8,0}};

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
	
	
	bool checkGoal(){
		int goal[] = {1,2,3,4,5,6,7,8,0};

		int num = 0;
		for(int i = 0; i < 3; i++){ 
        		for (int j = 0; j < 3; j++){
				if(current[i][j] != goal[num]){
					return false;
				}
				num++;  
        		}	 
    		}
		return true;
	}

	void checkMoves(){
		int i2;
		int j2;
		bool end = false;
		for (int i = 0; i < 3; i++){ 
        		for (int j = 0; j < 3; j++){
				if(current[i][j] = 0){
					end = true;
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

	State swap(int x, int y, int move){
		int temp[3][3];
		int hold;
		int arr[9];
		
		for(int i = 0; i < 3; i++){ 
        		for (int j = 0; j < 3; j++){
				temp[i][j] = current[i][i];  
        		} 
    		}

		if(move == 1){
			hold = temp[x-1][y];
			temp[x-1][y] = 0;
			temp[x][y] = hold;
		}
		else if(move == 2){
                        hold = temp[x+1][y];
                        temp[x+1][y] = 0;
                        temp[x][y] = hold;
                }
		else if(move == 3){
                        hold = temp[x][y-1];
                        temp[x][y-1] = 0;
                        temp[x][y] = hold;
                }
		else{
                        hold = temp[x][y+1];
                        temp[x][y+1] = 0;
                        temp[x][y] = hold;
                }

		int num = 0; 
		for(int i = 0; i < 3; i++){ 
        		for (int j = 0; j < 3; j++){
				arr[num] = temp[i][j];
				num++;  
        		} 
    		}	
		
		State *n = new State(arr);

		return *n;			 	
	}
	
	vector<State> expand(){
		cout << "Expanding state" << endl;
		this->print();
		vector<State> v;
		int x,y; //location of blank
		bool end;
		for(int i = 0; i < 3; i++){ 
        		for (int j = 0; j < 3; j++){
				if(current[i][j] == 0){
					end = true;
                                        x = i;
                                        y = j;
                                        break;
				}
        		}
			if(end){break;}
	 	}

		this->checkMoves();
		if(op1){
			State *a = new State(swap(x,y,1));
			a->g_n = this->g_n + 1;
			v.push_back(*a);
		}
		if(op2){
			State *b = new State(swap(x,y,2));
			b->g_n = this->g_n + 1;
			v.push_back(*b);
		}
		if(op3){
			State *c = new State(swap(x,y,3));
			c->g_n = this->g_n + 1;
			v.push_back(*c);
		}
		if(op4){
			State *d = new State(swap(x,y,4));
			d->g_n = this->g_n + 1;
			v.push_back(*d);
		}

		return v;
	}		

	void print(){
		for(int i = 0; i < 3; i++){
                	for (int j = 0; j < 3; j++){
                        	cout << current[i][j] << " ";
                        }
			cout << endl;
                }	
	}
	
	//overload comparison operator for priority queue
	friend bool operator>(const State& l, const State& r){
                return l.f_n > r.f_n;
	}
	
	//overload == operator for checking explored set
	friend bool operator!=(const State &s1, const State &s2){
		bool check = false;

		for(int i = 0; i < 3; i++){ 
        		for (int j = 0; j < 3; j++){
				if(s1.current[i][j] != s2.current[i][j]){
					check = true;
				}
				else{
					check = false;
				}		 
        		} 
    		}
		
		return check;
	}

};



#endif
