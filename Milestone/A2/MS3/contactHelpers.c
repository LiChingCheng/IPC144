/* -------------------------------------------
Name:Li-Ching,Cheng
Student number:143292175
Email:lcheng49@myseneca.ca
Section:SGG
Date:2018/07/31
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:

#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");

	clearKeyboard();
}

// getInt:
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

// getIntInRange:
int getIntInRange(int mini, int maxi) {

	int enterNum = 0;

	enterNum = getInt();

	while (enterNum < mini || enterNum > maxi) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", mini, maxi);
		enterNum = getInt();
	}

	return enterNum;
}

// yes:
int yes(void) {

	char yorn = { '\0' }, newLine = { '\0' };

	scanf(" %c%c", &yorn, &newLine);

	while (!(yorn == 'y' || yorn == 'Y' || yorn == 'n' || yorn == 'N') || newLine != '\n') {
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		clearKeyboard();
		scanf(" %c%c", &yorn, &newLine);
	}

	if (yorn == 'y' || yorn == 'Y')
		return 1;

	else
		return 0;
}

// menu:
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

// ContactManagerSystem:
void ContactManagerSystem(void) {

	int option = 0, ans = 0;

	do {
		option = menu();
		printf("\n");

		if (option != 0) {
			printf("<<< Feature %d is unavailable >>>\n", option);
			printf("\n");
			ans = 0;
			pause();
			printf("\n");
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

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[])
{
    int needInput = 1;

    while (needInput == 1) {
        scanf("%10s", telNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(telNum) == 10)
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    return -1;
}

// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{

}

// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{

}

// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact *contacts)
{

}

// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{

}

// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{

}

// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{

}

// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{

}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{

}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{

}