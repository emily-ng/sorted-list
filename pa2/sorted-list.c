/*
 * sorted-list.c
 */

#include "sorted-list.h"


SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
  if(cf!=NULL&& df!=NULL){
    SortedListPtr sl = malloc(sizeof(SortedListPtr));
    sl->head = NULL;
    sl->cf = cf;
    sl->df = df;
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
  Node* temp = malloc(sizeof(Node));
  //SortedListIteratorPtr iter = SLCreateIterator(list); 
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
      temp = list->head;
      temp-> next = (list->head)->next;
      while( temp->next!=NULL){
	if( list->cf(new->data,(temp->next)->data)==0 ){
	  printf("EQUAL to the next node from iter\n");
	  //  temp->refcount--;
	  return 0;
	  }
	else if(list->cf(new->data,(temp->next)->data)>0){
	  printf("INSERT IN BETWEEN NODES\n");
	  new->next  = temp->next;
	  (temp->next)->refcount++;
	  temp->next = new;
	  new->refcount++;
	  temp->refcount--;
	  return 1;
	}
	else{
	 //Next is greater, advance iterator
	  printf("ADVANCE\n");
	 temp->refcount--;
	 temp = temp->next;
	 temp->refcount++;
	}
	
      }
      //Reaches end, less than rest of list
        temp->next = new;
	//printf("check3pls\n");
	(temp->next)->refcount++;
	//printf("c5\n");
	temp->refcount--;
	//printf("c6\n");
	temp = temp->next;
	//printf("c7\n");
	temp->refcount++;
	
	printf("ADD TO END\n");
	return 1;

    }
       

  }    
  
}


//TODO
int SLRemove(SortedListPtr list, void *newObj){
 
  return 0; 
}
//TODO
SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
  SortedListIteratorPtr sp = malloc(sizeof(SortedListIteratorPtr));  
  sp->curr = malloc(sizeof(Node));
  sp->right = malloc(sizeof(Node));
  // tempcurr = list->head;
  sp->curr = list->head;
  sp->right = (list->head)->next;
  if(sp->curr==NULL){
    printf("list is empty; iter is NULL\n");
    return NULL;
  }
  else{
    printf("d: %d %d\n",*((int*)sp->curr->data),*((int*)sp->right->data));
    printf("NOT EMPTY\n");
    return sp;
  }
}

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
  printf("NEXT\n");
  if(iter == NULL){
    printf("NEXT IS NULL\n");
    return NULL;
  }
  else{
    printf("NEXT IS NOT NULL\n");
    //might be an issue??
    if((iter->curr)->next != NULL){
      return ((iter->curr)->next)->data;
    }
    else{
      return NULL;
    }
  }
}
