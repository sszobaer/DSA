#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 100;

class Stack {

private:
    int top;
    int arr[MAX_SIZE];
public:
    Stack() {
        top = -1;
    }
    bool isFull() {
        return top == MAX_SIZE - 1;



    }
    bool isEmpty() {
        return top == -1;
    }
    void push(int value) {



        if (isFull()) {



            cout << "Stack is full. Cannot push." << endl;
        }
        else {
            arr[++top] = value;
            cout << value << " pushed onto the stack." << endl;
        }
    }



    void display() {

        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";



            for (int i = 0; i <= top; i++) {



                cout << arr[i] << " ";



            }
            cout << endl;
        }
    }
};
int main() {

    Stack stack;
    int choice, value;
    while (true) {



        cout << "Choose an operation:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Display" << endl;
        cin >> choice;



        switch (choice) {

            case 1:
                cout << "Enter a value to push: ";
                cin >> value;
                stack.push(value);
                break;
                 case 2:
                stack.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
