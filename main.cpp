/*
 * main.cpp
 *
 *  Created on: Jan 22, 2021
 *      Author: maelstrom
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(){
	int i = 0;									//We'll use this as the index number to reference array elements
	int j = 0;									//We'll use this to count the number of elements in the array.
												//This is determined by the number of lines in the file we'll read in.
	int k = 0;									//We'll use this as the index number to change. The user will be prompted
												//to enter the element number to change
	string t = "";								//The string value to be entered by the user. This is the data the user
												//will enter when setting a new value to s[k]

	string r;									//We'll use this to temporarily hold the line currently being read by getline()
								//The full array of strings. We'll hold the entire contents of input.txt in this array.

	//I realize there's probably a more efficient way to do this, but I'm still learning and I want to see everything
	//that's going on. So I'm going to use two ifstreams, one to get the number of lines and one to read the individual
	//lines into the array.

	ifstream infile;							//Make an object called "infile" based on the ifstream() class
	infile.open("input.txt");					//Call the method "open" from our infile object, and point it to input.txt
	if(infile.fail())							//If we can't open the file, send a failure message"
	{ cout << "The file did not open" << endl;
	}
	else{										//If we can open the file, do stuff
		while(getline(infile, r))
		{
			j++;								//Using this to count the number of lines in the array. When debugging, the free() invalid pointer error happens here
		}
		infile.close();							//Close the file
		infile.clear();							//Flush the buffer
	}

	cout << j << endl;							//cout the number of lines in the file
	string s[j];
	ifstream infile2;							//Make an object called "infile" based on the ifstream() class
	infile2.open("input.txt");					//Call the method "open" from our infile object, and point it to input.txt
	if(infile2.fail())							//If we can't open the file, send a failure message"
	{ cout << "The file did not open" << endl;
	}
	else{										//If we can open the file, do stuff
		r = "";
		for(int y = 0; y < (j+1); y++)
		{
			getline(infile2, r);				//Get the next line of input.txt, assign it to the string named r.
			cout << r << endl;					//cout the current value of r. This will be the string of text on whichever line of the text file we're working with.
			s[y] = r;   						//!!! (Problem seems to be here.) Assign the current line, r, to the current array element we're working with. Essentially line # in the file
			cout << s[y] << endl;				//cout the current array element we're working with. Just so we can see what's going on.
		}
		infile2.close();							//Close the file
		infile2.clear();							//Flush the buffer
	}
	//Commenting out the rest. The free(): invalid pointer error occurs even if the below code is commented out

	/*	cout << sizeof(s[1]);						//Size of an individual element, should be 32 bytes
		cout << "Number of elements is: " << j << endl;
		cout << "Enter a line number to change: " << endl;
		cin >> k ;
		cout << "Enter a new value for line number: " << k << endl;
		cin >> t;
		cout << "Setting value of line number " << k << " to " << t << endl;
		/*s[k] = t;
		for(int m = 0; m < (j+1) ; m++){
			cout << "File will now contain: " << s[m];
		}
		i = 2;
		cout << "S is: " << s[i];*/
	return 0;
}







