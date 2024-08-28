///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024
///
/// Pointers Deque. Implementation based on a circular array of pointers to void
///

#ifndef _POINTERS_DEQUE_
#define _POINTERS_DEQUE_

typedef struct _PointersDeque Deque;

Deque* DequeCreate(int size);

void DequeDestroy(Deque** p);

void DequeClear(Deque* q);

int DequeSize(const Deque* q);

int DequeIsFull(const Deque* q);

int DequeIsEmpty(const Deque* q);

void* DequePeek_front(const Deque* q);

void* DequePeek_back(const Deque* q);

void DequePush_front(Deque* q, void* p);

void DequePush_back(Deque* q, void* p);

void* DequePop_front(Deque* q);

void* DequePop_back(Deque* q);

#endif  // _POINTERS_DEQUE_
