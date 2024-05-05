#ifndef NPUZZLESOLVER_HPP
#define NPUZZLESOLVER_HPP

#include "Problem.h"
#include "State.h"
#include <queue>
#include <set>

using namespace std;

class NPuzzleSolver{
    private:
        priority_queue <State, vector<State>, greater<State>> frontier;
        set<vector<vector<int>>> explored_set;
        Problem p;
        int node_expanded = 0;
        int max_queue_size = 1;
        int goal_depth = 0;
        void printInit();
        void initExploredSet();
        void reset();
        void printResult();

    public:
        NPuzzleSolver(Problem p){
            this->p = p;
        }
        bool UniformCostSearch();
        bool AStarManhattanSearch();
        bool AStarEuclidSearch();

};

#endif