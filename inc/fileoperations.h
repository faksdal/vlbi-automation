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
	unsigned long	currentInputFilePos = 0L;
	unsigned long	currentOutputFilePos = 0L;

	string		inputFileName, outputFileName;

	ifstream	inputFile;
	ofstream	outputFile;


	string	readHmtlTag(string _tag);
	string	skipInitialWhitespace(string _stringToSkip);
	void	updateFilepointerPositions(void);

protected:

public:
	fileoperations(char* _inputFileName, char* _outputFileName);
	virtual ~fileoperations();

	unsigned long	getInputFileSize(void)			{ return inputFileSize;			}
	unsigned long	getCurrentInputFilePos(void)	{ return currentInputFilePos;	}
	unsigned long	getCurrentOutputFilePos(void)	{ return currentOutputFilePos;	}

	string printOutputFileName(bool _printToScreen);
	string printInputFileName(bool _printToScreen);

	void			readFile(void);
	unsigned long	find(unsigned long _startPosition, string _searchString);
	string			fread(unsigned long _startPosition, unsigned long _nbytes);

};



#endif /* INC_FILEOPERATIONS_H_ */
