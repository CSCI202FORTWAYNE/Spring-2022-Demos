#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    graphType g(100);
    g.createGraph();
    g.printGraph();

    cout << endl;

    g.depthFirstTraversal();
    cout << endl;
    g.breadthFirstTraversal();


    return 0;
}