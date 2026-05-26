#include <iostream>
using namespace std;

char *stackArr;   // dynamic stack
int top = -1;
int maxSize;

// Push function
void push(char c) {