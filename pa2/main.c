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

  int k = 5;
  int* ob1 = malloc(sizeof(int*));
  ob1= &k;
  // *ob1 = k;
 
  int j = 4;
  int* ob2 = malloc(sizeof(int));
  ob2 = &j;
  // *ob2 = j;

  int m = 3;
  int* ob3 = malloc(sizeof(int));
  ob3 = &m;
  // *ob3 = m;
  
  int n = 6;
  int* ob4 = malloc(sizeof(int));
  ob4 = &n;
  // *ob4 = n;
  
  int o = 2;
  int* ob5 = malloc(sizeof(int));
  ob5 = &o;
  //*ob5 = o;

  int q = 1;
  int* ob6 = malloc(sizeof(int));
  ob6 = &q;
  //  *ob6 = q;

  SLInsert(list,ob1); 
    SLInsert(list,ob2);
    SLInsert(list,ob3);
   SLInsert(list,ob4);
    SLInsert(list,ob6);
    SLInsert(list,ob5);
   SortedListIteratorPtr iter = SLCreateIterator(list);
   SLNextItem(iter);
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

  // SLDestroy(list);

  return 0;

}
