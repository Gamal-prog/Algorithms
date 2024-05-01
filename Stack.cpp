#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    
    Node(int _value) {
        value = _value;
        next = nullptr;
    }
};

struct List {
    Node* first;
    
    List() {
        first = nullptr;
    }
    
    bool isEmpty() {
        return first == nullptr;
    }
    
    void push(int _value) {
        Node* p = new Node(_value);
        if (isEmpty()) {
            first = p;
            return;
        }
        p->next = first;
        first = p;
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        Node* p = first;
        int poppedValue = p->value;
        first = p->next;
        delete p;
        return poppedValue;
    }
    
    // Display List
    void print() {
        if (isEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return;
        }
        Node* p = first;
        while (p) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
};

void displayResults(List& n) {
    n.push(10);
    n.push(20);
    n.push(30);
    n.push(40);
    
    cout << "\n                        Tests" << endl;
    cout << " ---------------------------------------------------" << endl;
    cout << "  First Test  | Add value in list 10, then 20 to 40" << endl;
    cout << "              | ";
    n.print();
    cout << "  ------------|------------------------------------" << endl;
    cout << "              | Get elements" << endl;
    cout << "              | " << n.pop() << endl;
    cout << "              | " << n.pop() << endl;
    cout << "              | " << n.pop() << endl;
    cout << "              | " << n.pop() << endl;
    cout << "  ------------|------------------------------------" << endl;
    cout << "  Second Test | Delete elements from empty list" << endl;
    cout << "              | Message: ";
    n.pop();
    cout << "  ------------|------------------------------------" << endl;
    n.push(50);
    n.pop();
    if (n.isEmpty())
        cout << "  Third Test  | Message: Stack is empty!" << endl;
    else
        cout << "  Third Test  | Message: Someting go the wrong" << endl;
    cout << " ---------------------------------------------------" << endl;
}


int main()
{
    List n;
    displayResults(n);

    return 0;
}
