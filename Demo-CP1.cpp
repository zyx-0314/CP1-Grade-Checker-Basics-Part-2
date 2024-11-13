/*
	Cases
	- camelCase
		- camelLongerNameCase
	- snake_Camel_Case
	- PascalCase
		- PascalLongerNameCase
	- Snake_Pascal_Case
	- snake_lower_case
	- SNAKE_SCREAMING_CASE

	1. Naming Convention
		variable - camelCase (-10%)
		constant - SNAKE_SCREAMING_CASE (-10%)
		function - PascalCase (-10%)
	2. Naming should make sense & Use only global abbreviation
	3. Code Construction (-2%)
		{
			constant variable
			variable

			code block
		}
	4. Refrain using Global Variable (automatic 0)

*/

// Demo Project
// Collect Grade of student in 5 subjects and display average with their name

// Activity projects
// 1. Collect names and age of visitors of resort, based on their age provide them their required payment(Levels: Kids, Adult, Senior). payment should check if they input enoung
// 2. Sari Sari Store System, user can pick as much as they can and compute their total amount to be payed and add their name in receipt
// 3. Compute the total clients entering a park per group then providing them a name for their group for payment. if not payed enough they can't enter and will entertain other user
// 4. User can compute the salary of their worker per hour, inputing their salary per hour and their time of work, a additional bonus if they are working night shift (x1.5), early morning shift (x1.8)
// 5. 

#include <iostream>
#include <string>
#include <cstring>

std::string InputStringPassVal(std::string);
void InputStringPassRef(std::string, std::string&);
void ComputeGrade(float&);
bool WantToContinue();

int main()
{
	float average;
	std::string name, section, school;

	while (true) {
        // 1. Uses a function that set instruction in cout and accepts and return data in passing by value
		name = InputStringPassVal("Your Name: ");
		section = InputStringPassVal("Your Section: ");

        // 2. Uses a function that set instruction in cout and accepts and return data in passing by reference
		InputStringPassRef("Your School: ", school);

        // 3. Compute the grade in function by reference
		ComputeGrade(average);

        // 4. Display Data in hold
		std::cout << name << ":" << section << " - " << school << " - " << average << "\n";

        // 5. Using an WantToContinue function that returns boolean it will determine if the console app will exit or not
		if (!WantToContinue())
		{
			exit(0);
		}
	}

	return 0;
}

// A function that set instruction in cout and accepts and return data in passing by value
std::string InputStringPassVal(std::string instruction) {
	std::string inputString;

    // 1. it will use the instruction provided
	std::cout << instruction;
	std::getline(std::cin, inputString);

    // 2. return input
	return inputString;
}

// A function that set instruction in cout and accepts and return data in passing by reference
void InputStringPassRef(std::string instruction, std::string& inputString) {

    // 1. it will use the instruction provided
	std::cout << instruction;
    // 2. input the user information in the referenced variable
	std::getline(std::cin, inputString);
}

// A function that use by reference the average and store the computed grade
void ComputeGrade(float& average) {
	const int MAX = 5;

	int input, total = 0;

    // 3. it will loop until the i is more than the set value of MAX
	for (int i = 0; i < MAX; i++)
	{
        // 1. prompt the user 
            // the first part i + 1 is used to provide number indication to user in human number counting
		std::cout << i + 1 << " Input Grade: ";
		std::cin >> input;

        // 2. after input it will then be automatically added to the total
		total += input;
	}

    // it will do the computation of average
	average = total / MAX;
}

// A function that checks the user input if correct, and return true or false
bool WantToContinue() {
	bool choice;
	std::string input;

	do
	{
		std::cin.ignore();
        // 1. Prompt user a option
		std::cout << "Do you want to do another? [y/n]\n";
        // 2. Accepts user input even with space 
		std::getline(std::cin, input);

        // 3. select only the first character of the input and always in lower case
		    // input[0] is to get the first character input in string
		    // tolower converts the character to lowercase
		input = std::tolower(input[0]);

        // 4.1 if it is y or n it will set to return
		if (input == "y" || input == "n")
		{
			system("cls");
            // 5.1 if the input is y then return 1 which is true
			if (input == "y") {
				return 1;
			}
            // 5.2 else the input is y then return 0 which is false
			else {
				return 0;
			}
		}
    // 4.2 else it will loop back to start
	} while (true);
}

