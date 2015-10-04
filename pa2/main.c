#include "sorted-list.h"

/*For testing purposes, including comparator and destruct functions*/

int compInts (void* a, void* b){
  int i = *(int*)a;
  int j = *(int*)b;
  return i-j;
}

int compFloats (void* a, void* b){
  float i = *(float*)a;
  float j = *(float*)b;

  return (i-j);
}

int compChars(void* a, void* b){
  char i = *(char*)a;
  char j = *(char*)b;
  return (i-j);
}

int compStrings(void* a, void* b){
  char* i = a;
  char* j = b;

  return strcmp(i,j);
}

void destruct (void* a){
  free(a);
}

int main(int argc, char**argv){

  SortedListPtr list = SLCreate(compInts,destruct);
  int* ob1 = malloc(sizeof(int));
  int* ob2 =  malloc(sizeof(int));
  int* ob3 =  malloc(sizeof(int));
  int* ob4 =  malloc(sizeof(int));
  int* ob5 =  malloc(sizeof(int));
  int* ob6 =  malloc(sizeof(int));

  SortedListIteratorPtr iter;
  SortedListIteratorPtr iter2;
 
  
  *ob1 = 5;
  *ob2 = 9;
  *ob3 = 3;
  *ob4 = 7;
  *ob5 = 13;
  *ob6 = 2;

  SLInsert(list,ob1); 


  
  SLInsert(list,ob2);

  SLInsert(list,ob4);

  SLInsert(list,ob5);

  SLInsert(list,ob6);


   iter = SLCreateIterator(list);
   /* iter2 = SLCreateIterator(list);*/

   SLNextItem(iter);

   SLRemove(list,ob5);
 

     SLNextItem(iter);


   /*  SLDestroyIterator(iter);*/

   SLPrintInts(list);
   
   /*   SLDestroyIterator(iter2);*/
   /* SLDestroyIterator(iter);*/

   free(ob1);
   free(ob2);
   free(ob3);
   free(ob4);
   free(ob5);
   free(ob6);
  
  SLDestroy(list);

  return 0;

}
