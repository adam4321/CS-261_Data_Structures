/************************************************************************
** CS261-               Assignment 1 - Q.1
** Name:                Adam Wright
** Date:                6-29-19
** Description:         Complete the required functions in C
************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


struct student {
	int id;
	int score;
};

struct student* allocate() {
    /* Allocate memory for ten students */
    struct student* students = malloc(10 * sizeof(struct student));
     
    /* Return the pointer */
    return students;
}

void generate(struct student* students) {
    /* Generate random and unique IDs and random scores for ten students, 
    IDs being between 1 and 10, scores between 0 and 100 */
    int i;
    srand(time(NULL));
    int randId[10];

    /* Create an array of 1-10 in unique random order */
    for (i = 0; i < 10; i++) {
        randId[i] = i+1;
    }

    /* Shuffle the array by swapping each to a random index */
    for (i = 0; i < 10; i++) {
        int randIndx = rand() % 10;

        int temp = randId[i];
        randId[i] = randId[randIndx];
        randId[randIndx] = temp;
    }

    /* Set the array of students to have a unique id and random score */
    for (i = 0; i < 10; i++) {
        students[i].id = randId[i];
        students[i].score = rand() % 100; 
    }    
}

void output(struct student* students) {
    /*
    *    Output information about the ten students in the format:
    *           ID1 Score1
    *           ID2 score2
    *           ID3 score3
    *           ...
    *           ID10 score10
    */

    printf("\n");

    int i;

    for (i = 1; i <= 10; i++) {
        printf("ID%d %d ", i, students->id);
        printf("Score%d %d\n", i, students->score);
        students++;
    }

    printf("\n");
}

void summary(struct student* students) {
    /* Compute and print the minimum, maximum and average scores of the 
    ten students */

    int i;
    int min = 100;  /* highest possible value, so it can only go down */
    int max = 0;    /* lowest possible value, so it can only go up */
    int total = 0;
    
    for (i = 0; i < 10; i++) {

        if (students->score < min) {
            min = students->score;
        }

        if (students->score > max) {
            max = students->score;
        }

        total += students->score;
        students++;
    }

    double avg = total / 10.0;

    printf("The score's MIN: %d MAX: %d AVG: %f\n", min, max, avg);
    printf("\n");
}

void deallocate(struct student* stud) {
    /* Deallocate memory from stud */
    if (stud != NULL)
    free(stud);
}


int main() {
    struct student* stud = NULL;
    
    /* Call allocate */
    stud = allocate();
    
    /* Call generate */
    generate(stud);
    
    /* Call output */
    output(stud);
    
    /* Call summary */
    summary(stud);
    
    /* Call deallocate */
    deallocate(stud);

    return 0;
}
