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

#ifndef _INTEGERS_DEQUE_
#define _INTEGERS_DEQUE_

typedef struct _IntegersDeque Deque;

Deque* DequeCreate(int size);

void DequeDestroy(Deque** p);

void DequeClear(Deque* q);

int DequeSize(const Deque* q);

int DequeIsFull(const Deque* q);

int DequeIsEmpty(const Deque* q);

void* DequePeek_front(const Deque* q);

void* DequePeek_back(const Deque* q);

void DequePush_front(Deque* q, int p);

void DequePush_back(Deque* q, int p);

void* DequePop_front(Deque* q);

void* DequePop_back(Deque* q);

#endif  // _INTEGERS_DEQUE_
