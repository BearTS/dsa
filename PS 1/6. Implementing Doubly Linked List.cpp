
#include <iostream>
using namespace std;

// Creating a class for storing nodes
class Node {
 private:
  int d;    // Data part of node
  Node *n;  // Pointer next part of the node
  Node *p;  // Pointer prev part of the node

 public:
  // Initializing a front pointer
  Node *f = NULL;

  // Creating the front insertion function
  void f_insert(int data) {
    // Creating and Initalizing a node to determine current position
    Node *cur = new Node;
    cur->d = data;
    cur->n = NULL;
    cur->p = NULL;

    // If the list is empty then we directly make the front the current pointer
    if (f == NULL) {
      f = cur;
    }

    // If list is not empty then we point to the front and the convert front to
    // the current
    else {
      cur->n = f;
      f = cur;
    }
  }

  // Creating the front deletion function
  // Int type function cause the popped element can be used for certain
  // functions
  int f_delete() {
    // Checking if the list is empty
    if (f == NULL) {
      cout << "UNDERFLOW" << endl;
      return 6969;
    }

    // If the list is not empty then we pop the first element
    else {
      Node *cur = new Node;
      cur = f;
      f = f->n;
      int x = cur->d;
      delete (cur);
      cout << x << " is the popped element" << endl;
      return x;
    }
  }

  // Creating the back insertion function
  void b_insert(int data) {
    // Creating and Initalizing a node to determine current position
    Node *cur = new Node;
    cur->d = data;
    cur->n = NULL;
    cur->p = NULL;

    // If the node is empty then we directly make the front the current pointer
    if (f == NULL) {
      f = cur;
    }

    // If stack is not empty then we point to the back and the convert temporary
    // back pointer to the current
    else {
      Node *temp = new Node;
      temp = f;
      while (temp->n != NULL) {
        temp = temp->n;
      }
      temp->n = cur;
      cur->p = temp;
    }
  }

  // Creating the back deletion function
  // Int type function cause the popped element can be used for certain
  // functions
  int b_delete() {
    // Checking if the list is empty
    if (f == NULL) {
      cout << "UNDERFLOW" << endl;
      return 6969;
    }

    // If the list is not empty then we pop the last element
    else {
      Node *prev = new Node;
      Node *temp = new Node;
      temp = f;
      prev = NULL;
      while (temp->n != NULL) {
        prev = temp;
        temp = temp->n;
      }
      prev->n = NULL;
      int x = temp->d;
      delete (temp);
      cout << x << " is the popped element" << endl;
      return x;
    }
  }

  // Creating the middle insertion function
  void m_insert(int data) {
    // Creating and Initalizing a node to determine current position
    Node *cur = new Node;
    cur->d = data;
    cur->n = NULL;

    // Taking User input on the position of insertion
    int node;
    cout << "After how many nodes do you want to insert ";
    cin >> node;

    // If the list is empty then we directly make the top the current pointer
    if (f == NULL) {
      f = cur;
      cout << "The list has no elements so will be first inserted" << endl;
    }

    // If list is not empty then we point to the desired position and the
    // convert temporary to the current
    else {
      Node *temp = new Node;
      temp = f;
      int count = 0;
      while (count < node - 1 && temp->n != NULL) {
        count++;
        temp = temp->n;
      }
      cur->n = temp->n;
      temp->n = cur;
    }
  }

  // Creating the middle deletion function
  // Int type function cause the popped element can be used for certain
  // functions
  int m_delete() {
    // Taking user input on the node they want to delete
    int num;
    cout << "Enter the data you want to delete ";
    cin >> num;

    // Checking if the stack is empty
    if (f == NULL) {
      cout << "UNDERFLOW" << endl;
      return 6969;
    }

    // If the stack is not empty then we pop the element as per user requirement
    else {
      Node *prev = new Node;
      Node *temp = new Node;
      temp = f;
      prev = NULL;
      while (temp->d != num && temp->n != NULL) {
        prev = temp;
        temp = temp->n;
      }
      prev->n = temp->n;
      int x = temp->d;
      delete (temp);
      cout << x << " is the popped element" << endl;
      return x;
    }
  }

  // Creating the Display function
  void display() {
    // Checking if the list is empty
    if (f == NULL) {
      cout << "UNDERFLOW" << endl;
    }

    // If list is not empty we create a current node and print element by
    // element
    else {
      Node *temp = new Node;
      temp = f;

      // Printing elements of the list element by element
      while (temp != NULL) {
        cout << temp->d << " ";
        temp = temp->n;
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
    cout << "1. Insertion at front" << endl;
    cout << "2. Deletion at front" << endl;
    cout << "3. Insertion at back" << endl;
    cout << "4. Deletion at back" << endl;
    cout << "5. Insertion at middle" << endl;
    cout << "6. Deletion at middle" << endl;
    cout << "7. Display" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice ";
    cin >> ch;
    switch (ch) {
      // Case 1: Front Insertion
      case 1:
        cout << "Enter Data to be pushed ";
        cin >> d;
        obj.f_insert(d);
        break;

      // Case 2: Front Deletion
      case 2:
        x = obj.f_delete();
        break;

      // Case 3: Back Insertion
      case 3:
        cout << "Enter Data to be pushed ";
        cin >> d;
        obj.b_insert(d);
        break;

      // Case 4: Back Deletion
      case 4:
        x = obj.b_delete();
        break;

      // Case 5: Middle Insertion
      case 5:
        cout << "Enter Data to be pushed ";
        cin >> d;
        obj.m_insert(d);
        break;

      // Case 6: Middle Deletion
      case 6:
        x = obj.m_delete();
        break;

      // Case 7: Displaying Data
      case 7:
        obj.display();
        cout << endl;
        break;
    }
  } while (ch >= 1 && ch <= 7);
}
