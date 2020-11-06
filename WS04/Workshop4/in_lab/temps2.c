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


int main(void)
{

	int i, day;
	int high[NUMS], low[NUMS];

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
		}
	
	return 0;
}
