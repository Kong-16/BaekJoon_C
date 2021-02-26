#include <iostream>
#include <string>

using namespace std;

class node {
public:
    node();
    node(int a) { data = a; }
    int data;
    node* next;
};

class stack {
    node* nodeptr;
    int capacity;
public:
    stack();
    void push(int a);
    void pop();
    int size();
    int isEmpty();
    int top();
};

stack::stack() {
    nodeptr = NULL;
    capacity = 0;
}
void stack::push(int a) {
    node* n = new node(a);
    n->next = nodeptr;
    nodeptr = n;
    capacity++;
}
void stack::pop() {
    if (isEmpty()) {
        cout << -1 << endl;
        return;
    }
    cout << nodeptr->data << endl;
    node* tmp = nodeptr;
    nodeptr = nodeptr->next;
    delete tmp;
    capacity--;
}
int stack::size() {
    return capacity;
}
int stack::isEmpty() {
    if (capacity == 0)
        return 1;
    return 0;
}

int stack::top() {
    if (isEmpty())
        return -1;
    return nodeptr->data;
}

int main() {
    int num, pushNum;
    stack stack;
    string s;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> s;
        if (s == "push") {
            cin >> pushNum;
            stack.push(pushNum);
        }
        else if (s == "pop") {
            stack.pop();
        }
        else if (s == "size") {
            cout << stack.size() << endl;
        }
        else if (s == "empty") {
            cout << stack.isEmpty() << endl;
        }
        else if (s == "top") {
            cout << stack.top() << endl;
        }
    }
}