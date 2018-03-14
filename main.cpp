/*
 * Heap
 *
 * A program that creates a max heap from a series of numbers or a file name.
 * The heap will be able to be moved to the output and displayed visually when the tree is full.
 * The heap will be implemented as an array of nodes.
 *
 * class: C++, Galbraith
 * 
 * This code implements the top-down heapsort method from https://en.wikipedia.org/wiki/Heapsort
 * 
 * made by: Alex Young
 * last updated: 3/13/2018
 */

#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

void heapify(int a[], int count);
void siftUp(int a[], int start, int end);
void heapsort(int a[], int count);
void visualize(int a[], int count);

int main () {
	
	// this tree has all 100 numbers in it that will form the heap
	// the array is initialized to 0 and the first value is empty
	int tree[101] = { 0 };

	// user can choose to manually input or input with a file
	char entry[10];
	cout << "This program creates a max heap to sort a list of numbers from largest to smallest." << endl;
	cout << "Please choose to either enter numbers in manually [m] or with a file [f]." << endl;
	cin.get(entry, sizeof(entry));
	cin.get();

	// if the user types f or file then have them enter the name of the file
	if (strcmp(entry, "f") == 0 || strcmp(entry, "F") == 0 || strcmp(entry, "file") == 0 || strcmp(entry, "File") == 0) {
		char fileName[25];
		cout << "Please enter the name of the file you wish to sort: ";
		cin.get(fileName, sizeof(fileName));
		cin.get();
		// use ifstream to open the file
		ifstream inFile;
		
		inFile.open(fileName);

		// if there is a file then read in the values into the array
		if (inFile.is_open()) {
			cout << "Opening file..." << endl;
			int x;
			int i = 1;
			while (inFile >> x) {
				//cout << x << endl;
				tree[i] = x;
				i++;
			}
			
			tree[i] = 0;
		}
		
		// if there is not a file then say so and quit
		else if (!inFile) {
			cout << "Unable to open file " << fileName << endl;// << ".txt" << endl;
			return 0;
		}

		inFile.close();

	// otherwise if they dont enter 'f' or 'file' they are going manual
	} else {
		// have them enter a list of numbers
		cout << "Please enter a list of less than 100 numbers between 1 and 1000." << endl;
		cout << "When inputing your list, add a number at a time and press enter or space after each number." << endl;
		cout << "Type [QUIT] when your list is complete." << endl;

		// read in list into array
		int count = 1;
		while (count < 100) {
			cin >> tree[count];
			count++;
		}
	}
	
	// print and count the list the user provided
	int c = 0;
	
	cout << "[Your List]";
	for (int i = 1; tree[i] != 0; i++) {
		cout << "  " << tree[i];
		c++;
	}
	
	cout << endl << "[Count] " << c << endl << endl;
	
	// heapify the tree
	heapify(tree, c);
	
	// print out the heap
	cout << "[Heap]";
	for (int i = 1; tree[i] != 0; i++) {
		cout << "  " << tree[i];
	}
	cout << endl << endl;
	
	// print out the heap visually
	cout << "[Visual Representation]" << endl;
	visualize(tree, c);
	
	cout << endl;
	// sort and remove numbers from the heap
	heapsort(tree, c);
	cout << endl;
	// yay we are done
	return 0;
}

// this function creates a max heap in an array using the top-down method
void heapify(int a[], int count) {
	// end is the first node on the left
	int end = 2;
	
	while (end <= count) {
		siftUp(a, 1, end);
		// sift up for every child in the array
		end++;
		//cout << end << endl;
	}
	
	return;
}

// this function swaps a child with its parent if the parent is smaller
void siftUp(int a[], int start, int end) {
	int child = end;
	
	while (child > start) {
		int parent = child / 2;
		
		//cout << "parent " << parent << endl;
		int temp = 0;
		
		if (a[parent] < a[child]) {
			temp = a[parent];
			a[parent] = a[child];
			a[child] = temp;
			child = parent;
		} else {
			return;
		}	
	}
}

// this function sorts the heap in order from largest to smallest
void heapsort(int a[], int count) {
	int end = count;
	cout << "[Sorted]";
	
	// the first value is printed then removed, then the rest of the code is heapified again to find a new head
	while (end > 0) {
		cout << "  " << a[1];
		a[1] = a[end];
		a[end] = 0;
		end = end - 1;
		heapify(a, end);
	}
}

// this function will create a visual of my heap
void visualize(int a[], int count) {
	// outer loop loops through the lines and figures out how many entries you will print
	// inner loop prints out things for that line with logic to stop at end
	int lvl = 1;
	
	int current = 1;
	int num = 1;
	
	while (a[current] != 0) {
		cout << "[Level " << lvl << "] ";
		
		for (int i = 1; i <= num; i++) {
			
			// if the total number is less than the current index we stop
			if (current > count) {
				break;
			}
			
			cout << a[current] << "  ";
			current++;
		}
		
		num = num * 2;
		cout << endl;
		lvl++;
	}
	
}