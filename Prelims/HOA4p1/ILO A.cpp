#include <iostream>
#include <stack> // Calling Stack from the STL

int main() {
    std::stack<int> newStack;

    newStack.push(3); // Adds 3 to the stack
    newStack.push(8);
    newStack.push(15);

    // returns a boolean response depending on if the stack is empty or not
    std::cout << "Stack Empty? " << newStack.empty() << std::endl;

    // returns the size of the stack itself
    std::cout << "Stack Size: " << newStack.size() <<  std::endl;

    // removes the topmost element of the stack
    newStack.pop();

    std::cout << "Top Element of the Stack: " << newStack.top() << std::endl;

    std::cout << "Stack Size: " << newStack.size() <<  std::endl;

    return 0;
}