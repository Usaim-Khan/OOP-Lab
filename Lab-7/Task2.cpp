#include <iostream>
#include <string>
using namespace std;

class Order {
private:
    string items[100];
    double prices[100];
    int num_items;

public:
    static int total_orders;

    Order() {
        num_items = 0;
        total_orders++;
    }

    void add_item(string item_name, double item_price) {
        items[num_items] = item_name;
        prices[num_items] = item_price;
        num_items++;
    }

    void add_item(string item_name, string size, bool milk, double item_price) {

        if(size == "small")
            item_price = 2.00;
        else if(size == "medium")
            item_price = 3.00;
        else if(size == "large")
            item_price = 4.00;

        if(milk)
            item_price += 0.50;

        items[num_items] = item_name + " (" + size + ")";
        prices[num_items] = item_price;
        num_items++;
    }

    void add_item(string item_name, double item_price, int quantity) {
        double total_price = item_price * quantity;

        items[num_items] = item_name + " x" + to_string(quantity);
        prices[num_items] = total_price;
        num_items++;
    }

    void display_order() {
        cout << "Order Items:\n";
        for(int i = 0; i < num_items; i++) {
            cout << items[i] << " - $" << prices[i] << endl;
        }
    }
};

int Order::total_orders = 0;

int main() {

    Order o1;

    o1.add_item("Croissant", 2.5);
    o1.add_item("Coffee", "medium", true, 0);
    o1.add_item("Tea", 1.5, 3);

    o1.display_order();

    cout << "Total Orders: " << Order::total_orders << endl;

    return 0;
}