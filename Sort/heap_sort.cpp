// Heap sort is a comparison based sorting technique based on Binary Heap data structure.
// Like merge sort but unlike insertion sort, heapsort’s running time is O(nlogn)
// Like insertion sort but unlike merge sort, heapsort sorts in place:
// only a constant number of array elements are stored outside the input array at any time.
// Not only is the heap data structure useful for heapsort, but it also makes an efficient priority queue.
// The (binary) heap data structure is an array object that we can view as a nearly complete binary tree.
// The tree is completely filled on all levels except possibly the lowest, which is filled from the left up to a point.

#include <iostream> 
using namespace std; 

// To max heapify a subtree rooted with node i which is an index in arr[] and n is the size of the heap 
void max_heapify(int arr[], int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2*i + 1; // left = 2*i + 1 (assuming the indexing starts at 0)
	int r = 2*i + 2; // right = 2*i + 2 

	// If left child is larger than root (l < n is checked to make sure that we are not referring to elements outside of array bounds)
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 

		// Recursively max heapify the affected sub-tree 
		max_heapify(arr, n, largest); 
	} 
} 

// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
	// Build heap (rearrange array), we start from non-leaf node with largest index and go all the way down to the first node 
	for (int i = n / 2 - 1; i >= 0; i--) // as the leaves are already heaps which range from n/2 to n, we don't touch those elements 
		max_heapify(arr, n, i); 

	// One by one extract an element from heap 
	for (int i=n-1; i>=0; i--) 
	{ 
		// Move current root to end 
		swap(arr[0], arr[i]); 

		// call max heapify on the reduced heap
		max_heapify(arr, i, 0); 
	} 
} 

/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 

// Driver program to test heap sort
int main() 
{ 
    int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
    heapSort(arr, n);
    printArray(arr, n);
 
    return 0;
} 

