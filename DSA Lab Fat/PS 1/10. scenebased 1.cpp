
#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node *next;
  Node *first;
  void init() { first = NULL; }
  void display() {
    Node *temp = first;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
  }
  void b_insert() {
    Node *current = new Node();
    current->data = 0;
    current->next = NULL;
    if (first == NULL)
      first = current;
    else {
      Node *temp = first;
      while (temp->next != NULL) temp = temp->next;
      temp->next = current;
    }
  }
};
void update(Node x, int n) {
  for (int i = 1; i <= n; i++) {
    Node *temp = x.first;
    int count = 1;
    while (temp != NULL) {
      if (count % i == 0) temp->data++;
      count++;
      temp = temp->next;
    }
  }
}
int main() {
  Node o;
  int n;
  o.init();
  for (int i = 0; i < 13; i++) o.b_insert();
  cout << "Initial List" << endl;
  o.display();
  cout << endl << endl;
  cout << "No of iterations: ";
  cin >> n;
  cout << endl;
  update(o, n);
  cout << "Updated List" << endl;
  o.display();
}
