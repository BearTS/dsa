#include <iostream>
using namespace std;

// Creating the Class for Queue
class Queue {
 private:
  int *a;
  int size;
  int f = -1, r = -1;  // Initializing the front and rear

 public:
  Queue(int size) {
    a = new int[size];
    this->size = size;
  }
  // Creating Enqueue Function
  void enqueue(int data) {
    // Overflow condition (Queue is Full)
    if (r == size - 1) {
      cout << "OVERFLOW" << endl;
    }

    // If the queue is not full
    else {
      // Incrementing the rear index
      r++;
      a[r] = data;
    }
  }

  // Creating the dequque function
  // Int type function cause the popped element can be used for certain
  // functions
  int dequeue() {
    // Undeflow condition (Queue is Empty)
    if (r == f) {
      cout << "UNDERFLOW" << endl;
      return 6969;
    }

    // If the queue is not empty
    else {
      // Storing the popped element in a variable
      // Incrementing the front index
      f++;
      int x = a[f];
      cout << x << " got popped" << endl;
      return x;
    }
  }

  // Function to display elements of the queue
  void display() {
    for (int i = f + 1; i <= r; i++) {
      cout << a[i] << " ";
    }
  }
};

// Coding the main driver code
int main() {
  // Intializing Stack and number of elements in the stack
  int n, x;
  cout << "Enter the number of elements in the queue" << endl;
  cin >> n;

  // Creating queue object
  Queue q(n);

  // Entering the elements of the queue
  for (int i = 0; i < n; i++) {
    cout << "Enter element" << endl;
    cin >> x;
    q.enqueue(x);
  }

  // Displaying the queue
  q.display();
  cout << endl;

  // Dequeue elements
  int a = q.dequeue();
  int b = q.dequeue();

  // Displaying queue without popped elements
  q.display();
  cout << endl;
}
