#include <iostream>
using namespace std;


class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            next = NULL;
        }
};


class SinglyLinkedList {
    private:
        Node* head;
    public:
        SinglyLinkedList(int data){
            head = new Node(data);
        }
        void f_add(int data){
            Node *current = new Node(data);
            current->next=head;
            head = current;
        }
        int f_delete(){
            Node *temp = head;
            int element = head->data;
            if (head->next == NULL) {
                head = NULL;
            } else {
                head = head->next;
            }
            delete temp;
            return element;
        }
        void m_add(int data);
        int m_delete();

        void b_add(int data);
        int b_delete();

        void display() {
            Node *temp = head;
            while (temp != NULL) {
                cout << temp->data <<endl;
                temp = temp->next;
            }
        }
};

int main(){
    SinglyLinkedList s(10);
    s.f_add(11);
    s.f_add(12);
    s.display();
}