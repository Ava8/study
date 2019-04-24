/**
 * @file Graph.cxx   Implementation of Graph concept
 * @brief
 *   Contains the implementation of the Graph class.
 *
 * @author George Heineman
 * @date 6/15/08
 */

#include <stdio.h>
#include <string.h>
#include "Graph.h"






/**
 * Add edge to graph structure from (u,v).
 * If the graph is undirected, then we must add in reverse as well.
 * It is up to user to ensure that no edge already exists. The check
 * will not be performed here.
 *
 * \param u   integer identifier of a vertex
 * \param v   integer identifier of a vertex
 * \param w   planned weight.
 */
void Graph::addEdge (int u, int v, int w) {
    if (u > n_ || v > n_) {
        throw "Graph::addEdge given vertex larger than graph size";
    }

    pair<int,int> edge(v,w);
    vertices_[u].push_front(edge);

    // undirected have both.
    if (!directed_) {
        pair<int, int> edgeR (u,w);
        vertices_[v].push_front(edgeR);
    }
}


/**
 * Return edge weight, or INT_MIN if not present.
 * \param u   integer identifier of a vertex
 * \param v   integer identifier of a vertex
 * \return INT_MIN if edge doesn't exist, otherwise return its weight.
 */
int Graph::edgeWeight (int u, int v) const {
    for (VertexList::const_iterator ei = vertices_[u].begin();
         ei != vertices_[u].end();
         ++ei) {

        if (ei->first == v) {
            return ei->second;
        }
    }
    return numeric_limits<int>::min();
}
