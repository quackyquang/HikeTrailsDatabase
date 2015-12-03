#ifndef INPUTOUTPUT.h
#define INPUTOUTPUT.h
#include "Trails.h"

//File input output functions
void getData();
Trails parseData(std::string,std::string,std::string,double,double,double);
void writeData();

//Standard input output functions
void printMenu();
void add();
void findPop();
void findDif();
/*void remove(datatype &trail);
void printAll(datatype trailList);*/

#endif
