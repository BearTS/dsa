#include <iostream>
using namespace std;

class Node {
    public:
        Node *prev;
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            prev = NULL;
            next = NULL;
        }
};

class DoublyLinkedList {
    private:
        Node *head;
    public:
        DoublyLinkedList(int data) {
            head = new Node(data);
        }
        void f_add(int data) {
            Node *current = new Node(data);
            current->next = head;
            head->prev = current;
            head = current;
        }

        int f_delete(){
            Node *temp = head;
            int element = temp->data;
            head = temp->next;
            head->prev = NULL;
            delete temp;
            return element;
        }

        void b_add(int data){
            Node *temp = head;
            while (temp->next != NULL){
                temp = temp->next;
            }
            Node *current = new Node(data);
            temp->next=current;
            current->prev = temp;   
        }
        
        int b_delete(){
            Node *temp = head;
            while (temp->next != NULL){
                temp = temp->next;
            }
            int element = temp->data;
            temp->prev->next = NULL;
            delete temp;
            return element;
        }
        void display(){
            Node *temp = head;
            while (temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        
};

int main() {
    DoublyLinkedList s(11);
    for(int i=0; i <= 10; i++){
        s.f_add(i);
    }
    for(int i=0; i <= 10; i++){
        s.b_add(i);
    }
    s.b_delete();
    s.f_delete();
    s.display();
}