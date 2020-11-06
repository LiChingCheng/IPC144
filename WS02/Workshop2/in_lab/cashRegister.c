/*
Name:      Li-Ching, Cheng
Student#:  143292175
Section:   GG
*/

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include<stdio.h>

int main(void)
{

	double amount;
	int Loonies;
	int Quarters;
	double balance_owing1;
	double balance_owing2;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	Loonies = amount;
	balance_owing1 = amount - Loonies;
	Quarters = balance_owing1 / 0.25;
	balance_owing2 = balance_owing1 - Quarters * 0.25;


	printf("Loonies required: %d, balance owing $%.2lf\n", Loonies, balance_owing1);

	printf("Quarters required: %d, balance owing $%.2lf\n", Quarters, balance_owing2);

	return 0;
}