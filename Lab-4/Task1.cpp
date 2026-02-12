#include <iostream>
#include <string>
using namespace std;


class Novel{
    private:
        string title;
        string author;
        int cost;

    public:
        Novel(){}
        Novel(string t, string a, int c){
            title = t;
            author = a;
            cost = c;
        }
        ~Novel(){
            cout << "Destructor for Novel" << endl;
        }
        void display() const {
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Cost: " << cost << endl;
        }
};

int main(){
    Novel array[3] = {
        Novel("The Great Gatsby", "F. Scott Fitzgerald", 10),
        Novel("To Kill a Mockingbird", "Harper Lee", 12),
        Novel("1984", "George Orwell", 15)
    };

    cout << "Displaying all novels:" << endl << endl ;
    for (int i =0 ;i<3; i++){
        array[i].display();
    }
    return 0;

}