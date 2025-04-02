#include <bits/stdc++.h> // Include standard libraries
using namespace std;

// Function to perform bubble sort on an array
void bubble_sort(int arr[], int n) {
    // Outer loop to control the number of passes
    for (int i = n - 1; i >= 0; i--) {
        int didSwap = 0; // Flag to check if any swap occurred in this pass
        // Inner loop to compare adjacent elements
        for (int j = 0; j <= i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j + 1]; // Store the next element in a temporary variable
                arr[j + 1] = arr[j];   // Move the current element to the right
                arr[j] = temp;         // Place the next element in the current position
                didSwap = 1;           // Set the flag to indicate a swap occurred
            }
        }
        // If no swaps occurred, the array is already sorted, so we can break out of the loop
        if (didSwap == 0) {
            break;
        }
    }

    // Print the sorted array
    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print each element of the sorted array
    }
    cout << "\n"; // Print a newline for better formatting
}

int main() {
    // Initialize an array to be sorted
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Print the array before sorting
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print each element of the array
    }
    cout << endl; // Print a newline for better formatting

    // Call the bubble sort function to sort the array
    bubble_sort(arr, n);
    return 0; // End of the program
}