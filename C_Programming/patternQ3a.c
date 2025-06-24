#include<stdio.h>

int main(){
    for(int l=1; l<=7; l++){
        char c;
        for(c = 'a'; c<=('a'+7-l); c++){
            printf("%c",c);
        }
        for(int s=0; s<(2*l-3); s++){
            printf(" ");
        }
        if(l==1){
            c--;
        }
        for(c=c-1; c>='a'; c--){
            printf("%c",c);
        }
        printf("\n");
    }
}