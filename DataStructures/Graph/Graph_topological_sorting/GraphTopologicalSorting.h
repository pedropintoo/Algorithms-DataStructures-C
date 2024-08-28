///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024
///
/// Topological Sorting
///

#ifndef _GRAPH_TOPOLOGICAL_SORTING_
#define _GRAPH_TOPOLOGICAL_SORTING_

#include "Graph.h"
#include "IntegersQueue.h"

/// Init Image library.  (Call once!)
/// Currently, simply calibrate instrumentation and set names of counters.
void TopoInit(void) ;

typedef struct _GraphTopoSort GraphTopoSort;

GraphTopoSort* GraphTopoSortComputeV1(Graph* g);

GraphTopoSort* GraphTopoSortComputeV2(Graph* g);

GraphTopoSort* GraphTopoSortComputeV3(Graph* g);

void GraphTopoSortDestroy(GraphTopoSort** p);

// Getting the result

int GraphTopoSortIsValid(const GraphTopoSort* p);

unsigned int* GraphTopoSortGetSequence(const GraphTopoSort* p);

// DISPLAYING on the console

void GraphTopoSortDisplaySequence(const GraphTopoSort* p);

void GraphTopoSortDisplay(const GraphTopoSort* p);

#endif  //_GRAPH_TOPOLOGICAL_SORTING_
