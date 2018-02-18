#include <iostream>
#include <fstream>
#include "Assignment4.h"

using namespace std;

//WORKS
void CommunicationNetwork::addCity(std::string newCityName, std::string previousCityName){
   
	//cout << newCityName << " " << previousCityName << endl;

	//INITIALIZE A CITY TO BE ADDED
	City *nn = new City;
	nn -> cityName = newCityName;
	//MAKE A CRAWLER POINTER TO TRAVERSE THE LIST
	City *crwl = head;
	//FIGURE OUT IF THE LIST IS EMPTY
	if(head == 0){
	//IT IS
	//HEAD IS THE NEW CITY	
		head = nn;
	}else{
	//IT ISNT
	//FIND WHERE THE CITY SOULD GO
		if(previousCityName == "First"){
			nn -> next = head;
			head -> previous = nn;
			head = nn;
		}else if(previousCityName == ""){
		//IT SHOULD GO AT THE END APPARENTLY
			while(crwl -> next != nullptr){
				crwl = crwl -> next;
			}
			crwl -> next = nn;
			nn -> previous = crwl;
			//RESETS THE HEAD TO NN BECASUE THAT IS THE NEW HEAD
			tail = nn;
		}else{
			//IT SHOULD GO IN THE MIDDLE/END
			while(crwl -> cityName != previousCityName){
				crwl = crwl -> next;
			}

			//IT NEEDS TO BE ADDED TO THE END
			if(crwl -> next == nullptr){
				crwl -> next = nn;
				nn -> previous = crwl;

				tail = nn;

			//IT GOES SOMEWHERE IN THE MIDDLE
			}else{
				crwl -> next -> previous = nn;
				nn -> next = crwl -> next;

				crwl -> next = nn;
				nn -> previous = crwl;
			}
		}
	}	
}

//WORKS
void CommunicationNetwork::transmitMsg(char* filename){
    City *tmp = new City;
 	tmp = head;

 	string ss;

 	ifstream mainfile;
	
	mainfile.open(filename);

	if(mainfile.is_open()){
        while(mainfile >> ss){
			while(tmp -> next != nullptr){
		 		tmp -> message = ss;
		 		cout << tmp -> cityName << " received " << tmp -> message<< endl;
		 		tmp = tmp -> next;
		 	}
		 	tmp -> message = ss;
		 	cout << tmp -> cityName << " received " << tmp -> message << endl;
		 	tmp = tmp -> previous;
		 	while(tmp -> previous != nullptr){
		 		tmp -> message = ss;
		 		cout << tmp -> cityName << " received " << tmp -> message << endl;
		 		tmp = tmp -> previous;
		 	}
		 	head -> message = ss;
		 	cout << head -> cityName << " received " << head -> message << endl;
		}
	}
	
	mainfile.close();
}

//WORKS
void CommunicationNetwork::printNetwork(){
    cout << "===CURRENT PATH===" << endl;
     //THIS WONT WORK IF LIST OS EMPTY
	City *tmp = head;
	cout << "NULL <- ";
	while(tmp != nullptr){
		cout << tmp -> cityName;
		if(tmp -> next != nullptr){
	        cout << " <-> ";
	    }
		tmp = tmp -> next;
	}
	cout << " -> NULL" << endl;

	cout << "==================" << endl;
}

//WORKS
void CommunicationNetwork::buildNetwork(){
     string cities[10] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};
     City *tmp;
     City *tmp1 = new City;
     tmp = tmp1;
     //THIS IS SUPER IMPORTANT!!!!
     head = tmp1;

     tmp -> cityName = cities[0];
     for(int i = 1; i < 10; i++){
     	City *nn = new City;
     	nn -> cityName = cities[i];
     	nn -> previous = tmp;
     	tmp -> next = nn;
     	tmp = nn;
     }
}

//WORKS
void CommunicationNetwork::deleteCity(std::string removeCity){

	City *tmp = head;
	City *tmpA;
	City *tmpB;
	bool exist = false;
	while(tmp -> cityName != removeCity && tmp != tail){
		tmp = tmp -> next;
	}

	if(tmp -> cityName == removeCity){
		exist = true;
	}

	if(exist){
		tmpB = tmp -> previous;
		tmpA = tmp -> next;
		//END OF THE LIST
		if(tmp -> next == nullptr){
			tmpB -> next = nullptr;
			tail = tmpB;
		//BEGINING OF THE LIST
		}else if(tmp -> previous == nullptr){
			tmpA -> previous = nullptr;
			head = tmpA;
		//ANYWHERE ELSE
		}else{	
			tmpB -> next  = tmpA;
			tmpA -> previous = tmpB;
		}

		delete tmp;
		}

	if(!exist){
		cout << removeCity << " not found" << endl;
	}
}

//WORKS  
void CommunicationNetwork::deleteNetwork(){
    City *tmp = head;
    City *nxt;
    while(nxt != nullptr){
    	nxt = tmp -> next;
    	cout << "deleting " << tmp -> cityName << endl;
    	delete tmp;
    	tmp = nxt;
    }
    head = 0;
}

//WORKS
CommunicationNetwork::CommunicationNetwork(){
    City *nn = new City;
    City *head;
    head = nn;
    head = tail;
}

//WORKS
CommunicationNetwork::~CommunicationNetwork(){
		head = nullptr;
		tail = nullptr;
}
