#include <iostream>
class Node {
public:
    int data;
    Node* next;
};
Node *head = NULL, *tail = NULL;

void push(int newData) {
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}
int pop() {
    int tempVal;
    Node *temp;

    if (head == NULL) {
        head = tail = NULL;
        std::cout << "Stack Underflow." << std::endl;
        return -1;
    } else {
        temp = head;
        tempVal = temp->data;
        head = head->next;
        delete temp;
        return tempVal;
    }
}
void Top() {
if (head == NULL) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    } else {
    std::cout << "Top of Stack: " << head->data << std::endl;
}
}

void displayAll() {
    if (head == NULL) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }

    std::cout << "Stack elements (top to bottom): ";
    Node *current = head;
    while (current != NULL) {
        std::cout << current->data;
        if (current->next != NULL)
            std::cout << ", ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    push(1);
    std::cout << "After the first PUSH top of stack is: ";
    Top();

    push(5);
    std::cout << "After the second PUSH top of stack is: ";
    Top();

    std::cout << "Current stack: ";
    displayAll();

    pop();
    std::cout << "After the first POP operation, top of stack is: ";
    Top();

    pop();
    std::cout << "After the second POP operation, top of stack is: ";
    Top();

    std::cout << "Current stack: ";
    displayAll();

    pop();
    return 0;
}