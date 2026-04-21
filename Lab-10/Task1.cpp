#include <iostream>
#include <string>

template<typename T1, typename T2, typename T3>
class Product {
public:
    T1 ID;
    T2 name;
    T3 price;

    Product() {}
    Product(T1 id, T2 n, T3 p) : ID(id), name(n), price(p) {}
};

template<typename T1, typename T2, typename T3>
class Stock {
private:
    Product<T1, T2, T3>* products;
    int size;

public:
    Stock(int s) : size(s) {
        products = new Product<T1, T2, T3>[size];
    }

    ~Stock() {
        delete[] products;
    }

    void addProduct(int index, T1 id, T2 name, T3 price) {
        if (index >= 0 && index < size) {
            products[index] = Product<T1, T2, T3>(id, name, price);
        }
    }

    T3 calculateTotalCost(int quantity) {
        T3 total = T3(0);
        for (int i = 0; i < size; ++i) {
            total += products[i].price * quantity;
        }
        return total;
    }
};

int main() {
    Stock<int, std::string, double> stock(3);

    stock.addProduct(0, 1, "Product1", 10.0);
    stock.addProduct(1, 2, "Product2", 20.0);
    stock.addProduct(2, 3, "Product3", 30.0);

    int quantity = 5;
    double totalCost = stock.calculateTotalCost(quantity);

    std::cout << "Total cost of the products: " << totalCost << std::endl;

    return 0;
}

