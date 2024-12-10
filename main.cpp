//Final Exam - COMSC-210 - Avleen Gill

#include <iostream>
using namespace std;

//creating customer struct
struct Node {
    string name;
    string drinkOrder;
    Node* next;

    string names[8] = {"Alice", "Bob", "Ava", "Emily", "John", "Henry", "Frank", "Marc"};
    string drinks[8] = {"Latte", "Almondmilk Latte", "Green tea", "Iced tea", "Americano", "Caramel Frap", "Caramel Macchiato", "Vanilla latte"};

    Node(string n, string d) { name = n; drinkOrder = d; next = nullptr; }
};

void addcustomer(Node*&, string s, string d);
void servecustomer;
void displayline;


int main() {



    return 0;
}

void addcustomer(Node*& head, string name, string drink){
    Node* newNode = new Node(name, drink);

    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        w    
    }
}