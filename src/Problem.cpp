#include "../header/Problem.h"
#include <algorithm>
using namespace std;

Problem::Problem(){     
    // Default constructor
    this->size = 3;
    createGoalState();
    this->initial_state = {{1,0,3},{4,2,6},{7,5,8}};
}

Problem::Problem(vector<std::vector<int>> initial_state){
    // Constructor with input state
    this->initial_state = initial_state;
    this->size = initial_state.size();
    createGoalState();
}

void Problem::createGoalState(){
    // goal_state = {{1,2,3},{4,5,6},{7,8,0}}
    // goal_pos = {{0,0},{0,1},{0,2},{1,0}...}
    int n;
    for(unsigned int i = 0; i < this->size; i++){
        for(unsigned int j = 0; j < this->size; j++){
            n = (this->size*i) + j+1;
            this->goal_state[i][j] = n;
            this->goal_pos[n] = {(int)i,(int)j};
        }
    }

}

vector<vector<int>> Problem::up(vector<std::vector<int>> curState){
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
vector<vector<int>> Problem::down(vector<std::vector<int>> curState){
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
vector<vector<int>> Problem::left(vector<std::vector<int>> curState){
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
vector<vector<int>> Problem::right(vector<std::vector<int>> curState){
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

int Problem::manhattanDist(vector<std::vector<int>> curState){
    int d;
    int curValue;
    for(unsigned int i = 0; i < this->size; i++){
        for(unsigned int j = 0; j < this->size; j++){
            curValue = curState[i][j];
            for(unsigned int i = 0; i < this->size; i++){

            }
        }
    }
}
int Problem::euclidDist(vector<std::vector<int>> curState){

}