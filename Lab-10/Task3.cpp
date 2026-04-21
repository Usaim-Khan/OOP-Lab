#include <iostream>
using namespace std;

// ================= BASE CLASS =================
class Event {
protected:
    string name;
    string date;
    string venue;

public:
    Event(string n, string d, string v) {
        name = n;
        date = d;
        venue = v;
    }

    // Overloaded virtual functions
    virtual double calculateTicketPrice(int tier) = 0;              // Concert
    virtual double calculateTicketPrice(bool isSpeaker) = 0;        // Conference
    virtual double calculateTicketPrice(string category) = 0;       // Exhibition

    virtual void display() {
        cout << "\nEvent: " << name
             << "\nDate: " << date
             << "\nVenue: " << venue << endl;
    }

    virtual ~Event() {}
};

// ================= CONCERT =================
class Concert : public Event {
public:
    Concert(string n, string d, string v) : Event(n, d, v) {}

    double calculateTicketPrice(int tier) override {
        if (tier == 1) return 5000;     // VIP
        else if (tier == 2) return 3000; // Regular
        else return 1500;               // Economy
    }

    double calculateTicketPrice(bool) override { return 0; }
    double calculateTicketPrice(string) override { return 0; }
};

// ================= CONFERENCE =================
class Conference : public Event {
public:
    Conference(string n, string d, string v) : Event(n, d, v) {}

    double calculateTicketPrice(bool isSpeaker) override {
        if (isSpeaker) return 0;     // Speakers free
        else return 2000;            // Attendees pay
    }

    double calculateTicketPrice(int) override { return 0; }
    double calculateTicketPrice(string) override { return 0; }
};

// ================= EXHIBITION =================
class Exhibition : public Event {
public:
    Exhibition(string n, string d, string v) : Event(n, d, v) {}

    double calculateTicketPrice(string category) override {
        if (category == "Adult") return 1000;
        else if (category == "Student") return 500;
        else return 300; // Child
    }

    double calculateTicketPrice(int) override { return 0; }
    double calculateTicketPrice(bool) override { return 0; }
};

// ================= MAIN =================
int main() {
    // Array of base class pointers (no vector)
    Event* events[3];

    // Populate array
    events[0] = new Concert("Rock Concert", "10-May-2026", "GlobaArena");
    events[1] = new Conference("Business Conference", "15-May-2026", "GlobaArena");
    events[2] = new Exhibition("Art Exhibition", "20-May-2026", "GlobaArena");

    // Iterate and demonstrate late binding
    for (int i = 0; i < 3; i++) {
        events[i]->display();

        if (i == 0) {
            cout << "Ticket Price (Tier 1): "
                 << events[i]->calculateTicketPrice(1) << endl;
        }
        else if (i == 1) {
            cout << "Ticket Price (Attendee): "
                 << events[i]->calculateTicketPrice(false) << endl;
        }
        else if (i == 2) {
            cout << "Ticket Price (Student): "
                 << events[i]->calculateTicketPrice("Student") << endl;
        }
    }

    // Cleanup
    for (int i = 0; i < 3; i++) {
        delete events[i];
    }

    return 0;
}