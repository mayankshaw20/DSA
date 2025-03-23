#include <bits/stdc++.h>
using namespace std;

class StackQueue
{
public:
    stack<int> s1; // Stack to hold the elements for enqueue operation
    stack<int> s2; // Stack to hold the elements for dequeue operation

    // Method to add an element to the queue
    void enqueue(int data)
    {
        cout << "Element enqueued ::" << data << endl; // Print the enqueued element
        s1.push(data);                                 // Push the new element onto stack s1
    }

    // Method to remove and return the front element of the queue
    int dequeue()
    {
        // Check if the second stack (s2) is empty
        if (s2.empty())
        {
            // Transfer all elements from s1 to s2 to reverse their order
            while (!s1.empty())
            {
                s2.push(s1.top()); // Push the top element of s1 onto s2
                s1.pop();          // Remove the top element from s1
            }
        }

        // If s2 is still empty, the queue is empty
        if (s2.empty())
        {
            cout << "Queue is empty" << endl; // Print error message
            return -1;                        // Return a sentinel value indicating the queue is empty
        }

        int n = s2.top(); // Get the top element from s2 (the front of the queue)
        s2.pop();         // Remove the top element from s2
        return n;         // Return the popped element
    }

    // Method to get the front element of the queue without removing it
    int top()
    {
        // Check if the second stack (s2) is empty
        if (s2.empty())
        {
            // Transfer all elements from s1 to s2 to reverse their order
            while (!s1.empty())
            {
                s2.push(s1.top()); // Push the top element of s1 onto s2
                s1.pop();          // Remove the top element from s1
            }
        }

        // If s2 is still empty, the queue is empty
        if (s2.empty())
        {
            cout << "Queue is empty" << endl; // Print error message
            return -1;                        // Return a sentinel value indicating the queue is empty
        }

        return s2.top(); // Return the top element from s2 (the front of the queue) without removing it
    }

    // Method to get the size of the queue
    int size()
    {
        return s1.size() + s2.size(); // Return the total number of elements in the queue (from both stacks)
    }
};

int main()
{
    StackQueue q;  // Create a new queue
    q.enqueue(10); // Enqueue 10
    q.enqueue(20); // Enqueue 20
    q.enqueue(30); // Enqueue 30
    q.enqueue(40); // Enqueue 40

    cout << q.dequeue() << endl; // Should print 10 (first element)
    cout << q.dequeue() << endl; // Should print 20 (second element)
    cout << q.dequeue() << endl; // Should print 30 (third element)
    cout << q.dequeue() << endl; // Should print 40 (fourth element)

    // Attempting to dequeue from an empty queue
    cout << q.dequeue() << endl; // Should print "Queue is empty" and return -1

    cout << "The top of the queue is " << q.top() << endl;   // Should print "Queue is empty" and return -1
    cout << "The size of the queue is " << q.size() << endl; // Should print 0

    return 0; // End of the program
}