#include <iostream>
using namespace std;

char *stackArr;   // dynamic stack
int top = -1;
int maxSize;

// Normal push function
void push(char c) {
    if (top < maxSize - 1) {
        stackArr[++top] = c;
    }
}

// Normal pop function
char pop() {
    if (top == -1) {
        return '\0'; // empty stack
    }
    return stackArr[top--];
}

// Check if brackets are balanced
bool isValid(string s) {
    maxSize = s.length();          // stack size = input length
    stackArr = new char[maxSize];  // allocate dynamically

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // Only valid bracket characters allowed
        if (c != '{' && c != '}' && c != '[' && c != ']' && c != '<' && c != '>') {
            delete[] stackArr;
            return false;
        }

        if (c == '{' || c == '[' || c == '<') {
            push(c);   // use normal push
        } else {
            char topChar = pop();  // use normal pop
            if ((c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[') ||
                (c == '>' && topChar != '<')) {
                delete[] stackArr;
                return false;
            }
        }
    }

    bool balanced = (top == -1);
    delete[] stackArr; // free memory
    return balanced;
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;

    if (isValid(input))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
