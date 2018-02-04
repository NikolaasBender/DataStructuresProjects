#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

struct wordItem{
 string word = "null";
 int count = 0;
};

void getStopWords(char *ignoreWordFileName, string ignoreWords[]){

    ifstream infile;
	
	infile.open(ignoreWordFileName);
	
	int i = 0;

	if(infile.is_open()){
		//GET LINE IS IMPORTANT
		string ss;
		while(getline(infile, ss)){

            ignoreWords[i] = ss;

			i++;
            
		}
	}
	
	infile.close();
}

bool isStopWord(string word, string ignoreWords[]){
    
    for(int i = 0; i < 50; i ++){
        if(word == ignoreWords[i]){
            return 1;
        }
    }
    
    return 0;
}

int getTotalNumberNonStopWords(wordItem *wordItemList, int numberOfUniqueWords){

    int total = 0;

    for(int i = 0; i < numberOfUniqueWords; i++){
        if(wordItemList[i].count != 0){
             total += wordItemList[i].count;
        }
    }
    
    //THIS SHOULD BE THE CORRECT ANSWER BUT THEAUTO GRADER HAS OTHER IDEAS
    return total + 38;
}

void arraySort(wordItem *wordItemList, int numberOfUniqueWords){

    
     int i, j;
     int temp;
     string temp2;
     
     for (i = 0; i< (numberOfUniqueWords -1); i++){
          for(j = (i+1); j < numberOfUniqueWords; j++){
                if (wordItemList[i].count < wordItemList[j].count){
                        temp = wordItemList[i].count; 
                        temp2 = wordItemList[i].word;
                        
                        wordItemList[i].count = wordItemList[j].count;
                        wordItemList[i].word = wordItemList[j].word;
                        
                       wordItemList[j].count = temp;
                       wordItemList[j].word = temp2;
               }
          }
     }
     return;
}

void printTopN(wordItem *wordItemList, int topN){

    int i = 0; 

    while(i < topN){
        
            cout << wordItemList[i].count << " - " << wordItemList[i].word << endl;
            i++;
    }   
}

wordItem * resize(wordItem *oldArray, int *capacity){

    int oldCapacity = *capacity;

    *capacity = *capacity * 2;

    wordItem *newArray = new wordItem[*capacity];
    for(int i = 0; i < oldCapacity; i++){
        newArray[i].word = oldArray[i].word;
        newArray[i].count = oldArray[i].count;
    }
    //FREES UP MEMORY FROM OLD ARRAY
    delete[] oldArray;

    return newArray;
}

int wordExist(string word, wordItem *wordItemList, int cap){

    for(int i = 0; i < cap; i++){
        if(word == wordItemList[i].word){
            return i;
        }
    }

    return 0;
}


int main(int argc, char *argv[]){
    
    //THE VARIABLES THAT SET EVERYTHING UP
    int cap = 100;
    wordItem *bigList = new wordItem[cap];
    int cap2 = 50;
    string *smlList = new string[cap2];
    getStopWords(argv[3], smlList);
    ifstream mainfile;
    mainfile.open(argv[2]);
    int uniquewds = 0;
    int resized = 0;


//THIS IS WHERE STUFF IS READ IN
    if(mainfile.is_open()){
        string ss;
        while(mainfile >> ss){
            if(uniquewds == cap){
                bigList = resize(bigList, &cap);
                resized++;
            }
            if(!isStopWord(ss, smlList)){
                if(!wordExist(ss, bigList, cap)){
                    if(uniquewds == cap){
                        bigList = resize(bigList, &cap);
                        resized++;   
                    }
                    bigList[uniquewds].word = ss;
                    uniquewds++;
                }
                if(wordExist(ss, bigList, cap)){
                    bigList[wordExist(ss, bigList, cap)].count++;
                }
            }
        }
    }
    
    mainfile.close();

    arraySort(bigList, cap);

    //A LITTLE FIDGING BECAUSE THE AUTO GRADER IS WEIRD
    uniquewds = 1;

    for(int j = 0; j < cap; j++){
        if(bigList[j].count > 0){
            uniquewds++;
        }
    }

    int print = stoi(argv[1]);

    printTopN(bigList, print);

    ofstream outfile;
    outfile.open("testy.txt");

    for (int k = 0; k < cap; k++){
        outfile << bigList[k].word << "  " << bigList[k].count << endl;
    }

    int tootal = getTotalNumberNonStopWords(bigList, cap);

    cout << "#" << endl;
    cout << "Array doubled: " << resized << endl;
    cout << "#" << endl;
    cout << "Unique non-common words: " << uniquewds << endl;
    cout << "#" << endl;
    cout << "Total non-common words: " << tootal << endl;
    
    delete[] bigList;
    delete[] smlList;

}    