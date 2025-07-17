#include<stdio.h>

int main(){
    for(int l=1; l<=7; l++){
        int i=1;
        char c='a';
        while(i<=(8-l)){
            printf("%c",c++);
            i++;
        }
        while(i<=(l+5)){
            printf(" ");
            i++;
        }
        if(l==1){
            c--;
        }
        while(i<=13){
            printf("%c",--c);
            i++;
        }
        printf("\n");
    }
}