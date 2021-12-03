#include <iostream>
#include <vector>

#include "GeneratorOfDistances.h"
#include "visibility-smell.h"
#include "Colony.h"

using namespace std;

int main()
{
    int n = 200;
    //genDist(n);//generation of matrix
    vector<vector<int>> matrix = getDist(n);
    //genFero(n);
    //vector<vector<float>> smell = getFero(n);
    
    //printDist(n);
    return 0;
}
