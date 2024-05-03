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

struct Queue {
    Node* front;
    Node* back;
    
    Queue() {
        front = nullptr;
        back = nullptr;
    }
    
    bool isEmpty() {
        return front == nullptr;
    }
    
    void enqueue(int _value) {
        Node* p = new Node(_value);
        if (isEmpty()) {
            front = back = p;
        } else {
            back->next = p;
            back = p;
        }
    }
    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return 0;
        }
        Node* p = front;
        int dequeuedValue = p->value;
        front = p->next;
        if (front == nullptr) {
            back = nullptr;
        }
        delete p;
        return dequeuedValue;
    }
    
    // Display Queue
    void print() {
        if (isEmpty()) {
            cout << "Error: Queue is empty" << endl;
            return;
        }
        Node* p = front;
        while (p) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
};

void displayResults(Queue& n) {
    n.enqueue(10);
    n.enqueue(20);
    n.enqueue(30);
    
    cout << "\n                        Tests" << endl;
    cout << " --------------------------------------------------------" << endl;
    cout << "  First Test  | Add value in list 10, then 20, finaly 30" << endl;
    cout << "              | ";
    n.print();
    cout << "  ------------|-----------------------------------------" << endl;
    cout << "              | Get elements" << endl;
    cout << "              | " << n.dequeue() << endl;
    cout << "              | " << n.dequeue() << endl;
    cout << "              | " << n.dequeue() << endl;
    cout << "  ------------|-----------------------------------------" << endl;
    cout << "  Second Test | Delete elements from empty list" << endl;
    cout << "              | Message: ";
    n.dequeue();
    cout << "  ------------|------------------------------------" << endl;
    n.enqueue(40);
    n.dequeue();
    if (n.isEmpty()) 
        cout << "  Third Test  | Message: Queue is empty!" << endl;
    else
        cout << "  Third Test  | Message: Someting go the wrong" << endl;
    cout << " ---------------------------------------------------" << endl;
}

int main()
{
    Queue q;
    displayResults(q);
    
    return 0;
}
