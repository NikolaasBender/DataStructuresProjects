/*
NIKOLAAS BENDER 
HW 5
*/

#include <iostream>
#include <string>
#include <sstream>
#include "Queue.h"

using namespace std;

int menu(){
	cout << "======Main Menu=====" << endl
			<< "1. Enqueue word" << endl
			<< "2. Dequeue word" << endl
			<< "3. Print queue" << endl
			<< "4. Enqueue sentence" << endl
			<< "5. Quit" <<endl;

	string n;

	getline(cin, n);

	int nn = stoi(nn);

	return nn;
}

int main(int argc, char *argv[]){

	int o = 0;

	//INITIALIZES THE QUEUE
	Queue qzie(10);
	
	//THIS IS THE OPTIONS MENU
	while(o >= 0 && o <= 4){
		//THIS RESETS o FOR EACH TIME IT GETS USED
		o = 0;

		//THIS TAKES THE OPTION SELECTED FROM MENU
		o = menu();

		
		//ENQUEUE WORD
		if(o == 1){
			cout << "word: ";
			string in;
			getline(cin, in);
			qzie.enqueue(in); 
			//qzie.printQueue();
			o = 0;
		}

		//DEQUEUE WORD
		if(o == 2){
			qzie.dequeue();
			o = 0;
		}

		//PRINT QUEUE
		if(o == 3){
			qzie.printQueue();
			o = 0;
		}

		//ENQUEUE SENTENCE
		if(o == 4){
			cout << "sentence: ";
            string line;
            getline(cin, line);
			qzie.enqueueSentence(line); 
			qzie.printQueue();
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