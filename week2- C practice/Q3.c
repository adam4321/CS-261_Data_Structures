/************************************************************************
** CS261-               Assignment 1 - Q.3
** Name:                Adam Wright
** Date:                6-29-19
** Description:         Complete the required functions in C
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>


/* Convert ch to upper case, assuming it is in lower case currently */
char toUpperCase(char ch) {
    if (ch > 96 && ch < 123) {
        return ch - 32;
    } else {
        return ch;
    }
}

/* Convert ch to lower case, assuming it is in upper case currently */
char toLowerCase(char ch) {
    if (ch > 64 && ch < 91) {
        return ch + 32;
    } else {
        return ch;
    }
}

/* Return the length of the string */
int stringLength(char s[]) {
    int counter = 0;
    int i = 0;

    while (s[i] != '\0') {
        counter++;
        i++;
    }
    return counter;
}

/* Pass in pointer to word and convert to camelCase */
void camelCase(char* word) {
    while (*word != '\0') {

        /* If the input is an underscore then remove it and capitalize */
        if (*word == '_') {
            char* ptr = word;

            /* Loop to the string's end and swap all chars one place back */
            while (*word != '\0') {
                word++;
                char temp = *word;
                word--;
                *word = temp;
                word++;
            }

            word = ptr;
            *word = toUpperCase(*word);
        } else {
            word++;
        }
    }
}


int main() {
	/* Read the string from the keyboard */
    char inputStr[80];
    char str[80];

    printf("\n\nPlease enter a string of 80 characters or less\n");
    printf("with at least two words in it and press enter\n\n");
    scanf("%[^\n]s", inputStr);

    /* Format the string to lowercase */
    int i = 0;

    while (inputStr[i] != '\0') {
        inputStr[i] = toLowerCase(inputStr[i]);
        i++;
    }

    /* Remove incorrect characters and add underscores */
    i = 0;
    int j = 0;
    int isWordEnd = 0;

    while (inputStr[i] != '\0') {

        isWordEnd = 0;

        if (inputStr[i] > 96 && inputStr[i] < 123) {
            str[j] = inputStr[i];
            j++;

            if (inputStr[i+1] != '\0' && !(inputStr[i+1] > 96 && inputStr[i+1] < 123)) {
                isWordEnd = 1;
            }
        }

        i++;

        if (isWordEnd == 1 && inputStr[i] != '\0' && inputStr[i+1] != '\0') {
            str[j] = '_';
            j++;
        }

        if (inputStr[i] == '\0') {
            str[j] = '\0';
        }
    }

    printf("\nThe string formatted is: %s\n\n", str);

    int length = stringLength(str);
    printf("It's formatted length is %d characters\n", length);


    /* Check to see if the string is valid */
    i = 0;
    int valid = 0;

    while (i < length) {
        /* A properly formatted string will now have an underscore */
        if (str[i] == '_') {
            valid = 1;
        }

        i++;
    }


    /* If the string is not valid - Print an error and exit the program */
    if (valid == 0){
        printf("\nError: invalid input string\n\n");
        return 0;
    }
	
	/* Call camelCase */
    camelCase(str);	
	
	/* Print the new string */
    printf("\nThe string in camel case is: %s\n\n\n", str);	
	
	return 0;
}
