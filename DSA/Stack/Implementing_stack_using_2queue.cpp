// #follow the three steps
// given below::
// 1>COpy the queue1 element to queue2 and pop out the element from queue1
// 2> Push the element to queue1
// 3> Copy the queue2 element to qeueu1 and pop out the element form queue2
// later inthis code you can add runtime error and
#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    queue<int> q1; // First queue to hold stack elements
    queue<int> q2; // Second queue used for transferring elements

    // Method to push an element onto the stack
    void Push(int data) {
        // Step 1: Copy elements from q1 to q2
        int n = q1.size();
        for (int i = 0; i < n; i++) { //also can use while(!q1.empty)
            q2.push(q1.front()); // Move front element of q1 to q2
            q1.pop(); // Remove the front element from q1
        }
        
        // Step 2: Push the new element onto q1
        q1.push(data);
        
        // Step 3: Copy elements back from q2 to q1
        int n1 = q2.size();
        for (int i = 0; i < n1; i++) { //also can use while(!q2.empty)
            q1.push(q2.front()); // Move front element of q2 to q1
            q2.pop(); // Remove the front element from q2
        }
    }

    // Method to pop the top element from the stack
    int Pop() {
        // Check if the stack is empty
        if (q1.empty()) {
            cout << "Queue is Empty...."; // Print error message
            return -1; // Return a sentinel value
        }
        int n = q1.front(); // Get the front element (top of the stack)
        q1.pop(); // Remove the top element from the stack
        return n; // Return the popped element
    }

    // Method to get the top element of the stack without removing it
    int Top() {
        // Check if the stack is empty
        if (q1.empty()) {
            cout << "Queue is Empty...."; // Print error message
            return -1; // Return a sentinel value
        }
        return q1.front(); // Return the front element (top of the stack)
    }

    // Method to get the size of the stack
    int Size() {
        return q1.size(); // Return the number of elements in the stack
    }
};

int main() {
    Stack s; // Create a new stack
    s.Push(3); // Push 3 onto the stack
    s.Push(2); // Push 2 onto the stack
    s.Push(4); // Push 4 onto the stack
    s.Push(1); // Push 1 onto the stack

    // Display the top element of the stack
    cout << "Top of the stack: " << s.Top() << endl;

    // Pop elements from the stack and display them
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;

    // Display the size of the stack before removing another element
    cout << "Size of the stack before removing element: " << s.Size() << endl;

    // Pop another element and display it
    cout << "The deleted element is: " << s.Pop() << endl;

    // Display the top element after removing an element
    cout << "Top of the stack after removing element: " << s.Top() << endl;

    // Display the size of the stack after removing an element
    cout << "Size of the stack after removing element: " << s.Size() << endl;

    return 0; // End of the program
}