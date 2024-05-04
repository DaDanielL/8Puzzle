#include <iostream>
#include "../header/Problem.h"
#include "../header/NPuzzleSolver.h"
using namespace std;

int main()
{
    Problem p = Problem();
    NPuzzleSolver n = NPuzzleSolver();

    vector<vector<int> > s = {{4,5,1},{2,0,8},{7,3,6}};
    cout << p.euclidDist(s) << "\n";
    p.printState(s);

    n.UniformCostSearch(p);
    return 0;

}