///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024
///
/// Graph Generator
///

#include "GraphGenerator.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Graph.h"

Graph *GraphGenerateTopoSuccessWorst(unsigned int numVertices)
{   
    // Generate a Digraph with max number of edges (Success: WC)
    Graph* G = GraphCreate(numVertices, 1, 0);

    for (unsigned int v = 0; v < numVertices; v++) {
        for (unsigned int w = v+1; w < numVertices; w++) {
            GraphAddEdge(G,v,w); 
        }
    }

    return G;
}

Graph *GraphGenerateTopoSuccessBest(unsigned int numVertices) {
    // Generate a Digraph with only vertices (Success: BC)
    Graph* G = GraphCreate(numVertices,1,0);
    return G;
}

Graph *GraphGenerateTopoInsuccessWorst(unsigned int numVertices)
{   
    // Generate a Digraph with 2 components disconnected, the first one with a loop in the 2 vertices with less index
    // and the second one with max number of edges (Insuccess: WC)
    Graph* G = GraphCreate(numVertices,1,0);

    if (numVertices < 2) return G; // Impossible to have Insuccess with less than 2 vertex

    // loop in the 2 vertices with less index
    GraphAddEdge(G,0,1);
    GraphAddEdge(G,1,0);

    // max number of edges
    for (unsigned int v = numVertices-1; v > 1; v--) {
        for (unsigned int w = v-1; w > 0; w--) {
            GraphAddEdge(G,v,w); 
        }
    }
    
    return G;
}

Graph *GraphGenerateTopoInsuccessBest(unsigned int numVertices)
{   
    // Generate a Digraph with a loop including all vertices with less edges possible (Insuccess: BC)
    Graph* G = GraphCreate(numVertices,1,0);

    if (numVertices < 2) return G; // Impossible to have Insuccess with less than 2 vertex

    for (unsigned int v = 0; v < numVertices; v++) {
        if (v+1 == numVertices) { // last vertex case
            if (v != 0) GraphAddEdge(G,v,0); // check if is a self-loop
        }
        else GraphAddEdge(G,v,v+1); 
    }

    return G;
}
