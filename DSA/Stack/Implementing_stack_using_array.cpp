#include<bits./stdc++.h>

using namespace std;

class Stack{//object is bring created
 int size;
 int * arr;
 int top;
 public:
    Stack(){//running a constructor 
        //bedefault so that when obejct wull be created it 
        //initailaize it with the value given below
        top=-1;
        size=1000; 
        arr= new int(size);  // Dynamically allocate an array of integers
    }
    void push(int val){
        if(top==size){
            cout<<"Stack Overflow"<<endl;
        }
        else{
        arr[++top]=val;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
        }
        else
        top--;
    }
    int size(){
        return top+1;
    }
};
int main(){
    Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}