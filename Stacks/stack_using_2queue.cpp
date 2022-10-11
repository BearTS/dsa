#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Stack {
    private:
        queue<int> q1, q2;
    public:
        void push(int data) {
            q1.push(data);
        }
        int pop() {
            if (q1.empty() && q2.empty()) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            if (q2.empty()) {
                while (q1.size() > 1) {
                    q2.push(q1.front());
                    q1.pop();
                }
                int data = q1.front();
                q1.pop();
                return data;
            }
            else {
                while (q2.size() > 1) {
                    q1.push(q2.front());
                    q2.pop();
                }
                int data = q2.front();
                q2.pop();
                return data;
            }
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