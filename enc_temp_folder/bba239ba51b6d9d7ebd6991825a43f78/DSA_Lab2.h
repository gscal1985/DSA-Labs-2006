#pragma once

// Only compile if LAB_2 is on
#if LAB_2

#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

// Checks to see if a number is a palindrome (reads the same forwards and backwards)
//		An example of a palindrome word would be "racecar"
//
// In: _num			The number to check
//
// Return: True, if the number is a palindrome number
inline bool IsPalindromeNumber(unsigned int _num) {
	string str_num = to_string(_num);

	// 4
	int j = strlen(str_num.c_str()) - 1;

	// 5
	for (int i = 0; i < j; i++, j--)
	{//I use a for loop to compare both sides of the converted unsigned integer GScallion
		if (str_num[i] != str_num[j])
		{
			// 6
			return false;
		}
	}

	return true;
}


class DSA_Lab2
{
	friend class TestSuite;

private:

	vector<unsigned int> mValues;		// contains all of the values
	vector<unsigned int> mPalindromes;	// contains just the numbers that are palindromes

public:

	// Fill out the vector with the contents of the binary file
	//		First four bytes of the file are the number of ints in the file
	//
	// In:	_input		Name of the file to open
	//
	// Note: Make sure the vector is empty and shrunk to 0 capacity before adding values
	void Fill(const char* _input) {
	
		ifstream numBinFileContents;
	    numBinFileContents.open("numbers.bin", ios_base::binary);

		struct numBinFileContentsHeader
		{
			int numBinNumTotal;
			int numBinNumGroupingAmount;
		};

		struct actualNumBinFileValues
		{
			vector<int> numBinNumbers;
		};


		numBinFileContentsHeader header;
		numBinFileContents.read((char*) &header, sizeof(numBinFileContents));

		//Creating Vectors for the total number of values inside the ".bin" file.
		int createdNumberOfVectors = header.numBinNumTotal / header.numBinNumGroupingAmount;
		vector<int>* entireNumBinFileValues = new vector<int>[createdNumberOfVectors];
		//Current Vector To next Vector Declaration.
		int presentVector = 0;
		int nextVectorUp = 0;
		int nextGroupUp = 0;




		//read the rest of the file
		for (int ii = 0; ii < header.numBinNumTotal; ++ii , ++nextGroupUp)
		{
			if (nextGroupUp == header.numBinNumGroupingAmount)
			{
				nextVectorUp++;
				nextGroupUp = 0;
			}
			numBinFileContents.read((char*)&presentVector, sizeof(int));
			entireNumBinFileValues[nextVectorUp].push_back(presentVector);


		}
		//Close the opened ".bin" file.
		numBinFileContents.close();

	
		for (int iii = 0; iii < createdNumberOfVectors; ++iii)
		{
			//Printing out the all the vectors in a single line
			for (int k = 0; iii < entireNumBinFileValues[k].size(); ++k)
			{
				cout << entireNumBinFileValues[iii][k] << ' ';
				cout << '\n';
			}
		}






		//Delete new instance of vectors from memory.
		delete[]  entireNumBinFileValues;
	}

	// Fill out the vector with the contents of an array
	//
	// In:	_arr			The array of values
	//		_size			The number of elements in the array
	//
	// Note: Make sure the vector is empty and shrunk to 0 capacity before adding values
	void Fill(const unsigned int* _arr, int _size) {
	
	}

	// Remove all elements from vector and decrease capacity to 0
	void Clear() {
		mValues.clear();
		mPalindromes.clear();
	}

	// Sort the vector 
	//
	// In:	_ascending		To sort in ascending order or not
	void Sort(bool _ascending) {
		


	}

	// Get an individual element from the mValues vector
	int operator[](int _index) {
	
	}

	// Determine if a value is present in the vector
	// 
	// In:	_val		The value to check for
	//
	// Return: True, if the value is present
	bool Contains(unsigned int _val) const {
	
	}

	// Move all palindrome numbers from mValues vector to mPalindromes vector
	//
	// Pseudocode:
	//		iterate through the main values vector
	//			if the value is a palindrome
	//				add it to the palindrome vector
	//				remove it from the values vector
	void MovePalindromes() {
	
	}
};




#endif