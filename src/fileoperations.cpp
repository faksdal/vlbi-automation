/*
 * FileOperations.cpp
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 */

#include "../inc/fileoperations.h"



//
//	The constructor is in charge of opening both input- and output-files,
//	getting the filesize and position the file pointer at the beginning
//	of the input file.
//
//	It also gives an error if opening the files don't work out
//
fileoperations::fileoperations(char* _inputFileName, char* _outputFileName)
{
	inputFile.open(_inputFileName, ios::ate);
	if(!inputFile.is_open()){
		// error opening file
		cout << "Error opening input file: " << _inputFileName << ". Exiting..." << endl;
		exit(-1);
	}
	else{
		inputFileSize = inputFile.tellg();

		//
		// After getting the filesize, set file pointer at beginning of file.
		//
		inputFile.seekg(0, inputFile.beg);
	}

	outputFile.open(_outputFileName);
	if(!outputFile.is_open()){
		// error opening file
		cout << "Error opening output file: " << _outputFileName << ". Exiting..." << endl;
		exit(-1);
	}
}



//
//	The destructor is in charge of closing the files upon exit
//
fileoperations::~fileoperations()
{
	//
	// Close files upon exiting
	//
	inputFile.close();
	outputFile.close();
}
