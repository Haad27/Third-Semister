#include <iostream>
#include <string>
using namespace std;

// ✅ Integer Stack for evaluation
class IntStack {
private:
    int arr[100];
    int top;

public:
    IntStack() { top = -1; }

    void push(int value) {
        if (top >= 99) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() { return top == -1; }
};

// ✅ String Stack for infix conversion
class StringStack {
private:
    string arr[100];
    int top;

public:
    StringStack() { top = -1; }

    void push(string val) { arr[++top] = val; }
    string pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};

int evaluatePostfix(string exp) {
    IntStack s;
    for (char c : exp) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                default: cout << "Invalid operator: " << c << endl;
            }
        }
    }
    return s.pop();
}

void convertPostfixToInfix(string exp) {
    StringStack s;

    for (char c : exp) {
        if (!isdigit(c)) {
            s.push(string(1, c));
        } else {
            string val2 = s.pop();
            string val1 = s.pop();
            string expr = "(" + val1 + c + val2 + ")";
            s.push(expr);
        }
    }

    cout << "Infix form: " << s.pop() << endl;
}

int main() {
    string expr = "342*+";
    cout << "Postfix Expression: " << expr << endl;

    convertPostfixToInfix(expr);
    cout << "Result: " << evaluatePostfix(expr) << endl;
    return 0;
}
