#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue(int qs){
    queueSize = qs;
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;
    arrayQueue = new string[qs];
    
    
}


Queue::~Queue(){
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;
    queueSize = 0;
}

//Insert a new word into the circular queue, print out the added word and the index
//of the head and tail positions. If the queue is completely full, print "Queue is full."
//WORKS
void Queue::enqueue(std::string word){
	if(!queueIsFull()){
		//IT WANTS ME TO DO THIS
		cout << "E: " << word << endl;
		cout << "H: " << queueHead << endl;
		//THIS ADDS THE WORD AT THE TAIL LOCATION
		   //SEG FAULT RIGHT HERE
		arrayQueue[queueTail] = word;
		queueCount++;
		//THIS MOVES THE TAIL WHILE KEEPING IT INSIDE OF THE ARRAY
		if(queueTail == queueSize - 1){
			queueTail = 0;
		}else{
			queueTail++;
		}
		cout << "T: " << queueTail << endl;
	}else{
		cout << "Queue is full" << endl;
	}
}


//Perform the dequeue operation on the circular queue and print out the indices of
//the head and tail positions. Also print the word that was dequeued. If the queue is
//empty, print "Queue is empty."
void Queue::dequeue(){
	string tmp = arrayQueue[queueHead];
	if(!queueIsEmpty()){
	    arrayQueue[queueHead] = "";
		if(queueHead == queueSize - 1){
			queueHead = 0;
		}else{
			queueHead++;
		}
		cout << "H: " << queueHead << endl;
		cout << "T: " << queueTail << endl;
		cout << "word: " << tmp << endl;
		queueCount--;
	}else{
		cout << "Queue is empty" << endl;
	}

}



// Print all of the elements in the queue in the specified format from Appendix A. If
//the queue is empty print “Empty”.
//WORKS
void Queue::printQueue(){
	if(!queueIsEmpty()){
		int j = queueHead;
		for(int i = 0; i < queueSize; i++){
			if(arrayQueue[j] != ""){
				cout << j << ": " << arrayQueue[j] << endl;
				j = (j + 1)%(queueSize);
			}
		}
	}else{
		cout << "Empty" << endl;
	}

}

//WORDS IS THE SENTENCE THAT IS PASSED TO THE FUNCTION
//WORKS!!!!
void Queue::enqueueSentence(std::string words){
	string ss;
	int leng = words.length();
	char var;
	for(int i = 0; i < leng; i++){
		var = words[i];
		if(var != ' '){
			ss += var;
		}else{
			enqueue(ss);
			ss = "";
		}
	}
	enqueue(ss);	
}



// Returns true of false whether or not the queue is full.
//WORKS
bool Queue::queueIsFull(){
	if(queueCount == queueSize){
		return true;
	}else{
		return false;
	}
}

// Returns true or false whether or not the queue is empty.
bool Queue::queueIsEmpty(){
	if(queueCount == 0)
		return true;
	return false;
}