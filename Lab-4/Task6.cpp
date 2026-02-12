#include <iostream>
using namespace std;

class Book{
    private:
        int id;
        string title;
        string author;
        double price;
        const int maxBooks;
    public:
        static int totalBooks;

        Book(): maxBooks(5) {}
        Book(int i, string t, string a, double p): maxBooks(5){
            if (totalBooks < maxBooks){
                id = i;
                title = t;
                author = a;
                price = p;
                totalBooks++;
            } else {
                cout << "Maximum number of books reached. Book not created." << endl;
                id = 0;
                title = "";
                author = "";
                price = 0.0;
            }
        }
        ~Book(){
            cout << "Destructor for Book" << endl;
        }
        void display() const {
            cout << "Book ID: " << id << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Price: $" << price << endl;
            cout << "---------------------------" << endl;
        }   

};

int Book::totalBooks = 0;   

int main(){
    Book books[6] = {
        Book(1, "The Great Gatsby", "F. Scott Fitzgerald", 10.99),
        Book(2, "To Kill a Mockingbird", "Harper Lee", 8.99),
        Book(3, "1984", "George Orwell", 9.99),
        Book(4, "Pride and Prejudice", "Jane Austen", 7.99),
        Book(5, "The Catcher in the Rye", "J.D. Salinger", 6.99)

    };

    for (int i = 0; i < 5; i++) {
        books[i].display();
    }

    Book book6(6, "The Alchemist", "Paulo Coelho", 12.99);
    book6.display();
    cout << "Total Books Created: " << Book::totalBooks << endl;


}