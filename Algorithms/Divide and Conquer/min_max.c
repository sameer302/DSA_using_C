#include<stdio.h>

// 1) Without DAC

int main(){
    int* min_max(int [10]); // function prototyping
    int numbers[10];
    printf("Please enter 10 numbers:");
    for(int i = 0; i< 10; i++){
        scanf("%d",&numbers[i]);
    }
    int* result = min_max(numbers);
    printf("max = %d and min = %d", result[0], result[1]);
    return 0;
}

int* min_max(int numbers[10]){
    static int result[2]; // static since we are returning a pointer
    result[0] = result[1] = numbers[0];
    for(int i = 1; i < 10; i++){
        if(numbers[i] >= result[0]){
            result[0] = numbers[i];
        }else{
            if(numbers[i] <= result[1]){
                result[1] = numbers[i];
            }
        }
    }
    return result;
}