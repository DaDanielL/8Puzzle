#include "../header/Problem.h"
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

Problem::Problem(){     
    // Default constructor
    this->size = 3;
    createGoalState();
    this->initial_state = {{1,0,3},{4,2,6},{7,5,8}};
}

Problem::Problem(vector<vector<int> > initial_state){
    // Constructor with input state
    this->initial_state = initial_state;
    this->size = initial_state.size();
    createGoalState();
}

void Problem::createGoalState(){
    // goal_state = {{1,2,3},{4,5,6},{7,8,0}}
    // goal_pos = {{0,0},{0,1},{0,2},{1,0}...}
    // goal_pos keeps track of the pos of each number 0 - 8

    this->goal_state.resize(this->size, vector<int>(this->size));
    this->goal_pos.resize(this->size*this->size+1, vector<int>(2));

    int n;
    for(unsigned int i = 0; i < this->size; i++){
        for(unsigned int j = 0; j < this->size; j++){
            n = (this->size*i) + j+1;
            this->goal_state[i][j] = n;
            this->goal_pos[n] = {(int)i,(int)j};
        }
    }
    this->goal_pos[0] = {this->size-1, this->size-1};         // 0 is blank and is not at (0,0)
    this->goal_pos.pop_back();                                // remove extra value not in goal state
    this->goal_state[this->size-1][this->size-1] = 0;
}


vector<vector<int> > Problem::up(vector<vector<int> > curState){
    // find index of 0 or blank, swap with element
    for(unsigned int i = 0; i < this->size; i++){
        for(unsigned int j = 0; j < this->size; j++){
            if(curState[i][j] == 0){
                if(i + 1 >= this->size){
                    return curState;
                }else{
                    curState[i][j] = curState[i+1][j];
                    curState[i+1][j] = 0;
                }
            }
        }
    }
}
vector<vector<int> > Problem::down(vector<vector<int> > curState){
    // find index of 0 or blank, swap with element
    for(unsigned int i = 0; i < this->size; i++){
        for(unsigned int j = 0; j < this->size; j++){
            if(curState[i][j] == 0){
                if(i - 1 <= this->size){
                    return curState;
                }else{
                    curState[i][j] = curState[i-1][j];
                    curState[i-1][j] = 0;
                }
            }
        }
    }
}
vector<vector<int> > Problem::left(vector<vector<int> > curState){
    // find index of 0 or blank, swap with element
    for(unsigned int i = 0; i < this->size; i++){
        for(unsigned int j = 0; j < this->size; j++){
            if(curState[i][j] == 0){
                if(j - 1 <= this->size){
                    return curState;
                }else{
                    curState[i][j] = curState[i][j-1];
                    curState[i][j-1] = 0;
                }
            }
        }
    }
}
vector<vector<int> > Problem::right(vector<vector<int> > curState){
// find index of 0 or blank, swap with element
    for(unsigned int i = 0; i < this->size; i++){
        for(unsigned int j = 0; j < this->size; j++){
            if(curState[i][j] == 0){
                if(j + 1 >= this->size){
                    return curState;
                }else{
                    curState[i][j] = curState[i][j+1];
                    curState[i][j+1] = 0;
                }
            }
        }
    }
}

int Problem::manhattanDist(vector<vector<int> > curState){
    int d = 0;
    int actual_i;
    int actual_j;
    
    for(unsigned int i = 0; i < curState.size(); i++){
        for(unsigned int j = 0; j < curState.size(); j++){
            actual_i = this->goal_pos[curState[i][j]][0];             // if curState[i][j] == 4, then the acutal position of 4 can be found at the index 4 of goal_state
            actual_j = this->goal_pos[curState[i][j]][1]; 

            d += abs((int)(actual_i - i)) + abs((int)(actual_j - j));
        }           
    }
    return d;
}
double Problem::euclidDist(vector<vector<int> > curState){
    double d = 0.0;
    int actual_i;
    int actual_j;
    
    for(unsigned int i = 0; i < curState.size(); i++){
        for(unsigned int j = 0; j < curState.size(); j++){
            actual_i = this->goal_pos[curState[i][j]][0];             // if curState[i][j] == 4, then the acutal position of 4 can be found at the index 4 of goal_state
            actual_j = this->goal_pos[curState[i][j]][1]; 

            d += sqrt(pow(actual_i - (int) i,2) + pow(actual_j - (int) j ,2));
        }           
    }
    return d;
}

bool Problem::statesEqual(vector<vector<int> > a, vector<vector<int> > b){
    if(a.size() != b.size()){
        return false;
    }

    for(unsigned int i = 0; i < a.size(); i++){
        if(a[i].size() != b[i].size()){
            return false;
        }
        for(unsigned int j = 0; j < a.size(); j++){
            if(a[i][j] != b[i][j]){
                return false;
            }
        }
    }

    return true;

}