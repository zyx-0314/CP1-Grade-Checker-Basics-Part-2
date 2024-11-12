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
		name = InputStringPassVal("Your Name: ");
		section = InputStringPassVal("Your Section: ");

		InputStringPassRef("Your School: ", school);

		ComputeGrade(average);

		std::cout << name << ":" << section << " - " << school << " - " << average << "\n";

		if (!WantToContinue())
		{
			exit(0);
		}
	}

	return 0;
}

std::string InputStringPassVal(std::string instruction) {
	std::string inputString;

	std::cout << instruction;
	std::getline(std::cin, inputString);

	return inputString;
}

void InputStringPassRef(std::string instruction, std::string& inputString) {
	std::cout << instruction;
	std::getline(std::cin, inputString);
}

void ComputeGrade(float& average) {
	const int MAX = 5;

	int input, total = 0;

	for (int i = 0; i < MAX; i++)
	{
		std::cout << i + 1 << " Input Grade: ";
		std::cin >> input;

		total += input;
	}

	average = total / MAX;
}

bool WantToContinue() {
	bool choice;
	std::string input;

	do
	{
		std::cin.ignore();
		std::cout << "Do you want to do another? [y/n]\n";
		std::getline(std::cin, input);

		// input[0] is to get the first character input in string
		// tolower converts the character to lowercase
		input = std::tolower(input[0]);

		if (input == "y" || input == "n")
		{
			system("cls");
			if (input == "y") {
				return 1;
			}
			else {
				return 0;
			}
		}
	} while (true);

}