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



class FileOperations {

private:
	unsigned long	inputFileSize = 0L;

	ifstream	inputFile;
	ofstream	outputFile;


	string	readHmtlTag(string _tag);

protected:

public:
	FileOperations(char* _inputFileName, char* _outputFileName);
	virtual ~FileOperations();


	void	readFile(void);

};



#endif /* INC_FILEOPERATIONS_H_ */
