// 1) Without DAC

// #include<stdio.h>
// #include<stdlib.h>

// int main(){
//     int* min_max(int*, int); // function prototyping
//     int* numbers, count;
//     printf("Please enter the count of numbers:");
//     scanf("%d",&count);
//     numbers = (int *)malloc(count*sizeof(int));
//     printf("Please enter the numbers: ");
//     for(int i = 0; i< count; i++){
//         scanf("%d",&numbers[i]);
//     }
//     int* result = min_max(numbers, count);
//     printf("max = %d and min = %d", result[0], result[1]);
//     free(numbers);
//     return 0;
// }

// we can write this program even without making the function but its good to make a function
// so that it can be used again and again

// int* min_max(int* numbers, int count){
//     static int result[2]; // static since we are returning a pointer
//     result[0] = result[1] = numbers[0];
//     for(int i = 1; i < count; i++){
//         if(numbers[i] >= result[0]){
//             result[0] = numbers[i];
//         }else{
//             if(numbers[i] <= result[1]){
//                 result[1] = numbers[i];
//             }
//         }
//     }
//     return result;
// }

// 2 with DAC

// here we can make program either by using pointers or also by using structure.
// using static pointers is quite risky in recursive calls as te value can be overwritten.

// (a) using pointers

#include<stdio.h>
#include<stdlib.h>

int main(){
    int* min_max(int*,int,int); // function prototyping
    int *numbers, count;
    printf("Please enter count of numbers: ");
    scanf("%d",&count);
    numbers = (int *)malloc(count*sizeof(int));
    printf("Please enter the numbers: ");
    for(int i = 0; i< count; i++){
        scanf("%d",&numbers[i]);
    }
    int* result = min_max(numbers,0,count-1);
    printf("max = %d and min = %d", result[0], result[1]);
    return 0;
}

int* min_max(int* numbers, int i, int j){
    static int result[2];
    if(i==j){
        result[0] = result[1] = numbers[i];
        return(result);
    }
    else if(i+1==j){
        if(numbers[i] > numbers[j]){
            result[0] = numbers[i];
            result[1] = numbers[j];
        }else{
            result[0] = numbers[j];
            result[1] = numbers[i];
        }
        return(result);
    }
    else{
        int mid = (i+j)/2;
        int* left = min_max(numbers,i,mid);
        int temp[] = {left[0], left[1]};
        int* right = min_max(numbers,mid+1,j);
        if(temp[0] > result[0]){
            result[0] = temp[0];
        }
        if(temp[1] < result[1]){
            result[1] = temp[1];
        }
        return(result);
    }
}

// (b) using structure

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int max;
    int min;
} MinMax;