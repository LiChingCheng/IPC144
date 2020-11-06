/* -------------------------------------------
Name:Li-Ching,Cheng
Student number:143292175
Email:lcheng49@myseneca.ca
Section:SGG
Date:2018/07/10
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name* name) {
	
	char ans;

	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]30s", name->firstName);

	do {
		printf("Do you want to enter a middle initial(s)? (y or n): ");
		scanf(" %c", &ans);

		if (ans == 'y' || ans == 'Y') {
			printf("Please enter the contact's middle initial(s): ");
			scanf(" %[^\n]6s", name->middleInitial);
		}

	} while (!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));

	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]35s", name->lastName);

}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
	void getAddress(struct Address* address) {

		char ans;

		do {		
			printf("Please enter the contact's street number: ");
			scanf("%d", &address->streetNumber);

		} while ((address->streetNumber) <= 0);

		printf("Please enter the contact's street name: ");
		scanf(" %[^\n]40s", address->street);

		do {
			printf("Do you want to enter an apartment number? (y or n): ");
			scanf(" %c", &ans);

			if (ans == 'y' || ans == 'Y') {
				do {
					printf("Please enter the contact's apartment number: ");
					scanf("%d", &address->apartmentNumber);

				} while ((address->apartmentNumber) <= 0);
			}

		} while (!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));

		printf("Please enter the contact's postal code: ");
		scanf(" %[^\n]6s", address->postalCode);

		printf("Please enter the contact's city: ");
		scanf(" %[^\n]40s", address->city);

	}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:

	void getNumbers(struct Numbers* numbers){

		char ans;

		do {
			printf("Do you want to enter a cell phone number? (y or n): ");
			scanf(" %c", &ans);

			if (ans == 'y' || ans == 'Y') {
				printf("Please enter the contact's cell phone number: ");
				scanf("%20s", numbers->cell);				
			}

		} while (!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));

		do {
			printf("Do you want to enter a home phone number? (y or n): ");
			scanf(" %c", &ans);

			if (ans == 'y' || ans == 'Y') {
				printf("Please enter the contact's home phone number: ");
				scanf("%20s", numbers->home);
			}

		} while (!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));

		do {
			printf("Do you want to enter a business phone number? (y or n): ");
			scanf(" %c", &ans);

			if (ans == 'y' || ans == 'Y') {
				printf("Please enter the contact's business phone number: ");
				scanf("%20s", numbers->business);
			}

			} while (!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));
	}