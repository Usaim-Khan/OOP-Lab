#include <iostream>
#include <string>
using namespace std;

class StationaryShop {
private:
    string items[100];
    double prices[100];
    int itemCount;
public:
    void setItemCount(int count) {
        itemCount = count;
    }
    void addItem(string item, double price) {
        items[itemCount] = item;
        prices[itemCount] = price;
        itemCount++;
    }
    void fetchItems() {
        cout << "Items in the shop:" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i] << endl;
        }
    }
    void editPrice(int index, double newPrice) {
        if (index >= 0 && index < itemCount) {
            prices[index] = newPrice;
        } else {
            cout << "Invalid item index." << endl;
        }
    }
    void viewItemsAndPrices() {
        cout << "Items and their prices:" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << items[i] << ": " << prices[i] << endl;
        }
    }
    void generateReceipt(int purchasedItems[], int quantities[], int count) {
        double total = 0;
        cout << "Receipt:" << endl;
        for (int i = 0; i < count; i++) {
            int index = purchasedItems[i];
            double itemTotal = prices[index] * quantities[i];
            total += itemTotal;
            cout << items[index] << " x" << quantities[i] << " - " << itemTotal << endl;
        }
        cout << "Total Amount: " << total << endl;
    }


};    

int main(){
    StationaryShop shop;
    shop.setItemCount(0);
    shop.addItem("Pen", 1.5);
    shop.addItem("Notebook", 3.0);
    shop.addItem("Eraser", 0.5);

    shop.fetchItems();

    shop.editPrice(0, 2.0);

    shop.viewItemsAndPrices();

    int purchasedItems[] = {0, 1}; 
    int quantities[] = {2, 1}; 
    shop.generateReceipt(purchasedItems, quantities, 2);

    return 0;

}
