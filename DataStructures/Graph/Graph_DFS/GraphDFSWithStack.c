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
// GraphDFS - STACK-based Depth-First Search
//

#include "GraphDFSWithStack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersStack.h"

struct _GraphDFSWithStack {
  int* marked;       // To mark vertices when reached for the first time
  int* predecessor;  // The predecessor vertex, when a vertex was reached
  Graph* graph;
  unsigned int startVertex;
};

GraphDFSWithStack* GraphDFSWithStackExecute(Graph* g,
                                            unsigned int startVertex) {
  assert(g != NULL);
  assert(startVertex < GraphGetNumVertices(g));

  GraphDFSWithStack* traversal =
      (GraphDFSWithStack*)malloc(sizeof(struct _GraphDFSWithStack));
  assert(traversal != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  traversal->marked = (int*)calloc(numVertices, sizeof(unsigned int));
  assert(traversal->marked != NULL);

  traversal->predecessor = (int*)malloc(numVertices * sizeof(int));
  assert(traversal->predecessor != NULL);
  for (unsigned int i = 0; i < numVertices; i++) {
    traversal->predecessor[i] = -1;
  }

  traversal->graph = g;
  traversal->startVertex = startVertex;

  // CARRY OUT THE TRAVERSAL

  // TO BE COMPLETED !!
  // equiv to _dfs(traversal, startVertex);
  
  Stack* stack = StackCreate(numVertices); // max
  StackPush(stack, startVertex);
  traversal->marked[startVertex] = 1;
  traversal->predecessor[startVertex] = -1; // not necessary

  unsigned int vertex = startVertex;
  
  while (!StackIsEmpty(stack)) {
    vertex = StackPop(stack);
  
    unsigned int* neighbors = GraphGetAdjacentsTo(traversal->graph, vertex);
    for (unsigned int i = 1; i <= neighbors[0]; i++) {
      unsigned int w = neighbors[i];
      if (traversal->marked[w] == 0) {
        StackPush(stack, w);
        traversal->predecessor[w] = vertex;
        traversal->marked[w] = 1;
      }
    }
    free(neighbors);
  }

  StackDestroy(&stack);

  return traversal;
}

void GraphDFSWithStackDestroy(GraphDFSWithStack** p) {
  assert(*p != NULL);

  GraphDFSWithStack* aux = *p;

  free(aux->marked);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

int GraphDFSWithStackHasPathTo(const GraphDFSWithStack* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  return p->marked[v];
}

Stack* GraphDFSWithStackPathTo(const GraphDFSWithStack* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  Stack* s = StackCreate(GraphGetNumVertices(p->graph));

  if (p->marked[v] == 0) {
    return s;
  }

  // Store the path
  for (unsigned int current = v; current != p->startVertex;
       current = p->predecessor[current]) {
    StackPush(s, current);
  }

  StackPush(s, p->startVertex);

  return s;
}

// DISPLAYING on the console

void GraphDFSWithStackShowPath(const GraphDFSWithStack* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  Stack* s = GraphDFSWithStackPathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  StackDestroy(&s);
}

void GraphDFSWithStackDisplay(const GraphDFSWithStack* p) {
  assert(p != NULL);

  // TO BE COMPLETED !!
}
