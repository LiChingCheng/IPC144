/*
Name:      Li-Ching, Cheng
Student#:  143292175
Section:   GG
*/

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications

#include<stdio.h>

int main(void)
{
	float amount, gst;
	int loonies, quarters, dimes, nickels, pennies;
	int balance_owing, owing1, owing2, owing3, owing4, owing5;


	printf("Please enter the amount to be paid: $");
	scanf("%f", &amount);

	printf("GST: 1.13\n");                              //wrong: gst=amount*0.13  (8.68*0.13=1.13)  see the practiceHome that is correct.

	gst = amount * 0.13 + 0.005;
	balance_owing = (amount + gst) * 100;
	printf("Balance owing: $%.2f\n", (float)balance_owing / 100);

	loonies = balance_owing / 100;
	owing1 = balance_owing % 100;
	printf("Loonies required: %d, balance owing $%.2f\n", loonies, (float)owing1 / 100);

	quarters = owing1 / 25;
	owing2 = owing1 % 25;
	printf("Quarters required: %d, balance owing $%.2f\n", quarters, (float)owing2 / 100);

	dimes = owing2 / 10;
	owing3 = owing2 % 10;
	printf("Dimes required: %d, balance owing $%.2f\n", dimes, (float)owing3 / 100);

	nickels = owing3 / 5;
	owing4 = owing3 % 5;
	printf("Nickels required: %d, balance owing $%.2f\n", nickels, (float)owing4 / 100);

	pennies = owing4 / 1;
	owing5 = owing4 % 1;
	printf("Pennies required: %d, balance owing $%1.2f\n", pennies, (float)owing5 / 100);

	return 0;
}
