#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

static int p = 0;

class Bus {
    char busNo[5], driver[10], arrival[5], depart[5], from[10], to[10];
    char seat[8][4][10]; // 8 rows, 4 columns of seats with passenger names

public:
    void install();
    void allotment();
    void emptySeats();
    void showDetails();
    void availableBuses();
    void displaySeats(int busIndex);
    void displaySeatMatrix(int busIndex);
};

Bus buses[10];

void drawLine(char ch) {
    for (int i = 0; i < 80; i++) {
        cout << ch;
    }
    cout << endl;
}

void Bus::install() {
    cout << "Enter bus number: ";
    cin >> buses[p].busNo;

    cout << "Enter Driver's name: ";
    cin >> buses[p].driver;

    cout << "Enter Arrival time: ";
    cin >> buses[p].arrival;

    cout << "Enter Departure time: ";
    cin >> buses[p].depart;

    cout << "Enter starting location (From): ";
    cin >> buses[p].from;

    cout << "Enter destination (To): ";
    cin >> buses[p].to;

    buses[p].emptySeats();
    p++;
}

void Bus::allotment() {
    char busNumber[5];
    int seatNum;

    cout << "Enter bus number: ";
    cin >> busNumber;

    int busIndex = -1;
    for (int n = 0; n < p; n++) {
        if (strcmp(buses[n].busNo, busNumber) == 0) {
            busIndex = n;
            break;
        }
    }

    if (busIndex == -1) {
        cout << "Invalid bus number. Please try again." << endl;
        return;
    }

    cout << "Enter seat number (1-32): ";
    cin >> seatNum;

    if (seatNum < 1 || seatNum > 32) {
        cout << "Invalid seat number. There are only 32 seats available." << endl;
        return;
    }

    int row = (seatNum - 1) / 4;
    int col = (seatNum - 1) % 4;

    if (strcmp(buses[busIndex].seat[row][col], "Empty") == 0) {
        cout << "Enter passenger's name: ";
        cin >> buses[busIndex].seat[row][col];
        cout << "Seat reserved successfully!" << endl;
    } else {
        cout << "The seat is already reserved." << endl;
    }
}

void Bus::emptySeats() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(buses[p].seat[i][j], "Empty");
        }
    }
}

void Bus::showDetails() {
    char busNumber[5];
    cout << "Enter bus number: ";
    cin >> busNumber;

    int busIndex = -1;
    for (int n = 0; n < p; n++) {
        if (strcmp(buses[n].busNo, busNumber) == 0) {
            busIndex = n;
            break;
        }
    }

    if (busIndex == -1) {
        cout << "Invalid bus number. Please try again." << endl;
        return;
    }

    drawLine('*');
    cout << "Bus Number: " << buses[busIndex].busNo
         << "\nDriver: " << buses[busIndex].driver
         << "\nArrival Time: " << buses[busIndex].arrival
         << "\nDeparture Time: " << buses[busIndex].depart
         << "\nFrom: " << buses[busIndex].from
         << "\nTo: " << buses[busIndex].to << endl;
    drawLine('*');

    displaySeats(busIndex);
    displaySeatMatrix(busIndex);
}

void Bus::displaySeats(int busIndex) {
    int emptyCount = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            if (strcmp(buses[busIndex].seat[i][j], "Empty") == 0) {
                emptyCount++;
            } else {
                cout << "Seat " << (i * 4 + j + 1) << " is reserved for " << buses[busIndex].seat[i][j] << "." << endl;
            }
        }
    }

    cout << "\nThere are " << emptyCount << " empty seats in Bus Number: " << buses[busIndex].busNo << endl;
}

void Bus::displaySeatMatrix(int busIndex) {
    cout << "\nSeat Matrix for Bus " << buses[busIndex].busNo << ":\n";
    drawLine('-');

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            cout.width(10);
            cout.fill(' ');
            cout << buses[busIndex].seat[i][j];
        }
        cout << endl;
    }

    drawLine('-');
}

void Bus::availableBuses() {
    for (int n = 0; n < p; n++) {
        drawLine('*');
        cout << "Bus Number: " << buses[n].busNo
             << "\nDriver: " << buses[n].driver
             << "\nArrival Time: " << buses[n].arrival
             << "\nDeparture Time: " << buses[n].depart
             << "\nFrom: " << buses[n].from
             << "\nTo: " << buses[n].to << endl;
        drawLine('*');
    }
}

int main() {
    system("color 1E");
    int choice;

    while (true) {
        cout << "\n\n\n";
        cout << "\t1. Install Bus\n\t2. Reserve Seat\n\t3. Show Bus Details\n\t4. View Available Buses\n\t5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                buses[p].install();
                break;
            case 2:
                buses[p].allotment();
                break;
            case 3:
                buses[0].showDetails();
                break;
            case 4:
                buses[0].availableBuses();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
// By Aditya Kuranjekar.................Happy Coding..........||
