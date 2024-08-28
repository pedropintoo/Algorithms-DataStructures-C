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


#ifndef _GRAPH_GENERATOR_
#define _GRAPH_GENERATOR_

#include "Graph.h"

Graph* GraphGenerateTopoSuccessWorst(unsigned int numVertices);

Graph* GraphGenerateTopoSuccessBest(unsigned int numVertices);

Graph* GraphGenerateTopoInsuccessWorst(unsigned int numVertices);

Graph* GraphGenerateTopoInsuccessBest(unsigned int numVertices);

#endif  //_GRAPH_GENERATOR_