#include<stdio.h>

struct heap {
    int arr[100];
    int len;
};


void input(struct heap *);
void display(struct heap *);
void maxHeapify(struct heap *, int);
void swap(struct heap *, int, int);
void buildMaxHeap(struct heap *);
int extractMax(struct heap *);
void increaseKey(struct heap *, int);
void heapSort(struct heap *);

void main(){
    printf("Hello Ankit\n");
    struct heap arr;
    // Input elements into the array and setting the size
    input(&arr);
    // Display the elements in the array
    display(&arr);

    // Using buildMaxHeap
    buildMaxHeap(&arr);
    // maxHeapify(&arr, 4);
    display(&arr);

    int c;
    
    printf("What would you like to do? Choose your option:\n");
    printf("1 - Extract Max Element in the array.\n");
    printf("2 - Insert a new Element into the array.\n");
    printf("3 - Find the sorted(heap-sort) array\n");
    printf("4 - Exit\n");
    scanf("%d", &c);
    // c = Exit Condition
    while(c!=4){
        switch(c){
            case 1: {
                // Extract Max Value
                int max = extractMax(&arr);
                printf("Max Value:\t%d\n", max);
                display(&arr);
                break;
            }
            case 2: {
                // Add new element
                printf("Enter the element you want to add:\n");
                scanf("%d", &c);
                increaseKey(&arr, c);
                display(&arr);
                break;
            }
            case 3: {
                // Heapsort
                heapSort(&arr);
                break;
            }
            default: printf("Enter a valid option.\n");
        }
        printf("Enter your choice:\t");
        scanf("%d", &c);
    }  
}

void display(struct heap *arr){
    printf("Array:\t");
    for(int j = 0; j < arr->len; j++){
        printf("%d ", arr->arr[j]);
    }
    printf("\nLength:\t%d\n", arr->len);
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

void maxHeapify(struct heap *arr, int root){
    int left, right, largest;
    left = 2*(root) + 1;
    right = 2*(root) + 2;
    if(left >= arr->len) left = -100;
    if(right >= arr->len) right = -100;
    // To check if correct children are being selected
    // printf("%d, %d, %d\n", root, left, right);

    largest = root;

    if(arr->arr[left] > arr->arr[largest] && left != -100){
        largest = left;
    }
    if(arr->arr[right] > arr->arr[largest] && right != -100){
        largest = right;
    }

    if(largest != root){
        swap(arr, root, largest);
        maxHeapify(arr, largest);
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

int extractMax(struct heap *arr){
    int max = arr->arr[0];
    arr->arr[0] = arr->arr[arr->len-1];
    arr->len--;
    maxHeapify(arr, 0);
    return max;
}

void increaseKey(struct heap *arr, int val){
    arr->arr[arr->len] = val;
    arr->len++;
    int length = arr->len/2;
    while(length>=0){
        maxHeapify(arr, length--);
    }
}

void heapSort(struct heap *arr){
    int maxArr[arr->len];
    int i = 0, len = arr->len-1;
    while(len>=0){
        int max = extractMax(arr);
        maxArr[i++] = max;
        len--;
    }
    printf("Heap-Sort Array\n");
    for(int j = 0; j < i; j++){
        printf("%d ", maxArr[j]);
    }
    printf("\n");
}