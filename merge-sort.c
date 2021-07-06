#include<stdio.h>

struct merge {
    int arr[100];
    int len;
};

void input(struct merge *);
void display(struct merge *);
void swap(struct merge *, int, int);
void mergeArr(struct merge *, int, int, int);
void mergeSort(struct merge *, int, int);

void main(){
    // Defining the structure
    struct merge arr;
    // Input
    input(&arr);
    // Display Inputted Array
    display(&arr);

    // Merge-sort on the array
    mergeSort(&arr, 0, arr.len-1 );
    display(&arr);
}

void display(struct merge *arr){
    printf("Array:\t");
    for(int j = 0; j < arr->len; j++){
        printf("%d ", arr->arr[j]);
    }
    printf("\nLength:\t%d\n", arr->len);
}

void input(struct merge *arr){
    printf("Type the numbers to put in the array:\n(Enter -1 to exit)\n");
    int i = 0, c;
    scanf("%d", &c);
    while(c != -1){
        arr->arr[i++] = c;
        scanf("%d", &c);
    }
    arr->len = i;
}

void swap(struct merge *arr, int i, int j){
    arr->arr[i] = arr->arr[i] + arr->arr[j];
    arr->arr[j] = arr->arr[i] - arr->arr[j];
    arr->arr[i] = arr->arr[i] - arr->arr[j];
}

void mergeArr(struct merge *arr, int p, int q, int r){
    int left = q-p+1;
    int right = r-q;
    int lArr[left+1], rArr[right+1], i;
    for(i = 0; i < left; i++){
        lArr[i] = arr->arr[i+p];
    }
    int max = arr->len*10000;
    lArr[i] = max;
    printf("Left Array:\n");
    for(int j = 0; j <= i; j++){
        printf("%d ", lArr[j]);
    }
    printf("\n");
    for(i = 0; i < right; i++){
        rArr[i] = arr->arr[i+q+1];
    }
    rArr[i] = max;
    printf("Right Array:\n");
    for(int j = 0; j <= i; j++){
        printf("%d ", rArr[j]);
    }
    printf("\n");
    int j = 0, k = 0;
    i = p;
    while(i<=r){
        if(lArr[j]<rArr[k]){
            arr->arr[i] = lArr[j++];
        }
        else if(lArr[j]>rArr[k]){
            arr->arr[i] = rArr[k++];
        }
        else if(lArr[j]==rArr[k] && lArr[j] != max){
            arr->arr[i] = lArr[j++];
        }
        i++;
    }
    printf("Array:\n");
    for(int j = 0; j < arr->len; j++){
        printf("%d ", arr->arr[j]);
    }
    printf("\n");
}

void mergeSort(struct merge *arr, int p, int r){
    int i = 0;
    if(p<r){
        int q = (p+r)/2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        mergeArr(arr, p, q, r);
        //printf("Pass : %d\t", i++);
        display(arr);
        //printf("\n%d, %d, %d", p, q, r);
    }
}