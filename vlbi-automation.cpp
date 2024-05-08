/******************************************************************************
 *
 * vlbi-automation.cpp; Created by Jon Leithe based on https://www.geeksforgeeks.org/html-parser-in-c-cpp/
 * Date: 3/5-2024
 *
 * 
******************************************************************************/
  

#include <iostream>
//#include <stdio.h> 
//#include <string.h>
//#include <stdbool.h>


#include "inc/fileoperations.h"

using namespace std;


//
// Driver code
//
int main(int argc, char **argv)
{
	//string			searchString;
	//unsigned long	filePointer = 0L;

	if(argc < 3){
		cout << "Specify input and output file!" << endl;
		cout << "Usage: " << argv[0] << " <input-file.html> <output-file>" << endl;
		exit(-1);
	} // if(argc < 3)
  
	//
	//	create an object of type fileoperations, calling the constructor
	//	of the class
	//
	fileoperations fo(argv[1], argv[2]);
	fo.printInputFileName(true);
	fo.printOutputFileName(true);


	/*
	if(argc == 4)
		searchString = argv[3];
	else
		searchString = "<title>";
	*/

	/*
	cout << "main(): File pointer before fo.find(): " << filePointer << endl;
	filePointer = fo.find(0, searchString);
	cout << "main(): File pointer after fo.find(): " << filePointer << endl;

	cout << endl << "main(): Read from file at position " << filePointer << ": " << fo.fread(filePointer, 16) << endl;
	*/

    return 0; 
}

