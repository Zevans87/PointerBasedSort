/*Zachery Evans
02/16/2023
COSC-1137
Lab5*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//Global Variables

//Function Prototypes
int maxIndex(int[], int);

int main()
{
	//Variables, arrays, and vectors
	const int SIZE = 50, MIN = 10, MAX = 100;
	int maxValue = 0, temp = 0, arraySize = SIZE;
	int list[SIZE];
	vector <int> duplicates;
	int* iPtr = nullptr, * nextPtr = nullptr;
	ifstream infile;
	infile.open("SP23_1137_Lab4_input");

	if (infile)
		cout << "Yes";
	else cout << "no";

	//Random number generator
	unsigned seed = time(0);
	srand(seed);

	//Assigning pointer
	iPtr = list;

	//Populating the array called list
	for (int i = 0; i < SIZE; i++)
		list[i] = (rand() % (MAX - MIN + 1)) + MIN;

	//Reorder the list from smallest value to largest
	while (arraySize > 1)
	{
		maxValue = maxIndex(list, arraySize);
		iPtr = &list[maxValue];
		temp = *iPtr;
		*iPtr = list[arraySize - 1];
		list[arraySize - 1] = temp;
		arraySize--;
	}

	//Display sorted list
	for (int i = 0; i < SIZE; i++)
		cout << list[i] << " ";
	cout << endl;

	//Moving iPtr to beginning of the new sorted array called list
	iPtr = list;

	//Creating a vector called duplicates that will hold one copy of a duplicated number in the list array
	while (iPtr < &list[SIZE - 1])
	{
		nextPtr = iPtr + 1;
		if (*iPtr == *nextPtr)
		{
			duplicates.push_back(*iPtr);
		}
		while (*iPtr == *nextPtr && nextPtr <= &list[SIZE - 1])
			nextPtr++;
		iPtr = nextPtr;
	}

	//Checking to see if the vector is populated and will display its contents if populated
	if (duplicates.empty())
		cout << "There were no duplicates with this list." << endl;
	else
		for (int i = 0; i < duplicates.size(); i++)
			cout << duplicates[i] << " ";

	return 0;
}

//Function Definitions
int maxIndex(int array[], int size)
{
	int max = array[0], index = 0;
	for (int i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
			index = i;
		}
	}

	return index;
}