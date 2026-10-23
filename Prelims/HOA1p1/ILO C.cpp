#include <iostream>

int main() {
	int A, B, C;
	
	std::cout << "Enter value for A: ";
	std::cin >> A; 
	std::cout << "Enter value for B: ";
	std::cin >> B;
	
	std::cout << "Values before swap: \n\tA: " << A << "\n\tB: " << B << std::endl ;
	C = B;
	B = A;
	A = C;
	std::cout << "Values after swap: \n\tA: " << A << "\n\tB: "  << B;
}
