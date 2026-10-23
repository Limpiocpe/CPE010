#include <iostream>
#include <string>
class Node {
public:
    char data;
    Node* next;
};
Node *head = NULL, *tail = NULL;

void push(char newData) {
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
char pop() {
    char tempVal;
    Node *temp;

    if (head == NULL) {
        head = tail = NULL;
        return '\0';
    } else {
        temp = head;
        tempVal = temp->data;
        head = head->next;
        delete temp;
        return tempVal;
    }
}
bool isEmpty() {
    if (head == NULL)
        return true;
    return false;
}

bool isOpeningSymbol(char c) {
    return (c == '(' || c == '{' || c == '[');
}
bool isClosingSymbol(char c) {
    return (c == ')' || c == '}' || c == ']');
}
bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool checkBalance(std::string expr) {
    // reset stack for each new expression
    while (!isEmpty()) pop();

    for (size_t idx = 0; idx < expr.length(); idx++) {
        char ch = expr[idx];

        // a) If the character read is not a symbol to be balanced, ignore it.
        if (!isOpeningSymbol(ch) && !isClosingSymbol(ch))
            continue;

        // b) If the character is an opening symbol, push it onto the stack.
        if (isOpeningSymbol(ch)) {
            push(ch);
        }
        // c) If it is a closing symbol
        else if (isClosingSymbol(ch)) {
            // i) Report an error if the stack is empty.
            if (isEmpty()) {
                std::cout << "Error: Unmatched closing symbol '" << ch
                    << "' at position " << idx << " (stack empty)." << std::endl;
                return false;
            }
            // ii) Otherwise, pop the stack.
            char popped = pop();

            // d) If the symbol popped is not the corresponding opening symbol, report an error.
            if (!isMatchingPair(popped, ch)) {
                std::cout << "Error: Mismatched symbols. Popped '" << popped
                    << "' does not match closing '" << ch
                    << "' at position " << idx << "." << std::endl;
                return false;
            }
        }
    }

    // 3. At the end of input, if the stack is not empty: report an error.
    if (!isEmpty()) {
        std::cout << "Error: Stack not empty at end of input. Unclosed symbol(s) remain." << std::endl;
        return false;
    }

    return true;
}

int main() {
    std::string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };

    for (const auto &expr : expressions) {
        std::cout << "========================================" << std::endl;
        std::cout << "Expression: " << expr << std::endl;
        bool balanced = checkBalance(expr);
        std::cout << "Result: " << (balanced ? "VALID (Balanced)" : "INVALID (Not Balanced)") << std::endl;
    }

    return 0;
}