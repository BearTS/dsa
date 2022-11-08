#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 30

char a[MAX];
int top;

void push(char data) {
  top++;
  a[top] = data;
}

char pop() {
  if (top != -1) {
    int x = a[top];

    top--;
    return x;
  } else
    return ('\0');
}

int priority(char data) {
  if (data == '*' || data == '/' || data == '%')
    return 3;
  else if (data == '-' || data == '+')
    return 2;
  else if (data == '>' || data == '<')
    return 1;
  else
    return 0;
}

void postfix() {
  int len, j, k = 0;
  char opr;
  string s, post, t;
  cout << "enter the infix expression to be converted\n";
  cin >> s;
  len = s.length();
  top = -1;
  for (j = 0; j < len; j++) {
    if ((s[j] == ' ') || (s[j] == '\t'))  // to ignore unwanted spaces left in
                                          // between the characters of the
                                          // expression
      continue;
    else if ((isdigit(s[j])) ||
             (isalpha(
                 s[j])))  // this condition will evaluate to true for an operand
    {  // an operand can be a digit or alphabet and so simply add it to
      post.append(1, s[j]);  // post string
    } else if (s[j] == '(')  // if character is '(' push it onto the stack
      push(s[j]);
    else if (s[j] == ')')  // if character is ')'
    {
      do {
        opr = pop();     // pop the next character from the top of stack
        if (opr == '(')  // if popped character is '(' simply ignore
          break;
        else
          post.append(1,
                      opr);  // else append the popped character to post string
      } while (
          opr !=
          '(');  // the above steps are repeated till an '(' is encountered.
    } else       // this 'else' part will handle operators
    {
      if (top == -1)  // if stack is empty, simply push the current character
                      // (which is an operator)
        push(s[j]);   // on to the stack
      else {
        opr = pop();
        if (opr == '(') {
          push(opr);
          push(s[j]);
        } else {
          while (priority(opr) >= priority(s[j])) {
            post.append(1, opr);
            opr = pop();
            if (opr == '\0') break;
          }
          push(opr);
          push(s[j]);
        }
      }
    }
  }
  char x;
  do {
    x = pop();
    if (x != '\0') post.append(1, x);
  } while (x != '\0');
  post.append(1, '\0');
  cout << "Postfix eqn: " << post;
}
void prefix() {
  int len, j, k = 0;
  char opr;
  string s, post, t;
  cout << "enter the infix expression to be converted\n";
  cin >> s;
  reverse(s.begin(), s.end());
  len = s.length();
  top = -1;
  for (j = 0; j < len; j++) {
    if ((s[j] == ' ') || (s[j] == '\t'))
      continue;
    else if ((isdigit(s[j])) || (isalpha(s[j]))) {
      post.append(1, s[j]);
    } else if (s[j] == ')')
      push(s[j]);
    else if (s[j] == '(') {
      do {
        opr = pop();
        if (opr == ')')
          break;
        else
          post.append(1, opr);
      } while (opr != ')');
    } else {
      if (top == -1)
        push(s[j]);
      else {
        opr = pop();
        if (opr == '(') {
          push(opr);
          push(s[j]);
        } else {
          while (priority(opr) > priority(s[j])) {
            post.append(1, opr);
            opr = pop();
            if (opr == '\0') break;
          }
          push(opr);
          push(s[j]);
        }
      }
    }
  }
  char x;
  do {
    x = pop();
    if (x != '\0') post.append(1, x);
  } while (x != '\0');
  post.append(1, '\0');
  reverse(post.begin(), post.end());
  cout << "Prefix Eqn: " << post;
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