#include<stdio.h>

int main(){
    int *p, x, y;
    float f = 5.6;
    x = 5;
    y = &x;
    // p = &x;
    // p = &f;
    p = (int*)y;
    printf("%d",*p);
}