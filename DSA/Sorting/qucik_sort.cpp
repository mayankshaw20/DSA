
#include <bits/stdc++.h> // Include standard libraries
using namespace std;

// Function to partition the array around a pivot
int partition(vector<int> &arr, int low, int high) {
    // Choose the pivot as the first element of the current subarray
    int pivot = arr[low];
    int i = low; // Pointer for the next position to place a smaller element
    int j = high; // Pointer for the next position to place a larger element

    // Loop until the two pointers cross
    while (i < j) {
        // Move the left pointer to the right until we find an element greater than the pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        // Move the right pointer to the left until we find an element less than or equal to the pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }

        // If the left pointer is still less than the right pointer, swap the elements
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Place the pivot in its correct position
    swap(arr[low], arr[j]);
    // Return the index of the pivot
    return j;
}

// Recursive quicksort function
void qs(vector<int> &arr, int low, int high) {
    // Base case: if the subarray has one or no elements, it is already sorted
    if (low < high) {
        // Partition the array and get the pivot index
        int pIndex = partition(arr, low, high);
        // Recursively sort the left subarray
        qs(arr, low, pIndex - 1);
        // Recursively sort the right subarray
        qs(arr, pIndex + 1, high);
    }
}

// Function to initiate quicksort
vector<int> quickSort(vector<int> arr) {
    // Call the recursive quicksort function on the entire array
    qs(arr, 0, arr.size() - 1);
    // Return the sorted array
    return arr;
}

int main() {
    // Initialize an array to be sorted
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size(); // Get the size of the array

    // Print the array before sorting
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array using quicksort
    arr = quickSort(arr);

    // Print the array after sorting
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0; // End of the program
}