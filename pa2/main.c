#include "sorted-list.c"

//For testing purposes, including comparator and destroyer functions

int compInts (void* a, void* b){
  int i = *(int*)a;
  int j = *(int*)b;
  //  printf("size: %lu  %lu\n",sizeof(i),sizeof(a));
  //  printf("p: %d  %d \n",*(int*)a,*(int*)b);
  //   printf("%d\n",(i-j));
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

void destroyer (void* a){
  free(a);
}

int main(int argc, char**argv){
 
  SortedListPtr list = SLCreate(compInts,destroyer);
  //  SortedListIteratorPtr iter = SLCreateIterator(list);

  int k = 10;
  int* ob1 = malloc(sizeof(int*));
  ob1= &k;
  // *ob1 = k;
 
  int j = 8;
  int* ob2 = malloc(sizeof(int));
  ob2 = &j;
  // *ob2 = j;

  int m = 11;
  int* ob3 = malloc(sizeof(int));
  ob3 = &m;
  // *ob3 = m;
  
  int n = 6;
  int* ob4 = malloc(sizeof(int));
  ob4 = &n;
  // *ob4 = n;
  
  int o = 11;
  int* ob5 = malloc(sizeof(int));
  ob5 = &o;
  //*ob5 = o;

  int q = 9;
  int* ob6 = malloc(sizeof(int));
  ob6 = &q;
  //  *ob6 = q;

   SLInsert(list,ob3);
  
   SLInsert(list,ob2);
   SLInsert(list,ob2);
    SLInsert(list,ob1);
    SLInsert(list,ob4);
 Node *checker = malloc(sizeof(Node));                                                                                                               
  checker = list->head;                                                                                                                                   
  while(checker!=NULL){                                                                                                                                   
    printf("checker:%d  ref:%d\n", *((int*)checker->data),checker->refcount );
    checker = checker->next;                                                                                                                              
  }                                                                                                                               
  
  SortedListIteratorPtr iter = SLCreateIterator(list);
   printf("hey\n");

    while(SLNextItem(iter)!=NULL){
       //       printf("hi\n");
       printf("d:%d\n",*((int*)(iter->curr)->data));
       iter->curr = iter->right;
       iter->right = (iter->curr)->next;
    }
  

   /*SLInsert(list,ob2);
   
   SLInsert(list,ob4);
  
   SLInsert(list,ob6);
   SLInsert(list,ob2);
  */ 
   /*
  SLInsert(list,ob5);
  
  SLInsert(list, ob6);
  
  SLInsert(list,ob4);
   */

     //   printf("ABOUT TO PRINT\n");

   /* Node *checker = malloc(sizeof(Node));                                                                                                               
  checker = list->head;                                                                                                                                   
  while(checker!=NULL){                                                                                                                                   
    printf("checker:%d  ref:%d\n", *((int*)checker->data),checker->refcount );
    checker = checker->next;                                                                                                                              
  }                                                                                                                                                    
   */


  SLDestroy(list);

  return 0;

 }
