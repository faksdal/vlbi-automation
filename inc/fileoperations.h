/*
 * FileOperations.h
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 */

#ifndef INC_FILEOPERATIONS_H_
#define INC_FILEOPERATIONS_H_

#include <string>
#include <fstream>
#include <iostream>

using namespace std;



class fileoperations {

private:
	unsigned long	inputFileSize = 0L;

	ifstream	inputFile;
	ofstream	outputFile;


	string	readHmtlTag(string _tag);
	string	skipInitialWhitespace(string _stringToSkip);

protected:

public:
	fileoperations(char* _inputFileName, char* _outputFileName);
	virtual ~fileoperations();


	void			readFile(void);
	unsigned long	find(unsigned long _startPosition, string _searchString);

};



#endif /* INC_FILEOPERATIONS_H_ */
