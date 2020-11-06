/* -------------------------------------------
Name:Li-Ching,Cheng
Student number:143292175
Email:lcheng49@myseneca.ca
Section:SKK
Date:2018/07/03
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

int main(void)
{
	// Declare variables here:
	struct Name fullName = { {'\0'} };

	struct Address addInfo = { 0,{ '\0' },0,{ '\0' },{ '\0' } };

	struct Number phoneNum = { {'\0'} };

	char ans;

	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]30s", fullName.firstName);

		do{
			printf("Do you want to enter a middle initial(s)? (y or n): ");
			scanf(" %c", &ans);
			
			if (ans == 'y' || ans == 'Y') {
				printf("Please enter the contact's middle initial(s): ");
				scanf(" %[^\n]6s",fullName.middleInitial);
			}
		} while (!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));


		printf("Please enter the contact's last name: ");
		scanf(" %[^\n]35s", fullName.lastName);

		// Contact Address Input:
		do {
			printf("Please enter the contact's street number: ");
			scanf("%d", &addInfo.streetNumber);
		} while (addInfo.streetNumber <= 0);
		
			printf("Please enter the contact's street name: ");
			scanf(" %[^\n]40s", addInfo.street);
		
		do {
			printf("Do you want to enter an apartment number? (y or n): ");
			scanf(" %c", &ans);

			if (ans == 'y' || ans == 'Y') {
				do {
					printf("Please enter the contact's apartment number: ");
					scanf("%d", &addInfo.apartmentNumber);
				} while (addInfo.apartmentNumber <= 0);
			}			
		} while (!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));

		printf("Please enter the contact's postal code: ");
		scanf(" %[^\n]6s", addInfo.postalCode);

		printf("Please enter the contact's city: ");
		scanf(" %[^\n]40s", addInfo.city);

		// Contact Numbers Input:
		do {
			printf("Do you want to enter a cell phone number? (y or n): ");
			scanf(" %c", &ans);

			if (ans == 'y' || ans == 'Y') {
				printf("Please enter the contact's cell phone number: ");
				scanf(" %20s", phoneNum.cell);
			}
		} while (!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));

	do{
		printf("Do you want to enter a home phone number? (y or n): ");
		scanf(" %c", &ans);

		if (ans == 'y' || ans == 'Y') {
			printf("Please enter the contact's home phone number: ");
			scanf(" %20s", phoneNum.home);
		}
	} while (!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));

	do{
		printf("Do you want to enter a business phone number? (y or n): ");
		scanf(" %c", &ans);

		if (ans == 'y' || ans == 'Y') {
			printf("Please enter the contact's business phone number: ");
			scanf(" %20s", phoneNum.business);
		}
	} while (!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));

		// Display Contact Summary Details
		printf("\nContact Details\n");
		printf("---------------\n");
		printf("Name Details\n");
		printf("First name: %s\n", fullName.firstName);

		if (fullName.middleInitial[0] != '\0') {
			printf("Middle initial(s): %s\n", fullName.middleInitial);
		}

		printf("Last name: %s\n\n", fullName.lastName);

		printf("Address Details\n");
		printf("Street number: %d\n", addInfo.streetNumber);
		printf("Street name: %s\n", addInfo.street);

		if (addInfo.apartmentNumber > 0) {
			printf("Apartment: %d\n", addInfo.apartmentNumber);
		}

		printf("Postal code: %s\n", addInfo.postalCode);
		printf("City: %s\n\n", addInfo.city);

		printf("Phone Numbers:\n");

		if (phoneNum.cell[0] != '\0') {
			printf("Cell phone number: %s\n", phoneNum.cell);
		}

		if (phoneNum.home[0] != '\0') {
			printf("Home phone number: %s\n", phoneNum.home);
		}

		if (phoneNum.business[0] != '\0') {
			printf("Business phone number: %s\n\n", phoneNum.business);
		}

		// Display Completion Message

		printf("Structure test for Name, Address, and Numbers Done!\n");

		return 0;
	
}

/*  SAMPLE OUTPUT:
    
Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888

Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888

Structure test for Name, Address, and Numbers Done!
*/