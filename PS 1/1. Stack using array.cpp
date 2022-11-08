#include <iostream>
using namespace std;

// Creating the Class for Stack
class Stack {
 private:
  int *a;
  int size;
  int top = -1;  // Initializing top of the stack

 public:
  Stack(int size) {
    a = new int[size];
    this->size = size;
  }
  // Creating Push Function
  void push(int data) {
    // Overflow condition (Stack is Full)
    if (top == size - 1) {
      cout << "OVERFLOW" << endl;
    }

    // If the stack is not full
    else {
      // Incrementing top index and adding the data
      top++;
      a[top] = data;
    }
  }

  // Creating the pop function
  // Int type function cause the popped element can be used for certain
  // functions
  int pop() {
    // Undeflow condition (Stack is Empty)
    if (top == -1) {
      cout << "UNDERFLOW" << endl;
      return 6969;
    }

    // If the stack is not empty
    else {
      // Storing the popped element in a variable
      int x = a[top];
      cout << x << " got popped" << endl;
      top--;
      return x;
    }
  }

  // Function to display elements of the stack
  void display() {
    for (int i = top; i >= 0; i--) {
      cout << a[i] << " ";
    }
  }
};

// Coding the main driver code
int main() {
  // Intializing Stack and number of elements in the stack
  int n, x;
  cout << "Enter the number of elements in the stack" << endl;
  cin >> n;

  // Creating stack object
  Stack s(n);

  // Entering the elements of the stack
  for (int i = 0; i < n; i++) {
    cout << "Enter element" << endl;
    cin >> x;
    s.push(x);
  }

  // Displaying Stack
  s.display();
  cout << endl;

  // Popping elements from the stack
  int a = s.pop();
  int b = s.pop();

  // Displaying stack without popped elements
  s.display();
  cout << endl;
}
