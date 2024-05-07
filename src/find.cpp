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
#include <sstream>

#include "../inc/fileoperations.h"



//
//	find() searches for _searchString, returning the position in the file where the string starts
//
unsigned long fileoperations::find(unsigned long _startPosition, string _searchString)
{
	string			inputString;
	unsigned long	filePosition = 0L, position = 0L, stringPosition= 0L;


	if(!inputFile.is_open()){
		cout << "Error: inputfile not open, exiting" << endl;
		exit(-1);
	}


	//position = inputFile.tellg();
	//cout << "Current fp-pos: " << position << endl;
	while(getline(inputFile, inputString)){
		filePosition = inputFile.tellg();

		//
		//	If this is true, we've got a match
		//
		if((stringPosition = inputString.find(_searchString)) != string::npos){
			cout << "    Current fp-pos: " << (filePosition) << endl;
			cout << "Current string-pos: " << (stringPosition) << endl;
			cout << "              Line: " << inputString << endl;
			cout << "  Character at pos: " << inputString[stringPosition] << endl;
			cout << "InputString length: " << inputString.length() << endl;
			position = filePosition - (inputString.length() - 1) + stringPosition;

			cout << endl << "Position of searchstring inside file: " << position << endl;

			inputFile.seekg(position-1);
			char c = inputFile.get();
			cout << endl << "Character read from position: " << c << endl;

		}
		/*
		std::istringstream iss(line);
		int a, b;
		if (!(iss >> a >> b)) { break; } // error
		*/

		// process pair (a,b)
	}

	return position;
}
