#include <iostream>

bool logicalOP(bool A, bool B) {
    std::cout << "\nAll Logical Operations:\n";
    std::cout << "\tA AND B = " << (A && B) << std::endl;
    std::cout << "\tA OR B  = " << (A || B) << std::endl;
    std::cout << "\tNOT A   = " << (!A) << std::endl;
    std::cout << "\tNOT B   = " << (!B) << std::endl;

    return true;
};

int main() {
    bool A, B;

    std::cout << "\t\t  (0 or 1)\nInput value for A: ";
    std::cin >> A;

    std::cout << "Input value for B: ";
    std::cin >> B;

    if (logicalOP(A, B)) {
        std::cout << "\nSuccess. ";
    }

    return 0;
}

