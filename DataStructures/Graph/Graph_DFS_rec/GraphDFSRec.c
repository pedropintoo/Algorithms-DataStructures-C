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
// GraphDFSRec - RECURSIVE Depth-First Search
//

#include "GraphDFSRec.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersStack.h"

struct _GraphDFSRec {
  unsigned int* marked;  // To mark vertices when reached for the first time
  int* predecessor;      // The predecessor vertex, when a vertex was reached
  Graph* graph;
  unsigned int startVertex;
};

static void _dfs(GraphDFSRec* traversal, unsigned int vertex) {
  traversal->marked[vertex] = 1;

  unsigned int* neighbors = GraphGetAdjacentsTo(traversal->graph, vertex);
  // neighbors[0] - size of adjacents array
  for (unsigned int i = 1; i <= neighbors[0]; i++) { // da para optimizar... ?
    unsigned int w = neighbors[i];
    if (traversal->marked[w] == 0) {
      traversal->predecessor[w] = vertex;
      _dfs(traversal, w);
    }
  }

  free(neighbors);
}

GraphDFSRec* GraphDFSRecExecute(Graph* g, unsigned int startVertex) {
  assert(g != NULL);
  assert(startVertex < GraphGetNumVertices(g));

  GraphDFSRec* result = (GraphDFSRec*)malloc(sizeof(struct _GraphDFSRec));
  assert(result != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  result->marked = (unsigned int*)calloc(numVertices, sizeof(unsigned int));
  assert(result->marked != NULL);

  result->predecessor = (int*)malloc(numVertices * sizeof(int));
  assert(result->predecessor != NULL);
  for (unsigned int i = 0; i < numVertices; i++) {
    result->predecessor[i] = -1;
  }

  result->predecessor[startVertex] = 0;

  result->graph = g;
  result->startVertex = startVertex;

  // START THE RECURSIVE TRAVERSAL

  _dfs(result, startVertex);

  return result;
}

void GraphDFSRecDestroy(GraphDFSRec** p) {
  assert(*p != NULL);

  GraphDFSRec* aux = *p;

  free(aux->marked);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

unsigned int GraphDFSRecHasPathTo(const GraphDFSRec* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  return p->marked[v];
}

Stack* GraphDFSRecPathTo(const GraphDFSRec* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  Stack* s = StackCreate(GraphGetNumVertices(p->graph));

  if (p->marked[v] == 0) {
    return s;
  }

  // Store the path
  for (unsigned int current = v; current != p->startVertex;
       current = p->predecessor[current]) {
    StackPush(s, current); // it's no the best path !!!
  }

  StackPush(s, p->startVertex);

  return s;
}

// DISPLAYING on the console

void GraphDFSRecShowPath(const GraphDFSRec* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  Stack* s = GraphDFSRecPathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  StackDestroy(&s);
}

void GraphDFSRecDisplay(const GraphDFSRec* p) {
  assert(p != NULL);

  // TO BE COMPLETED !!
}
