#include <iostream>
#include "../header/Problem.h"
using namespace std;

int main()
{
    Problem p = Problem();

    vector<vector<int> > s = {{4,5,1},{2,0,8},{7,3,6}};
    cout << p.manhattanDist(s);
    return 0;

}