#include<stdio.h>

void swap(int *, int *);

void main(){
    int a, b;
    printf("Enter two numbers, space separated: \n");
    scanf("%d %d", &a, &b);
    printf("Before Swapping: %d %d\n", a, b);
    swap(&a, &b);
    printf("After Swapping: %d %d\n", a, b);
}

void swap(int *x, int *y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}