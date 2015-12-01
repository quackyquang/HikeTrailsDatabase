#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include "InputOutput.h"

using namespace std;

/*



*/
void getData()
{
	string temp{};
	fstream stream;
	stream.open("trails.txt",ios::in);
	while (!getline(stream, temp))
	{
		string junk = strtok((char*)temp.c_str(), ":");
		string name = strtok(NULL, ":");
		junk = strtok(NULL, ":");
		string park = strtok(NULL, ":");
		junk = strtok(NULL, ":");
		string location = strtok(NULL, ":");
		junk = strtok(NULL, ":");
		double distance = atof(strtok(NULL, ":"));
		junk = atof(strtok(NULL, ":"));
		double diff = atof(strtok(NULL, ":"));
		junk = atof(strtok(NULL, ":"));
		double pop = atof(strtok(NULL, ":"));
		Trails data(name, park, location, distance, diff, pop );
		//put into hash
		stream.close();
	}
	
}

void writeData()
{
	fstream stream;
	stream.open("out.txt", ios::out);
	//read in from hash tableeeeee :)S

}

//change CIN inputs to getline if doens't work
void printMenu(){
	int option;
	cout << "What would you like to do today?\n";
		cin >> option;

	cout << "1. Add new data\n";
	cout << "2. Delete data\n";
	cout << "3. Find data with key\n";
	cout << "4. List data in hash sequence\n";
	cout << "5. List data in key sequence (sorted)\n";
	cout << "6. Print indented tree\n";
	cout << "7. Efficiency\n";
	cout << "8. \n";
	cout << "9. Quit\n";

	switch (option){
	case 1:
		add();
		break;

	case 2:
		remove();
		break;

	case 3:
		findKey();
		break();

	case 4:
		listHash();
		break;

	case 5:
		listKey();
		break;

	case 6:
		printTree();
		break;

	case 7:
		efficiency();
		break;

	case 8:
		//option();
		break;

	case 9:
		return(0);





	default:
		cout << "Error, please select another option."
			printMenu();
	}


}
void add(){
	string name;
	string park;
	string location;
	double difficulty;
	double popularity;

	cin >> name;
	cin >> park;
	cin >> location;

	try{
		string temp;
		cin >> temp;

		difficulty = stod(temp);
		//cout << num;
		//cin >> difficulty;
		//stod(difficulty);

	}
	catch (int e){
		cout << "error enter a number for difficulty from(1-10). " << endl;

	}

	try{
		string temp2;
		cin >> temp2;
		popularity = stod(temp2);
		//cin >> popularity;

	}
	catch (int e){
		cout << "error enter a number for popularity from(1-10). " << endl;
	}

	Trail *trails(name, park, location, diffculty, popularity);

}

void findPop(){
	double top;
	double bot;

	while (top < bot){
		cout << "lower limit popularity";
		cin >> bot;
		cout << "upper limit popularity";
		cin top;

		if (top < bot){
			cout << "range window error, please re-enter range. \n";
		}
	}
	cout << "These trails have a popularity ranging from " << top << " to " << bot << endl;
	for (int i = 0; i <= trail.length; i++){
		if (trail[i].popularity <= top && trail[i].popularity >= bot){
			printInfo(trail[i]);
		}
	}


}

void findDif(){
	double top;
	double bot;

	while (top < bot){
		cout << "lower limit difficulty";
		cin >> bot;
		cout << "upper limit difficulty";
		cin top;

		if (top < bot){
			cout << "range window error, please re-enter range. \n";
		}
	}
	cout << "These trails have a difficulty ranging from " << top << " to " << bot << endl;
	for (int i = 0; i <= trail.length; i++){
		if (trail[i].popularity <= top && trail[i].popularity >= bot){
			printInfo(trail[i]);
		}
	}
}

/*void remove(datatype &trail){
	cout << trail.name << endl;
	cout << trail.park << endl;
	cout << trail.location << endl;
	cout << trail.difficulty << endl;
	cout << trail.popularity << endl << endl;
}

void printAll(datatype trailList){
	for (int i = 0; i < trailList.length; i++){
		printInfo(trailList.trail);
	}*/
}


