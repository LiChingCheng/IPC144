//--------------------------------------------------
// Name: Li-Ching, Cheng         
// Student Number: 143292175
// Email: lcheng49@myseneca.ca         
// Section: SGG       
// Workshop: 4      
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define NUM 3 
#define NUMS 10


// Place your code below


int main(void) {

	int i, day, highest, lowest, highest_day, lowest_day, enter_day, sum_high=0, sum_low=0;
	int high[NUMS], low[NUMS];
	float average=0;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between %d and %d, inclusive: ", NUM, NUMS);
	scanf("%d", &day);
	printf("\n");

	while (day < NUM || day > NUMS) {
		printf("Invalid entry, please enter a number between %d and %d, inclusive: ", NUM, NUMS);
		scanf("%d", &day);
		printf("\n");
	}
	
	for (i = 0; i < day; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}
	
	printf("\n");
	printf("Day  Hi  Low\n");

	for (i = 0; i < day; i++) {
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);

		if (i == 0) {
			highest = high[i];
			highest_day = 1;
			lowest = low[i];
			lowest_day = 1;
		}

		if (high[i] > highest) {
			highest = high[i];
			highest_day = i + 1;
		}

		if (low[i] < lowest) {
			lowest = low[i];
			lowest_day = i + 1;
		}
	}
	printf("\n");
	printf("The highest temperature was %d, on day %d\n", highest, highest_day);
	printf("The lowest temperature was %d, on day %d\n", lowest, lowest_day);
	printf("\n");

	do {
		printf("Enter a number between %d and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", 1, day);
		scanf("%d", &enter_day);
		printf("\n");

		if (enter_day >= 0) {

			while (enter_day<=0 || enter_day>day) {
				printf("Invalid entry, please enter a number between %d and %d, inclusive: ", 1, day);
				scanf("%d", &enter_day);
				printf("\n");
			}

			sum_high = 0;
			sum_low = 0;
			for (i = 0; i < enter_day; i++) {
				sum_high += high[i];
				sum_low += low[i];
			}

			average = (sum_high + sum_low) / (enter_day * 2.0f);
			printf("The average temperature up to day %d is: %.2f\n", enter_day, average);
			printf("\n");
		}
	} while (enter_day >= 0);

	printf("Goodbye!\n");

	return 0;
}