#include <stdio.h>
#include "Sorting.h"
#define size 50
int scan = 0;
int main(){
    int arr[size];
    int i;
    for(i=0;i<size;i++){
        scanf("%d",&scan);
        *(arr+i) = scan;
    }
    printf("the original array is\n");
    for(i = 0 ;i <size-1;i++){
        printf("%d, ", *(arr+i));
    }
    printf("%d\n",*(arr+i));
   int n = sizeof(arr)/sizeof(int);
   insertion_sort(&arr[0],n);
printf("the  array after sorting:\n");
   for(i = 0 ;i < n; i++ ){
       printf("%d, ",*(arr+i));
   }
   printf("%d\n",*(arr+i));
    return 0;
}
