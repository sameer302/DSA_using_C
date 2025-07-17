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

/* we can write this program even without making the function but its good to make a function
 so that it can be used again and again */

// int* min_max(int* numbers, int count){
//     static int result[2]; // static since we are returning a pointer to an array
//     result[0] = result[1] = numbers[0];
//     for(int i = 1; i < count; i++){
//         if(numbers[i] >= result[0]){
//             result[0] = numbers[i];
//         }else if(numbers[i] <= result[1]){
//                 result[1] = numbers[i];
//         }
//     }
//     return result;
// }

// 2 with DAC

/* here we can make program either by using pointers or also by using structure.
 using static pointers is quite risky in recursive calls as te value can be overwritten. */

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
        int *left = min_max(numbers,i,mid);
        int temp[] = {left[0], left[1]}; /* this is because since result is a static pointer so in recursive calls the value of this 
        pointer is likely to change and so we need to save the values of Lmin and Lmax so that further we can compare them with the 
        values of Rmin and Rmax and the final values will be stored in result array*/
        int* right = min_max(numbers,mid+1,j);
        if(temp[0] > right[0]){
            result[0] = left[0];
        }
        if(temp[1] < right[1]){
            result[1] = left[1];
        }
        return(result);
    }
}

// we cannot have a pointer and an array with same name in the same function

/* we cannot assign a pointer to initialize an array, an array can be initialized either by using elements enclosed in curly braces
or by initializing each element separately */

// (b) using structure
/*an array of integers and a structure with only integer data members are very similar to each other. The latter is 
just like every index in array can be given a unique name. */

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct{
//     int max;
//     int min;
// } MinMax;

// int main(){
//     MinMax min_max(int*, int, int);
//     int *numbers, count;
//     printf("please enter the count of numbers: ");
//     scanf("%d",&count);
//     numbers = (int*)malloc(count*sizeof(int));
//     printf("please enter the numbers one by one: ");
//     for(int i = 0; i < count; i++){
//         scanf("%d", &numbers[i]);
//     }
//     MinMax result = min_max(numbers, 0, count-1);
//     printf("max = %d and min = %d",result.max, result.min);
// }

// MinMax min_max(int* numbers, int i, int j){
//     static MinMax result;
//     if(i==j){
//         result.min = result.max = numbers[0];
//         return result;
//     }
//     else if(i+1==j){
//         if(numbers[i]<numbers[j]){
//             result.min = numbers[i];
//             result.max = numbers[j];
//         }else{
//             result.min = numbers[j];
//             result.max = numbers[i];
//         }
//         return result;
//     }
//     else{
//         int mid = (i+j)/2;
//         MinMax left = min_max(numbers, i, mid);
//         MinMax right = min_max(numbers, mid+1, j);
//         if(left.min < right.min){
//             result.min = left.min;
//         }else{
//             result.min = right.min;
//         }
//         if(left.max > right.max){
//             result.max = left.max;
//         }else{
//             result.max = right.max;
//         }
//         return result;
//     }
// }

/* so both the above programs made using array and structure work in similar way and both the programs can be written in two ways,
firstly using two arrays or two structures in the function, as we did in the case of array implementation, and
secondly using three arrays or three structures as we did in case of structure implementation. Also in both the implementation
only the array or structure that we are returning needs to be defined as static, the other ones which we are using in between
can be used as local. Using three arrays or structures will make our code more easy to understand.
In case of array as we cannot return an array from a function and also we cannot initialize an array with a pointer so if we try to use the
above logic as used in case of structure implimentation then we wil have to use both left and right pointers and then use two arrays one to 
store left min and max and one to store right min and max.
*/