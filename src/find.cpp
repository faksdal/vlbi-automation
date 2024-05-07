/*
 *	find.cpp
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 *
 */

//
// TODO -
//

#include <string>
//include <sstream>

#include "../inc/fileoperations.h"



//
//	find() searches for _searchString, returning the position in the file where the string starts
//
unsigned long fileoperations::find(unsigned long _startPosition, string _searchString)
{
	string			inputString;
	unsigned long	filePosition	= 0L;		// This starts with a 0
	unsigned long	position		= 0L;
	unsigned long	stringPosition	= 0L;		// This starts with a 0


	if(!inputFile.is_open()){
		cout << "Error: inputfile not open, exiting with exit(-1)!" << endl;
		exit(-1);
	}


	//
	//	As long as we have input from the file, we keep reading
	//
	while(getline(inputFile, inputString)){
		filePosition = inputFile.tellg();

		//cout << inputString << endl << endl;
		inputString = skipInitialWhitespace(inputString);
		//cout << inputString << endl << endl;

		//
		//	If this is true, we've got a match between _searchString and a
		//	substring in the read line
		//
		if((stringPosition = inputString.find(_searchString)) != string::npos){
			cout << "    Current filepointer position: " << (filePosition) << endl;
			cout << "             Line read from file: " << inputString << endl;
			cout << "       Length of the string read: " << inputString.length() << endl;
			cout << "Position of searchstring in line: " << (stringPosition) << endl;

			//
			//	Calculate file position for the start of the _searchString...
			//
			position = filePosition - inputString.length() - 1;

			//
			//	Seek to the current file position, read and print the next
			//	three characters
			//

			char c;
			inputFile.seekg(position);
			cout << endl << "Next thirteen character from file at position " << position << " is: ";
			for(int i = 0; i < 13; i++){
				c = inputFile.get();
				cout << c;
			}

			cout << endl;
		}
	}

	return position;
}
