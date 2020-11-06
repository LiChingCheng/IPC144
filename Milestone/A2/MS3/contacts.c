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

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include "contacts.h"
#include "contactHelpers.h"

// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


// getName:
void getName(struct Name* name) {

	int ans = 0;

	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]30s", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	ans = yes();

	if (ans == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]6s", name->middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]35s", name->lastName);

}

// getAddress:
void getAddress(struct Address* address) {

	int ans = 0;

	do {
		printf("Please enter the contact's street number: ");
		address->streetNumber = getInt();

	} while ((address->streetNumber) <= 0);

	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]40s", address->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	ans = yes();

	if (ans == 1) {
		do {
			printf("Please enter the contact's apartment number: ");
			address->apartmentNumber = getInt();

		} while ((address->apartmentNumber) <= 0);
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]6s", address->postalCode);

	printf("Please enter the contact's city: ");
	scanf(" %[^\n]40s", address->city);

}

// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers* numbers) {

	int ans = 0;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	ans = yes();

	if (ans == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	ans = yes();

	if (ans == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);

	}

}

// getContact
void getContact(struct Contact *contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
