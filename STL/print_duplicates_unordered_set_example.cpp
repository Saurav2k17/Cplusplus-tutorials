// Find duplicates from an array using unordered_set
// unordered_set is implemented using hash table where keys are hashed into indices of this hash table
// so it is not possible to maintain an order. All operation on unordered_set takes constant time O(1) 
// on an average which can go up to linear time in worst case which depends on the internally used hash function
// but practically they perform very well and generally provide constant time lookup operation.
// The unordered_set can contain key of any type – predefined or user-defined data structure but 
// when we define key of type user defined type, we need to specify our comparison function according to which keys will be compared.
// Need to use -std=c++11

#include <iostream>
#include <unordered_set> 
//#include <iterator> 
//#include <bits/stdc++.h>
using namespace std; 

// Print duplicates in arr[0..n-1] using unordered_set 
void printDuplicates(int arr[], int n) 
{ 
	// declaring unordered sets for checking and storing duplicates 
	unordered_set<int> intSet; 
	unordered_set<int> duplicate; 

	// looping through array elements 
	for (int i = 0; i < n; i++) 
	{ 
		// if element is not there then insert that here
		if (intSet.find(arr[i]) == intSet.end()) 
			intSet.insert(arr[i]); 

		// if element is already there then insert into duplicate set 
		else
			duplicate.insert(arr[i]); 
	} 

	// printing the result 
	std::cout << "Duplicate items are : "; 
	unordered_set<int> :: iterator itr; 

	// iterator itr loops from begin() till end() 
	for (itr = duplicate.begin(); itr != duplicate.end(); itr++) 
		std::cout << *itr << " "; 

	std::cout << std::endl;
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5}; 
	int n = sizeof(arr) / sizeof(int); 

	printDuplicates(arr, n); 
	return 0; 
} 

