// QuickSort works on divide and conquer paradigm. The partition method is the heart of this algorithm
// We select the last element as pivot, find its correct position in the list through comparisons and return that position
// This position index partitions the list into 2 lists.
// The members to the left are less than or equal to the member which is present in the position index
// and the members to the right are greater than that
// We would subsequently call quicksort method on those two lists to further partition those two lists and we keep continuing.

#include <iostream> 
using namespace std;

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 


// This function takes last element as pivot, places the pivot element at its correct position in sorted array
// It places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot

int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) // we scan through the list until last but one element
	{ 
		// If current element is smaller than or equal to pivot 
		if (arr[j] <= pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); // this is needed as i needs to point to most recent element which is <= the pivot element
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); // returning the index of the element which got placed in its final position in the array that's going to be sorted
} 


/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */

void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		// pi is partitioning index and after partition method gets run, arr[pi] would be at its right place
		int pi = partition(arr, low, high); 

		// Separately sort the elements before the partition index and after the partition index
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 


/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 


// Driver program to test above functions 
int main() 
{ 
    int n, i;
	cout << "\nEnter the number of data element to be sorted: ";
	cin >> n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout << "Enter element "<<i+1<<": ";
		cin >> arr[i];
	}
 

	quickSort(arr, 0, n - 1); 

	cout << "\nSorted array is: ";
	printArray(arr, n); 
	return 0; 
} 

