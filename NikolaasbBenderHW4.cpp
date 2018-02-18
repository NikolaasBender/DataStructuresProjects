/*
NIKOLAAS BENDER HOMEWORK 4 FOR DATA STRUCTURES 
CU BOULDER
*/

#include <iostream>
#include <string>
#include <fstream>

#include "Assignment4.h"

using namespace std;

//g++ -std=c++11 Assignment4.cpp Assignment4.h NikolaasbBenderHW4.cpp -o NikolaasbBenderHW4

//======================================================================
//THIS IS THE MENU THAT THE USER USES
//======================================================================
int menu(){
	cout << "======Main Menu======" << endl
			<< "1. Build Network" << endl
			<< "2. Print Network Path" << endl
			<< "3. Transmit Message Coast-To-Coast-To-Coast" << endl
			<< "4. Add City" << endl
			<< "5. Delete City" << endl
			<< "6. Clear Network" << endl
			<< "7. Quit" <<endl;

	int n;

	cin >> n;

	return n;
}

int main(int argc, char *argv[]){

	int o = 0;

	//INITIALIZES THE CITY
	CommunicationNetwork C2C;

	//THIS IS THE OPTIONS MENU
	while(o >= 0 && o <= 6){
		//THIS RESETS o FOR EACH TIME IT GETS USED
		o = 0;

		//THIS TAKES THE OPTION SELECTED FROM MENU
		o = menu();
		
		//BUILD NETWORK
		if(o == 1){
			C2C.buildNetwork();
			C2C.printNetwork();
			o = 0;
		}

		//PRINT NETWORK
		if(o == 2){
			C2C.printNetwork();
			o = 0;
		}

		//TRANSMIT MESSAGE
		if(o == 3){
			C2C.transmitMsg(argv[1]);
			o = 0;
		}

		//ADDS A CITY
		if(o == 4){
			cout << "Enter a city name:" << endl;
			string nc;
			cin >> nc;
			cout << "Enter a previous city name:" << endl;
			string prev;
			cin >> prev;
			C2C.addCity(nc, prev);
			o = 0;
		}

		//DELETE CITY
		if(o == 5){
			string dc;
			cout << "Enter a city name:" << endl;
			cin >> dc;
			C2C.deleteCity(dc);
		}

		//DELETE NETWORK
		if(o == 6){
			C2C.deleteNetwork();
		}

		//ERROR 
		if(o > 8){
			cout << "PLEASE ENTER THE NUMBER OF THE OPTION YOU WANT " << o << " IS NOT A VALID OPTION" << endl;
			o = 0;
		}

	}

	cout << "Goodbye!" << endl;
	C2C.deleteNetwork();
}