/* -------------------------------------------
Name:Li-Ching,Cheng
Student number:143292175
Email:lcheng49@myseneca.ca
Section:SGG
Date:2018/07/24
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:

#include "contacts.h"
#include "contactHelpers.h"

// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):

#define MAXCONTACTS 5

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
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

	char yorn = '\0', newLine = '\0';
	

	scanf("%c%c", &yorn, &newLine);
	
	while (!(yorn == 'y' || yorn == 'Y' || yorn == 'n' || yorn == 'N') || newLine != '\n') {

		if (newLine != '\n') {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only(Y)es or (N)o are acceptable>: ");
			scanf("%c%c", &yorn, &newLine);
		}
		else {
			printf("*** INVALID ENTRY *** <Only(Y)es or (N)o are acceptable>: ");
			scanf("%c%c", &yorn, &newLine);
		}
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

	struct Contact contacts[MAXCONTACTS] = { { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
	{ { "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
	{ { "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
	{ { "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } }, };

	do {
		option = menu();
		printf("\n");

		switch (option) {
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			printf("--- Contacts sorted! ---\n");
			pause();
			printf("\n");
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			ans = yes();
			printf("\n");

			if (ans == 1) {
				printf("Contact Management System: terminated\n");
			}
			break;
		}
	} while (ans == 0);
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
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
	int i;

	for (i = 0; i < size; i++) {
		if (strcmp(cellNum, contacts[i].numbers.cell) == 0) {
			return i;
		}
	}
	
	return -1;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}

// displayContact:
void displayContact(const struct Contact *contacts)
{
	
	if (contacts->name.middleInitial[0] == '\0') {
		printf(" %s %s\n", contacts->name.firstName, contacts->name.lastName);
	}
	else {
		printf(" %s %s %s\n", contacts->name.firstName, contacts->name.middleInitial, contacts->name.lastName);
	}

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contacts->numbers.cell, contacts->numbers.home, contacts->numbers.business);

	if (contacts->address.apartmentNumber > 0) {		
		printf("       %d %s, Apt# %d, %s, %s\n", contacts->address.streetNumber, contacts->address.street, contacts->address.apartmentNumber, contacts->address.city, contacts->address.postalCode);

	}
	else {		
		printf("       %d %s, %s, %s\n", contacts->address.streetNumber, contacts->address.street, contacts->address.city, contacts->address.postalCode);

	}
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
	int i, count = 0;

	displayContactHeader();

	for (i = 0; i < size; i++) {
		if (strlen(contacts[i].numbers.cell) > 0) {
			displayContact(&contacts[i]);
			count++;
		}
	}
	displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	int i;
	char newNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(newNum);
	i = findContactIndex(contacts, size, newNum);
	printf("\n");

	if (i >= 0) {
		displayContact(&contacts[i]);
		printf("\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
}

// addContact:
void addContact(struct Contact contacts[], int size)
{
	int i;
	char newNum[11] = { '\0' };

	i = findContactIndex(contacts, size, newNum);
	if (i >= 0) {
		getContact(&contacts[i]);
		printf("--- New contact added! ---\n");
	}

	else {
			printf("*** ERROR: The contact list is full! ***\n");
		}
}

// updateContact:
	void updateContact(struct Contact contacts[], int size)
{
	int i, ans = 0;
	char newNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(newNum);
	i = findContactIndex(contacts, size, newNum);

	if (i >= 0) {
		printf("\nContact found:\n");
		displayContact(&contacts[i]);

		printf("\nDo you want to update the name? (y or n): ");
		ans = yes();
		if (ans == 1) {
			getName(&contacts[i].name);
		}

		printf("Do you want to update the address? (y or n): ");
		ans = yes();
		if (ans == 1) {
			getAddress(&contacts[i].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		ans = yes();
		if (ans == 1) {
			getNumbers(&contacts[i].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	int i = 0, ans = 0;
	char newNum[11];

	printf("Enter the cell number for the contact: ");	
	getTenDigitPhone(newNum);
	i = findContactIndex(contacts, size, newNum);

	if (i == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contacts[i]);

		printf("\nCONFIRM: Delete this contact? (y or n): ");
		ans = yes();
		if (ans == 1) {
			contacts[i].numbers.cell[0] = '\0';
		
			printf("--- Contact deleted! ---\n");
		
		}	
	}
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
	int i, j;
	struct Contact tempNum;

	for (i = 0; i < size - 1; i++) {

		for (j = i + 1; j < size; j++) {
			
			if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0) {			
				tempNum = contacts[i];
				contacts[i] = contacts[j];
				contacts[j] = tempNum;
			}
		}
	}	
}