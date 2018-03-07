/*
 * Heap
 *
 * A program that creates a max heap from a series of numbers or a file name.
 * The heap will be able to be moved to the output and displayed visually when the tree is full.
 * The heap will be implemented as an array of nodes.
 *
 * class: C++, Galbraith
 *
 * made by: Alex Young
 * last updated: 3/7/2018
 */

#include <iostream>
#include <fstream>
//#include "node.h"

using namespace std;

int main () {

	int tree[120];
	
	char entry[10];
	cout << "This program creates a max heap to sort a list of numbers from largest to smallest." << endl;
	cout << "Please choose to either enter numbers in manually [m] or with a file [f]." << endl;
	cin.get(entry, sizeof(entry));
	cin.get();

	if (strcmp(entry, "f") == 0 || strcmp(entry, "F") == 0 || strcmp(entry, "file") == 0 || strcmp(entry, "File") == 0) {
		char fileName[25];
		cout << "Please enter the name of the file you wish to sort: ";
		cin.get(fileName, sizeof(fileName));
		cin.get();

		ifstream infile(fileName);

		if (!inFile) {
			cout << "Unable to open file " << fileName ".txt" << endl;
			return 0;
		}
		
		if (infile.is_open()) {
			infline.getline(tree, 120, 0);
		}
		
		inFile.close();

	} else {
		cout << "Please enter a list of less than 100 numbers between 1 and 1000." << endl;
		cout << "When inputing your list, add a number at a time and press enter after each number." << endl;
		cout << "Type [QUIT] when your list is complete." << endl;

		// read in list
	}






	return 0;
}
