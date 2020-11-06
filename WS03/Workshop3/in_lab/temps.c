// Name: Li-Ching, Cheng
// Student Number: 143292175
// Email: lcheng49@myseneca.ca
// Section: GG
// Date: 2018.05.29

#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3
// Put your code below:

int main(void)
{
	int i;
	int high, low;
	int sumHigh = 0;
	int sumLow = 0;
	float average;
	
	printf("---=== IPC Temperature Analyzer ===---\n");

	for(i=0; i<NUMS; i++) {
		do {
			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i + 1);
			scanf("%d", &low);
			printf("\n");
				if (high > 40 || low < -40 || low>high){
					printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
			    }
				
				else {
					sumHigh += high;
					sumLow += low;
				}
		} while (high > 40 || low<-40 || low>high);
	}
	average = (sumHigh + sumLow) / (NUMS * 2.0f);
	printf("The average (mean) temperature was: %.2f\n", average);
	return 0;
}
