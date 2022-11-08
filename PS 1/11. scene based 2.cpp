
#include <iostream>
#include <string>
using namespace std;

class Node {
 public:
  Node *prev;
  Node *succ;
  string name;
  string state;
  Node *head = NULL;
  void b_insert(string n, string s) {
    Node *current = new Node();
    current->name = n;
    current->state = s;
    current->prev = NULL;
    current->succ = current;
    if (head == NULL)
      head = current;
    else {
      Node *temp = head;
      while (temp->succ != head) temp = temp->succ;
      temp->succ = current;
      current->prev = temp;
      head->prev = current;
      current->succ = head;
    }
  }
  void display() {
    Node *temp = head;
    cout << temp->name << " " << temp->state << endl;
    temp = temp->succ;
    while (temp != head) {
      cout << temp->name << " " << temp->state << endl;
      temp = temp->succ;
    }
  }
  void del_val(Node *ptr) {
    Node *temp = head;
    while (temp != ptr) {
      temp = temp->succ;
    }
    temp->prev->succ = temp->succ;
    temp->succ->prev = temp->prev;
    delete temp;
  }
  void del_duplicate() {
    Node *val = head;
    Node *ftemp;
    Node *btemp;
    do {
      ftemp = val->succ;
      btemp = val->prev;
      while (ftemp != val) {
        if (ftemp->state == val->state) {
          del_val(ftemp);
          val = val->succ;
          break;
        } else if (btemp->state == val->state) {
          del_val(btemp);
          val = val->succ;
          break;
        } else {
          ftemp = ftemp->succ;
          btemp = btemp->prev;
        }
      }
      val = val->succ;
    } while (val != head);
  }
};

int main() {
  Node o;
  string n, s;
  int h, c = 1;
  while (c == 1) {
    cout << "Enter Choice: ";
    cin >> h;
    switch (h) {
      case 1:
        cout << "Enter Name: ";
        cin >> n;
        cout << "Enter State: ";
        cin >> s;
        o.b_insert(n, s);
        break;
      default:
        break;
    }
    cout << "Do you want to continue: ";
    cin >> c;
    cout << endl;
  }
  cout << "Initial List" << endl;
  o.display();
  cout << endl;
  o.del_duplicate();
  cout << "Final List" << endl;
  o.display();
}
