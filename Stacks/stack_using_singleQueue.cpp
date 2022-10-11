#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// use only 1 queue
class Stack {
    private:
        queue<int> q1;
    public:
        void push(int data) {
            q1.push(data);
        }
        int pop() {
            if (q1.empty()) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            int size = q1.size();
            for (int i = 0; i < size - 1; i++) {
                q1.push(q1.front());
                q1.pop();
            }
            int data = q1.front();
            q1.pop();
            return data;
        }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}