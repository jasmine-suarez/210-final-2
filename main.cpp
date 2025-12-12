// COMSC-210 | Final 2 | Jasmine Suarez
// IDE used: VS Code

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>
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
void printCoffeeQueue(Node*);

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

    string muffins[] = {
        "Blueberry Muffin", "Chocolate Chip Muffin", "Banana Nut Muffin",
        "Lemon Poppy Seed Muffin", "Chocolate Muffin"
    };

    // Coffee Booth
    Node* head = nullptr;
    Node* tail = nullptr;

    // Muffin Booth
    deque<string> muffinQueue;

    // Friendship Bracelet Booth
    vector<string> braceletQueue;

    // Coffee Booth Simulation
    for (int i = 0; i < INITIAL_SIZE; i++) {
        string newName = names[rand() % 15];
        string newDrink = drinks[rand() % 8];
        addTail(head, tail, newName, newDrink);
        cout << "    " << newName << " joins the line\n";
    }

    // Muffin Booth Simulation
    for (int i = 0; i < INITIAL_SIZE; i++) {
        muffinQueue.push_back(muffins[rand() % 5]);
    }

    for (int round = 1; round <= 10; round++) {
        cout << "\nRound " << round << ":\n";

        // COFFEE BOOTH
        // 50% chance a new person joins the queue
        if (rand() % 2 == 0) {
            string newName = names[rand() % 15];
            string newDrink = drinks[rand() % 8];
            addTail(head, tail, newName, newDrink);
            cout << "    " << newName << " joins the coffee line\n";
        }

        // Head of queue is served unless empty
        if (head != nullptr) {
            cout << "    " << head->name << " is served a(n) "
                 << head->drink << endl;
            serveHead(head, tail);
        }
        else
            cout << "    No one is in the coffee line to be served.\n";

        printCoffeeQueue(head);

        // MUFFIN BOOTH
        // 50% chance a new person is joins
        if (rand() % 2 == 0) {
            string newName = names[rand() % 15];
            string newMuffin = muffins[rand() % 5];
            muffinQueue.push_back(newName + " with a " + newMuffin);
            cout << "    " << newName << " joins the muffin line\n";
        }

        // Head of queue is served unless empty
        if (!muffinQueue.empty()) {
            cout << "    " << muffinQueue.front() << " is served a muffin.\n";
            muffinQueue.pop_front();
        }
        else {
            cout << "    No one is in the muffin line to be served.\n";
        }

        // FRIENDSHIP BRACELET BOOTH
        // 50% chance a new person joins the queue
        if (rand() % 2 == 0) {

        }
        // Head of queue is served unless empty
        if (!braceletQueue.empty()) {
            cout << "    " << braceletQueue.front() << " is served a friendship bracelet\n";
            braceletQueue.erase(braceletQueue.begin());
        }
        else {
            cout << "    No one is in the friendship bracelet line to be served.\n";
        }

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

void printCoffeeQueue(Node* head) {
    Node* current = head;
    cout << "\nCoffee Queue:\n";
    while (current != nullptr) {
        cout << "    " << current->name << " with a " << current->drink << endl;
        current = current->next;
    }
    cout << endl;
}