///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024
///
/// Graph Test Topological Sorting
///

#include <stdlib.h>
#include <assert.h>

#include "Graph.h"
#include "GraphGenerator.h"
#include "GraphTopologicalSorting.h"
#include "instrumentation.h"

#define VERSIONS 3          // Number of different versions of topological sort algorithm

typedef GraphTopoSort* (*TopoSortFcn)(Graph*);

typedef Graph* (*TopoGeneFcn)(unsigned int);

// Pointers to Topological Generate Functions
TopoGeneFcn topoGeneFcns[4] = {
  GraphGenerateTopoSuccessWorst,
  GraphGenerateTopoSuccessBest,
  GraphGenerateTopoInsuccessWorst,
  GraphGenerateTopoInsuccessBest
};

// Pointers to Topological Sort Functions
TopoSortFcn topoSortFcns[VERSIONS] = {
  GraphTopoSortComputeV1,
  GraphTopoSortComputeV2,
  GraphTopoSortComputeV3
};

int main(int argc, char* argv[]) {

  if (argc < 5) {
    fprintf(stderr, "Usage: %s CASE MIN_VERTICES INC_VERTICES MAX_VERTICES\n", argv[0]);
    exit(1);
  }

  TopoInit();

  unsigned int CASE = atoi(argv[1]); // selected case
  unsigned int MIN_VERTICES = atoi(argv[2]); // start for the for loop
  unsigned int INC_VERTICES = atoi(argv[3]); // increment for the for loop
  unsigned int MAX_VERTICES = atoi(argv[4]); // end for the for loop

  for (unsigned int numVertices = MIN_VERTICES; numVertices <= MAX_VERTICES; numVertices+= INC_VERTICES) {

    TopoGeneFcn geneFcn = topoGeneFcns[CASE]; // select function to generate the correct case graph
    Graph* G = geneFcn(numVertices); // generate the correct case graph

    for (int version = 0; version < VERSIONS; version++) {
      TopoSortFcn sortFcn = topoSortFcns[version];
      
      InstrReset();
      GraphTopoSort* result = sortFcn(G); // Execute sort algorithm in all versions
      InstrPrintTest(numVertices);  // Display the table

      GraphTopoSortDestroy(&result);
    }
    
    GraphDestroy(&G);
  }
 
	return 0;
}
