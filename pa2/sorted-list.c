/*
 * sorted-list.c
 */

#include "sorted-list.h"


SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
  if(cf!=NULL){
    SortedListPtr sl = malloc(sizeof(SortedListPtr));
    sl->head = NULL;
    sl->list_length = 0;
    sl->cf = cf;
    return sl;
  }
  else{
    return NULL;
  }
}


void SLDestroy(SortedListPtr list){
  Object* lh= list->head;
  Object* temp;
  while(lh!=NULL){
    temp = lh;
    lh = lh->next;
    free(temp);
  }
  free(list);
}


//TODO
int SLInsert(SortedListPtr list, void *newObj){
  if(list->cf(list,newObj)==0){
    return 0;
  }
  else{
    return 1;
  }
  
  return 0;
}


//TODO
int SLRemove(SortedListPtr list, void *newObj){
 
  return 0; 
}


SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
  SortedListIteratorPtr sp = malloc(sizeof(SortedListIteratorPtr));  
  sp->curr = list->head;
  if(sp->curr==NULL){
    return NULL;
  }
  else{
    return sp;
  }
}

//TODO
void SLDestroyIterator(SortedListIteratorPtr iter){
}

//TODO
void * SLGetItem( SortedListIteratorPtr iter ){
  return NULL;
}

//TODO
void * SLNextItem(SortedListIteratorPtr iter){
  return NULL;
}
