#include "sorted-list.c"

//For testing purposes, including comparator and destroyer functions

int compInts (void* a, void* b){
  int i = *(int*)a;
  int j = *(int*)b;
  return i-j;
}

int compDoubles (void* a, void* b){
  double i = *(double*)a;
  double j = *(double*)b;

  return (i-j);
}
int compFloats (void* a, void* b){
  float i = *(float*)a;
  float j = *(float*)b;

  return (i-j);
}

void destruct (void* a){
  free(a);
}

int main(int argc, char**argv){

  SortedListPtr list = SLCreate(compInts,destruct);

  int* ob1 = malloc(sizeof(int*));
  *ob1 = 5;
 
  int* ob2 = malloc(sizeof(int));
   *ob2 = 4;

  int* ob3 = malloc(sizeof(int));
  *ob3 = 3;
  
  int* ob4 = malloc(sizeof(int));
  *ob4 = 6;
  
  int* ob5 = malloc(sizeof(int));
  *ob5 = 1;

  int* ob6 = malloc(sizeof(int));
  *ob6 = 1;

  SLInsert(list,ob1); 
    SLInsert(list,ob2);
    SLInsert(list,ob3);
    // SLRemove(list,ob3);
   SLInsert(list,ob4);
    SLInsert(list,ob6);
    SLInsert(list,ob5);
     SLRemove(list,ob6);
     SLRemove(list,ob4);
     // SLRemove(list,ob4);
    SortedListIteratorPtr iter = SLCreateIterator(list);
    SortedListIteratorPtr iter2 = SLCreateIterator(list);
    //  SortedListIteratorPtr iter3 = SLCreateIterator(list);
   SLNextItem(iter2);
   SLDestroyIterator(iter2);
   SLDestroyIterator(iter);

   Node *checker = malloc(sizeof(Node));                                                                                        
     checker = list->head;                                                                                                      
     while(checker!=NULL){                                                                                                      
     printf("checker:%d  ref:%d\n", *((int*)checker->data),checker->refcount );
     checker = checker->next;                                                                                                
   }                                                                                                               
  
     //  SortedListIteratorPtr iter = SLCreateIterator(list);
  

  /* while(SLNextItem(iter)!=NULL){

        printf("d:%d\n",*((int*)(iter->curr)->data));
	
     }
  */

  SLDestroy(list);

  return 0;

}
