#ifndef STATE_HPP
#define STATE_HPP

#include <vector>
using namespace std;

class State{
    private:
        vector<vector<int>> state;
        int cost;
        int heuristic;

    public:
        State(vector<vector<int>> s, int c, int h){
            this->state = state;
            this->cost = cost;
            this->heuristic = heuristic;
        }
        vector<vector<int>> getState(){
            return state;
        }
        int getCost(){
            return cost;
        }
        int getHeuristic(){
            return heuristic;
        }
};

#endif