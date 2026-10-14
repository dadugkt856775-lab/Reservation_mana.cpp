
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

struct Passenger {
    int bookingID;
    string name;
    int age;
    int seatNumber;
};

int main() {
    vector<Passenger> passengers;
    map<int, Passenger> bookings;
    set<int> availableSeats;

    const int TOTAL_SEATS = 20;
    int nextBookingID = 1001;
    int choice;

    for (int i = 1; i <= TOTAL_SEATS; i++) {
        availableSeats.insert(i);
    }

    do {
        cout << "\n===== BUS RESERVATION SYSTEM =====\n";
        cout << "1. Book Seat\n";
        cout << "2. Cancel Booking\n";
        cout << "3. Display Bookings\n";
        cout << "4. Search Booking\n";
        cout << "5. Display Available Seats\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (availableSeats.empty()) {
                cout << "Sorry! All seats are booked.\n";
                continue;
            }

            Passenger p;

            cout << "Enter Passenger Name: ";
            cin.ignore();
            getline(cin, p.name);

            cout << "Enter Passenger Age: ";
            cin >> p.age;

            if (p.age <= 0 || p.age > 120) {
                cout << "Invalid age!\n";
                continue;
            }

            cout << "\nAvailable Seats: ";
            for (int seat : availableSeats) {
                cout << seat << " ";
            }

            cout << "\nEnter Seat Number: ";
            cin >> p.seatNumber;

            auto it = availableSeats.find(p.seatNumber);

            if (it == availableSeats.end()) {
                cout << "Seat unavailable or invalid!\n";
                continue;
            }

            p.bookingID = nextBookingID++;

            bookings[p.bookingID] = p;
            passengers.push_back(p);
            availableSeats.erase(it);

            cout << "\nBooking Successful!\n";
            cout << "Booking ID: " << p.bookingID << "\n";
            cout << "Passenger: " << p.name << "\n";
            cout << "Seat Number: " << p.seatNumber << "\n";
        }
        else if (choice == 2) {
            int id;

            cout << "Enter Booking ID to cancel: ";
            cin >> id;

            auto it = bookings.find(id);

            if (it == bookings.end()) {
                cout << "Booking not found!\n";
                continue;
            }

            int seat = it->second.seatNumber;
            bookings.erase(it);
            availableSeats.insert(seat);

            for (auto p = passengers.begin();
                 p != passengers.end(); ++p) {
                if (p->bookingID == id) {
                    passengers.erase(p);
                    break;
                }
            }

            cout << "Booking cancelled successfully!\n";
            cout << "Seat " << seat << " is now available.\n";
        }
        else if (choice == 3) {
            if (bookings.empty()) {
                cout << "No bookings available.\n";
            }

            for (const auto &item : bookings) {
                const Passenger &p = item.second;

                cout << "\nBooking ID: " << p.bookingID
                     << "\nPassenger: " << p.name
                     << "\nAge: " << p.age
                     << "\nSeat Number: " << p.seatNumber
                     << "\n";
            }
        }
        else if (choice == 4) {
            int id;

            cout << "Enter Booking ID: ";
            cin >> id;

            auto it = bookings.find(id);

            if (it != bookings.end()) {
                const Passenger &p = it->second;

                cout << "\nBooking Found!\n";
                cout << "Name: " << p.name << "\n";
                cout << "Age: " << p.age << "\n";
                cout << "Seat: " << p.seatNumber << "\n";
            }
            else {
                cout << "Booking not found!\n";
            }
        }
        else if (choice == 5) {
            cout << "\nAvailable Seats: ";

            if (availableSeats.empty()) {
                cout << "No seats available.";
            } else {
                for (int seat : availableSeats) {
                    cout << seat << " ";
                }
            }

            cout << "\nTotal Available: "
                 << availableSeats.size() << "\n";
        }
        else if (choice == 6) {
            cout << "Thank you for using the Bus Reservation System!\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
