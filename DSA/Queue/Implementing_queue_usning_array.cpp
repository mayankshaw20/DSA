#include <iostream>
using namespace std;

class Queue
{
    int front, rear; // Indices for the front and rear of the queue
    int *arr;        // Pointer to the array that holds the queue elements
    int maxsize;     // Maximum size of the queue
    int currsize;    // Current number of elements in the queue

public:
    Queue(int size) // Constructor to initialize the queue with a given size
    {
        arr = new int(size); // Allocate memory for the queue
        maxsize = size;      // Set the maximum size
        front = -1;         // Initialize front to -1 (indicating an empty queue)
        rear = -1;          // Initialize rear to -1 (indicating an empty queue)
        currsize = 0;       // Initialize current size to 0
    }

    ~Queue() // Destructor to free allocated memory
    {
        delete[] arr; // Free allocated memory
    }

    void enqueue(int x) // Function to add an element to the queue
    {
        if (currsize == maxsize) // Check if the queue is full
        {
            cout << "queue is full" << endl; // Print message if full
            return; // Exit the function
        }
        if (front == -1) // If the queue is empty
        {
            front = 0; // Set front to 0
        }
        cout << "Element enqueued  :: " << x << endl; // Print the enqueued element
        arr[(++rear) % maxsize] = x; // Add the element to the rear and wrap around if necessary
        currsize++; // Increment the current size of the queue
    }

    int dequeue() // Function to remove and return the front element of the queue
    {
        if (front == -1) // Check if the queue is empty
        {
            cout << "Queue Empty\nExiting..." << endl; // Print message if empty
            return 0; // Return 0 (could be improved with error handling)
        }
        int popped = arr[front]; // Store the front element to return it
        if (currsize == 1) // If this is the last element
        {
            front = -1; // Reset front to -1
            rear = -1; // Reset rear to -1
        }
        else
        {
            front = (front + 1) % maxsize; // Move front to the next element, wrapping around if necessary
        }
        currsize--; // Decrement the current size of the queue

        return popped; // Return the popped element
    }

    int queuemaxsize() // Function to return the current size of the queue
    {
        cout << "Size is "; // Print message indicating size
        return currsize; // Return the current size
    }

    int queuetop() // Function to return the front element of the queue without removing it
    {
        if (front == -1) // Check if the queue is empty
        {
            cout << "Queue is Empty" << endl; // Print message if empty
            exit(1); // Exit the program (could be improved with error handling)
        }
        return arr[front]; // Return the front element
    }
};

int main()
{
    Queue q(5); // Create a queue of size 5
    q.enqueue(10); // Enqueue element 10
    q.enqueue(20); // Enqueue element 20
    q.enqueue(30); // Enqueue element 30
    q.enqueue(40); // Enqueue element 40
    q.enqueue(50); // Enqueue element 50
    q.enqueue(60); // Attempt to enqueue element 60 (should indicate queue is full)
    cout << q.queuemaxsize() << "\n"; // Print the current size of the queue
    cout << "The peek of the queue after deleting an element is : " << q.queuetop() << endl; // Print the front element
    cout << q.dequeue() << endl; // Dequeue and print the front element
    cout << q.dequeue() << endl; // Dequeue and print the front element
    cout << q.dequeue() << endl; // Dequeue and print the front element
    cout << q.dequeue() << endl; // Dequeue and print the front element
    cout << q.dequeue() << endl; // Dequeue and print the front element
    cout << q.dequeue() << endl; // Attempt to dequeue from an empty queue (should indicate empty)
    cout << q.queuemaxsize() << "\n"; // Print the current size of the queue
    cout << "The peek of the queue after deleting an element :" << q.queuetop() << endl;
}