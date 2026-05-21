#include <iostream>
using namespace std;

int maxSize;
int topIdx = -1;
char *stackArr;



bool isFull() {
    return (topIdx == maxSize - 1);
}



bool isEmpty() {
    return (topIdx == -1);
}

void push(char ch) {
    if (!isFull()) {
        stackArr[++topIdx] = ch;
    }
}



char pop() {
    if (!isEmpty()) {
        return stackArr[topIdx--];
    }
    return '\0';
}



void reverseWords(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n') {
            push(str[i]);
        } else {
            while (!isEmpty()) {
                cout << pop();
            }
            cout << " ";
        }
    }
    while (!isEmpty()) {
        cout << pop();
    }
}





int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    maxSize = 100;
    stackArr = new char[maxSize];

    cout << "Reversed words: ";
    reverseWords(str);

    delete[] stackArr;
    return 0;
}

