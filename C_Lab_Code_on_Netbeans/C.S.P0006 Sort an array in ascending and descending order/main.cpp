/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 000100000001011
 *
 * Created on January 13, 2019, 9:40 PM
 */

#include <stdio.h>
#include <cstdlib>

using namespace std;

/*
 * 
 */
void display(int *a, int sizeOfArray){
    for(int i = 0; i < sizeOfArray; i++){
        printf("%d\t", a[i]);
    }
}

void sortDesceding (int *a, int sizeOfArray){
    for (int i = 0; i < sizeOfArray / 2; i++ ){
        int temp = a[i];
        a[i] = a[sizeOfArray-i-1];
        a[sizeOfArray-i-1] = temp;
    }
    display(a,sizeOfArray);
}

int main(int argc, char** argv) {
    int sizeOfArray, *a;
    while (1){
        char enter;
        printf("Please enter size of array: ");
        int flag = scanf("%d%c", &sizeOfArray, &enter);
        if(flag == 0 || enter != '\n'){
            while (getchar() != '\n');
        }
        else{
            break;
        }
    }
    a = (int *) malloc (sizeOfArray * sizeof(int*));//mảng  a = ....
    char enter;
    for (int i = 0; i < sizeOfArray; i++ ){
        while(1){
            printf("Enter element [%d]: ", i);
            int flag = scanf("%d%c", &a[i], &enter);
            if(flag == 0 || enter != '\n'){
                while (getchar() != '\n');
            }
            else{
                break;
            }
        }
    }
    printf ("The array sorted in ascending:\n");
    display(a,sizeOfArray);
    printf("\n\nThe array  sorted in descending:\n");
    sortDesceding(a, sizeOfArray);
    getchar();
    return 0;
}

