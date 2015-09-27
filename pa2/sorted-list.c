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
  
  Node* new = malloc(sizeof(Node));
  new->next = NULL;
  new->data = newObj;
  new->refcount = 1;
  
  SortedListIteratorPtr iter = SLCreateIterator(list); 
  
  if(list->head==NULL){
    list->head = malloc(sizeof(Node));
    list->head = new;
    printf("%p  %d\n",new->data, *((int*)new->data));
    
    return 1;
  }
 
  //Checks comparator function for value
   
   
  else{
  
    printf("%p  %d\n",new->data, *((int*)new->data));
    if(SLNextItem(iter)==NULL){
      (list->head)->next = new;   
    }
    else{

      while(SLNextItem(iter)!=NULL){
      
	if(list->cf(new->data,SLGetItem(iter))==0){
	  printf("equal\n");
	  return 0;
	}
	else if( (list->cf(new->data,SLGetItem(iter))) <0 && (list->cf(new->data,SLNextItem(iter)))>0 ){
	  printf("New Data is Less Than iter->curr ---- INSERTING\n");
	  new->next = (iter->curr)->next;
	  (iter->curr)->next = new;

	}
	else{
	  printf("New Data is Greater Than iter->curr\n");
	}
	printf("iter->curr: %d\n",*((int*)(iter->curr)->data ) );
	(iter->curr)->refcount--;
	iter->curr = (iter->curr)->next;
	printf("iter->curr2: %d\n",*((int*)(iter->curr)->data ) );
   	(iter->curr)->refcount++;
      }
      printf("break\n");
      // (iter->curr)->next = new; 

    }  
  
    

  }        
  
  Node *checker = malloc(sizeof(Node));
  checker = list->head;
  while(checker!=NULL){
    printf("checker: %d\n", *((int*)checker->data) );
    checker = checker->next;
  }

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
