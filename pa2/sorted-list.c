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
  //  Node* temp = malloc(sizeof(Node));
  Node* temp = NULL;
  printf("Input:  %d\n", *((int*)new->data));

  if(list->head==NULL){
    printf("CREATE HEAD\n");
    //pointer to new node
    list->head = malloc(sizeof(Node));
    new->refcount++;
    list->head = new;
    // (list->head)->refcount++;
    //    printf("r:%d\n",(list->head)->refcount);
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
      new->refcount++;
      list->head = new;
      return 1;
    }
    else{
      temp = list->head;
      temp-> next = (list->head)->next;
      while( temp->next!=NULL){
	if( list->cf(new->data,(temp->next)->data)==0 ){
	  printf("EQUAL to the next node from iter\n");
	  return 0;
	}
	else if(list->cf(new->data,(temp->next)->data)>0){
	  //new data greater than next
	  printf("INSERT IN BETWEEN NODES\n");
	  new->refcount++;
	  new->next  = temp->next;
	  temp->next = new;
	  return 1;
	}
	else{
	  //Next is greater, advance iterator
	  //  printf("ADVANCE\n");
	  temp = temp->next;
	}
	
      }
      //Reaches end, less than rest of list
      new->refcount++;
      temp->next = new;	
      printf("ADD TO END\n");
      return 1;

    }       

  }    
  
}


//TODO
int SLRemove(SortedListPtr list, void *newObj){
  // Node* prev = malloc(sizeof(Node));
  //Node* curr = malloc(sizeof(Node));
  Node* prev = NULL;
  Node* curr = NULL;
  
  /* if(list->cf(newObj,list->head->data)==0){
      printf("FOUND A MATCH AT HEAD --REMOVE\n");
      list->head = list->head->next;
      return 1;
      }*/
  curr= list->head;
  curr->next  = (list->head)->next;
  prev=curr;

  while(curr!=NULL){
    if(list->cf(newObj,curr->data)==0){
       if(curr==list->head){printf(
       "THIS IS THE HEAD!\n");
	list->head = curr->next;
	}
      printf("FOUND A MATCH IN LIST --REMOVE\n ");
      curr->refcount--;
      prev->next = curr->next;
      return 1;
    }  
    prev = curr;
    curr = curr->next;
  }
  printf("FAILED TO REMOVE\n");
  return 0; 
}
//TODO
SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
  if(list->head==NULL){
    //    printf("list is empty; iter is NULL\n");
    return NULL;
  }
  else{
    SortedListIteratorPtr sp = malloc(sizeof(SortedListIteratorPtr));  
    sp->curr = malloc(sizeof(Node));
    sp->right = malloc(sizeof(Node));
   
    sp->curr = list->head;
    list->head->refcount++;
    sp->right = (list->head)->next;
    //    printf("d: %d %d\n",*((int*)sp->curr->data),*((int*)sp->right->data));
    printf("NOT EMPTY\n");
    return sp;
  }
}

void SLDestroyIterator(SortedListIteratorPtr iter){
  iter->curr->refcount--;
  free(iter->curr);
  free(iter->right);
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
  if(iter->right == NULL){
    printf("NEXT IS NULL\n");
    return NULL;
  }
  else{
    printf("NEXT IS NOT NULL\n");
    iter->curr->refcount--;
    iter->curr = iter->right;
    iter->curr->refcount++;
    iter->right = (iter->curr)->next;
    return iter->curr->data;    
    
  }
}
