#include <stdio.h>
#define ARR_MAX 1000

void sort_section(int *ptr, int *qtr){
    int *start = (ptr < qtr) ? ptr : qtr;
    int *end = (ptr < qtr) ? qtr  : ptr;

    int len = end - start + 1;

    for (int i=0; i<len-1; i++){
      int flag = 0;
      for (int *p=start; p<end-i; p++){
        if (*p > *(p+1)){
          int temp;
          temp = *(p +1);
          * (p + 1 )= *p;
          *p = temp;
          flag = 1;
        }
      }

      for (int *p = start; p<=end; p++ ){
        printf("%d ", *p);
      }
      printf("\n");

      if(!flag) break;

        
    }
    
}

int main() {
  int N, a, b;
  scanf("%d%d%d", &N, &a, &b);
  int arr[ARR_MAX] = {0};
  for (int i = 0; i < N; i++) {
    scanf("%d", arr + i);
  }
  sort_section(&arr[a], &arr[b]);
  for (int i = 0; i < N; i++) {
    printf("%d ", *(arr + i));
  }
}