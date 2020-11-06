/*
Name: Cheng, Li-Ching
Student number: 143292175
Email: lcheng49@myseneca.ca
Workshop: 5
Section: SGG
Date: 2018.06.12
*/

// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Define Number of Employees "SIZE" to be 2
#define SIZE 4


// Declare Struct Employee 
struct Employee {
	int id;
	int age;
	double salary;
};


/* main program */

int main(void) {

	int option = 0, empNum = 0, i, idUpdate = 0, idWrong = 0;

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero

	struct Employee emp[SIZE] = { { 0 } };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program

			printf("Exiting Employee Data Program. Good Bye!!!\n");

			break;

		case 1:

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0; i < SIZE; i++) {
				if (emp[i].id > 0) {
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				}
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

		case 3:

			idWrong = 0;
			
			do {
				printf("Update Employee Salary\n");
				printf("======================\n");
				printf("Enter Employee ID: ");
				scanf("%d", &idUpdate);

				for (i = 0; i < SIZE; i++) {
					if (idUpdate == emp[i].id) {						
						printf("The current salary is %.2lf\n", emp[i].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[i].salary);
						printf("\n");
						idWrong = 1;
					}
				}
			} while (idWrong == 0);

			break;

		case 4:
			
			idWrong = 0;

			do {
				printf("Remove Employee\n");
				printf("===============\n");
				printf("Enter Employee ID: ");
				scanf("%d", &idUpdate);

				for (i = 0; i < SIZE; i++) {
					if (idUpdate == emp[i].id) {
						emp[i].id = 0;
						emp[i].age = 0;
						emp[i].salary = 0;
						idWrong = 1;
						printf("Employee %d will be removed\n", idUpdate);
						printf("\n");
						empNum--;
					}
				}
			} while (idWrong == 0);		

			break;

		default:

			printf("ERROR: Incorrect Option: Try Again\n\n");

		} 

	} while (option != 0);

	return 0;

}







// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 113
Enter Employee Age: 53
Enter Employee Salary: 120345.78

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 114
Enter Employee Age: 25
Enter Employee Salary: 46780

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 112
The current salary is 65000.00
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   99999.99
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 112
Employee 112 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!
*/