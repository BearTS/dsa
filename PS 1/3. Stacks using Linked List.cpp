
#include <iostream>
using namespace std;

// Creating a class for storing nodes
class Node {
 private:
  int d;    // Data part of node
  Node *n;  // Pointer part of the node

 public:
  // Initializing a top pointer
  Node *top = NULL;

  // Creating the Push function
  void push(int data) {
    // Creating and Initalizing a node to determine current position
    Node *cur = new Node;
    cur->d = data;
    cur->n = NULL;

    // If the stack is empty then we directly make the top the current pointer
    if (top == NULL) {
      top = cur;
    }

    // If stack is not empty then we point to the top and the convert top to the
    // current
    else {
      cur->n = top;
      top = cur;
    }
  }

  // Creating the Pop function
  // Int type function cause the popped element can be used for certain
  // functions
  int pop() {
    // Checking if the stack is empty
    if (top == NULL) {
      cout << "UNDERFLOW" << endl;
      return 6969;
    }

    // If the stack is not empty then we pop the last element
    {
      Node *cur = new Node;
      cur = top;
      top = top->n;
      int x = cur->d;
      delete (cur);
      cout << x << " got popped" << endl;
      return x;
    }
  }

  // Creating the Display function
  void display() {
    // Checking if the stack is empty
    if (top == NULL) {
      cout << "UNDERFLOW" << endl;
    }

    // If stack is not empty we create a current node and print element by
    // element
    else {
      Node *cur = new Node;
      cur = top;

      // Printing elements of the stack element by element
      while (cur != NULL) {
        cout << cur->d << " ";
        cur = cur->n;
      }
    }
  }
};

// Coding the main driver function
int main() {
  // Creating the node object
  Node obj;

  // Creating variables for data, element and choice
  int d, x, ch;

  // Switch Case for choices
  do {
    cout << "Enter Choice ";
    cin >> ch;
    switch (ch) {
      // Case 1: Pushing
      case 1:
        cout << "Enter Data to be pushed ";
        cin >> d;
        obj.push(d);
        break;

      // Case 2: Popping
      case 2:
        x = obj.pop();
        break;

      // Case 3: Displaying Data
      case 3:
        obj.display();
        cout << endl;
        break;
    }
    cout << endl;
  } while (ch >= 1 && ch <= 3);
}
