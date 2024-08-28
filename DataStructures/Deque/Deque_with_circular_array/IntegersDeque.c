///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024
///
/// Integers Deque. Implementation based on a circular array
///

#include "IntegersDeque.h"

#include <assert.h>
#include <stdlib.h>

struct _IntegersDeque {
  int max_size;  // maximum Queue size
  int cur_size;  // current Queue size
  int head;
  int tail;
  int* data;  // the Queue data (integers stored in an array)
};

// PRIVATE auxiliary function

static int increment_index(const Deque* q, int i) {
  return (i + 1 < q->max_size) ? i + 1 : 0;
}

static int decrement_index(const Deque* q, int i) {
  return (i - 1 >= 0) ? i - 1 : q->max_size - 1;
}

// PUBLIC functions

Deque *DequeCreate(int size) { 
  assert(size >= 10 && size <= 1000000);
  Deque* q = (Deque*)malloc(sizeof(Deque));
  if (q == NULL) return NULL;

  q->max_size = size;
  q->cur_size = 0;

  q->head = 1;  // cur_size = tail - head + 1
  q->tail = 0;

  q->data = (int*)malloc(size * sizeof(int));
  if (q->data == NULL) {
    free(q);
    return NULL;
  }
  return q;
}

void DequeDestroy(Deque** p) {
  assert(*p != NULL);
  Deque* q = *p;
  free(q->data);
  free(q);
  *p = NULL;
}

void DequeClear(Deque* q) {
  q->cur_size = 0;
  q->head = 1;  // cur_size = tail - head + 1
  q->tail = 0;
}

int DequeSize(const Deque* q) { return q->cur_size; }

int DequeIsFull(const Deque* q) { return (q->cur_size == q->max_size) ? 1 : 0; }

int DequeIsEmpty(const Deque* q) { return (q->cur_size == 0) ? 1 : 0; }

void* DequePeek_front(const Deque* q) {
  assert(q->cur_size > 0);
  return q->data[q->head];
}

void *DequePeek_back(const Deque *q) {
  assert(q->cur_size > 0);
  return q->data[q->tail];
}

void DequePush_front(Deque *q, int i) {
  assert(q->cur_size < q->max_size);
  q->head = decrement_index(q, q->head);
  q->data[q->head] = i;
  q->cur_size++;
}

void DequePush_back(Deque *q, int i) {
  assert(q->cur_size < q->max_size);
  q->tail = increment_index(q, q->tail);
  q->data[q->tail] = i;
  q->cur_size++;
}

void *DequePop_front(Deque *q) {
  assert(q->cur_size > 0);
  int old_head = q->head;
  q->head = increment_index(q, q->head);
  q->cur_size--;
  return q->data[old_head];
}

void *DequePop_back(Deque *q) {
  assert(q->cur_size > 0);
  int old_tail = q->tail;
  q->tail = decrement_index(q, q->tail);
  q->cur_size--;
  return q->data[old_tail];
}
