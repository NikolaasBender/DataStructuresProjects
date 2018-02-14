/*
NIKOLAAS BENDER HOMEWORK 4 FOR DATA STRUCTURES 
CU BOULDER
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct city{
	
	city *next;
	string cityName;
	string message;
};

//======================================================================
//THIS BUILDS THE DEFAULT NETWROK
//THIS WORKS
//======================================================================
city *buildNetwork(){

	//INITIALIZING EACH CITY BY MAJOR AIRPORT CALL SIGN
	city *lax = new city;
	city *phx = new city;
	city *den = new city;
	city *dfw = new city;
	city *stl = new city;
	city *ord = new city;
	city *atl = new city;
	city *dca = new city;
	city *lga = new city;
	city *bos = new city;

	//INITIALIZING EACH CITY NAME 
	lax -> cityName = "Los Angeles";
	phx -> cityName = "Phoenix";
	den -> cityName = "Denver";
	dfw -> cityName = "Dallas";
	stl -> cityName = "St. Louis";
	ord -> cityName = "Chicago";
	atl -> cityName = "Atlanta";
	dca -> cityName = "Washington, D.C.";
	lga -> cityName = "New York";
	bos -> cityName = "Boston";

	//THIS INITIALIZES THE LINK
	lax -> next = phx;
	phx	-> next = den;
	den	-> next = dfw;
	dfw	-> next = stl;
	stl	-> next = ord;
	ord	-> next = atl;
	atl	-> next = dca;
	dca	-> next = lga;
	lga -> next = bos;
	bos	-> next =  nullptr;

	return lax;
}

//======================================================================
//THIS FINDS A CITY BASED UPON THE NAME OF THE CITY
//IT SHOULD WORK 
//======================================================================
city *fndCty(city *head, string city){

	while(head -> cityName != city){
		head = head -> next;
	}

	return head;
}

//======================================================================
//THIS SHOULD ADD THE CITY
//REALLY IT NEEDS THE CITY FINDER TO FEED INTO IT
//THIS WORKS
//======================================================================
city *addCity(city *head, city *previous, string ctyName){

	//THIS IS THE NEW CITY THAT GETS INSERTED
	city *nn = new city;

	//THIS SETS THE CITY NAME
	nn -> cityName = ctyName;

	//THIS WORKS FOR INSERTING AT THE END OR THE MIDDLE
	if(previous != NULL){
		//THIS SETS THE NEW CITY TO BE THE NEXT
		//AS DICTATED BY PREVIOUS
		nn -> next = previous -> next;

		//SET PREVIOUS NEXT TO THE NEW CITY
		previous -> next = nn;
	}else if(previous == NULL){
		nn -> next = head;

		head = nn;
	}

	return head;	
}

//======================================================================
//THIS TRANSMITS THE MESSAGE FROM A FILE 
//THROUGH THE NETWORKONE STRING AT A TIME
//THIS WORKS
//======================================================================
void transmitMsg(city *head){
     
 	city *tmp = new city;
 	tmp = head;

 	string ss;

 	ifstream mainfile;
	
	mainfile.open("messageIn.txt");

	if(mainfile.is_open()){
        while(mainfile >> ss){
			while(tmp -> next != nullptr){
		 		tmp -> message = ss;
		 		cout << tmp -> cityName << " received " << tmp -> message << endl;
		 		tmp = tmp -> next;
		 	}
		 	tmp -> message = ss;
		 	cout << tmp -> cityName << " received " << tmp -> message << endl;
		 	tmp = head;
		}
	}
	
	mainfile.close();    
}

//======================================================================
//THIS PRINTS THE WHOLE PATH
//THIS WORKS 
//======================================================================
void printPath(city *head){

	cout << "===CURRENT PATH===" << endl;

	while(head != nullptr){
		cout << head -> cityName << " -> ";
		head = head -> next;
	}
	cout << " NULL" << endl;

	cout << "==================" << endl;
}

//======================================================================
//THIS IS THE MENU THAT THE USER USES
//======================================================================
int menu(){
	cout << "======Main Menu======" << endl <<
	"1. Build Network" << endl <<
	"2. Print Network Path" << endl <<
	"3. Transmit Message Coast-To-Coast" << endl <<
	"4. Add City"<< endl <<
	"5. Quit" << endl;

	int n;

	cin >> n;

	return n;
}

int main(){

	int o = 0;

	//THIS SETS UP THE HEAD
	city *head;

	//THIS IS THE OPTIONS MENU
	while(o >= 0 && o <= 4){
		//THIS RESETS o FOR EACH TIME IT GETS USED
		o = 0;

		//THIS TAKES THE OPTION SELECTED FROM MENU
		o = menu();

		//BUILD NETWORK
		if(o == 1){
			head = buildNetwork();
			o = 0;
		}

		//PRINT NETWORK
		if(o == 2){
			printPath(head);
			o = 0;
		}

		//TRANSMIT MESSAGE
		if(o == 3){
			transmitMsg(head);
			o = 0;
		}

		//ADDS A CITY
		if(o == 4){
			cout << "Enter a City name:" << endl;
			string nc;
			cin >> nc;
			cout << "Enter a previous City name:" << endl;
			string prev;
			cin >> prev;
			head = addCity(head, fndCty(head, prev), nc);
			o = 0;
		}

		//ERROR 
		if(o > 5){
			cout << "PLEASE ENTER THE NUMBER OF THE OPTION YOU WANT " << o << " IS NOT A VALID OPTION" << endl;
			o = 0;
		}

	}

	cout << "Goodbye!" << endl;



}