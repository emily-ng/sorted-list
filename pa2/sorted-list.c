/*
 *Tim Goetjen
 *Emily Ng
 *CS214 Assignment 2
 *
 * sorted-list.c
 */

#include "sorted-list.h"

/*
 *Creates pointer to a new sorted list object
 *returns sorted list pointer if created successfully
 *returns NULL otherwise
 */

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

/*
 *Destroys sorted list, freeing allocated memory
 */

void SLDestroy(SortedListPtr list){
  Node* lh= list->head;
  Node* temp;
  while(lh!=NULL){
    temp = lh;
    lh = lh->next;
    list->df(temp->data);
    free(temp);
  }
  free(list);
}


/*
 *Function that inserts a node into list, excluding duplicates
 *returns 1 when successful
 *returns 0 when unsuccessful
 */

int SLInsert(SortedListPtr list, void *newObj){  
  Node* temp = NULL;
  /*checks for empty list*/
  if(list->head==NULL){
    list->head = malloc(sizeof(Node));
    list->head->refcount++;
    list->head->data = newObj;
    return 1;
  }
 
  /*Checks when list is not empty*/
  else{
    Node* new = malloc(sizeof(Node));
    new->next = NULL;
    /*new->data = malloc(sizeof(int));*/
    new->data = newObj;
    new->refcount = 0;
    /*when item to add data is equal to data of head*/
    if( list->cf(new->data,(list->head)->data)==0  ){
      return 0;
    }
    /*when item to add data is greater than head data*/
    else if( list->cf(new->data,(list->head)->data)>0 ){
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
	  return 0;
	}
	/*new data greater than next*/
	else if(list->cf(new->data,(temp->next)->data)>0){
	  new->refcount++;
	  new->next  = temp->next;
	  temp->next = new;
	  return 1;
	}
	/*continue to traverse list*/
	else{
	  temp = temp->next;
	}	
      }
      
      new->refcount++;
      temp->next = new;	
      return 1;

    }       

  }    
  
}

/*
 *Function that removes node from sorted list
 *Returns 0 when fails
 *Returns 1 when succeeds
 */
int SLRemove(SortedListPtr list, void *newObj){
  Node* prev = NULL;
  Node* curr = NULL;
  Node* delete = NULL;  

  curr= list->head;
  if(curr == NULL){ /*Remove from empty list fails*/
    return 0;
  }
  curr->next  = (list->head)->next;
  prev=curr;

  /*traverses sorted list*/
  while(curr!=NULL){
    /*when node to be deleted is the head of list*/
    if(list->cf(newObj,curr->data)==0){
      if(curr==list->head){
	list->head = curr->next;
      }
      curr->refcount--;
      /*check refcount to see if node should be freed*/
      if(curr->refcount==0){
        delete = curr;
      }

      prev->next = curr->next;

      /*node has 0 refcount, free it*/
      if(delete!=NULL){
	list->df(delete->data);
	free(delete);
      }
       return 1;
    }  
    /*continue traverse*/  
    prev = curr;
    curr = curr->next;
  }
  /*unsuccessful remove*/
  return 0; 
}
/*
 *Function used to create iterator as pointer to head of list
 *Returns iterator when successful
 *Returns NULL otherwise
 */
SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
  /*checks for empty list*/
  if(list->head==NULL){
    return NULL;
  }
  /*list is not empty*/
  else{
    SortedListIteratorPtr sp = malloc(sizeof(SortedListIteratorPtr));  
    sp->curr = malloc(sizeof(Node));
   
    sp->curr = list->head;
    list->head->refcount++;
 
    return sp;
  }
}
/*
 *Function that destroys iterator object
 *Frees memory allocated when iterator is created
 */
void SLDestroyIterator(SortedListIteratorPtr iter){
  iter->curr->refcount--;
  free(iter);
}

/*
 *Function that retrieves data at node that iterator currently points to
 *Returns 0 when iter points to NULL
 *Returns data when iter points to a node
 */
void * SLGetItem( SortedListIteratorPtr iter ){
  /*current node is NULL*/
  if(iter->curr==NULL){
    return 0;
  }
  /*current node is not NULL*/
  else{
    return (iter->curr)->data;
  }
}

/*
 *Function that retrieves data of the next of the node that iter points to
 *Also advances the iterator
 *Returns NULL when the next is NULL
 *Returns data when next node is not NULL
 *If the node the iterator points to is removed, this function will still continue the traverse,
 *and will point the iterator to the next node of the removed node.
 *If a node is inserted between the node the iterator points to and the next node,
 *when the iterator is advanced it will point to the newly inserted node. 
*/
void * SLNextItem(SortedListIteratorPtr iter){  
  if(iter->curr->next == NULL){
    iter->curr = NULL;
    return iter->curr;
  }
  /*next node is not NULL*/
  else{
    /*advances iterator*/
    iter->curr->refcount--;
     iter->curr = iter->curr->next;
    iter->curr->refcount++;
    /*    iter->right = (iter->curr)->next;*/
    return iter->curr->data;    
    
  }
}

/*integer print functions*/
void SLPrintInts(SortedListPtr list){
  Node *checker;
  checker = list->head;
  if(checker==NULL){
    printf("empty list: nothing to print\n");
  }
  else{
    while(checker!=NULL){ 
      printf("%d  ref:%d\n", *((int*)checker->data),checker->refcount );
      checker = checker->next;
    }
  }
  printf("\n");
}

/*string print function*/
void SLPrintStrings(SortedListPtr list){
  Node *checker;
  checker = list->head;
  if(checker==NULL){
    printf("empty list: nothing to print\n");
  }
  else{
    while(checker!=NULL){ 
      printf("%s  ref:%d\n", (char*)checker->data,checker->refcount );
      checker = checker->next;
    }
  }
}
