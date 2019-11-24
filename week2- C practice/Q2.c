/************************************************************************
** CS261-               Assignment 1 - Q.2
** Name:                Adam Wright
** Date:                6-29-19
** Description:         Complete the required functions in C
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Swap the addresses stored in the pointer variables a and b and return c */
int foo(int* a, int* b, int c) {

    int temp = *a;
    *a = *b;
    *b = temp;
    
    /* Decrement the value of integer variable c */
    c--;
    return c;
}


int main() {
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    srand(time(0));

    int x = rand() % 10;
    int y = rand() % 10;
    int z = rand() % 10;

    /* Print the values of x, y and z */
    printf("\nx = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n\n", z);

    /* Call foo() appropriately, passing x,y,z as parameters */
    int temp =  foo(&x, &y, z);
    
    /* Print the values of x, y and z */
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n\n", z);

    /* Print the value returned by foo */
    printf("The value of foo's return is %d\n\n", temp);

    return 0;
}

/*

a. Yes, the return value from foo is decremented by 1 vs the value of z.
All variables are passed by value in C and the return value is a different object
and z wasn't passed by address like x and y were, so z is unchanged. 

b. Yes, the values of x and y were modified inside of foo because they were passed
by address so their values were swapped in place inside of foo. 

*/