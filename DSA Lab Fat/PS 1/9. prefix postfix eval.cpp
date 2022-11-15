#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 30
using namespace std;
int a[MAX];
int top;


void push(int data) {
  int i;
  top++;
  a[top] = data;
}
int pop() { return (a[top--]); }
int eval(int d1, int d2, char sym) {
  int r;
  switch (sym) {
    case '+':
      r = d1 + d2;
      break;
    case '-':
      r = d1 - d2;
      break;
    case '*':
      r = d1 * d2;
      break;
    case '/':
      r = d1 / d2;
      break;
    case '%':
      r = d1 % d2;
      break;
  }
  return (r);
}
void postfix() {
  int i, j, val, opd1, opd2, h;

  string post;
  cout << "enter the postfix expression to be evaluated: ";
  cin >> post;
  i = post.length();
  top = -1;
  for (j = 0; j < i; j++) {
    if ((post[j] == ' ') || (post[j] == '\t'))
      continue;
    else if (isdigit(post[j])) {
      val = post[j] - 48;
      push(val);
    } else if (isalpha(post[j])) {
      cout << "enter the value of " << post[j];
      cin >> val;
      push(val);
    } else {
      opd2 = pop();
      opd1 = pop();
      int x = eval(opd1, opd2, post[j]);
      push(x);
    }
  }
  cout << "the result of the give postfix expression is: " << pop();
  cout << endl;
}

void prefix() {
  int i, j, val, opd1, opd2, h;

  string post;  // 34+
  cout << "enter the prefix expression to be evaluated: ";
  cin >> post;  // 34+
  i = post.length();  // 3
  reverse(post.begin(), post.end());
  cout << post << endl;
  top = -1;
  for (j = 0; j < i; j++) {
    if ((post[j] == ' ') || (post[j] == '\t'))
      continue;
    else if (isdigit(post[j])) {
      val = post[j] - 48;
      push(val);
    } else if (isalpha(post[j])) {
      cout << "enter the value of " << post[j];
      cin >> val;
      push(val);
    } else {
      opd1 = pop();
      opd2 = pop();
      int x = eval(opd1, opd2, post[j]);
      push(x);
    }
  }
  cout << "the result of the give prefix expression is: " << pop();
  cout << endl;
}

int main() {
  int h, c = 1;
  while (c == 1) {
    cout << "1.Postfix" << endl;
    cout << "2.Prefix" << endl;
    cout << "Enter Choice: ";
    cin >> h;
    switch (h) {
      case 1:
        postfix();
        break;
      case 2:
        prefix();
        break;
      default:
        break;
    }
    cout << endl;
    cout << "Do you want to continue: ";
    cin >> c;
    cout << endl;
  }
}
