/**
 * @file mst.h    Defines the interface to Minimum Spanning Tree
 * @brief
 *   Defines the interface to minimum spanning tree problem
 *
 * @author George Heineman
 * @date 6/15/08
 */

#ifndef _MST_H_
#define _MST_H_

#include "BinaryHeap.h"
#include "Graph.h"

/**
 * Compute the Minimum Spanning Tree for the graph and leave results of
 * computation within the computed pred[] array for each vertex.
 * \param graph    Graph to be used as basis for computation.
 * \param pred     pred[] array to contain the previous vertex for each vertex.
 */
/**
 * Given undirected graph, compute MST starting from a randomly
 * selected vertex. Encoding of MST is done using 'pred' entries.
 * \param graph    the undirected graph
 * \param pred     pred[] array to contain previous information for MST.
 */
void mst_prim(Graph const &graph, vector<int> &pred) {

    // initialize pred[] and key[] arrays. Start with arbitrary
    // vertex s=0. Priority Queue PQ contains all v in G.
    const int n = graph.numVertices();
    pred.assign(n, -1);
    vector<int> key(n, numeric_limits<int>::max());
    key[0] = 0;

    BinaryHeap pq(n);
    vector<bool> inQueue(n, true);
    for (int v = 0; v < n; v++) {
        pq.insert(v, key[v]);
    }

    while (!pq.isEmpty()) {
        int u = pq.smallest();
        inQueue[u] = false;

        // Process all neighbors of u to find if any edge beats best distance
        for (VertexList::const_iterator ci = graph.begin(u);
             ci != graph.end(u); ++ci) {
            int v = ci->first;
            if (inQueue[v]) {
                int w = ci->second;
                if (w < key[v]) {
                    pred[v] = u;
                    key[v] = w;
                    pq.decreaseKey(v, w);
                }
            }
        }
    }
}

#endif /* _MST_H_ */
