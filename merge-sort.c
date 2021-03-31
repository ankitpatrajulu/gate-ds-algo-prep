#include<stdio.h>

void mergesort(int *, int, int);
void merge(int *, int, int, int);

void main() {
    printf("Enter the numbers to sort. Enter -1 to stop entering.\n");
    int arr[100];
    int i = 0, j, temp;
    scanf("%d", &temp);
    while(temp != -1){
        arr[i++] = temp;
        scanf("%d", &temp);
    }
    for(j = 0; j<i; j++){
        printf("%d ", arr[j]);
    }
    printf("\n");
    mergesort(arr, 0, i-1);
}

void mergesort(int *arr, int p, int r) {
    if(p<r){
        int q = (p+r)/2;
        mergesort(arr, p, q);
        mergesort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

void merge(int *arr, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;

    int larr[n1+1];
    int rarr[n2+1];
    int i = 0;
    for(i = 0; i < n1; i++){
        larr[i] = arr[i+p];
    }
    larr[i] = 1000;

    for(int j = 0; j <= i; j++){
        printf("%d ", arr[j]);
    }
    printf("\n");

    for(i = 0; i < n2; i++){
        rarr[i] = arr[i+q+1];
    }
    rarr[i] = 1000;

    for(int j = 0; j <= i; j++){
        printf("%d ", arr[j]);
    }
    printf("\n");
    int k = p, j = 0;
    i = 0;
    while(k<=r){
        printf("%d, %d, %d\n",i, j, k);
        if(larr[i]<rarr[j]){
            arr[k] = larr[i];
            i++;
        }else if(larr[i]>rarr[j]){
            arr[k] = rarr[j];
            j++;
        }else if(larr[i]==rarr[j] && larr[i]!= 1000){
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    for(i = 0; i <= r; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}