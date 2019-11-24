/**********************************
**	stack.c: Stack application. 
***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/*****************************************************************
**  Using stack to check for unbalanced parentheses.
******************************************************************/

/*******************************************************************************
**  Returns the next character of the string, once reaches end return '0' (zero)
**	param: 	s pointer to a string 				
********************************************************************************/
char nextChar(char* s) {
    
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);

	if ( c == '\0' ) {
		return '\0';	
    } else { 
		return c;
    }
}


/***********************************************************
**  Checks whether the (), {}, and [] are balanced or not
**	param: 	s pointer to a string 	
**	pre: 	
**	post:	
***********************************************************/
int isBalanced(char* s) {

    /* Print the string argument */
    printf("The string entered is: %s\n", s);

    /* End if the string is NULL (return 1 == true) */
    if (s == NULL) {
        return 1;
    }

    DynArr *ptr = newDynArr(10);
    char c;

    /* Call nextChar function to iterate through the string */
    for (c = nextChar(s); c; c = nextChar(s)) {
        /* Push an opening token onto the stack */
        if (c == '(' || c == '{' || c == '[') {
            pushDynArr(ptr, c);
        }

        /* Fail and clean up if a closing token is found first (return 0 == false) */
        else if ((c == ')' && (isEmptyDynArr(ptr) || topDynArr(ptr) != '(')) ||
                 (c == '}' && (isEmptyDynArr(ptr) || topDynArr(ptr) != '{')) ||
                 (c == ']' && (isEmptyDynArr(ptr) || topDynArr(ptr) != '['))) {
            deleteDynArr(ptr);

            return 0;
        }

        /* Remove the opening token if a matching closing token is found */
        else if (c == ')' || c == '}' || c == ']') {
            popDynArr(ptr);
        }
    }

    /* If the stack has tokens then clean up and (return 0 == false) */
    if (!isEmptyDynArr(ptr)) {
        deleteDynArr(ptr);

        return 0;
    }

    /* If empty then clean up and (return 1 == true) */
    deleteDynArr(ptr);

    return 1;
}


int main(int argc, char* argv[]) {
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res) {
		printf("The string %s is balanced\n",s);
    } else { 
		printf("The string %s is not balanced\n",s);
    }

	return 0;	
}
