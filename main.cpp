#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Room {
public:
    int roomNumber;
    string roomType;
    double price;
    bool isAvailable;

    Room(int number, string type, double price) : roomNumber(number), roomType(type), price(price), isAvailable(true) {}
};

class Customer {
public:
    int customerId;
    string name;
    string email;

    Customer(int id, string name, string email) : customerId(id), name(name), email(email) {}
};

class Booking {
public:
    int bookingId;
    int customerId;
    int roomNumber;
    string checkInDate;
    string checkOutDate;

    Booking(int id, int custId, int roomNum, string checkIn, string checkOut)
        : bookingId(id), customerId(custId), roomNumber(roomNum), checkInDate(checkIn), checkOutDate(checkOut) {}
};

class HotelManagementSystem {
private:
    vector<Room> rooms;
    vector<Customer> customers;
    vector<Booking> bookings;
    int bookingCounter;

public:
    HotelManagementSystem() : bookingCounter(0) {}

    void addRoom(int number, string type, double price) {
        rooms.emplace_back(number, type, price);
    }

    void addCustomer(int id, string name, string email) {
        customers.emplace_back(id, name, email);
    }

    void bookRoom(int customerId, int roomNumber, string checkIn, string checkOut) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber && room.isAvailable) {
                room.isAvailable = false;
                bookings.emplace_back(++bookingCounter, customerId, roomNumber, checkIn, checkOut);
                cout << "Room booked successfully!" << endl;
                return;
            }
        }
        cout << "Room is not available!" << endl;
    }

    void displayRooms() {
        cout << "Available Rooms:" << endl;
        for (const auto& room : rooms) {
            if (room.isAvailable) {
                cout << "Room Number: " << room.roomNumber << ", Type: " << room.roomType << ", Price: $" << room.price << endl;
            }
        }
    }

    void displayCustomers() {
        cout << "Customers:" << endl;
        for (const auto& customer : customers) {
            cout << "ID: " << customer.customerId << ", Name: " << customer.name << ", Email: " << customer.email << endl;
        }
    }

    void displayBookings() {
        cout << "Bookings:" << endl;
        for (const auto& booking : bookings) {
            cout << "Booking ID: " << booking.bookingId << ", Customer ID: " << booking.customerId
                 << ", Room Number: " << booking.roomNumber << ", Check-in: " << booking.checkInDate
                 << ", Check-out: " << booking.checkOutDate << endl;
        }
    }
};

int main() {
    HotelManagementSystem hms;

    // Sample data
 ```cpp
    hms.addRoom(101, "Single", 100.0);
    hms.addRoom(102, "Double", 150.0);
    hms.addRoom(103, "Suite", 250.0);
    hms.addCustomer(1, "John Doe", "john@example.com");
    hms.addCustomer(2, "Jane Smith", "jane@example.com");

    int choice;
    do {
        cout << "\nHotel Management System Menu:" << endl;
        cout << "1. Display Rooms" << endl;
        cout << "2. Display Customers" << endl;
        cout << "3. Book Room" << endl;
        cout << "4. Display Bookings" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hms.displayRooms();
                break;
            case 2:
                hms.displayCustomers();
                break;
            case 3: {
                int customerId, roomNumber;
                string checkIn, checkOut;
                cout << "Enter Customer ID: ";
                cin >> customerId;
                cout << "Enter Room Number: ";
                cin >> roomNumber;
                cout << "Enter Check-in Date (YYYY-MM-DD): ";
                cin >> checkIn;
                cout << "Enter Check-out Date (YYYY-MM-DD): ";
                cin >> checkOut;
                hms.bookRoom(customerId, roomNumber, checkIn, checkOut);
                break;
            }
            case 4:
                hms.displayBookings();
                break;
            case 5:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}