#include "sorted-list.c"

//For testing purposes, including comparator and destroyer functions

int compInts (void* a, void* b){
  int i = *(int*)a;
  int j = *(int*)b;

  return (i-j);
}

void destroyer (void* a){
  free(a);
}

int main(int argc, char**argv){
  printf("check1\n");
  SortedListPtr list = SLCreate(compInts,destroyer);
 
  printf("check2\n");
  int k = 10;
  void* ob1 = &k;
 
  int j = 8;
  void* ob2 = malloc(sizeof(int));
  ob2 = &j;

  SLInsert(list,ob1);
  
  SLInsert(list,ob2);

  SLDestroy(list);

  return 0;
}
