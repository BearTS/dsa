
#include <iostream>
using namespace std;

// Creating a class for storing nodes
class Node {
 private:
  int d;    // Data part of node
  Node *n;  // Pointer part of the node

 public:
  // Initializing a front and rear pointer
  Node *f = NULL;
  Node *r = NULL;

  // Creating the Enquque function
  void enqueue(int data) {
    // Creating and Initalizing a node to determine current position
    Node *cur = new Node;
    cur->d = data;
    cur->n = NULL;

    // If the queue is empty then we directly make the rear and front the
    // current pointer
    if (r == NULL) {
      r = cur;
      f = cur;
    }

    // If queue is not empty then we point to the rear and the convert rear to
    // the current
    else {
      r->n = cur;
      r = cur;
    }
  }

  // Creating the Dequque function
  // Int type function cause the popped element can be used for certain
  // functions
  int dequeue() {
    // Checking if the queue is empty
    if (f == NULL) {
      cout << "UNDERFLOW" << endl;
      return 6969;
    }

    // If the queue is not empty then we remove the last element
    {
      Node *cur = new Node;
      int x = f->d;
      cur = f;
      f = f->n;
      delete (cur);
      cout << x << " got popped" << endl;
      return x;
    }
  }

  // Creating the Display function
  void display() {
    // Checking if the stack is empty
    if (r == NULL) {
      cout << "UNDERFLOW" << endl;
    }

    // If stack is not empty we create a current node and print element by
    // element
    else {
      Node *cur = new Node;
      cur = f;

      // Printing elements of the stack element by element
      while (cur != NULL) {
        cout << cur->d << " ";
        cur = cur->n;
      }
    }
  }
};

// Coding Main driver function
int main() {
  // Creating Object node
  Node obj;

  // Creating variables for data, element and choice
  int d, x, ch;

  // Switch case for choices
  do {
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;
    cin >> ch;
    switch (ch) {
      // Case 1: Enququing
      case 1:
        cout << "Enter Data to be pushed ";
        cin >> d;
        obj.enqueue(d);
        break;

      // Case 2: Dequeuing
      case 2:
        x = obj.dequeue();
        break;

      // Case 3: Displaying Data
      case 3:
        obj.display();
        cout << endl;
        break;
    }
  } while (ch >= 1 && ch <= 3);
}
