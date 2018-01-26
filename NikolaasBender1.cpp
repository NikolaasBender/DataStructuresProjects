//HOMEWORK 1
//Nikolaas Bender

/*
https://moodle.cs.colorado.edu/pluginfile.php/65928/mod_resource/content/11/Assignment%201%20Community%20Garage%20Sale.pdf
Your	program needs	to	read	the	file	until	it	reaches	the	end,	and	you	can’t	assume	there	
will	always	be	100	lines,	there	may	be	less.	As	lines	are	read	from	the	file,	you	need	to	
check	if	there	is	a	match	with	the	existing	items	in	the	message	board.	There	are	two	
options	to	consider:
	Match	is	not	found	in	the	array
	Match	is	found	in	the	array
*/


#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//=====================================================================
//THIS IS THE PERSON STRUCT TO REPRESENT A CRAIGSLIST PERSON
//IT OVER SIMPLIFIES IN CERTIAN CASES BUT IS A PERFECT AMOUNT OF DATA 
//FOR THIS HOMWWORK
//=====================================================================
struct person{
//THIS SETS UP THE PARAMETERS WITH SOME PRE SET FOR FUTURE USE
	int p = 0;
	bool m = 0;
	std::string i = " ";
	std::string w = " ";

	//THIS IS A CONSTRUCTOR
	person(){} 
	person(std::string item, std::string want, int price, bool match){
		p = price;
		w = want;
		i = item;
		m = match;
	}

};

//=====================================================================
//THIS MATCHES THE PEOPLE BY COMPARING PARAMETERS THEN CHANGING
//THE MATCH BOOLEAN VARIABLE TO TURE TO KEEP TRACK OF PEOPLE 
//WHO HAVE FOUND MATHCES
//THIS METHOD USES MORE MEMORY BUT I THINK IS A MORE
//STRAIGHTFORWARD WAY OF DOING IT BECAUSE IT MAKES MORE SENSE
//IT HAS A FALSE SAFE SO IT WILL WORK EVERY TIME
//=====================================================================
void matcher(person buyer[], person seller[]){

	//RUNS THROUGH ALL BUYERS AND SELLERS USING NESTED FOR LOOPS
	for(int g = 0; g < 100; g++){	
		for(int k = 0; k < 100; k++){
			//MUST NOT HAVE A MATCH AND MUST BE THE CORRECT ITEM AND THE PRICE MUST WORK 
			if(seller[k].i == buyer[g].i && seller[k].p <= buyer[g].p && seller[k].m == 0 && buyer[g].m == 0 && seller[k].p != 0 && buyer[g].p != 0){

			//SETS THE MATCH VALUE TO TRUE FOR BOTH PEOPLE WHEN ALL REQUIREMENTS ARE SATISFIED
				seller[k].m = 1;
				buyer[g].m = 1;

				//PRINTS ALL OF THE MATCHES
				cout << seller[k].i << " " << seller[k].p << endl;

			}
		}
	}
}

//=====================================================================
//=====================================================================
//MAIN STATMENT (MEAT AND POTATOES)
//=====================================================================
//=====================================================================
int main(int argc, char* argv[]){

	//MAKE AN ARRAY FOR THE PEOPLE SELLING
	person sellers[100];
	
	//MAKE AN ARRAY FOR THE PEOPLE BUYING
	person buyers[100];
	

	//THIS IS THE FILE STRING FOR STORING THAT
	string file;

	//=====================================================================
	//DECIDES IF IT WILL USE THE INPUT FILE OR THE DEFAULT FILE
	//=====================================================================
	if(argc == 2){

		//INPUT FILE SPECIFIED BY USER
		file = argv[1];

	}else{
		//DEFAULT FILE 
		file = "garagesale.txt";

	}

	std::ifstream myfile(file);



	if(myfile.is_open()){
		std::string line;
		int b = 0;
		int s = 0;

		person dummy;

		//GET LINE IS IMPORTANT
		while(getline(myfile, line)){

			//STRING STREAM
			std::stringstream ss;
			//PUTS THE STRING INTO THE STRING STREAM
			ss<<line;

			std::string item;
			std::string want;
			std::string price;	

			getline(ss, item, ',');
			dummy.i = item;

			getline(ss, want, ',');
			dummy.w = want;

			getline(ss, price);
			//CHANGES THE STRING OF PRICE TO AN INTEGER
			dummy.p = stoi(price);

			//=====================================================================
			//SORTS THE DUMMYS INTO THE RESPECTIVE ARRAYS
			//=====================================================================
			if(dummy.w == " wanted"){
				buyers[b] = dummy;
				b++;
			}else{
				sellers[s] = dummy;
				s++;
			}
		}


	}else{

		std::cout << "ERROR! FIX PLS!" << std::endl;
		return 0;

	}
	//=====================================================================
	//RUNS THE MATCH MAKER FUNCTION TO FIND MATCHES
	//=====================================================================
	// cout <<"=================================================================" << endl 
	// << "THE MATCHES ARE" << endl 
	// << "=================================================================" << endl;
	matcher(buyers, sellers);

	// cout <<"=================================================================" << endl 
	// << "THE PEOPLE WHO DIDNT GET A MATCH" << endl
	// <<"=================================================================" << endl;
	//=====================================================================
	//PRINTS THE PEOPLE WHO DIDNT GET A MATCH
	//=====================================================================
	cout << "#" << endl;
	for(int d = 0; d < 100; d++){

		if(buyers[d].m == 0 && buyers[d].i != " "){

			cout << buyers[d].i << "," << buyers[d].w << ", " << buyers[d].p <<endl;
		}

		if(sellers[d].m == 0 && sellers[d].i != " "){

			cout << sellers[d].i << "," << sellers[d].w << ", " << sellers[d].p << endl;
		}

	}
}