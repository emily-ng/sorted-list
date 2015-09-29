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
 
  SortedListPtr list = SLCreate(compInts,destroyer);
 
  int k = 10;
  void* ob1 = malloc(sizeof(int));
  ob1 = &k;
 
  int j = 8;
  void* ob2 = malloc(sizeof(int));
  ob2 = &j;

  int m = 5;
  void* ob3 = malloc(sizeof(int));
  ob3 = &m;

  int n = 6;
  void* ob4 = malloc(sizeof(int));
  ob4 = &n;
 
  int o = 3;
  void* ob5 = malloc(sizeof(int));
  ob5 = &o;

  SLInsert(list,ob1);
  
  SLInsert(list,ob2);

  SLInsert(list,ob3);
  
  SLInsert(list,ob4);
  
  SLInsert(list, ob5);


 Node *checker = malloc(sizeof(Node));                                                                                                               
  checker = list->head;                                                                                                                                   
  while(checker!=NULL){                                                                                                                                   
    printf("checker: %d\n", *((int*)checker->data) );
    checker = checker->next;                                                                                                                              
  }                                                                                                                                                    
 


  SLDestroy(list);

  return 0;

 }
