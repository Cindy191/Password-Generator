#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;


int main(){
	ifstream inFS;
	string object;
	string random_object;
	vector<string> short_object_list;
	vector<string> medium_object_list;
	vector<string> long_object_list;
	bool valid = false;
	string length;
	int three_number;
	int lower = 100;
	int upper = 999;
	int i = 0;

	inFS.open("List_of_Objects.txt");
	if(!inFS.is_open()) {
		return 1;
	}


	//Creating my object_list vector
	while(!inFS.eof()){ 
		inFS >> object;
		//cout << object << endl;
			if(object.size() <= 3){
				short_object_list.push_back(object);
			}
			else if(object.size() <= 6) {
				medium_object_list.push_back(object);
			}
			else {
				long_object_list.push_back(object);
			}
		++i;
	}

	//ASK USER IF THEY WANT A SHORT, MEDIUM, OR LONG PASSWORD
	cout << "Determine your desired length of your generated password. Type 's' for short, 'm' for medium, 'l' for long." << endl;
	cin >> length;

	if(((length.at(0) == 's' || length.at(0) == 'm' || length.at(0) == 'l')) && (length.size() == 1)){
		valid = true;
	}
	else {
		while(valid == false) {
			cout << "Invalid input, please enter 's' for short, 'm' for medium, 'l' for long-lengthed password:" << endl;
			cin >> length;
				if((length.at(0) == 's' || length.at(0) == 'm' || length.at(0) == 'l') && (length.size() == 1)) {
					valid = true;
				}
			}
		}

	//Selecting a random word from object_list
	if(length == "s"){
		srand(time(NULL));
		random_object = short_object_list.at(rand()%short_object_list.size());
	}

	if(length == "m"){
		srand(time(NULL));
		random_object = medium_object_list.at(rand()%medium_object_list.size());
	}

	if(length == "l"){
		srand(time(NULL));
		random_object = long_object_list.at(rand()%long_object_list.size());
	}

	
	//Create 3 numbers and print the chosen object and numbers together
	three_number = rand()%(upper - lower+1) + lower; // this logic means it can spit out a number between upper(1000) and lower(100) - INCLUSIVE
	
	//Selecting a random special character
	char character;;
	vector<char> char_list = {'@', '#', '$', '%', '^', '&', '*'};
	character = char_list.at(rand()%7);

	//Combining object, number, and special character to generate Password
	cout << "Password: " << random_object << three_number << character << endl;


}