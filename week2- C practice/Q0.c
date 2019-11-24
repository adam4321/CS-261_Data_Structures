/************************************************************************
** CS261-               Assignment 1 - Q.0
** Name:                Adam Wright
** Date:                6-29-19
** Description:         Complete the required functions in C
************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fooA(int* iptr) {
    /* Print the value and address of the integer pointed to by iptr */
    printf("The value is: %d\n", *iptr);
    printf("The address is: %p\n\n", iptr);

    /* Increment the value of the integer pointed to by iptr by 5 */
    *iptr += 5;  

    /* Print the address of iptr itself */
    printf("The pointer's address is: %p\n\n", &iptr);

    /* Dummy variable, ignore the warning */
    int c=5;  
}

void fooB(int* jptr) {
    /* Print the value and address of the integer pointed to by jptr */
    printf("The value is: %d\n", *jptr);          
    printf("The address is: %p\n\n", jptr);

    /* Decrement the address by 1 pointed to by jptr using jptr */
    jptr--;
      
    /* Print the address of jptr itself */
    printf("The pointer's address is: %p\n\n", &jptr);
}


int main() {
    /* Declare an integer x and initialize it randomly to a value in [0,10] */
    srand(time(0));
    int x = rand() % 10;
    
    /* Print the value and address of x */
    printf("\nThe value is: %d\n", x);
    printf("The address is: %p\n\n", &x);

    /* Call fooA() with the address of x */
    fooA(&x);
    
    /* Print the value of x */
    printf("The value is: %d\n\n", x);

    /* QUESTION 1: x is now different from the value printed before because
    it's value was changed by using indirection inside of fooA */
    
    /* Call fooB() with the address of x */
    fooB(&x);
    
    /* Print the value and address of x */
    printf("The value is: %d\n", x);
    printf("The address is: %p\n\n", &x);

    /* QUESTION 2: The value and address are the same because we made no change
    to the value and the address was passed by value so the decrement was
    made to the local copy of the pointer inside fooB and not made to
    the copy in main. The function signature would have needed to pass
    by double indirection to change the address of x from inside fooB */
    
    return 0;
}
