#include "../header/NPuzzleSolver.h"
#include "../header/Problem.h"
#include "../header/State.h"
#include <iostream>
#include <queue>
#include <set>

using namespace std;

bool NPuzzleSolver::UniformCostSearch(Problem p){

    int node_expanded = 0;
    int max_queue_size = 0;
    int goal_depth = 0;

    // Initialize frontier to initial state
    priority_queue <State, vector<State>, greater<State>> frontier;
    State init_state(p.getInitialState(), 0, 0);
    frontier.push(init_state);

    cout << "------------------------------" << endl;
    cout << "Doing Uniform Cost Search..." << endl << endl;
    cout << "Initial State: " << endl;
    p.printState(p.getInitialState());
    cout << endl;
    
    // Initialize explored set
    set<vector<vector<int>>> explored_set;
    explored_set.insert(init_state.getState());

    while(true){
        // if frontier empty return failure
        if(frontier.empty()){
            cout << "No Solution Found!!" << endl << endl;
            return false;
        }

        // choose leaf node remove from frontier
        State leaf = frontier.top();
        frontier.pop();

        // print
        cout << "The best state to expand with g(n) = " << leaf.getCost() << endl;
        p.printState(leaf.getState());


        // if node is goal return solution
        if(p.goalReached(leaf.getState())){
            cout << "Goal!!" << endl << endl;
            return true;
        }

        // add node to explored set
        explored_set.insert(leaf.getState());

        // expand, add results nodes to frontier if not in explored set
        set<vector<vector<int>>> allChildren = p.allOperator(leaf.getState());

        for(auto itr = allChildren.begin(); itr != allChildren.end(); itr++){
            if(explored_set.find(*itr) == explored_set.end()){
                frontier.push(State(*itr, leaf.getCost()+1, 0));                // g(n) = g(n) of parent + 1, h(n) = 0
            }
        }
        
    }
}
