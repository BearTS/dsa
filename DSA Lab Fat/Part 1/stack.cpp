#include <iostream>
using namespace std;

class Stack {
    private:
        int top;
        int *arr;
        int size;
    public:
        Stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }
        void push(int data) {
            if (top >= size - 1) {
                
                cout << "Stack is full" << endl;
                return;    
            }
            arr[++top] = data;
            cout << "Element pushed to stack: " << data << " at position " << top << endl;
        }
        int pop(){
            if (top == -1) {
                cout << "Stack is empty" <<endl;
                return 9999;
            }
            return arr[top--];
        }
        void display() {
            if (top == -1) {
                cout << "Stack is empty"<< endl;
                return;
            }
            cout << "Elements in the stack are: ";
            for (int i=0; i <= top; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Stack a(10);
    a.pop();
    a.display();
    for (int i=0; i < 10; i++){
        a.push(i);
    }
    a.push(99);
    a.display();
    cout << a.pop();
    a.display();
}