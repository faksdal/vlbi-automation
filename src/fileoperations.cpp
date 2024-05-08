/*
 * FileOperations.cpp
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 */
#include <string.h>
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
	//cout << "Constructor called" << endl;

	inputFileName	= _inputFileName;
	outputFileName	= _outputFileName;

	//cout << "Opening inputfile " << inputFileName << endl;
	inputFile.open(inputFileName, ios::ate);
	if(!inputFile.is_open()){
		// error opening file
		cout << "Error opening input file: " << inputFileName << ". Exiting..." << endl;
		exit(-1);
	}
	else{
		//cout << "Inputfile: " << inputFileName << " opened ok" << endl;
		inputFileSize = inputFile.tellg();

		//
		// After getting the filesize, set file pointer at beginning of file.
		//
		//cout << "Input file pointer currently at " << inputFile.tellg() << endl;
		inputFile.seekg(0, ios::beg);
		//cout << "Input file pointer reset at " << inputFile.tellg() << endl;
	}

	//cout << " Opening outputfile: " << outputFileName << endl;
	outputFile.open(outputFileName);
	if(!outputFile.is_open()){
		// error opening file
		cout << "Error opening output file: " << outputFileName << ". Exiting..." << endl;
		exit(-1);
	}
	else{
		//cout << "Outputfile: " << outputFileName << " opened ok" << endl;
	}

	//
	//	update current file pointer positions
	//
	updateFilepointerPositions();

	//cout << "Exit constructor" << endl;
}



//
//	The destructor is in charge of closing the files upon exit
//
fileoperations::~fileoperations()
{
	cout << "Destructor called" << endl;
	//
	// Close files upon exiting
	//
	inputFile.close();
	outputFile.close();
	cout << "Exit destructor" << endl;
}
