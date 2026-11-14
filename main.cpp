#include <iostream>
using namespace std;

struct Ticket {
    int ticketNumber;
    string movieName;
};

const int SIZE = 100;
Ticket ticketStack[SIZE];
int top = -1;

void bookTicket(int number, string name) {
    if (top >= SIZE - 1) {
        cout << "Booking full. Hindi na puwedeng mag-book ng ticket.\n";
        return;
    }
    top++;
    ticketStack[top].ticketNumber = number;
    ticketStack[top].movieName = name;
    cout << "Ticket booked: " << name << " (Number: " << number << ")\n";
}

void cancelTicket() {
    if (top < 0) {
        cout << "Walang ticket na naka-book. Wala tayong puwedeng i-cancel.\n";
        return;
    }
    cout << "Ticket cancelled: " << ticketStack[top].movieName
         << " (Number: " << ticketStack[top].ticketNumber << ")\n";
    top--;
}

void showTickets() {
    if (top < 0) {
        cout << "Wala pang naka-book na ticket.\n";
        return;
    }
    cout << "Mga naka-book na ng ticket:\n";
    for (int i = top; i >= 0; i--) {
        cout << "- " << ticketStack[i].movieName
             << " (Number: " << ticketStack[i].ticketNumber << ")\n";
    }
}

int main() {
    int choice, number;
    string name;

    do {
        cout << "\n--- Movie Ticketing ---\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. Show Tickets\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Ticket Number: ";
            cin >> number;
            cout << "Enter Movie Name: ";
            cin.ignore();
            getline(cin, name);
            bookTicket(number, name);
        }
        else if (choice == 2) {
            cancelTicket();
        }
        else if (choice == 3) {
            showTickets();
        }
        else if (choice == 4) {
            cout << "Thank you for buying!\n";
        }
        else {
            cout << "Invalid choice. Subukan ulit.\n";
        }
    } while (choice != 4);

    return 0;
}
