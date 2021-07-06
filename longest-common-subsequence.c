#include<stdio.h>

void main(){
    printf("Enter the strings to find the subsequence in:\n");

    // Input the two strings
    char sub1[100], sub2[100];
    scanf("%s", sub1);
    scanf("%s", sub2);
    printf("%s %s\n", sub1, sub2);

    // Determining the length of the strings
    int len1, len2;
    for(len1 = 0; sub1[len1]!='\0'; len1++);
    for(len2 = 0; sub1[len2]!='\0'; len2++);
    printf("%d %d\n", len1, len2);

    // Setting 0 when i = 0 or j = 0
    int arr[len1][len2];
    for(int i = 0; i <= len1; i++){
        for(int j = 0; j <= len2; j++){
            if(i == 0 || j == 0){
                arr[i][j] = 0;
            }
        }
    }

    // Bottom up approach
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(sub1[i-1]==sub2[j-1]){
                arr[i][j] = 1 + arr[i-1][j-1];
            } else {
                if(arr[i-1][j]>arr[i][j-1]){
                    arr[i][j] = arr[i-1][j];
                } else arr[i][j] = arr[i][j-1];
            }
        }
    }
    
    // Display the matrix
    for(int i = 0; i <= len1; i++){
        for(int j = 0; j <= len2; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Print one max sequence under the consition that only one subsequence exists
    char maxSeq[arr[len1-1][len2-1]], k = 0;
    for(int i = len1; i >= 0; i--){
        for(int j = len2; j >= 0; j--){
            if(arr[i-1][j-1]==arr[i][j]-1 && (arr[i-1][j] != arr[i][j]) && (arr[i][j-1] != arr[i][j])){
                maxSeq[k++] = sub1[i-1];
            }
        }
    }
    printf("%s \n", maxSeq);

}