#include <iostream>
#include "../header/Problem.h"
#include "../header/NPuzzleSolver.h"
using namespace std;

int main()
{
    Problem p = Problem();
    NPuzzleSolver n = NPuzzleSolver();

    n.UniformCostSearch(p);
    return 0;

}