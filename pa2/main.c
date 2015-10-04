#include "sorted-list.h"

/*For testing purposes, including comparator and destruct functions*/

int compInts (void* a, void* b){
  int i = *(int*)a;
  int j = *(int*)b;
  return i-j;
}

int compFloats (void* a, void* b){
  float i = *(float*)a;
  float j = *(float*)b;

  return (i-j);
}

int compChars(void* a, void* b){
  char i = *(char*)a;
  char j = *(char*)b;
  return (i-j);
}

int compStrings(void* a, void* b){
  char* i = a;
  char* j = b;

  return strcmp(i,j);
}

void destruct (void* a){
  free(a);
}

int main(int argc, char**argv){

  SortedListPtr list = SLCreate(compInts,destruct);

  int* ob1 = malloc(sizeof(int));
  int* ob2 =  malloc(sizeof(int));
  int* ob3 =  malloc(sizeof(int));
  int* ob4 =  malloc(sizeof(int));
  int* ob5 =  malloc(sizeof(int));
  int* ob6 =  malloc(sizeof(int));
  int* ob7 =  malloc(sizeof(int));
  int* ob8 =  malloc(sizeof(int));
  int* ob9 =  malloc(sizeof(int));
  SortedListIteratorPtr iter;
  SortedListIteratorPtr iter2;
  SortedListIteratorPtr iter3;
  *ob1 = 5;
  *ob2 = 9;
  *ob3 = 3;
  *ob4 = 7;
  *ob5 = 13;
  *ob6 = 2;
  *ob7 = 5;
  *ob8 = 1;
  *ob9 = 4;
  
  /*Remove attempted on empty list, SLRemove returns 0*/
  SLRemove(list,ob1);
  /*Iterator create attempted, SLCreateIterator returns NULL*/
  iter = SLCreateIterator(list);
  /*Insert into empty list, SLInsert returns 1*/
  SLInsert(list,ob1);
  SLPrintInts(list);
  /*Remove only node (head), SLRemove returns 1*/
  SLRemove(list,ob1);
  SLInsert(list,ob2);
  SLPrintInts(list);
  /*Insert in front of single node list, SLInsert returns 1*/
  SLInsert(list,ob3);
  SLPrintInts(list);
  /*Insert at end of list, SLInsert returns 1*/
  SLInsert(list,ob4);
  SLPrintInts(list);
  /*Insert in between nodes, SLInsert returns 1*/
  SLInsert(list,ob5);
  SLPrintInts(list);
  /*Insert of duplicate value, no node inserted, SLInsert returns 0*/
  SLInsert(list,ob7);
  SLPrintInts(list);
  /*Additional nodes inserted*/
  SLInsert(list,ob6);
  SLPrintInts(list);
  /*Remove attempted on item not in list, SLRemove returns 0*/
  SLRemove(list,ob8);
  SLPrintInts(list);
  /*Remove last node in list, SLRemove returns 1*/
  SLRemove(list,ob6);
  SLPrintInts(list);
  /*Remove node in middle of list, SLRemove returns 1*/
  SLRemove(list,ob4);
  SLPrintInts(list);

  /*Iterator created, SLCreateIterator returns pointer*/
  iter2 = SLCreateIterator(list);
  /*Node that iterator points to is removed then SLNextItem called, Iterator continues
    to next of removed node*/
  SLRemove(list,ob5);
  SLNextItem(iter2);
  SLPrintInts(list);
  /*Next node of node that iterator points to is removed then SLNextItem called,
    iterator moves on to the node past the removed node.
    SLGetItem used to collect data from node iterator points to.*/
  printf("Iter2 points to %d\n",*((int*)(SLGetItem(iter2))));
  SLNextItem(iter2);
  SLPrintInts(list);
  /*Node inserted after iterator and iterator advanced to that node*/
  SLInsert(list,ob9);
  SLNextItem(iter2);
  SLPrintInts(list);
  /*GetItem of NULL iterator returns 0*/
  SLNextItem(iter2);
  SLNextItem(iter2);
  if(iter2->curr==NULL){
    printf("Iter2 is NULL\n");
  }
  iter3 = SLCreateIterator(list);
  SLDestroyIterator(iter3);
  SLDestroy(list);

  return 0;

}
