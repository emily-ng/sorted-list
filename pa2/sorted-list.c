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
  printf("\n");
  printf("NEW INSERT\n");
  Node* new = malloc(sizeof(Node));
  new->next = NULL;
  new->data = newObj;
  new->refcount = 0;
  
  SortedListIteratorPtr iter = SLCreateIterator(list); 
  printf("Input:  %d\n", *((int*)new->data));

  if(list->head==NULL){
    printf("CREATE HEAD\n");
    //pointer to new node
    list->head = malloc(sizeof(Node));
    list->head = new;
    (list->head)->refcount++;
    printf("r:%d\n",(list->head)->refcount);
    return 1;
  }
 
  //Checks comparator function for value 
  else{
    //AddToFront ---NEEDED
    if( list->cf(new->data,(list->head)->data)==0  ){
       printf("EQUAL to head\n");
       // (iter->curr)->refcount--;
      return 0;
    }
    else if( list->cf(new->data,(list->head)->data)>0 ){
          printf("GREATER THAN HEAD\n");
	  new->next = list->head;
	  list->head = new;
	  return 1;
     }
    else{
      while(( iter->curr)->next!=NULL){
	if( list->cf(new->data,((iter->curr)->next)->data)==0 ){
	  printf("EQUAL to the next node from iter\n");
	  //REMOVE ITERATOR
	  (iter->curr)->refcount--;
	  return 0;
	  }
	else if(list->cf(new->data,((iter->curr)->next)->data)>0){
	  printf("INSERT IN BETWEEN NODES\n");
	  new->next  = (iter->curr)->next;
	  ((iter->curr)->next)->refcount++;
	  (iter->curr)->next = new;
	  new->refcount++;
	  (iter->curr)->refcount--;
	  return 1;
	}
	else{
	 //Next is greater, advance iterator
	  printf("ADVANCE\n");
	 (iter->curr)->refcount--;
	 iter->curr = (iter->curr)->next;
	 (iter->curr)->refcount++;
	}
	//(iter->curr)->refcount--;
	
      }
      //Reaches end, less than rest of list
        (iter->curr)->next = new;
	//printf("check3pls\n");
	((iter->curr)->next)->refcount++;
	//printf("c5\n");
	(iter->curr)->refcount--;
	//printf("c6\n");
	iter->curr = (iter->curr)->next;
	//printf("c7\n");
	(iter->curr)->refcount++;
	
	printf("ADD TO END\n");
	return 1;

    }
       

  }    
  
  // printf("\n");
  //return 0;

}


//TODO
int SLRemove(SortedListPtr list, void *newObj){
 
  return 0; 
}

//TODO
SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
  SortedListIteratorPtr sp = malloc(sizeof(SortedListIteratorPtr));  
  Node* tempcurr = malloc(sizeof(Node));
  tempcurr = list->head;
  sp->curr = list->head;
  if(tempcurr==NULL){
    printf("iter is NULL\n");
    return NULL;
  }
  else{
    tempcurr->refcount++; 
    return sp;
  }
}

//TODO
void SLDestroyIterator(SortedListIteratorPtr iter){
  free(iter->curr);
  free(iter);
}

//TODO
void * SLGetItem( SortedListIteratorPtr iter ){
  if(iter->curr==NULL){
    printf("get NULL\n");
    return 0;
  }
  else{
     printf("get item: %d\n", *((int*)(iter->curr)->data) );
    return (iter->curr)->data;
  }
}

//TODO
void * SLNextItem(SortedListIteratorPtr iter){
  if(iter->curr == NULL){
    return NULL;
  }
  else{
    //might be an issue??
    if((iter->curr)->next != NULL){
      return ((iter->curr)->next)->data;
    }
    else{
      return NULL;
    }
  }
}
