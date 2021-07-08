#include<stdio.h>

void main(){
    // Enter the sum to calculate for
    printf("Enter the sum to calculate for:\n");
    int sum, temp, len = 0, subset[30];
    scanf("%d", &sum);
    printf("Enter the subsets:\n(Enter -1 to end)\n");
    scanf("%d", &temp);
    while(temp != -1){
        subset[len++] = temp;
        scanf("%d", &temp);
    }
    int arr[len][sum];
    for(int i = 0; i <= len; i++){
        
    }
}