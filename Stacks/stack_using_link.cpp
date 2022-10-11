#include <iostream>

using namespace std;

class Node {
    int data;
    Node *next;
    public:
    Node *top = NULL;
    void push(int x){
        Node *current = new Node;
        current->data = x;
        current->next = NULL;
        if (top == NULL){
            top = current;
        }
        else{
            current->next = top;
            top = current;
        }
    }
    int pop(){
        if (top == NULL){
            cout << "Stack is empty" << endl;
            return 9999;
        }
        else{
            Node *temp = top;
            top = top->next;
            int x = temp->data;
            delete temp;
            return x;
        }
    }
    void display(){
        Node *temp = top;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        
    }
    
}
int main () {
    Node n;
    n.push(1);
    n.push(2);
    n.push(3);
    n.push(4);
    n.display();
    cout << n.pop() << endl;
    n.display();
    return 0;
}