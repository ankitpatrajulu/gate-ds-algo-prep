#include<stdio.h>

void strcopy(char *, char *);

void main() {
    char s1[] = "Ankit ";
    char s2[] = "Patra!";

    printf("%s\n", s1);
    printf("%s\n", s2);

    strcopy(&s1, &s2);

    printf("%s\n", s1);
}

void strcopy(char *a1, char *a2){
    int i = 3;
    while(a1[i]!= NULL){
        i++;
        printf("%c", a1[i]);
    }
}