#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Product {
private:
    int id;
    string name;
    T price;
    int stock;

public:
    Product() : id(0), name(""), price(T()), stock(0) {}
    Product(int id, const string &name, T price, int stock)
        : id(id), name(name), price(price), stock(stock) {}

    int getId() const { return id; }
    string getName() const { return name; }
    T getPrice() const { return price; }
    int getStock() const { return stock; }
    void setStock(int value) { stock = value; }

    void display() const {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Price: " << price
             << ", Stock: " << stock << '\n';
    }
};

template <typename T>
class Order {
private:
    Product<T> *products;
    int capacity;

public:
    Order(int size) : capacity(size) {
        if (size <= 0) {
            throw invalid_argument("Inventory size must be positive");
        }
        products = new Product<T>[capacity];
    }

    ~Order() {
        delete[] products;
    }

    void addProduct(int index, const Product<T> &product) {
        if (index < 0 || index >= capacity) {
            throw out_of_range("Product index is invalid");
        }
        products[index] = product;
    }

    void displayStock() const {
        cout << "Available bakery stock:\n";
        for (int i = 0; i < capacity; ++i) {
            if (products[i].getId() != 0) {
                products[i].display();
            }
        }
        cout << "\n";
    }

    T placeOrder(int productId, int quantity) {
        try {
            if (quantity <= 0) {
                throw invalid_argument("Quantity must be greater than zero");
            }

            int index = -1;
            for (int i = 0; i < capacity; ++i) {
                if (products[i].getId() == productId) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                throw invalid_argument("Product ID not found");
            }

            Product<T> &product = products[index];
            if (quantity > product.getStock()) {
                throw runtime_error("Requested quantity exceeds available stock");
            }

            int remainingStock = product.getStock() - quantity;
            product.setStock(remainingStock);
            T totalBill = product.getPrice() * quantity;

            cout << "Order placed successfully for product '"
                 << product.getName() << "'\n";
            cout << "Quantity: " << quantity << ", Total bill: " << totalBill << "\n";
            return totalBill;
        }
        catch (const out_of_range &ex) {
            cout << "Error: " << ex.what() << "\n";
        }
        catch (const invalid_argument &ex) {
            cout << "Invalid argument: " << ex.what() << "\n";
        }
        catch (const runtime_error &ex) {
            cout << "Runtime error: " << ex.what() << "\n";
        }
        catch (...) {
            cout << "An unexpected error occurred while placing the order." << "\n";
        }
        return T();
    }
};

int main() {
    try {
        Order<double> bakery(5);

        bakery.addProduct(0, Product<double>(101, "Chocolate Croissant", 2.75, 15));
        bakery.addProduct(1, Product<double>(102, "Blueberry Muffin", 1.95, 20));
        bakery.addProduct(2, Product<double>(103, "Sourdough Bread", 4.50, 10));
        bakery.addProduct(3, Product<double>(104, "Cinnamon Roll", 3.20, 12));
        bakery.addProduct(4, Product<double>(105, "Banana Bread", 3.80, 8));

        bakery.displayStock();

        cout << "Customer order 1:\n";
        bakery.placeOrder(102, 3);

        cout << "Customer order 2:\n";
        bakery.placeOrder(103, 12);

        cout << "Customer order 3:\n";
        bakery.placeOrder(107, 2);

        cout << "Customer order 4:\n";
        bakery.placeOrder(104, 0);
    }
    catch (const exception &ex) {
        cout << "Initialization failed: " << ex.what() << "\n";
    }

    return 0;
}
