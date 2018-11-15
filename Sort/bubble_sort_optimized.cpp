/*

Add two optimizations to the bubble sort algorithm:

Notice how with each iteration of bubble sort, the biggest number remaining gets bubbled to the end of the array. After the first iteration, the last array element is sorted. After the second iteration, the second to last array element is sorted too. And so on… With each iteration, we don’t need to recheck elements that we know are already sorted. Change your loop to not re-check elements that are already sorted.
If we go through an entire iteration without doing a swap, then we know the array must already be sorted. Implement a check to determine whether any swaps were made this iteration, and if not, terminate the loop early. If the loop was terminated early, print on which iteration the sort ended early.

*/

#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
 
int main()
{
    int array[] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    const int length = sizeof(array) / sizeof(array[0]);
 
    // Step through each element of the array except the last
    for (int iteration = 0; iteration < length-1; ++iteration)
    {
        // Account for the fact that the last element is already sorted with each subsequent iteration
        // so our array "ends" one element sooner
        int endOfArrayIndex(length - iteration);
 
        bool swapped(false); // Keep track of whether any elements were swapped this iteration
 
        // Search through all elements up to the end of the array - 1
        // The last element has no pair to compare against
        for (int currentIndex = 0; currentIndex < endOfArrayIndex - 1; ++currentIndex)
        {
            // If the current element is larger than the element after it
            if (array[currentIndex] > array[currentIndex + 1])
            {
                // Swap them
                std::swap(array[currentIndex], array[currentIndex + 1]);
                swapped = true;
            }
        }
 
        // If we haven't swapped any elements this iteration, we're done early
        if (!swapped)
        {
            // iteration is 0 based, but counting iterations is 1-based.  So add 1 here to adjust.
            std::cout << "Early termination on iteration: " << iteration+1 << '\n';
            break;
        }
    }
 
    // Now print our sorted array as proof it works
    for (int index = 0; index < length; ++index)
        std::cout << array[index] << ' ';
 	std::cout << std::endl;
    return 0;
}
