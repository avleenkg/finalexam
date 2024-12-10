//Final Exam - COMSC-210 - Avleen Gill

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//creating customer struct
struct Node {
    string name;
    string drinkOrder;
    Node* next;

    Node(string n, string d) { name = n; drinkOrder = d; next = nullptr; }
    Node() {name = ""; drinkOrder = ""; next = nullptr;}
};

void addcustomer(Node*&, string s, string d);
void servecustomer(Node*&);
void displayline(Node*&); //call in each round


int main() {
    srand(time(0));

    string names[8] = {"Alice", "Bob", "Ava", "Emily", "John", "Henry", "Frank", "Marc"};
    string drinks[8] = {"Latte", "Almondmilk Latte", "Green tea", "Iced tea", "Americano", "Caramel Frap", "Caramel Macchiato", "Vanilla latte"};

    Node* coffeeLine;
    for (int initialq = 0; initialq < 3; initialq++) {
        string randname = names[rand() % 8];
        string randdrink = drinks[rand() % 8];

        addcustomer(coffeeLine, randname, randdrink);
    }
    int prob = rand() % 100;
    for (int rounds = 0; rounds < 10; rounds++) {
        cout << "-------Round " << rounds + 1 << "-------\n";

        if (coffeeLine) {
            cout << "Serving customer:\n";
            servecustomer(coffeeLine);
        }
        else {
            cout << "Line is currently empty.\n";
        }
        if (prob < 50) {
            addcustomer(coffeeLine, rand)
        }
    }




    return 0;
}

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
    while (temp) {
        cout << "\t" << temp->name << " | " << temp->drinkOrder << endl;
        temp = temp->next;
    }
    cout << endl;
}