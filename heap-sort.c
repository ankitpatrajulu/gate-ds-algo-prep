#include<stdio.h>

struct heap {
    int arr[100];
    int len;
};

void display(struct heap *arr){
    printf("Array:\t");
    for(int j = 0; j < arr->len; j++){
        printf("%d ", arr->arr[j]);
    }
    printf("Length:\t%d\n", arr->len);
}

void input(struct heap *arr){
    printf("Type the numbers to put in heap:\n(Enter -1 to exit)\n");
    int i = 0, c;
    scanf("%d", &c);
    while(c != -1){
        arr->arr[i++] = c;
        scanf("%d", &c);
    }
    arr->len = i;
}

void maxHeapify(struct heap *, int);
void swap(struct heap *, int, int);
void buildMaxHeap(struct heap *);

void main(){
    printf("Hello Ankit\n");
    struct heap arr;
    // Input elements into the array and setting the size
    input(&arr);
    // Display the elements in the array
    display(&arr);

    // Using buildMaxHeap
    buildMaxHeap(&arr);
    display(&arr);

}

void maxHeapify(struct heap *arr, int root){
    int left, right, largest;
    if(root<arr->len/2){
        left = 2*(root) + 1;
        right = 2*(root) + 2;
        // To check if correct children are being selected
        // printf("%d, %d, %d\n", root, left, right);

        largest = root;

        if(arr->arr[left] > arr->arr[largest]){
            largest = left;
        }
        if(arr->arr[right] > arr->arr[largest]){
            largest = right;
        }

        if(largest != root){
            swap(arr, root, largest);
            maxHeapify(arr, largest);
        }
    }
}

void swap(struct heap *arr, int i, int j){
    arr->arr[i] = arr->arr[i] + arr->arr[j];
    arr->arr[j] = arr->arr[i] - arr->arr[j];
    arr->arr[i] = arr->arr[i] - arr->arr[j];
}

void buildMaxHeap(struct heap *arr){
    int length = (arr->len)/2;
    int i = 0;
    while(length>=0){
        maxHeapify(arr, length);
        printf("Pass %d\t", i++);
        display(arr);
        length--;
    }
}