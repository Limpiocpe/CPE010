#include <iostream>
#include <string.h>

// Problem 1 - Create a class for fruit and vegetables
class Fruits {

private:
    std::string name;
    double price;
    int quantity;

public:

    // Constructor
    Fruits(std::string fName = "", double fPrice = 0, int fQuan = 0) {
        name = fName;
        price = fPrice;
        quantity = fQuan;

        std::cout << "Fruit Constructor Called\n";
    }

    // Destructor
    ~Fruits() {
        std::cout << "Fruit Destructor Called\n";
    }

    // Copy Constructor
    Fruits(const Fruits &copy) {
        std::cout << "Fruit Copy Constructor Called\n";

        name = copy.name;
        price = copy.price;
        quantity = copy.quantity;
    }

    //Copy Assignment Operator
    Fruits& operator=(const Fruits &copy) {

        if (this != &copy) {
            std::cout << "Fruit Copy Assignment Called\n";

            name = copy.name;
            price = copy.price;
            quantity = copy.quantity;
        }

        return *this;
    }

    //For problem 3 - calculate total grocery cost
    double totalSum() const {
        return price * quantity;
    }

    void printDetails() const {

        std::cout << "Fruit:  " << name
                  << "\n\tPrice: " << price << " PHP"
                  << "\n\tQuantity: " << quantity
                  << "\n\tTotal: " << totalSum()
                  << std::endl;
    }
};

class Vegetables {

private:
    std::string name;
    double price;
    int quantity;

public:

    //Constructor
    Vegetables(std::string vName = "", double vPrice = 0, int vQuan = 0) {

        name = vName;
        price = vPrice;
        quantity = vQuan;

        std::cout << "Vegetable Constructor Called\n";
    }

    //Destructor
    ~Vegetables() {
        std::cout << "Vegetable Destructor Called\n";
    }

    // Copy Constructor
    Vegetables(const Vegetables &copy) {

        name = copy.name;
        price = copy.price;
        quantity = copy.quantity;

        std::cout << "Vegetable Copy Constructor Called\n";
    }

    //Copy Assignment Operator
    Vegetables& operator=(const Vegetables &copy) {

        if (this != &copy) {
            std::cout << "Vegetable Copy Assignment Called\n";

            name = copy.name;
            price = copy.price;
            quantity = copy.quantity;
        }

        return *this;
    }

    double totalSum() const {

        return price * quantity;
    }

    void printDetails() const {

        std::cout << "Vegetable: " << name
                  << "\n\t   Price: " << price << " PHP"
                  << "\n\t   Quantity: " << quantity
                  << "\n\t   Total: " << totalSum()
                  << std::endl;
    }
};

//For problem 3 - Calculate grocery total cost
double TotalSum(Fruits* fruits[], int fQuan,
                Vegetables* vegetables[], int vQuan) {

    double total = 0;

    for(int i = 0; i < fQuan; i++) {
        if(fruits[i] != nullptr)
            total += fruits[i]->totalSum();
    }

    for(int i = 0; i < vQuan; i++) {
        if(vegetables[i] != nullptr)
            total += vegetables[i]->totalSum();
    }

    return total;
}

int main() {

    Fruits *apple = new Fruits("Apple", 10, 7);
    Fruits *banana = new Fruits("Banana", 10, 8);

    Vegetables *broccoli = new Vegetables("Broccoli", 60, 12);
    Vegetables *lettuce = new Vegetables("Lettuce", 50, 10);

    // Problem 2 - Array for Grocery List
    Fruits* fruits[] = {apple, banana};
    Vegetables* vegetables[] = {broccoli, lettuce};

    std::cout << "\n==========================\n|| Jenna's Grocery List ||\n==========================\n";

    //Display all fruits
    for(int i = 0; i < 2; i++) {
        fruits[i]->printDetails();
    }

    //Display all vegetables
    for(int i = 0; i < 2; i++) {
        vegetables[i]->printDetails();
    }

    //Problem 3 - Total Sum of all grocery
    std::cout << "\nTotal Amount = PHP "
              << TotalSum(fruits, 2, vegetables, 2)
              << std::endl << std::endl;

    //Problem 4 - Delete Lettuce
    delete vegetables[1];
    vegetables[1] = nullptr;

    std::cout << "\nAfter deleting Lettuce\n\n";

    std::cout << "Updated Total = PHP "
              << TotalSum(fruits, 2, vegetables, 2)
              << std::endl << std::endl;

    delete apple;
    delete banana;
    delete broccoli;

    return 0;
}