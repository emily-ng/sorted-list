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
    list->head = malloc(sizeof(Node));
    //    printf("head size: %lu\n", sizeof(list->head));
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
	  printf("EQUAL to a node\n");
	  return 0;
	  }
	else if(list->cf(new->data,((iter->curr)->next)->data)>0){
	  printf("INSERT IN BETWEEN NODES\n");
	  new->next  = (iter->curr)->next;
	  (iter->curr)->next = new;
	return 1;
	}
	else{
	 iter->curr = (iter->curr)->next;
	}
	
      }
      //Reaches end, less than rest of list
        (iter->curr)->next = new;
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
  // Node * templeft = malloc(sizeof(Node));
  // Node* tempright = malloc(sizeof(Node));
  tempcurr = list->head;
  sp->curr = list->head;
  if(tempcurr==NULL){
    printf("iter is NULL\n");
    return NULL;
  }
  else{
    tempcurr->refcount++; 
    // printf("iter: %d  refcount:%d \n", *((int*)tempcurr->data), tempcurr->refcount );
    return sp;
  }
}

//TODO
void SLDestroyIterator(SortedListIteratorPtr iter){
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
