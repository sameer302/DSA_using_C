#include<stdio.h>

int main(){
    for(int l=1; l<=4; l++){
        int i=1;
        while(i<=7){
            printf("1");
            i++;
            while(i>=(6-l) && i<=(l+2)){
                printf(" ");
                i++;
            }
        }
        printf("\n");
    }
}