///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024
///
/// Integers Binary Tree
///

#include "IntegersBinTree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "PointersQueue.h"
#include "PointersStack.h"

struct _TreeNode {
  ItemType item;
  struct _TreeNode* left;
  struct _TreeNode* right;
};

// Only implemented to read from a file
//Tree* TreeCreate(void) { return NULL; }

void TreeDestroy(Tree** pRoot) {
  Tree* root = *pRoot;

  if (root == NULL) return;

  TreeDestroy(&(root->left));
  TreeDestroy(&(root->right));

  free(root);
  *pRoot = NULL;
}

int TreeIsEmpty(const Tree* root) { return root == NULL; }

int TreeEquals(const Tree* root1, const Tree* root2) {
  if (root1 == NULL && root2 == NULL) return 1;
  if (root1 == NULL || root2 == NULL) return 0;

  if (root1->item != root2->item) return 0;

  return TreeEquals(root1->left,root2->left) && TreeEquals(root1->right,root2->right);
}

int TreeMirrors(const Tree* root1, const Tree* root2) {
  if (root1 == NULL && root2 == NULL) return 1;
  if (root1 == NULL || root2 == NULL) return 0;

  if (root1->item != root2->item) return 0;

  return TreeEquals(root1->left,root2->right) && TreeEquals(root1->right,root2->left);
}

int TreeGetNumberOfNodes(const Tree* root) {
  if (root == NULL) return 0;
  
  return 1 + TreeGetNumberOfNodes(root->left) + TreeGetNumberOfNodes(root->right);
}

int TreeGetHeight(const Tree* root) {
  if (root == NULL) return -1; // NULL node... (don't have incident edge)
  
  int h_left = TreeGetHeight(root->left);
  int h_right = TreeGetHeight(root->right);

  int h = (h_left > h_right) ? h_left : h_right;

  return 1 + h;
}

ItemType TreeGetMin(const Tree *root) {
  if (root == NULL) return NO_ITEM;
  
  ItemType min = root->item;
  
  ItemType min_left = TreeGetMin(root->left);
  if (min_left != NO_ITEM && min_left < min) min = min_left;

  ItemType min_right = TreeGetMin(root->right);
  if (min_right != NO_ITEM && min_right < min) min = min_right;

  return min;
}

ItemType TreeGetMax(const Tree *root)
{
  if (root == NULL) return NO_ITEM;
  
  ItemType max = root->item;
  
  ItemType max_left = TreeGetMax(root->left);
  if (max_left != NO_ITEM && max_left > max) max = max_left;

  ItemType max_right = TreeGetMax(root->right);
  if (max_right != NO_ITEM && max_right > max) max = max_right;

  return max;
}

Tree *TreeGetPointerToMinNode(Tree *root) {
  if (root == NULL) return NULL;
  
  Tree* min = root;
  
  Tree* min_left = TreeGetPointerToMinNode(root->left);
  if (min_left && min_left->item < min->item) min = min_left;

  Tree* min_right = TreeGetPointerToMinNode(root->right);
  if (min_right && min_right->item < min->item) min = min_right;

  return min;
}

Tree *TreeGetPointerToMaxNode(Tree *root) {
  if (root == NULL) return NULL;
  
  Tree* max = root;
  
  Tree* max_left = TreeGetPointerToMaxNode(root->left);
  if (max_left && max_left->item < max->item) max = max_left;

  Tree* max_right = TreeGetPointerToMaxNode(root->right);
  if (max_right && max_right->item < max->item) max = max_right;

  return max;
}

void TreeTraverseInPREOrder(Tree* root, void (*function)(ItemType* p)) {
  if (root == NULL) return;

  function(&(root->item)); // Process item

  TreeTraverseInPREOrder(root->left, function); // Process left side

  TreeTraverseInPREOrder(root->right, function); // Process right side

}

void TreeTraverseINOrder(Tree* root, void (*function)(ItemType* p)) {
  if (root == NULL) return;

  TreeTraverseINOrder(root->left, function); // Process left side

  function(&(root->item)); // Process item

  TreeTraverseINOrder(root->right, function); // Process right side
}

void TreeTraverseInPOSTOrder(Tree* root, void (*function)(ItemType* p)) {
  if (root == NULL) return;

  TreeTraverseInPOSTOrder(root->left, function); // Process left side

  TreeTraverseInPOSTOrder(root->right, function); // Process right side

  function(&(root->item)); // Process item
}

void TreeTraverseLevelByLevelWithQUEUE(Tree* root, void (*function)(ItemType* p)) {
  if (root == NULL) return;

  // Not checking for queue errors !!
  // Create the QUEUE for storing POINTERS

  Queue* q = QueueCreate();

  QueueEnqueue(q, root);

  while (QueueIsEmpty(q) == 0) {
    Tree* p = QueueDequeue(q);

    function(&(p->item));

    if (p->left != NULL) {
      QueueEnqueue(q, p->left); 
    }
    if (p->right != NULL) {
      QueueEnqueue(q, p->right);
    }
  }

  QueueDestroy(&q);
}

