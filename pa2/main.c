#include "sorted-list.c"

//For testing purposes, including comparator and destroyer functions

int compInts (void* a, void* b){
  int i = *(int*)a;
  int j = *(int*)b;

  if(i==j){
    return 0;
  }
  else if (i>j){
    return 1;
  }
  else {
    return -1;
  }
}

void destroyer (void* a){
  free(a);
}

int main(int argc, char**argv){
  
  SortedListPtr list = SLCreate(compInts,destroyer);
  
  void* ob1 = 1;
  void* obj2 = 2;
  void* obj3 =3;

  SLInsert(list,ob1);
  SLInsert(list,ob2);
  SLInsert(list, ob3);

  SLDestroy(list);

  return 0;
}
