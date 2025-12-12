// COMSC-210 | Final 2 | Jasmine Suarez
// IDE used: VS Code

#include <iostream>
using namespace std;

// Milesetone 1
struct Node {
    string name;
    string drink;
    Node* next;
    Node(string n, string d, Node* nxt = nullptr) {
        name = n;
        drink = d;
        next = nxt;
    }
};

int main() {

    string names[] = {
    "Aiden", "Bella", "Carlos", "Diana", "Evan",
    "Fiona", "George", "Hana", "Ivan", "Jasmine"
    };

    string drinks[] = {
    "Latte", "Mocha", "Americano", "Espresso",
    "Cappuccino", "Matcha Latte", "Chai Tea", "Hot Chocolate"
    };

    return 0;
}