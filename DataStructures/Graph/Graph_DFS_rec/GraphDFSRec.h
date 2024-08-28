///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
// Algoritmos e Estruturas de Dados --- 2023/2024
//
// Joaquim Madeira, Joao Manuel Rodrigues - June 2021, Nov 2023
//
// GraphDFS - RECURSIVE Depth-First Search
//

#ifndef _GRAPH_DFS_REC_
#define _GRAPH_DFS_REC_

#include "Graph.h"
#include "IntegersStack.h"

typedef struct _GraphDFSRec GraphDFSRec;

GraphDFSRec* GraphDFSRecExecute(Graph* g, unsigned int startVertex);

void GraphDFSRecDestroy(GraphDFSRec** p);

// Getting the result

unsigned int GraphDFSRecHasPathTo(const GraphDFSRec* p, unsigned int v);

Stack* GraphDFSRecPathTo(const GraphDFSRec* p, unsigned int v);

// DISPLAYING on the console

void GraphDFSRecShowPath(const GraphDFSRec* p, unsigned int v);

void GraphDFSRecDisplay(const GraphDFSRec* p);

#endif  // _GRAPH_DFS_REC_
