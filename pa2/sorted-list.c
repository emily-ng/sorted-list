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
  // Node* temp1 = malloc(sizeof(Node));
  // Node* temp2 = malloc(sizeof(Node));
  printf("NEW INSERT\n");
  Node* new = malloc(sizeof(Node));
  new->next = NULL;
  new->data = newObj;
  new->refcount = 1;
  
  SortedListIteratorPtr iter = SLCreateIterator(list); 
  
  if(list->head==NULL){
    list->head = malloc(sizeof(Node));
    list->head = new;
    printf("pnull: %p  %d\n",new->data, *((int*)new->data));

    return 1;
  }
 
  //Checks comparator function for value
   
   
  else{
    printf("iter->curr??: %d\n",*((int*)(iter->curr)->data ) );
    printf("p: %p  %d\n",new->data, *((int*)new->data));

    if( (iter->curr)->next==NULL){
      printf("NextItem is NULL\n");
      // (list->head)->next = new; 
      (iter->curr)->next = new;
      iter->curr = (iter->curr)->next;
      printf("iter->curr next: %d\n",*((int*)(iter->curr)->data ) );
      printf("\n");
      return 1;
    }
    else{
      while( (iter->curr)->next!=NULL){
	 printf("ELSE iter->curr is now: %d\n",*((int*)(iter->curr)->data ) );
	if( *( (int*)(((iter->curr)->next)->data) ) < *((int*)(new->data))   ){
	new->next  = (iter->curr)->next;
	(iter->curr)->next = new;
	return 1;
	}
	//	 printf("ELSE iter->curr is now: %d\n",*((int*)(iter->curr)->data ) );
	 iter->curr = (iter->curr)->next;
      }
         (iter->curr)->next = new;
	 //return 1;
     
    }  
  
    

  }        
  
  /*  Node *checker = malloc(sizeof(Node));
  checker = list->head;
  while(checker!=NULL){
    printf("checker: %d\n", *((int*)checker->data) );
    checker = checker->next;
  }
  */
  printf("\n");
  return 0;

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
