#include <iostream>
#include <string>
using namespace std;

class Reservation {
private:
    string renterName, carModel, rentalStartDate, rentalEndDate;
    int reservationNumber;
    float rentalRate;

public:
    static int totalReservations;
    static const int maxReservations = 3;

    Reservation() : reservationNumber(0), rentalRate(0.0f) {}

    Reservation(string renterName, string carModel,
                string rentalStartDate, string rentalEndDate,
                float rentalRate)
    {
        this->renterName = renterName;
        this->carModel = carModel;
        this->rentalStartDate = rentalStartDate;
        this->rentalEndDate = rentalEndDate;
        this->rentalRate = rentalRate;

        totalReservations++;
        reservationNumber = totalReservations;
    }

    static bool canCreate() {
        return totalReservations < maxReservations;
    }

    void display() const {
        cout << "Reservation Number: " << reservationNumber << endl;
        cout << "Renter Name: " << renterName << endl;
        cout << "Car Model: " << carModel << endl;
        cout << "Start Date: " << rentalStartDate << endl;
        cout << "End Date: " << rentalEndDate << endl;
        cout << "Rate: " << rentalRate << endl;
        cout << "--------------------------" << endl;
    }
};

int Reservation::totalReservations = 0;

int main() {
    Reservation reservations[Reservation::maxReservations];
    int count = 0;

    while (Reservation::canCreate()) {
        reservations[count] = Reservation(
            "John Doe",
            "Toyota Camry",
            "2024-07-01",
            "2024-07-10",
            50.0f
        );

        reservations[count].display();
        count++;
    }

    cout << "Total Reservations: "
         << Reservation::totalReservations << endl;

    return 0;
}
