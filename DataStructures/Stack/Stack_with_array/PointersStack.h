///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
//
// Algoritmos e Estruturas de Dados - 2023/2024 - 1o semestre
//
// J. Madeira - April 2020
//
// Pointers stack (First In Last Out) implementation based on an array of
// pointers to void
//

#ifndef _POINTERS_STACK_
#define _POINTERS_STACK_

typedef struct _PointersStack Stack;

Stack* StackCreate(int size);

void StackDestroy(Stack** p);

void StackClear(Stack* s);

int StackSize(const Stack* s);

int StackIsFull(const Stack* s);

int StackIsEmpty(const Stack* s);

void* StackPeek(const Stack* s);

void StackPush(Stack* s, void* p);

void* StackPop(Stack* s);

#endif  // _POINTERS_STACK_
