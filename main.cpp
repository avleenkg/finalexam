//Final Exam - COMSC-210 - Avleen Gill

#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>
#include <vector>
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

//creating customer struct for bracelet booth
struct BraceletCus{
    string name;
    string color;
    BraceletCus(string n, string c) { name = n; color = c; }
};

//functions for coffee booth
void addcustomer(Node*&, string s, string d);
void servecustomer(Node*&);
void displayline(Node*&); //call in each round

//functions for muffin booth
void addmuffincus(deque<MuffinCustomer>& muffinLine, string name, string muffin);
void servemuffincus(deque<MuffinCustomer>& muffinLine);
void displaymuffinline(deque<MuffinCustomer>& muffinLine);

//functions for bracelet booth
void addbraceletcus(vector<BraceletCus>& braceletLine, string name, string color);
void servebraceletcus(vector<BraceletCus>& braceletLine);
void displaybraceletline(vector<BraceletCus>& braceletLine);


int main() {
    srand(time(0));

    string names[29] = {"Alice", "Bob", "Ava", "Emily", "John", "Henry", "Frank", "Marc", "Angel", "Angela", "Elizabeth", "Sierra", "Aaron", "Emery", "Sophia", "James", "Michael", "Isabella", "Olivia", "Ethan", "Daniel", "Mia", "David", "Charlotte", "William", "Benjamin", "Amelia", "Lucas", "Madison"};
    string drinks[24] = {"Latte", "Almondmilk Latte", "Green tea", "Iced tea", "Americano", "Caramel Frap", "Caramel Macchiato", "Vanilla latte", "Mocha", "Espresso", "Cappuccino", "Chai Latte", "Flat White", "Macchiato", "Cold Brew", "Honey Latte", "Matcha Latte", "Iced Coffee", "Turmeric Latte", "Irish Coffee", "Peach Tea", "Lemonade", "Raspberry Iced Tea", "Coconut Milk Latte"};
    string muffins[22] = {"Blueberry", "Chocolate Chip", "Banana", "Cinnamon", "Vanilla", "Lemon Icing", "Chocolate", "Apple Cinnamon", "Raisin", "Strawberry", "Carrot", "Poppy Seed", "Pumpkin", "Maple Pecan", "Peach", "Orange", "Peanut Butter", "Cherry", "Lemon Poppy", "Almond", "Oatmeal", "Zucchini"};
    string braceletcolors[26] = {"Blue", "Red", "Pink", "Aqua", "Beige", "Cream", "Brown", "Black", "Gray", "White", "Purple", "Turquoise", "Yellow", "Green", "Orange", "Silver", "Gold", "Copper", "Lavender", "Fuchsia", "Emerald", "Teal", "Ivory", "Maroon", "Coral", "Charcoal"};
    
    //objects
    Node* coffeeLine = nullptr;
    deque<MuffinCustomer> muffinLine;
    vector<BraceletCus> braceletLine;

    //initializing for coffee
    for (int initialq = 0; initialq < 3; initialq++) {
        string randname = names[rand() % 29];
        string randdrink = drinks[rand() % 24];

        addcustomer(coffeeLine, randname, randdrink);
    }
    //initializing for muffin
    for (int initialq = 0; initialq < 3; initialq++) {
        string randname = names[rand() % 29];
        string randmuffin = muffins[rand() % 22];

        addmuffincus(muffinLine, randname, randmuffin);
    }
    //initializing for bracelets
    for (int initialq = 0; initialq < 3; initialq++) {
        string randname = names[rand() % 29];
        string randcolor = braceletcolors[rand() % 26];

        addbraceletcus(braceletLine, randname, randcolor);
    }

    int prob = rand() % 100;

    for (int rounds = 0; rounds < 10; rounds++) {
        cout << "-------Round " << rounds + 1 << "-------\n";

        string randname = names[rand() % 29];
        string randdrink = drinks[rand() % 24];
        string randmuffin = muffins[rand() % 22];
        string randcolor = braceletcolors[rand() % 26];

        //coffee line
        if (coffeeLine) {
            cout << "Serving coffee customer:\n";
            servecustomer(coffeeLine);
        }
        else {
            cout << "Coffee line is currently empty.\n";
        }

        //muffin line
        if (!muffinLine.empty()) {
            cout << "Serving muffin customer:\n";
            servemuffincus(muffinLine);
        }
        else {
            cout << "Muffin line is currently empty.\n";
        }

        //bracelet booth
        if (!braceletLine.empty()) {
            cout << "Serving bracelet customer:\n";
            servebraceletcus(braceletLine);
        }
        else {
            cout << "Bracelet line is currently empty.\n";
        }

        //combined
        if (prob < 50) {
            //generate random for coffee
            string randcoffeename = names[rand() % 29];
            string randdrink = drinks[rand() % 24];
            addcustomer(coffeeLine, randname, randdrink);

            //generate random for muffin
            string randmuffinname = names[rand() % 29];
            string randmuffin = muffins[rand() % 22];
            addmuffincus(muffinLine, randname, randmuffin);

            string randbraceletname = names[rand() % 29];
            string randbraceletcolor = braceletcolors[rand() % 26];
            addbraceletcus(braceletLine, randbraceletname, randbraceletcolor);
        }

        //display
        cout << "Displaying...\n";
        displayline(coffeeLine); cout << endl;
        displaymuffinline(muffinLine); cout << endl;
        displaybraceletline(braceletLine); cout << endl;

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
    cout << "Customer joined coffee line: " << newNode->name << " | " << newNode->drinkOrder << endl;
}
void servecustomer(Node*& head){
    if (!head) {
        return;
    }
    Node* temp = head;
    cout << "Customer: " << temp->name << " | " << temp->drinkOrder << endl;
    head = head->next;
    delete temp;
}
void displayline(Node*& head) {
    if (!head) {
        cout << "Coffee line is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Current coffee line queue:\n";
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
        cout << "Muffin line currently empty.\n";
        return;
    }
    cout << "Current muffin line queue:\n";
    cout << "\tCustomer name | Muffin order\n";
    for (auto customer : muffinLine) {
        cout << "\t" << customer.name << " | " << customer.muffin << endl;
    }
}

//functions for bracelet booth
void addbraceletcus(vector<BraceletCus>& braceletLine, string name, string color){
    braceletLine.push_back(BraceletCus(name, color));
    cout << "Customer joined bracelet line: " << name << " | " << color << endl;
}
void servebraceletcus(vector<BraceletCus>& braceletLine){
    if (braceletLine.empty()){
        return;
    }
    BraceletCus head = braceletLine.front();
    cout << "Customer: " << head.name << " | " << head.color << endl;
    braceletLine.erase(braceletLine.begin());
}
void displaybraceletline(vector<BraceletCus>& braceletLine){
    if (braceletLine.empty()) {
        cout << "Bracelet line is currently empty.\n";
        return;
    }
    cout << "Current bracelet line queue:\n";
    cout << "\tCustomer name | Bracelet color\n";
    for (auto customer : braceletLine) {
        cout << "\t" << customer.name << " | " << customer.color << endl;
    }
    cout << endl;
}