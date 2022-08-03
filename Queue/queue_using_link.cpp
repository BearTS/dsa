#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
private:
    Node *front;
    Node *rear;
public:
    Queue() {
        this->front = NULL;
        this->rear = NULL;
    }
    void enqueue(int data) {
        Node *newNode = new Node(data);
        if (this->front == NULL) {
            this->front = newNode;
            this->rear = newNode;
        } else {
            this->rear->next = newNode;
            this->rear = newNode;
        }
    }
    int dequeue() {
        if (this->front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int data = this->front->data;
        this->front = this->front->next;
        if (this->front == NULL) {
            this->rear = NULL;
        }
        return data;
    }
    bool isEmpty() {
        return this->front == NULL;
    }
    void display() {
        if (this->front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = this->front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
 
int main ()
{
    Queue *a = new Queue();
    for (int i = 0; i < 10; i++) {
        a->enqueue(i);
    }
    a->display();
    cout << "After dequeue" << endl;
    a->dequeue();
    a->display();
    return 0;
}