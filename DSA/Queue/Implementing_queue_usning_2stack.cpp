#include <bits/stdc++.h>
using namespace std;
class StackQueue
{
public:
    stack<int> s1; // Stack to hold the elements for enqueue operation
    stack<int> s2; // Stack to temporarily hold elements during enqueue

    // Method to add an element to the queue
    void enqueue(int data)
    {
        // Move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top()); // Push the top element of s1 to s2
            s1.pop();          // Remove the top element from s1
        }
        // Push the new element onto s1
        s1.push(data);
        // Move all elements back from s2 to s1
        while (!s2.empty())
        {
            s1.push(s2.top()); // Push the top element of s2 back to s1
            s2.pop();          // Remove the top element from s2
        }
    }

    // Method to remove and return the front element of the queue
    int dequeue()
    {
        // Check if the queue is empty
        if (s1.empty())
        {
            cout << "Queue is empty" << endl; // Print error message
            return -1;                        // Return a sentinel value
        }
        int popped = s1.top(); // Get the top element (front of the queue)
        s1.pop();              // Remove the top element from s1
        return popped;         // Return the popped element
    }

    // Method to get the front element of the queue without removing it
    int top()
    {
        // Check if the queue is empty
        if (s1.empty())
        {
            cout << "Queue is empty" << endl; // Print error message
            return -1;                        // Return a sentinel value
        }
        return s1.top(); // Return the top element (front of the queue)
    }

    // Method to get the size of the queue
    int size()
    {
        return s1.size(); // Return the number of elements in the queue
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