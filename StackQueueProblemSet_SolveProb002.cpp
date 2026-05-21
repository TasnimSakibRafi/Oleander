#include <iostream>
#include <cstring>
using namespace std;

int maxSize;
int topIdx = -1;
char *stackArr;

bool isFull() { return (topIdx == maxSize - 1); }
bool isEmpty() { return (topIdx == -1); }

void push(char ch) {
    if (!isFull()) stackArr[++topIdx] = ch;
}

char pop() {
    if (!isEmpty()) return stackArr[topIdx--];
    return '\0';
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (isEmpty()) return false;
            char topChar = pop();
            if (!isMatching(topChar, str[i])) return false;
        }
    }
    return isEmpty();
}

int main() {
    string input;
    cout << "Enter parentheses string: ";
    cin >> input;

    maxSize = input.size();
    stackArr = new char[maxSize];

    if (isBalanced(&input[0]))
        cout << "True";
    else
        cout << "False";

    delete[] stackArr;
    return 0;
}

