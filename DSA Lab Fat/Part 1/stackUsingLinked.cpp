#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }       
};

class Stack{
    private:
        Node *top;
    public:
        Stack(){
            top = NULL;
        }
        void push(int data) {
            Node *current = new Node(data);
            if (top == NULL){
                top = current;
            } else {
                current -> next = top;
                top = current;
            }
        }
        int pop() {
            if (top == NULL) {
                cout << "Stack is empty";
                return -1;
            } 
            Node *temp = top;
            top = top -> next;
            int x = temp->data;
            delete temp;
            return x;
        }

        void display() {
            if (top == NULL) {
                cout << "Stack is empty, nothing to display" <<endl;
                return;
            }
            Node *temp = top;
            while (temp != NULL) {
                cout << temp->data << endl;
                temp = temp->next;
            }
            return;
        }
};

int main() {
    Stack s;
    for (int i = 0; i < 10; i++) {
        s.push(i);   
    }

    s.display();
    for (int i = 0; i <= 10; i++) {
        cout << s.pop();   
    }
    
    s.display();
}