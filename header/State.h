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
            this->state = s;
            this->cost = c;
            this->heuristic = h;
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

        bool operator<(const State& rhs) const{
            return (this->cost + this->heuristic) < (rhs.cost + rhs.heuristic);
        }

        bool operator>(const State& rhs) const{
            return (this->cost + this->heuristic) > (rhs.cost + rhs.heuristic);
        }
};

#endif