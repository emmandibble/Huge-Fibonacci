// Emma Dibble
// Project 2: Huge Fibonacci
// U0000004444
// COP4415.02

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Fibonacci.h"


//adds two Huge Integers
HugeInteger *hugeAdd(HugeInteger *p, HugeInteger *q){
    //allocates memory to a pointer
    HugeInteger *newInte;
    newInte = malloc(sizeof(HugeInteger));

    if(newInte == NULL){
        return NULL;
    }

    int i;

    //checking to find the largest length
    if(p->length > q->length){
        newInte->length = p->length;
        newInte->digits = calloc(newInte->length+1,sizeof(int));

        for(i = 0; i < q->length; i++){
            //adding the smallest length to the largest

            if(p->digits[i] + q->digits[i] > 9){
                newInte->digits[i] = (p->digits[i] + q->digits[i] + newInte->digits[i])%10;
                newInte->digits[i+1] += 1;
            }

            else{
                newInte->digits[i] += p->digits[i] + q->digits[i];
            }
        }

        for(i = q->length; i < p->length; i++){
            newInte->digits[i] += p->digits[i];
        }
    }
    //checking to find the largest length
    else if(q->length > p->length){
        newInte->length = q->length;
        newInte->digits = calloc(newInte->length+1,sizeof(int));

        for(i = 0; i < p->length; i++){
            //adding the smallest length to the largest

            if((p->digits[i] + q->digits[i] + newInte->digits[i]) > 9){
                newInte->digits[i] = (p->digits[i] + q->digits[i] + newInte->digits[i]) % 10;
                newInte->digits[i+1] += 1;
            }

            else{
                newInte->digits[i] += p->digits[i] + q->digits[i];
            }
        }

        for(i = p->length; i < q->length; i++){
            newInte->digits[i] += q->digits[i];
        }
    }

    //if they're equal length
    else{
        newInte->length = p->length;
        newInte->digits = calloc((newInte->length+1), sizeof(int));

        for(i = 0; i < p->length; i++){

            if ((p->digits[i] + q->digits[i] + newInte->digits[i]) > 9){
                newInte->digits[i+1]+= 1;
                newInte->digits[i] = ((p->digits[i] + q->digits[i] + newInte->digits[i]) % 10);
                if((p->length - 1) == i){
                    newInte->length++;
                }
            }

            else{
                newInte->digits[i] += p->digits[i] + q->digits[i];
            }
        }
    }
    return newInte;
}

//frees allocated memory
HugeInteger *hugeDestroyer(HugeInteger *p){
    if(p == NULL){
        return NULL;
    }

    free(p->digits);
    free(p);

    return NULL;
}

//calculates the length of an unsigned integer n
int numLength(unsigned int n){
    int count = 0;
    count++;

    while(n > 9){
        count++;
        n = n/10;
    }

    return count;
}

//converts a String to a Huge Integer
HugeInteger *parseString(char *str){
    if(str == NULL){
        return NULL;
    }

    //allocates memory to return pointer
    HugeInteger *newInte;
    newInte = malloc(sizeof(HugeInteger));

    if(newInte == NULL){
        return NULL;
    }

    int len = strlen(str);
    newInte->length = len;
    newInte->digits = malloc(sizeof(int)*newInte->length);

    //sets String values into Huge Integer
    int i;

    for(i = 0; i < len; i++){
        newInte->digits[i] = str[len-1-i]-48;
    }

    return newInte;
}

//converts unsigned integer to Huge Integer
HugeInteger *parseInt(unsigned int n){

    //allocates memory to return pointer
    HugeInteger *newInte;
    newInte = malloc(sizeof(HugeInteger));

    if(newInte == NULL){
        return NULL;
    }

    int diCount = 0;
    diCount = numLength(n);
    newInte->length = diCount;
    newInte->digits = malloc(sizeof(int)*newInte->length);

    //sets digit values in the unsigned integer to Huge Integer
    int i;

    for(i = 0; i < newInte->length; i++){
        newInte->digits[i] = n%10;
        n = n/10;
    }

    return newInte;
}

//converts Huge Integer to unsigned integer
unsigned int *toUnsignedInt(HugeInteger *p){

    HugeInteger *unint = parseInt(UINT_MAX);
    unsigned int temp = UINT_MAX;

    //allocates memory to return pointer
    unsigned int *newInte = malloc(sizeof(unsigned int));

    if(newInte == NULL){
        return NULL;
    }

    if(p == NULL || p->length > unint->length){
        return NULL;
    }

    *newInte = 0;
    int i;
    int tens = 1;
    int array[unint->length];

    //converts Huge Integer to unsigned int
    if(p->length == unint->length){
        for(i = 0; i < unint->length; i++){
            array[i] = temp % 10;
            temp /= 10;
        }

        for(i = p->length-1; i >= 0; i--){
            if(p->digits[i] < array[i]){
                break;
            }

            if(p->digits[i] < array[i]){
                return NULL;
            }
        }
    }

    for(i = 0; i < p->length; i++){
        *newInte += (p->digits[i] * tens);
        tens *= 10;
    }

    return newInte;
}

//calculates the n'th number in the sequence
HugeInteger *fib(int n){

    HugeInteger *newInte = malloc(sizeof(HugeInteger));
    HugeInteger *fib1 = malloc(sizeof(HugeInteger));
    HugeInteger *fib2 = malloc(sizeof(HugeInteger));

    if(newInte == NULL || fib1 == NULL || fib2 == NULL){
        return NULL;
    }

    if(n == 0){
        newInte = parseInt(0);
        return newInte;
    }

    else if(n == 1){
        newInte = parseInt(1);
        return(newInte);
    }

    else{
        fib1 = parseInt(0);
        fib2 = parseInt(1);
        newInte = parseInt(0);
        int i;

        for(i = 2; i <= n; i++){
            newInte = hugeAdd(fib1, fib2);
            hugeDestroyer(fib1);
            fib1 = fib2;
            fib2 = newInte;
        }
    }

    return newInte;
}

double difficultyRating(){
    double rating = 4;
    return rating;
}

double hoursSpent(){
    double hours = 12.5;
    return hours;
}
