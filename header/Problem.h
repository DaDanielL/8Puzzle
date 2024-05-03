#ifndef PROBLEM_HPP
#define PROBLEM_HPP

#include <vector>
using namespace std;

class Problem{
    private:
        int size;
        vector<vector<int>> initial_state;
        vector<vector<int>> goal_state;
        vector<vector<int>> goal_pos;

        void createGoalState();

    public:
        Problem();
        Problem(vector<std::vector<int>> initial_state);

        vector<vector<int>> up(vector<std::vector<int>> curState);
        vector<vector<int>> down(vector<std::vector<int>> curState);
        vector<vector<int>> left(vector<std::vector<int>> curState);
        vector<vector<int>> right(vector<std::vector<int>> curState);

        int manhattanDist(vector<std::vector<int>> curState);
        int euclidDist(vector<std::vector<int>> curState);
};

#endif