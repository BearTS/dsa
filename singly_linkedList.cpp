#include <iostream>
using namespace std;

// singly linked list

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    Node *head;
public:
    LinkedList() {
        this->head = NULL;
    }
    void f_insert(int data) {
        Node *new_node = new Node(data);
        new_node->next = this->head;
        this->head = new_node;        
    }
    void f_delete(){
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    void display(){
        if (this->head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = this->head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void mid_insert(int data){
        cout << "Enter index of node to insert" << endl;
        int index;
        cin >> index;
        if (this->head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *current = new Node(data);
        Node *temp = this->head;
        int count = 1;
            while (count < index && temp->next != NULL) {
                temp = temp->next;
                count++;
            }
            current->next = temp->next;
            temp->next = current;
    }
    int mid_delete(){
        int x;
        cout << "enter node index to delete" << endl;
        cin >> x;
        if (this->head == NULL) {
            cout << "List is empty" << endl;
            return -1;
        }
        Node *temp = this->head;
        Node *prev = NULL;
        while (temp->next != NULL && temp->data != x) {
            prev = temp;
            temp = temp->next;

        }
        if (temp->data == x) {
            prev->next = temp->next;
            delete temp;
            return x;
        }
        cout << "Node not found" << endl;
        return -1;
    }
    void b_insert(int data){
        if (this->head == NULL) {
            this->head = new Node(data);
            return;
        }
        Node *current = new Node(data);
        Node *temp = this->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = current;
    }
    int b_delete(){
        //  back delete from right
        if (this->head == NULL) {
            cout << "List is empty" << endl;
            return -1;
        }
        Node *temp = this->head;
        Node *prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        int x = temp->data;
        prev->next = NULL;
        delete temp;
        return x;
    }
};

int main() {
    LinkedList ll;
    cout << "Press 1 to front insert" << endl;
    cout << "Press 2 to display" << endl;
    cout << "Press 3 to front delete" << endl;
    cout << "Press 4 to mid insert" << endl;
    cout << "Press 5 to mid delete" << endl;
    cout << "Press 6 to back insert" << endl;
    cout << "Press 7 to back delete" << endl;
    cout << "Enter Choice: ";
    int choice;
    cin >> choice;
    while (choice != 0) {
        switch (choice) {
            case 1:
                cout << "Enter data: ";
                int data;
                cin >> data;
                ll.f_insert(data);
                break;
            case 2:
                ll.display();
                break;
            case 3:
                ll.f_delete();
                break;
            case 4:
                cout << "Enter data: ";
                int data1;
                cin >> data1;
                ll.mid_insert(data1);
                break;
            case 5:
                cout << "delete data: " << ll.mid_delete() << endl;
                break;
            case 6:
                cout << "Enter data: ";
                int data2;
                cin >> data2;
                ll.b_insert(data2);
                break;
            case 7:
                cout << "delete data: " << ll.b_delete() << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
        cout << "Enter Choice: ";
        cin >> choice;
    }
    return 0;
}