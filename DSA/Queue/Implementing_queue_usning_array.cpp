#include <iostream>
using namespace std;
class Queue
{
    int front, rear;
    int *arr;
    int maxsize;
    int currsize;

public:
    Queue(int size)
    {
        arr = new int(size);
        maxsize = size;
        front = -1;
        rear = -1;
        currsize = 0;
    }
    ~Queue()
    {
        delete[] arr; // Free allocated memory
    }
    void enqueue(int x)
    {
        if (currsize == maxsize)
        {
            cout << "queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        cout << "Element enqueued  :: " << x << endl;
        arr[(++rear) % maxsize] = x; //(rear + 1) % maxmaxsize; also ca be written as this
        currsize++;                  // increment the currsize of maxsize
    }
    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Empty\nExiting..." << endl;
            return 0;
        }
        int popped = arr[front];
        if (currsize == 1)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % maxsize;
        }
        currsize--; // also can be written as  front = (front + 1) % maxSize;

        return popped;
    }
    int queuemaxsize()
    {
        cout << "Size is ";
        return currsize;
    }
    int queuetop()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[front]; // performing this because
        // there might be possibility that it is circular array
    }
};
int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << q.queuemaxsize() << "\n";
    cout << "The peek of the queue after deleting an element is : " << q.queuetop() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.queuemaxsize() << "\n";
    cout << "The peek of the queue after deleting an element " << q.queuetop() << endl;
}