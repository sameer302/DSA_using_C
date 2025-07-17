#include<stdio.h>

int main(){
    for(int l=1; l<=7; l++){
        int i=1;
        char c='a';
        while(i<=13){
            if(i<=(8-l)){
                printf("%c", c++);
                i++;
            }else{
                if(l==1 && i==(9-l)){
                    c--;
                }
                printf("%c", --c);
                i++;
            }
            while(i>=(9-l) && i<=(l+5)){
                printf(" ");
                i++;
            }
        }
        printf("\n");
    }
}