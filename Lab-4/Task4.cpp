#include <iostream>
#include <string>
using namespace std;

class Event {
private:
    string eventName;
    int eventID;
    string date;
    string time;
    string venue;
    string category;

public:
    static int totalEvents;
    static const int maxEvents = 3;


    Event() : eventID(0) {} 
    Event(string eventName, int eventID,
          string date, string time,
          string venue, string category)
    {
        this->eventName = eventName;
        this->eventID = eventID;
        this->date = date;
        this->time = time;
        this->venue = venue;
        this->category = category;

        totalEvents++;
    }


    ~Event() {
        cout << "Destructor for Event: " << eventName << endl;
    }

    static bool canAddEvent() {
        return totalEvents < maxEvents;
    }

    void display() const {
        cout << "Event Name: " << eventName << endl;
        cout << "Event ID: " << eventID << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
        cout << "Venue: " << venue << endl;
        cout << "Category: " << category << endl;
        cout << "---------------------------" << endl;
    }
};

int Event::totalEvents = 0;


int main() {
    Event events[Event::maxEvents];
    int count = 0;

    if (Event::canAddEvent()) {
        events[count++] = Event("Tech Conference", 101,
                                 "2024-08-10", "10:00 AM",
                                 "Expo Center", "Technology");
    }

    if (Event::canAddEvent()) {
        events[count++] = Event("Music Concert", 102,
                                 "2024-09-01", "07:00 PM",
                                 "City Stadium", "Entertainment");
    }

    if (Event::canAddEvent()) {
        events[count++] = Event("Art Exhibition", 103,
                                 "2024-09-15", "11:00 AM",
                                 "Art Gallery", "Culture");
    }

    if (!Event::canAddEvent()) {
        cout << "Maximum number of events reached." << endl;
    }

    cout << "\nEvent Details:\n";
    for (int i = 0; i < count; i++) {
        events[i].display();
    }

    cout << "Total Events: " << Event::totalEvents << endl;

    return 0;
}
