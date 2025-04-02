#include <bits/stdc++.h> // Include standard libraries for C++
using namespace std; // Use the standard namespace

// Function to merge two halves of an array
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // Create a temporary array to hold merged elements
    int left = low;      // Starting index of the left half of arr
    int right = mid + 1; // Starting index of the right half of arr

    // Merging elements into the temporary array in sorted order
    while (left <= mid && right <= high) // While there are elements in both halves
    {
        if (arr[left] <= arr[right]) // If the left element is less than or equal to the right element
        {
            temp.push_back(arr[left]); // Add the left element to temp
            left++; // Move to the next element in the left half
        }
        else // If the right element is less than the left element
        {
            temp.push_back(arr[right]); // Add the right element to temp
            right++; // Move to the next element in the right half
        }
    }

    // If there are remaining elements in the left half
    while (left <= mid) // While there are still elements in the left half
    {
        temp.push_back(arr[left]); // Add the remaining left elements to temp
        left++;// Move to the next element in the left half
    }

    // If there are remaining elements in the right half
    while (right <= high) // While there are still elements in the right half
    {
        temp.push_back(arr[right]); // Add the remaining right elements to temp
        right++; // Move to the next element in the right half
    }

    // Copy the sorted elements from the temporary array back to the original array
    for (int i = low; i <= high; i++) // Iterate over the range from low to high
    {
        arr[i] = temp[i - low]; // Copy elements from temp back to arr
    }
}

// Function to perform merge sort on the array
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high) // Base case: if the subarray has one or no elements
        return; // Exit the function

    int mid = (low + high) / 2; // Calculate the midpoint of the current subarray
    mergeSort(arr, low, mid);      // Recursively sort the left half
    mergeSort(arr, mid + 1, high); // Recursively sort the right half
    merge(arr, low, mid, high);    // Merge the two sorted halves
    
}

// Main function
int main()
{
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}; // Initialize the array to be sorted
    int n = 7; // Size of the array

    cout << "Before Sorting Array: " << endl; // Print a message before sorting
    for (int i = 0; i < n; i++) // Loop through the array
    {
        cout << arr[i] << " "; // Print each element of the array
    }
    cout << endl; // Print a newline

    mergeSort(arr, 0, n - 1); // Call mergeSort to sort the array

    cout << "After Sorting Array: " << endl; // Print a message after sorting
    for (int i = 0; i < n; i++) // Loop through the sorted array
    {
        cout << arr[i] << " "; // Print each element of the sorted array
    }
    cout << endl; // Print a newline

    return 0; // Return 0 to indicate successful execution
}
//time complexity o(nlogn)
//space complexity o(n) bazox of temp array