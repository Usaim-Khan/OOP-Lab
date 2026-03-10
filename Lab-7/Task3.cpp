#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title;
    string author;
    int year;

public:
    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    virtual void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << year << endl;
    }
};

class ReferenceBook : public Book {
private:
    string topic;

public:
    ReferenceBook(string t, string a, int y, string tp)
        : Book(t, a, y) {
        topic = tp;
    }

    void display() const override {
        Book::display();
        cout << "Topic: " << topic << endl;
    }
};

int main() {

    ReferenceBook r1("Data Structures Handbook", "John Smith", 2018, "Algorithms");
    r1.display();

    return 0;
}