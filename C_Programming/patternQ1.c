#include<stdio.h>

int main(){
    for(int l=1; l<=4; l++){
        int i=1;
        while(i<=7){
            printf("1");
            i++;
            while(i>=l+1 && i<=(7-l)){
                printf(" ");
                i++;
            }
        }
        printf("\n");
    }
}