///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
// Joaquim Madeira, Algoritmos e Estruturas de Dados, November 2023
//
// Adapted from an old example (2003, 2020)
//
// Integers Binary Tree
//

#ifndef _INTEGERS_BINTREE_
#define _INTEGERS_BINTREE_

// JUST storing integers
typedef int ItemType;

static int NO_ITEM = -999;

typedef struct _TreeNode Tree;

// Only implemented to read from a file
//Tree* TreeCreate(void);

void TreeDestroy(Tree** pRoot);

// Tree properties

int TreeIsEmpty(const Tree* root);

int TreeEquals(const Tree* root1, const Tree* root2);

int TreeMirrors(const Tree* root1, const Tree* root2);

// ...

// Getters

int TreeGetNumberOfNodes(const Tree* root);

int TreeGetHeight(const Tree* root);

ItemType TreeGetMin(const Tree* root);

ItemType TreeGetMax(const Tree* root);

Tree* TreeGetPointerToMinNode(Tree* root);

Tree* TreeGetPointerToMaxNode(Tree* root);

// ...

// Recursive Traversals

void TreeTraverseInPREOrder(Tree* root, void (*function)(ItemType* p));

void TreeTraverseINOrder(Tree* root, void (*function)(ItemType* p));

void TreeTraverseInPOSTOrder(Tree* root, void (*function)(ItemType* p));

// Traversals using a QUEUE or STACK

void TreeTraverseLevelByLevelWithQUEUE(Tree* root,
                                       void (*function)(ItemType* p));

void TreeTraverseInPREOrderWithSTACK(Tree* root, void (*function)(ItemType* p));

void TreeTraverseINOrderWithSTACK(Tree* root, void (*function)(ItemType* p));

void TreeTraverseInPOSTOrderWithSTACK(Tree* root, void (*function)(ItemType* p));

// ...

// Operations with items

int TreeContains(const Tree* root, const ItemType item);

int TreeAdd(Tree** pRoot, const ItemType item);

int TreeRemove(Tree** pRoot, const ItemType item);

// ...

// Storing and reading from a FILE

int TreeStoreInFile(const Tree* root, char* fileName, int fileType);

Tree* TreeGetFromFile(char* fileName, int fileType);

// JUST FOR RUNNING EXAMPLES - REMOVE FROM THE INTERFACE

Tree* createExampleTree(void);

#endif  // _INTEGERS_BINTREE_