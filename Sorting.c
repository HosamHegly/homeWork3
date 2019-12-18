#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
#define size 50
void shift_element(int *arr, int n) {
   int i;
   int temp = *(arr+n-1);
   for (i = n-1; i > 0 ; i--) {
      *(arr+i) = *(arr+i-1);
   }    
    *arr = temp;
}
//{99, 78, -1, 42, 12};
void Element(int *arr,int len){
    int j = len;
    int value = *(arr+len);
    while(j>0&& *(arr+j-1)>=value){
        *(arr+j) = *(arr+j-1);
        j--;
    }
    *(arr+j) = value;
}
void insertion_sort(int* arr , int len){
    int i;
	for(i = 1; i < len ; i++)
		if(*(arr+i) < *(arr+i-1))
		Element(arr, i);
}
