#ifndef SORTED_LIST_H
#define SORTED_LIST_H
/*
 * sorted-list.h
 */

#include <stdlib.h>
#include <stdio.h>

struct Node_{
  void* data;
  struct Node_* next;
  int refcount;
};
typedef struct Node_ Node;

struct SortedList
{
  Node* head;
  int (*cf)(void*, void*);
  int (*df)(void*);
};
typedef struct SortedList* SortedListPtr;

//left is greater than; right is less than
struct SortedListIterator
{
  Node* left;
  Node* right;
  Node* curr;
};

typedef struct SortedListIterator* SortedListIteratorPtr;

typedef int (*CompareFuncT)( void *, void * );

typedef void (*DestructFuncT)( void * );

int compInts(void* a, void* b);

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df);

void SLDestroy(SortedListPtr list);

int SLInsert(SortedListPtr list, void *newObj);

int SLRemove(SortedListPtr list, void *newObj);

SortedListIteratorPtr SLCreateIterator(SortedListPtr list);

void SLDestroyIterator(SortedListIteratorPtr iter);

void * SLGetItem( SortedListIteratorPtr iter );

void * SLNextItem(SortedListIteratorPtr iter);

#endif
