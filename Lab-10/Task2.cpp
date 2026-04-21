#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Theater; // forward declaration

class Seat {
private:
    int row;
    int seatNumber;
    bool reserved;

    void reserve() {
        if (reserved)
            throw runtime_error("Seat already reserved.");
        reserved = true;
    }

    void cancelReservation() {
        if (!reserved)
            throw runtime_error("Seat is not reserved.");
        reserved = false;
    }

    bool getStatus() const {
        return reserved;
    }

public:
    Seat(int r = 0, int s = 0) : row(r), seatNumber(s), reserved(false) {}

    friend class Theater; // Only Theater can modify Seat
};

class Theater {
private:
    vector<vector<Seat>> seats;
    int numRows;
    int numSeatsPerRow;

    bool isValidSeat(int row, int seat) {
        return (row >= 0 && row < numRows &&
                seat >= 0 && seat < numSeatsPerRow);
    }

public:
    void initializeSeats(int rows, int seatsPerRow) {
        numRows = rows;
        numSeatsPerRow = seatsPerRow;

        seats.resize(rows);
        for (int i = 0; i < rows; i++) {
            seats[i].reserve(seatsPerRow);
            for (int j = 0; j < seatsPerRow; j++) {
                seats[i].emplace_back(i, j);
            }
        }
    }

    void viewAvailableSeats() {
        cout << "\nSeating Chart (O = Available, X = Reserved)\n";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numSeatsPerRow; j++) {
                cout << (seats[i][j].getStatus() ? "X " : "O ");
            }
            cout << endl;
        }
    }

    void reserve(int row, int seat) {
        if (!isValidSeat(row, seat))
            throw out_of_range("Invalid seat position.");

        seats[row][seat].reserve();
        cout << "Seat reserved successfully.\n";
    }

    void cancelReservation(int row, int seat) {
        if (!isValidSeat(row, seat))
            throw out_of_range("Invalid seat position.");

        seats[row][seat].cancelReservation();
        cout << "Reservation cancelled successfully.\n";
    }
};

int main() {
    Theater theater;
    theater.initializeSeats(5, 6); // change size if needed

    int choice, row, seat;

    while (true) {
        cout << "\n1. View Seats\n2. Reserve Seat\n3. Cancel Reservation\n4. Exit\nChoice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                theater.viewAvailableSeats();
            }
            else if (choice == 2) {
                cout << "Enter row and seat (0-based index): ";
                cin >> row >> seat;
                theater.reserve(row, seat);
            }
            else if (choice == 3) {
                cout << "Enter row and seat (0-based index): ";
                cin >> row >> seat;
                theater.cancelReservation(row, seat);
            }
            else if (choice == 4) {
                break;
            }
            else {
                cout << "Invalid choice.\n";
            }
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }

        theater.viewAvailableSeats(); // show updated chart
    }

    return 0;
}