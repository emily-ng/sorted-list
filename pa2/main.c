#include "sorted-list.h"

/*For testing purposes, including comparator and destruct functions*/

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
  int* ob1;
  int* ob2;
  int* ob3;
  int* ob4;
  int* ob5;
  int* ob6;
 
  SortedListIteratorPtr iter;
  SortedListIteratorPtr iter2;
 
  ob1 = malloc(sizeof(int*));
  *ob1 = 5;
 
  ob2 = malloc(sizeof(int));
   *ob2 = 4;

   ob3 = malloc(sizeof(int));
  *ob3 = 3;
  
  ob4 = malloc(sizeof(int));
  *ob4 = 6;
  
  ob5 = malloc(sizeof(int));
  *ob5 = 1;

  ob6 = malloc(sizeof(int));
  *ob6 = 1;

  SLInsert(list,ob1); 
    SLInsert(list,ob2);
    SLInsert(list,ob3);

   SLInsert(list,ob4);
    SLInsert(list,ob6);
    SLInsert(list,ob5);
     SLRemove(list,ob6);
     SLRemove(list,ob4);

    iter = SLCreateIterator(list);
    iter2 = SLCreateIterator(list);

   SLNextItem(iter2);
   
   SLPrint(list);
  
   SLDestroyIterator(iter2);
   SLDestroyIterator(iter);

   free(ob1);
   free(ob2);
   free(ob3);
   free(ob4);
   free(ob5);
   free(ob6);

  SLDestroy(list);

  return 0;

}
