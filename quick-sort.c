#include<stdio.h>

void display(int *arr, int size){
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int p, int r, int size){
    int key = arr[r];
    int j = p;
    int i = j-1;

    while(j<r){
        if(arr[j]<key){
            i++;
            if(i!=j){
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
        j++;
    }

    i++;
    arr[i] = arr[i] + arr[r];
    arr[r] = arr[i] - arr[r];
    arr[i] = arr[i] - arr[r];
    display(arr, size);
    return i;
}

void quickSort(int *arr, int p, int r, int size){
    if(p < r){
        int q = partition(arr, p, r, size);
        quickSort(arr, p, q-1, size);
        quickSort(arr, q+1, r, size);
    }
}

void main(){
    int arr[] = {1, 4, 3, 0, 9, 7, 2};
    //int part = partition(arr, 0, 6);
    //printf("%d\n", part);
    int size = 7;
    
    printf("Unsorted Array\n");
    display(arr, size);

    quickSort(arr, 0, 6, size);

    printf("Sorted Array\n");
    display(arr, size);
}
