#include<bits./stdc++.h>
using namespace std;

// Structure to represent a node in the queue
struct QueueNode
{
    int data; // Data stored in the node
    QueueNode * next; // Pointer to the next node in the queue

    // Constructor to initialize a new node
    QueueNode(int x){
        data = x; // Set the data
        next = NULL; // Initialize next pointer to NULL
    }  
};

// Structure to represent the queue
struct Queue {
    QueueNode* front; // Pointer to the front of the queue
    QueueNode* rear; // Pointer to the rear of the queue
    int currsize; // Current size of the queue

    // Constructor to initialize an empty queue
    Queue() {
        front = NULL; // Initialize front to NULL
        rear = NULL; // Initialize rear to NULL
        currsize = 0; // Initialize current size to 0
    }

    // Destructor to clean up the queue
    ~Queue() {
        while (front != NULL) {
            dequeue(); // Dequeue all elements to free memory
        }
    }

    // Function to add an element to the queue
    void enqueue(int x) {
        QueueNode * element = new QueueNode(x); // Create a new node
        if (rear == NULL) { // If the queue is empty
            front = element; // Set front to the new node
            rear = element; // Set rear to the new node
        } else {
            rear->next = element; // Link the new node at the end
            rear = element; // Update rear to the new node
        }
        currsize++; // Increment the size of the queue
    }

    // Function to remove and return the front element of the queue
    int dequeue() {
        if (front == NULL) { // Check if the queue is empty
            cout << "Queue is empty" << endl; // Print message
            return -1; // Return -1 to indicate failure
        }
        QueueNode* temp = front; // Store the front node
        int popped = front->data; // Get the data from the front node
        front = front->next; // Move front to the next node
        if (front == NULL) { // If the queue becomes empty
            rear = NULL; // Set rear to NULL as well
        }
        delete temp; // Free the memory of the dequeued node
        currsize--; // Decrement the size of the queue
        return popped; // Return the data of the dequeued node
    }

    // Function to get the front element of the queue without removing it
    int queuetop() {
        if (front == NULL) { // Check if the queue is empty
            cout << "Queue is empty" << endl; // Print message
            return -1; // Return -1 to indicate failure
        }
        return front->data; // Return the data of the front node
    }

    // Function to get the current size of the queue
    int queuesize() {
        return currsize; // Return the current size
    }
};

int main() {
    Queue q; // Create a new queue
    q.enqueue(3); // Enqueue element 3
    q.enqueue(4); // Enqueue element 4
    q.enqueue(5); // Enqueue element 5
    cout << q.queuesize() << endl; // Print the current size of the queue

    // Dequeue elements and print them
    cout << "Dequeued element  :" << q.dequeue() << "\n"; // Dequeue and print
    cout << "Dequeued element  :" << q.dequeue() << "\n"; // Dequeue and print
    cout << "Dequeued element  :" << q.dequeue() << "\n"; // Dequeue and print
    cout << "Dequeued element  :" << q.dequeue() << "\n"; // Dequeue and print
    cout << "Dequeued element  :" << q.dequeue() << "\n"; // Dequeue and print
    cout << q.queuesize() << endl; // Print the current size of the queue after dequeuing
}
//it is almost same but having the features of try and except during the runtime
// #include <bits/stdc++.h>
// using namespace std;
// struct QueueNode {
//     int data;
//     QueueNode *next;
//     QueueNode(int x) : data(x), next(NULL) {}
// };
// struct Queue {
//     QueueNode* front;
//     QueueNode* rear;
//     int currsize;
//     Queue() : front(NULL), rear(NULL), currsize(0) {}
//     ~Queue() {
//         while (front != NULL) {
//             dequeue();
//         }
//     }
//     void enqueue(int x) {
//         QueueNode *element = new QueueNode(x);
//         if (rear == NULL) { // Queue is empty
//             front = element;
//             rear = element;
//         } else {
//             rear->next = element;
//             rear = element;
//         }
//         currsize++;
//     }
//     int dequeue() {
//         if (front == NULL) {
//             throw runtime_error("Queue is empty");
//         }
//         QueueNode* temp = front;
//         int popped = front->data;
//         front = front->next;
//         if (front == NULL) { // If the queue becomes empty
//             rear = NULL;
//         }
//         delete temp;
//         currsize--;
//         return popped;
//     }
//     int queuetop() {
//         if (front == NULL) {
//             throw runtime_error("Queue is empty");
//         }
//         return front->data;
//     }
//     int queuesize() {
//         return currsize;
//     }
// };
// int main() {
//     Queue q;
//     try {
//         q.enqueue(3);
//         q.enqueue(4);
//         q.enqueue(5);
//         cout<<q.queuesize()<<endl;
//         cout << "Dequeued element: " << q.dequeue() << "\n";
//         cout << "Dequeued element: " << q.dequeue() << "\n";
//         cout << "Dequeued element: " << q.dequeue() << "\n";
//          cout<<q.queuesize()<<endl;
//         cout << "Dequeued element: " << q.dequeue() << "\n"; // This will now throw an exception
       
//     } catch (const runtime_error &e) {
//         cout << e.what() << "\n";
//     }
//     return 0;
// }
    