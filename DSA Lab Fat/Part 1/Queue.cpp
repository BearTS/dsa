#include <iostream>
using namespace std;


class Queue {
    private:
        int rear;
        int *arr;
        int front;
        int size;
    public:
        Queue(int size) {
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        bool isEmpty() {
            if (front == -1)
                return true;
            return false;
        }

        bool isFull() {
            if (front == 0 && rear == size - 1)
                return true;
            return false; 
        }

        void enqueue(int data){
            if (isFull()) {
                cout << "Queue is full" << endl;
                return;
            }
            if (front == -1) front++;
            arr[++rear] = data;
            cout << "Inserted " << data << "at position " << rear << endl; 
        }

        int dequeue() {
            if (isEmpty()) {
                cout << "Queue is Empty" << endl;
                return 9999;
            }
            int temp = arr[front];
            if (front >= rear) {
                front = -1;
                rear = -1;
            } else {
                front++;
            }
            return temp;
        }

        void peek(){
            if (isEmpty()) {
                cout << "Queue is Empty" << endl;
            }
            cout << "Element in front is " << arr[front] << endl;
            
        }
};

int main (){
    Queue q(10);
    q.dequeue();
    cout << "Now Enquing" << endl;
    for (int i=0; i < 10; i++) {
        q.enqueue(i);
    }
    q.enqueue(21);
    cout << "Now Dequingin" << endl;
    q.dequeue();
    q.peek();
    for (int i=0; i < 11; i++) {
        cout << q.dequeue();
    }

}