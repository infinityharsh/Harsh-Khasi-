#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Passenger {
private:
    string name;
    string seatNumber;
public:
    Passenger(const string& n, const string& seat)
        : name(n), seatNumber(seat) {}

    string getName() const {
        return name;
    }

    string getSeatNumber() const {
        return seatNumber;
    }
};

class Flight {
private:
    string flightNumber;
    vector<Passenger> passengers;

public:
    Flight(const string& number) : flightNumber(number) {}

    string getFlightNumber() const {
        return flightNumber;
    }

    void addPassenger(const string& name, const string& seat) {
        passengers.push_back(Passenger(name, seat));
    }

    void displayPassengerList() const {
        cout << "Passenger List for Flight " << flightNumber << ":" << endl;
        cout << "---------------------------------" << endl;
        for (const auto& passenger : passengers) {
            cout << "Name: " << passenger.getName() << ", Seat: " << passenger.getSeatNumber() << endl;
        }
        cout << "---------------------------------" << endl;
    }
};

int main() {
    string flightNumber;
    cout << "Enter Flight Number: ";
    cin >> flightNumber;

    Flight flight(flightNumber);

    string name;
    cout << "Enter Passenger Name: ";
    cin.ignore();
    getline(cin, name);

    string seatNumber;
    cout << "Enter Seat Number: ";
    cin >> seatNumber;

    flight.addPassenger(name, seatNumber);

    cout << "Ticket booked successfully for " << name << " on Flight " << flightNumber <<endl;
    cout << "Happy Journey";
    flight.displayPassengerList();

    return 0;
}