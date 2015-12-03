#include<iostream>
#include <iomanip>
#include <string>
#include "BST.h"
using namespace std;

// function for mainmenu screen display

void printSearchModule()
{
	cout << "|================================|\n";
	cout << "|         Search Menu            |\n";
	cout << "|                                |\n";
	cout << "|  1. Search by Trail Name       |\n";
	cout << "|  2. Search by Difficutly       |\n";
	cout << "|  3. Search by Populairty       |\n";
	cout << "|  4. Search by Distance         |\n";
	cout << "|  6. Sort All Trails            |\n";
	cout << "|  7. Return to the Main Menu    |\n";
	cout << "|                                |\n";
	cout << "|  Enter Your Choice: ";

}
void printEditModule()
{
	cout << "|==================================|\n";
	cout << "|      Bay Area Hiking Trails      |\n";
	cout << "|                                |\n";
	cout << "|     1. Edit Trail Name         |\n";
	cout << "|     2. Delete Trail Name       |\n";
	cout << "|     3. Return to Main Menu     |\n";
	cout << "|                                |\n";
	cout << "|  Enter Your Choice: ";
}

void printAddModule()
{
	cout << "|================================|\n";
	cout << "|      Bay Area Hiking Trails    |\n";
	cout << "|                                |\n";
	cout << "|  1. Add a Trail                |\n";
	cout << "|  2. Return to the Main Menu    |\n";
	cout << "|                                |\n";
	cout << "|  Enter Your Choice: ";

}


int main()
{
	void printMain();
	void printSearchModule();
	void printEditModule();
	void printAddModule();

	int tempOption = 0;
	string command = "";

	do{
		printMain();
		getline(cin, command);

		tempOption = static_cast<int>(atoi(command.c_str()));

		if ((tempOption< 1) || (tempOption> 3))
		{
			cout << "Invalid Input, Please enter a number between 1 and 3: ";
			continue;
		}

		if (tempOption == 1){
			cout << endl << endl;
			//search module
			/*Search menu("trails.txt");
			menu.printSearchModule();*/
		}
	