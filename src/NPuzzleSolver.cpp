#include "../header/NPuzzleSolver.h"
#include "../header/Problem.h"
#include "../header/State.h"
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

void NPuzzleSolver::initFrontier(){
    // Initialize frontier to initial state
    State init_state(this->p.getInitialState(), 0, 0);
    this->frontier.push(init_state);

    cout << "------------------------------" << endl;
    cout << "Doing Uniform Cost Search..." << endl << endl;
    cout << "Initial State: " << endl;
    this->p.printState(this->p.getInitialState());
    cout << endl;
}

void NPuzzleSolver::initExploredSet(){
    // Initialize explored set
    this->explored_set.insert(this->p.getInitialState());
}

void NPuzzleSolver::printResult(){
    cout << "Goal!!" << endl << endl;
    cout << "To solve this problem, the search algorithm expanded a total of " << this->node_expanded << " nodes" << endl;
    cout << "The maximum of nodes in queue at any time: " << this->max_queue_size << endl;
    cout << "The depth of the goal node was: " << this->goal_depth << endl;
}

void NPuzzleSolver::reset(){
    this->frontier = priority_queue <State, vector<State>, greater<State>>();
    this->explored_set.clear();
    this->node_expanded = 0;
    this->max_queue_size = 1;
    this->goal_depth = 0;
}

bool NPuzzleSolver::AStarEuclidSearch(){
    reset();

    // Initialize frontier to initial state
    this->initFrontier();
    
    // Initialize explored set
    this->initExploredSet();

    while(true){
        // if frontier empty return failure
        if(this->frontier.empty()){
            cout << "No Solution Found!!" << endl << endl;
            return false;
        }

        // choose leaf node remove from frontier
        State leaf = this->frontier.top();
        this->frontier.pop();

        // print
        cout << "The best state to expand with g(n) = " << leaf.getCost() << endl;
        p.printState(leaf.getState());


        // if node is goal return solution
        if(p.goalReached(leaf.getState())){
            this->goal_depth = leaf.getCost();
            this->printResult();
            return true;
        }

        // add node to explored set
        this->explored_set.insert(leaf.getState());

        // expand, add results nodes to frontier if not in explored set
        this->node_expanded++;
        set<vector<vector<int>>> allChildren = p.allOperator(leaf.getState());

        for(auto itr = allChildren.begin(); itr != allChildren.end(); itr++){
            if(explored_set.find(*itr) == explored_set.end()){
                frontier.push(State(*itr, leaf.getCost()+1, p.euclidDist(leaf.getState())));                // g(n) = g(n) of parent + 1, h(n) = euclid

                // check for max_queue_size
                this->max_queue_size = max((int) this->max_queue_size, (int) frontier.size());
            }
        }
        
    }
}

bool NPuzzleSolver::AStarManhattanSearch(){
    reset();

    // Initialize frontier to initial state
    this->initFrontier();
    
    // Initialize explored set
    this->initExploredSet();

    while(true){
        // if frontier empty return failure
        if(this->frontier.empty()){
            cout << "No Solution Found!!" << endl << endl;
            return false;
        }

        // choose leaf node remove from frontier
        State leaf = this->frontier.top();
        this->frontier.pop();

        // print
        cout << "The best state to expand with g(n) = " << leaf.getCost() << endl;
        p.printState(leaf.getState());


        // if node is goal return solution
        if(p.goalReached(leaf.getState())){
            this->goal_depth = leaf.getCost();
            this->printResult();
            return true;
        }

        // add node to explored set
        this->explored_set.insert(leaf.getState());

        // expand, add results nodes to frontier if not in explored set
        this->node_expanded++;
        set<vector<vector<int>>> allChildren = p.allOperator(leaf.getState());

        for(auto itr = allChildren.begin(); itr != allChildren.end(); itr++){
            if(explored_set.find(*itr) == explored_set.end()){
                frontier.push(State(*itr, leaf.getCost()+1, p.manhattanDist(leaf.getState())));                // g(n) = g(n) of parent + 1, h(n) = manhattan

                // check for max_queue_size
                this->max_queue_size = max((int) this->max_queue_size, (int) frontier.size());
            }
        }
        
    }
}

bool NPuzzleSolver::UniformCostSearch(){

    reset();

    // Initialize frontier to initial state
    this->initFrontier();
    
    // Initialize explored set
    this->initExploredSet();

    while(true){
        // if frontier empty return failure
        if(this->frontier.empty()){
            cout << "No Solution Found!!" << endl << endl;
            return false;
        }

        // choose leaf node remove from frontier
        State leaf = this->frontier.top();
        this->frontier.pop();

        // print
        cout << "The best state to expand with g(n) = " << leaf.getCost() << endl;
        p.printState(leaf.getState());


        // if node is goal return solution
        if(p.goalReached(leaf.getState())){
            this->goal_depth = leaf.getCost();
            this->printResult();
            return true;
        }

        // add node to explored set
        this->explored_set.insert(leaf.getState());

        // expand, add results nodes to frontier if not in explored set
        this->node_expanded++;
        set<vector<vector<int>>> allChildren = p.allOperator(leaf.getState());

        for(auto itr = allChildren.begin(); itr != allChildren.end(); itr++){
            if(explored_set.find(*itr) == explored_set.end()){
                frontier.push(State(*itr, leaf.getCost()+1, 0));                // g(n) = g(n) of parent + 1, h(n) = 0

                // check for max_queue_size
                this->max_queue_size = max((int) this->max_queue_size, (int) frontier.size());
            }
        }
        
    }
}
