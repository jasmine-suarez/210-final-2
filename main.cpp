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

void addTail(Node *&, Node *&, string, string);
void serveHead(Node *&, Node *&);

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

    Node* head = nullptr;
    Node* tail = nullptr;

    // Milestone 2
    cout << "Coffee booth opens:\n";
    for (int i = 0; i < INITIAL_SIZE; i++) {
        string newName = names[rand() % 15];
        string newDrink = drinks[rand() % 8];
        addTail(head, tail, newName, newDrink);
        cout << "    " << newName << " joins the line\n";
    }

    for (int round = 1; round <= 10; round++) {
        cout << "\nRound " << round << ":\n";

        // 50% chance a new person joins the queue
        if (rand() % 2 == 0) {
            string newName = names[rand() % 15];
            string newDrink = drinks[rand() % 8];
            addTail(head, tail, newName, newDrink);
            cout << "    " << newName << " joins the line\n";
        }

        // Head of queue is served unless empty
        if (head != nullptr) {
            cout << "    " << head->name << " is served a "
                 << head->drink << endl;
            serveHead(head, tail);
        }
        else
            cout << "    No one is in line to be served.\n";

    }

    return 0;
}

void addTail(Node *&head, Node *&tail, string name, string drink) {
    Node *newNode = new Node(name, drink);
    newNode->next = nullptr;
    if (head == nullptr)
        head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void serveHead(Node *&head, Node *&tail) {
    if (head == nullptr)
        return;

    Node *temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr)
        tail = nullptr;
}