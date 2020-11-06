// Name: Li-Ching, Cheng
// Student Number: 143292175
// Email: lcheng49@myseneca.ca
// Section: SGG
// Date: 2018.05.29

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define NUMS 4
// Put your code below:

int main(void)
 {
	int i, high, low, max, min, max_day, min_day, sumHigh=0, sumLow=0;
	float average=0;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++) {
		
		do{
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
		}while (high > 40 || low < -40 || high < low);
		
		if (i == 0) {
			max = high;
			max_day = 1;
			min = low;
			min_day = 1;
		}
		if (high > max) {
			max = high;
			max_day = i + 1;
		}
		if (low < min) {
			min = low;
			min_day = i + 1;
		}
	}
	
	average = (sumHigh + sumLow) / (NUMS*2.0f);
	printf("The average (mean) temperature was: %.2f\n", average);
	printf("The highest temperature was %d, on day %d\n", max, max_day);
	printf("The lowest temperature was %d, on day %d\n", min, min_day);

	return 0;
	}