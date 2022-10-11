// creating adt stack
#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
    int top;
    int capacity;
    int *array;
public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        top = -1;
        array = new int[capacity];
    }
    void push(int value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        array[++top] = value;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return array[top--];
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack a(10);
    for(int i = 0; i < 10; i++)
    {
        a.push(i);
    }
    a.display();
    a.pop();
    cout << "After pop" << endl;
    a.display();
}