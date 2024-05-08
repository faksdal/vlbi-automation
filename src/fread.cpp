/*
 * fread.cpp
 *
 *  Created on: May 8, 2024
 *      Author: leijon
 */

//
// TODO - describe what we're calculating here...
//

#include <string.h>

#include "../inc/fileoperations.h"



//
//	fread() will read _nbytes number of bytes from the inputFile stream, and
//	return the read string. It also updates the file position pointers
//
string fileoperations::fread(unsigned long _startPosition, unsigned long _nbytes)
{
	unsigned long i	= 0;
	string	retVal	= "";

	char	readBuffer[_nbytes+1];


	cout << endl << "fread(): Seeking to file position " << _startPosition << " in inputfile " << inputFileName << endl;
	if(inputFile.is_open())
		cout << "fread(): File is open" << endl;
	//inputFile.seekg(_startPosition, inputFile.beg);
	inputFile.seekg(_startPosition, ios::beg);
	cout << endl << "fread(): File position at " << inputFile.tellg() << endl;

	for(i = 0; i < _nbytes; i++){
		readBuffer[i] = inputFile.get();

	}
	readBuffer[i] = '\0';
	retVal = readBuffer;

	cout << "fread(): retVal: " << retVal << ", length of retVal: " << retVal.length() << endl;

	updateFilepointerPositions();

	return(retVal);
}
