/******************************************************************************
 *
 * htmlparser.c; Created by Jon Leithe based on https://www.geeksforgeeks.org/html-parser-in-c-cpp/
 * Date: 3/5-2024
 *
 * First I edited this to accept an input file, instead of a buffer
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
	if(argc < 3){
		cout << "Specify input and output file!" << endl;
		cout << "Usage: " << argv[0] << " <input-file.html> <output-file>" << endl;
		exit(-1);
	} // if(argc < 3)
  
	fileoperations fo(argv[1], argv[2]);

	fo.find(0, "lang=");

    return 0; 
}

