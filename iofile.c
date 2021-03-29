#include<stdio.h>

void main() {
    printf("hello Ankit\n");
    int d1 = 23;
    float f1 = 63.8;
    char c1 = 'A';
    printf("%d, %6d, %f, %2.2f, %c, %d\n", d1, d1, f1, f1, c1, c1);
    char c = 'a';
    while((c=getchar())!='z'){
        printf("%c\n", c);
    }
}