#include <iostream> 

using namespace std;

class Queue {
private:
    int *arr;
    int size;
    int front;
    int rear;
public:
    Queue(int size) {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        this->arr = new int[size];
    }
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = data;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int data = arr[front];
        front = (front + 1) % size;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        return data;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (rear + 1) % size == front;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main () {
    Queue a(10);
    for (int i = 0; i < 10; i++) {
        a.enqueue(i);
    }
    a.display();
    a.dequeue();
    cout << "After dequeue" << endl;
    a.display();
    return 0;
}