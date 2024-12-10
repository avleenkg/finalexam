//Final Exam - COMSC-210 - Avleen Gill

#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>
using namespace std;

//creating customer struct for coffee booth
struct Node {
    string name;
    string drinkOrder;
    Node* next;

    Node(string n, string d) { name = n; drinkOrder = d; next = nullptr; }
    Node() {name = ""; drinkOrder = ""; next = nullptr;}
};

//creating customer struct for muffin booth
struct MuffinCustomer{
    string name;
    string muffin;
    MuffinCustomer(string n, string m) { name = n; muffin = m; }
};

//functions for coffee booth
void addcustomer(Node*&, string s, string d);
void servecustomer(Node*&);
void displayline(Node*&); //call in each round

//functions for muffin booth
void addmuffincus(deque<MuffinCustomer>& muffinLine, string name, string muffin);
void servemuffincus(deque<MuffinCustomer>& muffinLine);
void displaymuffinline(deque<MuffinCustomer>& muffinLine);


int main() {
    srand(time(0));

    string names[14] = {"Alice", "Bob", "Ava", "Emily", "John", "Henry", "Frank", "Marc", "Angel", "Angela", "Elizabeth", "Sierra", "Aaron", "Emery"};
    string drinks[8] = {"Latte", "Almondmilk Latte", "Green tea", "Iced tea", "Americano", "Caramel Frap", "Caramel Macchiato", "Vanilla latte"};
    string muffins[7] = {"Blueberry", "Chocolate Chip", "Banana", "Cinnamon", "Vanilla", "Lemon Icing", "Chocolate"};

    //objects
    Node* coffeeLine;
    deque<MuffinCustomer> muffinLine;

    //initializing for coffee
    for (int initialq = 0; initialq < 3; initialq++) {
        string randname = names[rand() % 14];
        string randdrink = drinks[rand() % 8];

        addcustomer(coffeeLine, randname, randdrink);
    }
     //initializing for muffin
    for (int initialq = 0; initialq < 3; initialq++) {
        string randname = names[rand() % 14];
        string randmuffin = muffins[rand() % 7];

        addmuffincus(muffinLine, randname, randmuffin);
    }

    int prob = rand() % 100;

    for (int rounds = 0; rounds < 10; rounds++) {
        cout << "-------Round " << rounds + 1 << "-------\n";

        string randname = names[rand() % 14];
        string randdrink = drinks[rand() % 8];
        string randmuffin = muffins[rand() % 7];

        //coffee line
        if (coffeeLine) {
            cout << "Serving customer:\n";
            servecustomer(coffeeLine);
        }
        else {
            cout << "Line is currently empty.\n";
        }
        if (prob < 50) {
            addcustomer(coffeeLine, randname, randdrink);
        }

        //muffin line
        if (!muffinLine.empty()) {
            cout << "Serving customer:\n";
            servemuffincus(muffinLine);
        }
        else {
            cout << "Line is currently empty.\n";
        }

        displayline(coffeeLine);
        cout << endl;
    }


    return 0;
}

//functions for coffee booth
void addcustomer(Node*& head, string name, string drink){
    Node* newNode = new Node(name, drink);

    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Customer joined line: " << newNode->name << " | " << newNode->drinkOrder << endl;
}
void servecustomer(Node*& head){
    if (!head) {
        return;
    }
    Node* temp = head;
    cout << "Customer: " << temp->name << " is served | " << temp->drinkOrder << endl;
    head = head->next;
    delete temp;
}
void displayline(Node*& head) {
    if (!head) {
        cout << "Line is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Current line queue:\n";
    cout << "\tCustomer name | Drink order\n";
    while (temp) {
        cout << "\t" << temp->name << " | " << temp->drinkOrder << endl;
        temp = temp->next;
    }
    cout << endl;
}

//functions for muffin booth
void addmuffincus(deque<MuffinCustomer>& muffinLine, string name, string muffin) {
    muffinLine.push_back(MuffinCustomer(name, muffin));
    cout << "Customer joined muffin line: " << name << " | " << muffin << endl;
}
void servemuffincus(deque<MuffinCustomer>& muffinLine) {
    if (muffinLine.empty()) {
        return;
    }
    MuffinCustomer head = muffinLine.front();
    cout << "Customer: " << head.name << " | " << head.muffin << endl;
    muffinLine.pop_front();
}
void displaymuffinline(deque<MuffinCustomer>& muffinLine) {
    if (muffinLine.empty()) {
        cout << "Line currently empty.\n";
        return;
    }
    cout << "Current line queue:\n";
    cout << "\tCustomer name | Muffin order\n";
    for (auto customer : muffinLine) {
        cout << "\t" << customer.name << " | " << customer.muffin << endl;
    }
}