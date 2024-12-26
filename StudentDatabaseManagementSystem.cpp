#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string arr1[20], arr2[20], arr3[20], arr4[20], arr5[20];
int total = 0;

void enter() {
    int ch = 0;
    cout << "\nHow many students do you want to enter? ";
    cin >> ch;

    if (ch <= 0 || total + ch > 20) {
        cout << "\nInvalid input or exceeding maximum storage (20 records allowed).\n";
        return;
    }
    cin.ignore(); // Clear the input buffer before using getline.

    for (int i = total; i < total + ch; i++) {
        cout << "\nEnter the details of student " << i + 1 << ":\n";

        cout << "Enter name: ";
        getline(cin, arr1[i]);
        cout << "Enter Roll no: ";
        getline(cin, arr2[i]);
        cout << "Enter course: ";
        getline(cin, arr3[i]);
        cout << "Enter class: ";
        getline(cin, arr4[i]);
        cout << "Enter contact: ";
        getline(cin, arr5[i]);
    }
    total += ch;
}

void show() {
    if (total == 0) {
        cout << "\nNo data is entered.\n";
    } else {
        for (int i = 0; i < total; i++) {
            cout << "\nDetails of Student " << i + 1 << ":\n";
            cout << "Name: " << arr1[i] << "\n";
            cout << "Roll no: " << arr2[i] << "\n";
            cout << "Course: " << arr3[i] << "\n";
            cout << "Class: " << arr4[i] << "\n";
            cout << "Contact: " << arr5[i] << "\n";
        }
    }
}

void search() {
    if (total == 0) {
        cout << "\nNo data is entered.\n";
        return;
    }

    string rollno;
    cout << "\nEnter the roll number of the student to search: ";
    cin.ignore(); // Clear the input buffer.
    getline(cin, rollno);

    for (int i = 0; i < total; i++) {
        if (rollno == arr2[i]) {
            cout << "\nDetails of the student:\n";
            cout << "Name: " << arr1[i] << "\n";
            cout << "Roll no: " << arr2[i] << "\n";
            cout << "Course: " << arr3[i] << "\n";
            cout << "Class: " << arr4[i] << "\n";
            cout << "Contact: " << arr5[i] << "\n";
            return;
        }
    }
    cout << "\nNo student found with the given roll number.\n";
}

void update() {
    if (total == 0) {
        cout << "\nNo data is entered.\n";
        return;
    }

    string rollno;
    cout << "\nEnter the roll number of the student to update: ";
    cin.ignore(); // Clear the input buffer.
    getline(cin, rollno);

    for (int i = 0; i < total; i++) {
        if (rollno == arr2[i]) {
            cout << "\nCurrent details of the student:\n";
            cout << "Name: " << arr1[i] << "\n";
            cout << "Roll no: " << arr2[i] << "\n";
            cout << "Course: " << arr3[i] << "\n";
            cout << "Class: " << arr4[i] << "\n";
            cout << "Contact: " << arr5[i] << "\n";

            cout << "\nEnter new details:\n";
            cout << "Enter name: ";
            getline(cin, arr1[i]);
            cout << "Enter Roll no: ";
            getline(cin, arr2[i]);
            cout << "Enter course: ";
            getline(cin, arr3[i]);
            cout << "Enter class: ";
            getline(cin, arr4[i]);
            cout << "Enter contact: ";
            getline(cin, arr5[i]);
            cout << "\nStudent record updated successfully.\n";
            return;
        }
    }
    cout << "\nNo student found with the given roll number.\n";
}

void deleterecord() {
    if (total == 0) {
        cout << "\nNo data is entered.\n";
        return;
    }

    int choice;
    cout << "\nPress 1 to delete all records.\n";
    cout << "Press 2 to delete a specific record.\n";
    cin >> choice;
    cin.ignore(); // Clear the input buffer.

    if (choice == 1) {
        total = 0;
        cout << "\nAll records deleted successfully.\n";
    } else if (choice == 2) {
        string rollno;
        cout << "\nEnter the roll number of the student to delete: ";
        getline(cin, rollno);

        for (int i = 0; i < total; i++) {
            if (rollno == arr2[i]) {
                for (int j = i; j < total - 1; j++) {
                    arr1[j] = arr1[j + 1];
                    arr2[j] = arr2[j + 1];
                    arr3[j] = arr3[j + 1];
                    arr4[j] = arr4[j + 1];
                    arr5[j] = arr5[j + 1];
                }
                total--;
                cout << "\nStudent record deleted successfully.\n";
                return;
            }
        }
        cout << "\nNo student found with the given roll number.\n";
    } else {
        cout << "\nInvalid choice.\n";
    }
}

int main() {
    while (true) {
        int value;
        cout << "\nMenu:\n";
        cout << "1. Enter data\n";
        cout << "2. Show data\n";
        cout << "3. Search data\n";
        cout << "4. Update data\n";
        cout << "5. Delete data\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> value;

        switch (value) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                deleterecord();
                break;
            case 6:
                cout << "\nExiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    }
}
// By Aditya Kailash Kuranjekar.........................HAPPY CODING.................................||
