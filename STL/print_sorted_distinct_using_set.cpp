// Print sorted distinct elements
// Need to compile with -std=c++11 setting

#include <iostream> 
#include <set>
//#include <bits/stdc++.h>
using namespace std; 

void printSorted(int arr[], int size) 
{ 
	// Create a set using array elements 
	set<int> s(arr, arr + size); 

	// Print contents of the set. 
	for (auto x : s) 
		cout << x << " ";
	cout << endl; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 3, 2, 2, 1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printSorted(arr, n); 
	return 0; 
} 

