#include <iostream>
#include "mst.h"


void debug(int n, vector<int> pred) {
    cout << "n   pred\n";
    for (unsigned int i = 0; i < (unsigned int) n; i++) {
        cout << i << ". " << pred[i] << endl;
    }
    cout << "--------" << endl;
}

/*
 
                     5  -(6)- 6
                    / \      /(11)
                  (7) (10)- 7
                  /
 0 -(2)- 1 -(3)- 2 -(3)- 4
                  \
                  (2)
                    \
                     3
 
 */

int main() {
    const int n = 8;
    Graph g(n);

    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 3);
    g.addEdge(4, 5, 5);
    g.addEdge(5, 2, 7);
    g.addEdge(5, 6, 6);
    g.addEdge(5, 7, 10);
    g.addEdge(6, 7, 11);

    vector<int> pred(n);

    mst_prim(g, pred);

    debug(n, pred);
    return 0;
}
