// COMSC-210 | Final 2 | Jasmine Suarez
// IDE used: VS Code

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int INITIAL_SIZE = 3;

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

Node* head = nullptr;
Node* tail = nullptr;

int main() {
    srand(time(0));

    string names[] = {
    "Aiden", "Bella", "Carlos", "Diana", "Evan",
    "Fiona", "George", "Hana", "Ivan", "Jasmine",
    "Aaron", "Cheyenne", "Sophia", "Emily", "Max"
    };

    string drinks[] = {
    "Latte", "Mocha", "Americano", "Espresso",
    "Cappuccino", "Matcha Latte", "Chai Tea", "Hot Chocolate"
    };

    // Milestone 2
    cout << "Coffee booth opens:\n";
    for (int i = 0; i < INITIAL_SIZE; i++) {
        string newName = names[rand() % 15];
        string newDrink = drinks[rand() % 8];
    }

    return 0;
}