#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q; // Queue to hold stack elements
public: 

    // Method to push an element onto the stack
    void Push(int x) { // O(n) since we are making the push operation costly
        int n = q.size(); // Get the current size of the queue
        q.push(x); // Push the new element onto the queue
        // Move all elements in the queue to the back to maintain stack order
        for (int i = 0; i < n; i++) {
            q.push(q.front()); // Move the front element to the back
            q.pop(); // Remove the front element
        }
    }

    // Method to pop the top element from the stack
    int Pop() {
        // Check if the stack is empty
        if (q.empty()) {
            cout << "Queue is Empty...."; // Print error message
            return -1; // Return a sentinel value
        }
        int popped = q.front(); // Get the front element (top of the stack)
        q.pop(); // Remove the top element from the stack
        return popped; // Return the popped element
    }

    // Method to get the top element of the stack without removing it
    int stacktop() {
        // Check if the stack is empty
        if (q.empty()) {
            cout << "Queue is Empty...."; // Print error message
            return -1; // Return a sentinel value
        }
        return q.front(); // Return the front element (top of the stack)
    }

    // Method to get the size of the stack
    int stacksize() {
        return q.size(); // Return the number of elements in the stack
    }
};

int main() {
    Stack s; // Create a new stack
    s.Push(3); // Push 3 onto the stack
    s.Push(2); // Push 2 onto the stack
    s.Push(4); // Push 4 onto the stack
    s.Push(1); // Push 1 onto the stack

    // Display the top element of the stack
    cout << "Top of the stack: " << s.stacktop() << endl;

    // Display the size of the stack before removing any elements
    cout << "Size of the stack before removing element: " << s.stacksize() << endl;

    // Pop elements from the stack and display them
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;

    // Display the top element after removing all elements
    cout << "Top of the stack after removing element: " << s.stacktop() << endl;

    // Display the size of the stack after removing all elements
    cout << "Size of the stack after removing element: " << s.stacksize() << endl;

    return 0; // End of the program
}