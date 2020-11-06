/*
Name: Li-Ching, Cheng
Student number: 143292175
Email: lcheng49@myseneca.ca
Workshop: 5
Section: SGG
Date: 2018.06.12
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Define Number of Employees "SIZE" to be 2
#define SIZE 2



// Declare Struct Employee 
struct Employee {
	int id;
	int age;
	double salary;
};


/* main program */

int main(void) {

	int option = 0, empNum = 0, i = 0;

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero

	struct Employee emp[SIZE] = { {0} };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		
		// Capture input to option variable
		scanf("%d",&option);
		printf("\n");
		
		switch (option) {
		case 0:	// Exit the program
			
			printf("Exiting Employee Data Program. Good Bye!!!\n");

			break;

		case 1: 
		
				printf("EMP ID  EMP AGE EMP SALARY\n");
				printf("======  ======= ==========\n");
				for (i = 0; i < SIZE; i++) {

					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				}
				printf("\n");

			break;

		case 2:	
			printf("Adding Employee\n");
			printf("===============\n");			
						
			if (empNum >= SIZE) { 
				printf("ERROR!!! Maximum Number of Employees Reached\n");
				printf("\n");
			}

			else {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[empNum].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[empNum].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[empNum].salary);
				empNum++;
				printf("\n");
			}

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0; 
}



//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