void TreeTraverseInPREOrderWithSTACK(Tree* root, void (*function)(ItemType* p)) {
  Stack* stack = StackCreate();
  StackPush(stack, root);

  while(!StackIsEmpty(stack)) {
    Tree* p = StackPop(stack);

    function(&(p->item));

    if (p->right != NULL) {
      StackPush(stack, p->right); // right first (STACK!)
    }
    if (p->left != NULL) {
      StackPush(stack, p->left);
    }
  }

  StackDestroy(&stack);
}

void TreeTraverseINOrderWithSTACK(Tree* root, void (*function)(ItemType* p)) {
  
  Stack* stack = StackCreate();
  Tree* current = root;

  while(!StackIsEmpty(stack) || current != NULL) {
    while(current != NULL) {
      StackPush(stack, current);
      current = current->left; // add until is no left node possible
    }

    current = StackPop(stack);
    function(&(current->item));

    current = current->right; // check if right is possible
  }

  StackDestroy(&stack);
}

void TreeTraverseInPOSTOrderWithSTACK(Tree *root, void (*function)(ItemType *p)) {
  
  Stack* stack = StackCreate();
  Tree* current = root;

  do {
    while (current) {
      if (current->right) StackPush(stack,current->right);
      StackPush(stack,current); // Right node before current
      
      current = current->left;
    }

    current = StackPop(stack);
    if (current->right && (StackSize(stack) > 0) && (StackPeek(stack) == current->right)) {  
      // Change the order between current and right node
      StackPop(stack);

      StackPush(stack,current);
      current = current->right;
    } else {
      // Doesn't have a right child, or the right child has already been processed
      function(&(current->item));
      current = NULL;
    }

  } while(!StackIsEmpty(stack));

  StackDestroy(&stack);
}

// ...

int TreeContains(const Tree* root, const ItemType item) {
  if (root == NULL) return 0;
  if (root->item == item) return 1;

  return TreeContains(root->left,item) || TreeContains(root->right,item);
}

// ...

// Storing and reading from a FILE

struct _fileNode {
  ItemType item;
  int emptyLeftSubTree;
  int emptyRightSubTree;
};

static void _storeInFile(const Tree* root, FILE* f, int fileType) {
  if (root == NULL) {
    return;
  }

  struct _fileNode r;
  r.item = root->item;
  r.emptyLeftSubTree = (root->left == NULL);
  r.emptyRightSubTree = (root->right == NULL);

  if (fileType == 1) {
    fprintf(f, "%d %d %d ", r.item, r.emptyLeftSubTree, r.emptyRightSubTree);
  } else {
    fwrite(&r, sizeof(struct _fileNode), 1, f);
  }

  _storeInFile(root->left, f, fileType);
  _storeInFile(root->right, f, fileType);
}

static void _getFromFile(Tree** pRoot, FILE* f, int fileType) {
  struct _fileNode r;

  if (fileType == 1) {
    fscanf(f, "%d", &r.item);
    fscanf(f, "%d", &r.emptyLeftSubTree);
    fscanf(f, "%d", &r.emptyRightSubTree);
  } else {
    fread(&r, sizeof(struct _fileNode), 1, f);
  }

  Tree* newNode = (Tree*)malloc(sizeof(struct _TreeNode));

  newNode->item = r.item;

  if (r.emptyLeftSubTree) {
    newNode->left = NULL;
  } else {
    _getFromFile(&(newNode->left), f, fileType);
  }

  if (r.emptyRightSubTree) {
    newNode->right = NULL;
  } else {
    _getFromFile(&(newNode->right), f, fileType);
  }

  *pRoot = newNode;
}

int TreeStoreInFile(const Tree* root, char* fileName, int fileType) {
  FILE* f = fopen(fileName, "w");
  if (f == NULL) {
    return 0;
  }

  _storeInFile(root, f, fileType);

  fclose(f);
  return 1;
}

Tree* TreeGetFromFile(char* fileName, int fileType) {
  FILE* f = fopen(fileName, "r");
  if (f == NULL) {
    return NULL;
  }

  Tree* root;
  _getFromFile(&root, f, fileType);

  fclose(f);
  return root;
}

// JUST FOR RUNNING EXAMPLES - REMOVE FROM THE INTERFACE

Tree* createExampleTree(void) {
  // SHOULD NEVER BE DONE LIKE THIS !!!???!!!

  int numNodes = 8;

  Tree* nodes[numNodes];

  for (int i = 0; i < numNodes; i++) {
    nodes[i] = (Tree*)malloc(sizeof(Tree));
    nodes[i]->item = i + 1;
    nodes[i]->left = nodes[i]->right = NULL;
  }

  nodes[3]->left = nodes[7];

  nodes[1]->left = nodes[3];
  nodes[1]->right = nodes[4];

  nodes[2]->left = nodes[5];
  nodes[2]->right = nodes[6];

  nodes[0]->left = nodes[1];
  nodes[0]->right = nodes[2];

  return nodes[0];
}
