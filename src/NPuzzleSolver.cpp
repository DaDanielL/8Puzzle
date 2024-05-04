#include "../header/NPuzzleSolver.h"
#include "../header/Problem.h"
#include "../header/State.h"
#include <iostream>
#include <queue>
#include <set>

using namespace std;

bool NPuzzleSolver::UniformCostSearch(Problem p){
    // Initialize frontier to initial state
    priority_queue <State, vector<State>, greater<State>> frontier;
    State init_state(p.getInitialState(), 0, 0);
    frontier.push(init_state);

    // Initialize explored set
    set<vector<vector<int>>> explored_set;

    while(true){
        // if frontier empty return failure
        if(frontier.empty()){
            return false;
        }

        // choose leaf node remove from frontier
        State leaf = frontier.top();
        frontier.pop();

        // if node is goal return solution
        if(p.goalReached(leaf.getState())){
            return true;
        }

        // add node to explored set
        explored_set.insert(leaf.getState());

        // expand, add results nodes to frontier if not in explored set
    }
}
