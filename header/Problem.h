#ifndef PROBLEM_HPP
#define PROBLEM_HPP

#include <vector>
using namespace std;

class Problem{
    private:
        int size;
        vector<vector<int> > initial_state;
        vector<vector<int> > goal_state;
        vector<vector<int> > goal_pos;

        void createGoalState();

    public:
        Problem();
        Problem(vector<vector<int> > initial_state);

        vector<vector<int> > up(vector<vector<int> > curState);
        vector<vector<int> > down(vector<vector<int> > curState);
        vector<vector<int> > left(vector<vector<int> > curState);
        vector<vector<int> > right(vector<vector<int> > curState);

        int manhattanDist(vector<vector<int> > curState);
        double euclidDist(vector<vector<int> > curState);

        bool statesEqual(vector<vector<int> > a, vector<vector<int> > b);
        void printState(vector<vector<int> > s);
};

#endif