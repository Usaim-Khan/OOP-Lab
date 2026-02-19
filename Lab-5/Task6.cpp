#include <iostream>
#include <string>
using namespace std;

class MenuItem {
    private:
        string name;
        double price;

    public:
        MenuItem(string n = "", double p = 0.0) {
            name = n;
            price = p;
        }

        void setName(string n) {
            name = n;
        }

        void setPrice(double p) {
            price = p;
        }

        string getName() {
            return name;
        }

        double getPrice() {
            return price;
        }

        void display() {
            cout << "  " << name << " - $" << price << endl;
        }
};

class Menu {
    private:
        MenuItem menuItems[100];
        int itemCount;
        static int MaxItems;

    public:
        Menu() : itemCount(0) {}

        void addItem(MenuItem item) {
            if (itemCount >= MaxItems) {
                cout << "Cannot add more items. Menu is full!" << endl;
                return;
            }
            menuItems[itemCount++] = item;
        }

        void removeItem(string iName) {
            for (int i = 0; i < itemCount; i++) {
                if (menuItems[i].getName() == iName) {
                    for (int j = i; j < itemCount - 1; j++) {
                        menuItems[j] = menuItems[j + 1];
                    }
                    cout << "Item '" << iName << "' removed from menu." << endl;
                    itemCount--;
                    return;
                }
            }
            cout << "Item not found in menu." << endl;
        }

        MenuItem getItem(string iName) {
            for (int i = 0; i < itemCount; i++) {
                if (menuItems[i].getName() == iName) {
                    return menuItems[i];
                }
            }
            return MenuItem("", -1);
        }

        void displayMenu() {
            cout << "\n========== MENU ==========" << endl;
            if (itemCount == 0) {
                cout << "Menu is empty." << endl;
            } else {
                for (int i = 0; i < itemCount; i++) {
                    cout << (i + 1) << ". ";
                    menuItems[i].display();
                }
            }
            cout << "========================" << endl;
        }

        int getItemCount() {
            return itemCount;
        }

        MenuItem getItemAt(int index) {
            if (index >= 0 && index < itemCount) {
                return menuItems[index];
            }
            return MenuItem("", -1);
        }
};

int Menu::MaxItems = 100;

class Payment {
    private:
        double total;

    public:
        Payment() : total(0.0) {}

        void calculateTotal(MenuItem items[], int n) {
            total = 0.0;
            for (int i = 0; i < n; i++) {
                total += items[i].getPrice();
            }
        }

        void displayTotal() {
            cout << "Total Amount: $" << total << endl;
        }

        double getTotal() {
            return total;
        }
};

class Order {
    private:
        MenuItem* orderedItems;
        int totalItems;
        Payment payment;
        int orderId;

    public:
        Order(int n, int id) : totalItems(n), orderId(id) {
            orderedItems = new MenuItem[n];
        }

        void addOrderItem(MenuItem item, int index) {
            if (index >= 0 && index < totalItems) {
                orderedItems[index] = item;
            }
        }

        void calculatePayment() {
            payment.calculateTotal(orderedItems, totalItems);
        }

        void displayOrder() {
            cout << "\n========== ORDER #" << orderId << " ==========" << endl;
            cout << "Items Ordered:" << endl;
            for (int i = 0; i < totalItems; i++) {
                cout << "  " << (i + 1) << ". ";
                orderedItems[i].display();
            }
            cout << "\n";
            payment.displayTotal();
            cout << "========================" << endl;
        }

        double getTotal() {
            return payment.getTotal();
        }

        ~Order() {
            delete[] orderedItems;
        }
};

class Restaurant {
    private:
        Menu menu;
        Order* orders[50];
        int orderCount;
        string restaurantName;

    public:
        Restaurant(string name) : orderCount(0), restaurantName(name) {
            for (int i = 0; i < 50; i++) {
                orders[i] = nullptr;
            }
        }

        void setRestaurantName(string name) {
            restaurantName = name;
        }

        string getRestaurantName() {
            return restaurantName;
        }

        void addMenuItems(MenuItem item) {
            menu.addItem(item);
        }

        void displayMenu() {
            cout << "\n ========== " << restaurantName << " ==========" << endl;
            menu.displayMenu();
        }

        Order* placeOrder(int numOfItems) {
            if (orderCount >= 50) {
                cout << "Cannot place more orders!" << endl;
                return nullptr;
            }

            Order* newOrder = new Order(numOfItems, orderCount + 1);
            int itemIndex = 0;

            cout << "\n--- Placing Order #" << (orderCount + 1) << " ---" << endl;
            cout << "Select items by number from the menu:" << endl;

            for (int i = 0; i < numOfItems; i++) {
                int choice;
                cout << "Enter item number " << (i + 1) << ": ";
                cin >> choice;

                if (choice > 0 && choice <= menu.getItemCount()) {
                    MenuItem selectedItem = menu.getItemAt(choice - 1);
                    newOrder->addOrderItem(selectedItem, itemIndex);
                    itemIndex++;
                } else {
                    cout << "Invalid selection. Please try again." << endl;
                    i--;
                }
            }

            newOrder->calculatePayment();
            orders[orderCount] = newOrder;
            orderCount++;

            return newOrder;
        }

        void displayAllOrders() {
            cout << "\n========== ALL ORDERS ==========" << endl;
            for (int i = 0; i < orderCount; i++) {
                if (orders[i] != nullptr) {
                    orders[i]->displayOrder();
                }
            }
        }

        ~Restaurant() {
            for (int i = 0; i < orderCount; i++) {
                if (orders[i] != nullptr) {
                    delete orders[i];
                }
            }
        }
};

int main() {

    Restaurant restaurant("Gourmet Delights");
    restaurant.setRestaurantName("Gourmet Delights");


    cout << "========== ADDING ITEMS TO MENU ==========" << endl;
    restaurant.addMenuItems(MenuItem("Burger", 12.99));
    restaurant.addMenuItems(MenuItem("Pizza", 14.99));
    restaurant.addMenuItems(MenuItem("Pasta", 13.49));
    restaurant.addMenuItems(MenuItem("Salad", 9.99));
    restaurant.addMenuItems(MenuItem("Soda", 2.99));
    cout << "Items added to menu successfully!" << endl;


    restaurant.displayMenu();


    cout << "\n========== ORDER 1 ==========" << endl;
    Order* order1 = restaurant.placeOrder(2);

    cout << "\n========== ORDER 2 ==========" << endl;
    Order* order2 = restaurant.placeOrder(3);

    restaurant.displayAllOrders();

    return 0;
}