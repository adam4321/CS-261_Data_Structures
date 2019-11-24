/**************************************************************
**  Author:       Adam Wright
**  Description:  Test that IDE setup works for C
**************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
	double sideA = 4;
	double sideB = 13;
	double sideC = 15;

	double semiP = 0;
	double area = 0;

	semiP = 0.5 * (sideA + sideB + sideC);

	area = sqrt( semiP * (semiP - sideA) * (semiP - sideB) * (semiP - sideC) );
	printf("The area of Triangle A B C =  %0.2f\n", area);

	return 0;
}