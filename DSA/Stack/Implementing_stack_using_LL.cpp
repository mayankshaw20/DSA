#include<iostream>
using namespace std;

struct stackNode {
  int data;//data part of the Node
  stackNode * next; //it is pointer to the next node//address part of the node

  stackNode(int d) { //Calling a constructor which will intialise the value 
    data = d;
    next = NULL;//initializing the next as a NULL
  }
};
struct stack {
  stackNode * top; //This pointer points to the top node of the stack.
  int size;// This variable keeps track of the number of elements in the stack.
  stack() {
    top = NULL; //Constructor: Initializes top to NULL (indicating an empty stack) and size to 0.
    size = 0;
  }
  void stackPush(int x) {
    stackNode * element = new stackNode(x);
    element -> next = top;
    top = element;
    cout << "Element pushed" << "\n";
    size++;
  }
  int stackPop() {
    if (top == NULL) {
      return -1;
    }
    int topData = top -> data;
    stackNode * temp = top;
    top = top -> next;
    delete temp;
    size--;
    return topData;
  }
  int stackSize() {
    return size;
  }
  bool stackIsEmpty() {
    return top == NULL;
  }
  int stackPeek() {
    if (top == NULL) return -1;
    return top -> data;
  }
  void printStack() {
    stackNode * current = top;
    while (current != NULL) {
      cout << current -> data << " ";
      current = current -> next;
    }
  }
};
int main() {
  stack s;
  s.stackPush(10);
  cout << "Element popped: " << s.stackPop() << "\n";
  cout << "Stack size: " << s.stackSize() << "\n";
  cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n";
  cout << "stack's top element: " << s.stackPeek() << "\n";
  return 0;
}