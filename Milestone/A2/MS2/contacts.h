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


//------------------------------------------------------
// Structure Types
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        structures here...                       |
// +-------------------------------------------------+

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code here...
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code here...
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

// Structure type Contact declaration
// Place your code here...
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function prototypes here...              |
// +-------------------------------------------------+


// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name *);

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address *);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers *);

// Get and store from standard input the values for a Contact
// Place your code here...
void getContact(struct Contact *);