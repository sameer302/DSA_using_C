#include<stdio.h>

int main(){
    int x = 1;
    while(x++<4){
        printf("abc\n");
    }

    int y = 1;
    do{
        printf("def\n");
    }while(y++<4);
}