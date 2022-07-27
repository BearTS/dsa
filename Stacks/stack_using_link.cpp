#include <iostream>

using namespace std;

class Node 
{
    int data;
    Node *addr;
    public:
        void push(int data)
        {
            Node *newNode = new Node();
            newNode->data = data;
            newNode->addr = this->addr;
            this->addr = newNode;
        }
        int pop()
        {
            Node *temp = this->addr;
            if (temp == NULL)
            {
                cout << "Stack is empty" << endl;
                return 0;
            }
            int x = temp->data;
            this->addr = this->addr->addr;
            delete temp;
            return x;
        }
        void display() {
            Node *temp = this->addr;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->addr;
            }
            cout << endl;
            delete temp;
        }


};

int main() {
    Node *stack = new Node();
    int choice;
    while (choice != 4) {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                int data;
                cout << "Enter data to push" << endl;
                cin >> data;
                stack->push(data);
                break;
            case 2:
                cout << "Popped element is " << stack->pop() << endl;
                break;
            case 3:
                stack->display();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
}