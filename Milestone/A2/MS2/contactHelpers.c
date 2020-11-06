/* -------------------------------------------
Name:Li-Ching,Cheng
Student number:143292175
Email:lcheng49@myseneca.ca
Section:SGG
Date:2018/07/17
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");

	clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
	int enterNum = 0;
	char newLine = { '\0' };

	scanf("%d%c", &enterNum, &newLine);

	while (newLine != '\n') {
		
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		clearKeyboard();
		scanf("%d%c", &enterNum, &newLine);
	}

	return enterNum;
}

// getIntInRange function definition goes here:
int getIntInRange(int mini, int maxi) {

	int enterNum = 0;

	enterNum = getInt();

	while (enterNum < mini || enterNum > maxi) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", mini, maxi);
		enterNum = getInt();
	}

	return enterNum;
}

// yes function definition goes here:
int yes(void) {

	char yorn = '\0', newLine = '\0';

	scanf(" %c%c", &yorn, &newLine);

	while (!(yorn == 'y' || yorn == 'Y' || yorn == 'n' || yorn == 'N') || newLine != '\n') {
		printf("*** INVALID ENTRY *** <Only(Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &yorn, &newLine);
		clearKeyboard;
	}                                                    //change

	/*while (newLine != '\n') {
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &yorn, &newLine);
	}

	while (!(yorn == 'y' || yorn == 'Y' || yorn == 'n' || yorn == 'N')) {
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &yorn, &newLine);

		while (newLine != '\n') {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			scanf("%c%c", &yorn, &newLine);
		}
	}*/

	if (yorn == 'y' || yorn == 'Y')
		return 1;

	else
		return 0;
}

// menu function definition goes here:
int menu(void) {

	int option;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	option = getIntInRange(0, 6);

	return option;
}

// ContactManagerSystem function definition goes here:
void ContactManagerSystem(void) {

	int option = 1, ans = 0;

	do {
		option = menu();
		printf("\n");

		if (option != 0) {
			switch (option) {
			case 1:
				printf("<<< Feature 1 is unavailable >>>\n");
				printf("\n");
				pause();
				printf("\n");
				break;
			case 2:
				printf("<<< Feature 2 is unavailable >>>\n");
				printf("\n");
				pause();
				printf("\n");
				break;
			case 3:
				printf("<<< Feature 3 is unavailable >>>\n");
				printf("\n");
				pause();
				printf("\n");
				break;
			case 4:
				printf("<<< Feature 4 is unavailable >>>\n");
				printf("\n");
				pause();
				printf("\n");
				break;
			case 5:
				printf("<<< Feature 5 is unavailable >>>\n");
				printf("\n");
				pause();
				printf("\n");
				break;
			case 6:
				printf("<<< Feature 6 is unavailable >>>\n");
				printf("\n");
				pause();
				printf("\n");
				break;
			}
			
		}


		else {

			printf("Exit the program? (Y)es/(N)o: ");
			ans = yes();
			printf("\n");

			if (ans == 1) {
				printf("Contact Management System: terminated\n");
			}
		}

	} while (ans == 0);
}