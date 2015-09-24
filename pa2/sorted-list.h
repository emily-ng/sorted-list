#ifndef SORTED_LIST_H
#define SORTED_LIST_H
/*
 * sorted-list.h
 */

#include <stdlib.h>
#include <stdio.h>

struct Object_{
  void* data;
  struct Object_* next;
};
typedef struct Object_ Object;

struct SortedList
{
  Object* head;
  int (*cf)(void*, void*);
  int list_length;
};
typedef struct SortedList* SortedListPtr;

//left is greater than; right is less than
struct SortedListIterator
{
  Object* left;
  Object* right;
  Object* curr;
};
typedef struct SortedListIterator* SortedListIteratorPtr;

typedef int (*CompareFuncT)( void *, void * );

typedef void (*DestructFuncT)( void * );

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df);

void SLDestroy(SortedListPtr list);

int SLInsert(SortedListPtr list, void *newObj);

int SLRemove(SortedListPtr list, void *newObj);

SortedListIteratorPtr SLCreateIterator(SortedListPtr list);

void SLDestroyIterator(SortedListIteratorPtr iter);

void * SLGetItem( SortedListIteratorPtr iter );

void * SLNextItem(SortedListIteratorPtr iter);

#endif
