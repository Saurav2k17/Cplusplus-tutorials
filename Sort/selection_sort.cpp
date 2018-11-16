/*

Selection sort

There are many ways to sort an array. Selection sort is probably the easiest sort to understand, which makes it a good candidate for teaching even though it is one of the slower sorts.

Selection sort performs the following steps to sort an array from smallest to largest:
1) Starting at array index 0, search the entire array to find the smallest value
2) Swap the smallest value found in the array with the value at index 0
3) Repeat steps 1 & 2 starting from the next index

In other words, we’re going to find the smallest element in the array, and swap it into the first position. Then we’re going to find the next smallest element, and swap it into the second position. This process will be repeated until we run out of elements.

Note that the last comparison will always be with itself (which is redundant), so we can actually stop 1 element before the end of the array.

*/


/*
#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
 
int main()
{
	const int length = 5;
	int array[length] = { 30, 50, 20, 10, 40 };
 
	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we’ve encountered this iteration
		// Start by assuming the smallest element is the first element of this iteration
		int smallestIndex = startIndex;
 
		// Then look for a smaller element in the rest of the array
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// then keep track of it
				smallestIndex = currentIndex;
		}
 
		// smallestIndex is now the smallest element in the remaining array
                // swap our start element with our smallest element (this sorts it into the correct place)
		std::swap(array[startIndex], array[smallestIndex]);
	}
 
	// Now that the whole array is sorted, print our sorted array as proof it works
	for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';
 	std::cout << std::endl;
	return 0;
}

*/

/*

Because sorting arrays is so common, the C++ standard library includes a sorting function named std::sort. std::sort lives in the <algorithm> header, and can be invoked on an array like so:


#include <algorithm> // for std::sort
#include <iostream>
 
int main()
{
	const int length = 5;
	int array[length] = { 30, 50, 20, 10, 40 };
 
	std::sort(array, array+length);
 
	for (int i=0; i < length; ++i)
		std::cout << array[i] << ' ';
 
	return 0;
}



*/








/*

Write a program that:
* Asks the user how many names they wish to enter.
* Asks the user to enter each name.
* Calls a function to sort the names (use selection sort code)
* Prints the sorted list of names.

Hint: Use a dynamic array of std::string to hold the names.
Hint: std::string supports comparing strings via the comparison operators < and >

*/




#include <iostream>
#include <string>
#include <utility> 
/* for std::swap, if you're not C++11 compatible, #include <algorithm> instead of #include <utility>*/
 
void sortArray(std::string *array, int length)
{
	// Step through each element of the array
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we've encountered so far.
		int smallestIndex = startIndex;
 
		// Look for smallest element remaining in the array (starting at startIndex+1)
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// If the current element is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// This is the new smallest number for this iteration
				smallestIndex = currentIndex;
		}
 
		// Swap our start element with our smallest element
		std::swap(array[startIndex], array[smallestIndex]);
	}
}
 
int main()
{
	std::cout << "How many names would you like to enter? ";
	int length;
	std::cin >> length;
 
	// Allocate an array to hold the names
	std::string *names = new std::string[length];
 
	// Ask user to enter all the names
	for (int i = 0; i < length; ++i)
	{
		std::cout << "Enter name #" << i + 1 << ": ";
		std::cin >> names[i];
	}
 
	// Sort the array
	sortArray(names, length);
 
	std::cout << "\nHere is your sorted list:\n";
	// Print the sorted array
	for (int i = 0; i < length; ++i)
		std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
 
	delete[] names; // don't forget to use array delete
	// we don't need to set names to nullptr/0 here because it's going to go out of scope immediately after this anyway
 
	return 0;
}


