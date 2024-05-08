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
//	find() searches for _searchString, starting at _startPosition, returning
//	the position in the file where the string starts.
//	find() also updates the file pointer positions
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

	if(inputFile.is_open())
		cout << "find(): File is open" << endl;

	inputFile.seekg(_startPosition, ios::beg);
	filePosition = inputFile.tellg();
	cout << "find(): filePosition: " << filePosition << endl;

	//
	//	As long as we have input from the file, we keep reading
	//
	while(getline(inputFile, inputString)){
		inputFile.eof() ? cout << "eof flag set" << endl : cout << "eof flag not set" << endl;
		if(inputFile.eof())
			break;

		if((filePosition = inputFile.tellg()) >= inputFileSize){
			//	we've reached end-of-file and should act accordingly
			cout << "End-of-file reached. FP reset to beginning of file!" << endl;
			cout << "Current file pointer position: " << filePosition << ", compared to filesize: " << inputFileSize << endl;
			inputFile.seekg(0, ios::beg);
			filePosition = inputFile.tellg();
			break;
		}
		//cout << "find(): filePosition: " << filePosition << endl;


		//
		//	Delete any initial whitespace in the string
		//
		inputString = skipInitialWhitespace(inputString);


		//
		//	If this is true, we've got a match between _searchString and a
		//	substring in the read line
		//
		if((stringPosition = inputString.find(_searchString)) != string::npos){
			//
			//	Calculate file position for the start of the _searchString...
			//
			cout << "find(): filePosition: " << filePosition << endl;
			/*
			position = filePosition - inputString.length() - 1;
			cout << "            position: " << position << endl;
			cout << "        filePosition: " << filePosition << endl;
			cout << "inputString.length(): " << inputString.length() << endl;
			*/
			position = filePosition - inputString.length() - 1;

			/*	This section is for debug purposes

			//
			//	Seek to the current file position, read and print the next
			//	thirteen characters... Just to see we know where we're at
			//
			char c;
			inputFile.seekg(position);
			cout << endl << "Next thirteen character from file at position " << position << " is: ";
			for(int i = 0; i < 13; i++){
				c = inputFile.get();
				cout << c;
			}

			cout << endl << "Line: " << inputString << endl;
			*/
			break;
		}
		//cout << "find(): Before updateFilepointerPositions()" << endl;
		updateFilepointerPositions();
		//cout << "find(): After updateFilepointerPositions()" << endl;
	}
	return(position);
}
