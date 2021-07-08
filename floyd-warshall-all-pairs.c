#include<stdio.h>
#define row 4
#define col 4
void display(int *);


void main(){
    int arr[row][col] = {
        {0, 11, 1, 6},
        {11, 0, 7, 3},
        {1, 7, 0, 2},
        {6, 3, 2, 0}
    };
    //int *p = arr[0];
    printf("Original Array:\n");
    //display(arr[0]);
    int temp[4][4];
    for(int i = 0; i < row; i+=1){
        for(int j = 0; j < col; j++){
            // *(*(arr+i)+j)
            printf("%d ", arr[i][j]);
            temp[i][j] = arr[i][j];
        }
        printf("\n");
    }
    printf("\n");
    int round = 0, val1, val2;
    while(round<4){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                //printf("%d, %d, %d\n", temp[i][j], temp[i][round], temp[round][j]);/
                // Putting a max value
                val1 = 1000, val2 = 1000;
                if(i!=j){
                    if(arr[i][round] != 0) val1 = arr[i][round];
                    if(arr[round][j] != 0) val2 = arr[round][j];
                    if(val1 != 1000 && val2 != 1000){
                        if(val1+val2 < arr[i][j] && i!=j){
                            temp[i][j] = val1+val2;
                            //printf("%d\n", arr[i][j]);
                        }
                    }
                }
            }
            //printf("\n");
        }
        round++;
        printf("Round %d:\n", round);
        //display(arr[0]);
        for(int i = 0; i < row; i+=1){
            for(int j = 0; j < col; j++){
                printf("%d ",  temp[i][j]);
                arr[i][j] = temp[i][j];
            }
        printf("\n");
        }
        printf("\n");
    }
}

void display(int *arr){
    for(int i = 0; i < row; i+=4){
        for(int j = 0; j < col; j++){
            printf("%d ", (arr+i)[j]);
        }
        printf("\n");
    }
}