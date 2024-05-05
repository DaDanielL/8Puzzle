#include <iostream>
#include "../header/Problem.h"
#include "../header/NPuzzleSolver.h"
using namespace std;

int main()
{
    int puzzle_size = 3;
    int puzzle_option;
    int alg_option;
    vector<vector<int>> custom_puzzle;
    vector<int> row_input;
    int num;
    Problem p;
    NPuzzleSolver solver = NPuzzleSolver();

    cout<<"Welcome to Daniel Lin (862385642) 8 Puzzle solver."<<endl;

    cout<<"Type \'1\' to use a default puzzle, or \'2\' to enter your own puzzle."<<endl;
    cin>>puzzle_option;
    if(puzzle_option == 1){
        p = Problem();
    }else if (puzzle_option == 2){
        cout<<"Enter your puzzle, use 0 to represent blank" << endl;

        for(unsigned int i = 1; i <= puzzle_size; i++){
            cout<<"Enter row " << i << ", use space or tabs between numbers  ";
            for(unsigned int j = 1; j <= puzzle_size; j++){
                cin >> num;
                row_input.push_back(num);
            }
            custom_puzzle.push_back(row_input);
            row_input.clear();
        }
        p = Problem(custom_puzzle);
    }else{
        cout<<"Invalid Input." << endl;
        return -1;
    }
    cout<<endl<<endl;

    cout<<"Enter your choice of algorithm: "<<endl;
    cout<<"1. Uniform Cost Search" << endl;
    cout<<"2. A* with Manhattan Heuristic" << endl;
    cout<<"3. A* with Euclidean Heuristic" << endl << endl;
    cin>>alg_option;
    switch(alg_option){
        case 1:
            solver.UniformCostSearch(p);
            break;
        case 2:
            solver.UniformCostSearch(p);
            break;
        case 3:
            solver.UniformCostSearch(p);
            break;
        default:
            cout<<"Invalid Input."<<endl;
            return -1;
    }   

    return 0;

}