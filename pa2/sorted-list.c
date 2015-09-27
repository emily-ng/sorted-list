/*
 * sorted-list.c
 */

#include "sorted-list.h"


SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
  if(cf!=NULL){
    SortedListPtr sl = malloc(sizeof(SortedListPtr));
    sl->head = NULL;
    sl->cf = cf;
    return sl;
  }
  else{
    return NULL;
  }
}


void SLDestroy(SortedListPtr list){
  Node* lh= list->head;
  Node* temp;
  while(lh!=NULL){
    temp = lh;
    lh = lh->next;
    free(temp);
  }
  free(list);
}


//TODO
int SLInsert(SortedListPtr list, void *newObj){
  
  Node* new = malloc(sizeof(Node));
  new->next = NULL;
  new->data = newObj;
  new->refcount = 1;


  if(list->head==NULL){
    printf("Empty\n");
    list->head = malloc(sizeof(Node));
    (list->head)->next = new;
    printf("%p  %d\n",new->data, *((int*)new->data));
    SortedListIteratorPtr sp = SLCreateIterator(list); 
    printf("sp: %p\n",sp);
    return 1;
  }
  else{
    
  }


  return 1;


}


//TODO
int SLRemove(SortedListPtr list, void *newObj){
 
  return 0; 
}

//TODO
SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
  SortedListIteratorPtr sp = malloc(sizeof(SortedListIteratorPtr));  
  sp->curr = list->head;
  if(sp->curr==NULL){
    printf("iter is NULL\n");
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
  if(iter->curr == NULL){
    return NULL;
  }
  else{
    return iter->right;
  }
}
