#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Queue {
    private:
        stack<int> s1, s2;
    public:
        void enqueue(int data) {
            s1.push(data);
        }
        int dequeue() {
            if (s1.empty() && s2.empty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int data = s2.top();
            s2.pop();
            return data;
        }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}