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
// GraphBFS - QUEUE-based Breadth-First Search
//

#include "GraphBFSWithQueue.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersQueue.h"
#include "IntegersStack.h"

struct _GraphBFSWithQueue {
  int* marked;       // To mark vertices when reached for the first time
  int* distance;     // The number of edges on the path from the start vertex
  int* predecessor;  // The predecessor vertex, when a vertex was reached
  Graph* graph;
  unsigned int startVertex;
};

GraphBFSWithQueue* GraphBFSWithQueueExecute(Graph* g,
                                            unsigned int startVertex) {
  assert(g != NULL);
  assert(startVertex < GraphGetNumVertices(g));

  GraphBFSWithQueue* traversal =
      (GraphBFSWithQueue*)malloc(sizeof(struct _GraphBFSWithQueue));
  assert(traversal != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  //
  // TO BE COMPLETED !!
  //
  // CREATE AND INITIALIZE
  // traversal->marked
  // traversal->distance
  // traversal->predecessor
  //

  traversal->marked = (int*)calloc(numVertices, sizeof(unsigned int));
  assert(traversal->marked != NULL);

  traversal->predecessor = (int*)malloc(numVertices * sizeof(int));
  assert(traversal->predecessor != NULL);
  for (unsigned int i = 0; i < numVertices; i++) {
    traversal->predecessor[i] = -1;
  }

  traversal->distance = (int*)calloc(numVertices, sizeof(int));
  assert(traversal->distance != NULL);

  traversal->graph = g;
  traversal->startVertex = startVertex;

  // CARRY OUT THE TRAVERSAL

  // TO BE COMPLETED !!

  Queue* queue =  QueueCreate(numVertices);
  QueueEnqueue(queue, startVertex);
  traversal->marked[startVertex] = 1;
  traversal->predecessor[startVertex] = -1; // not necessary
  traversal->distance[startVertex] = 0;

  while(!QueueIsEmpty(queue)){
    int vertex = QueueDequeue(queue);
    unsigned int* neighbors = GraphGetAdjacentsTo(g, vertex);
    for (unsigned int i = 1; i <= neighbors[0]; i++) {
      unsigned int w = neighbors[i];
      if (traversal->marked[w] == 0) {
        traversal->marked[w] = 1;
        traversal->predecessor[w] = vertex;
        traversal->distance[w] = traversal->distance[vertex] + 1;
        QueueEnqueue(queue,w);
      }
    }

    free(neighbors);
  }

  QueueDestroy(&queue);

  return traversal;
}

void GraphBFSWithQueueDestroy(GraphBFSWithQueue** p) {
  assert(*p != NULL);

  GraphBFSWithQueue* aux = *p;

  free(aux->marked);
  free(aux->predecessor);
  free(aux->distance); // need to add!

  free(*p);
  *p = NULL;
}

// Getting the result

int GraphBFSWithQueueHasPathTo(const GraphBFSWithQueue* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  return p->marked[v];
}

Stack* GraphBFSWithQueuePathTo(const GraphBFSWithQueue* p, unsigned int v) {
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

void GraphBFSWithQueueShowPath(const GraphBFSWithQueue* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  Stack* s = GraphBFSWithQueuePathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  StackDestroy(&s);
}

void GraphBFSWithQueueDisplay(const GraphBFSWithQueue* p) {
  assert(p != NULL);

  // TO BE COMPLETED !!
  printf("---\n");
  Graph* g = p->graph;
  unsigned int numVertices = GraphGetNumVertices(g);

  printf("BFSWithQueue -> startVertex = %u\n",p->startVertex);
  for (unsigned int vertex = 0; vertex < numVertices; vertex++) {
    printf("Vertex: %u -- marked: %u -- distance: %u\n",vertex,p->marked[vertex],p->distance[vertex]);
    
    if (GraphBFSWithQueueHasPathTo(p,vertex)) {
      printf("Path (%u, %u): ",p->startVertex,vertex);
      Stack* stack = GraphBFSWithQueuePathTo(p,vertex);
      int v = StackPop(stack);
      printf("%d",v);
      while(!StackIsEmpty(stack)) {
        v = StackPop(stack);
        printf(" - %d",v);
      }
      printf("\n");

      StackDestroy(&stack);
    }
    
  }


}
