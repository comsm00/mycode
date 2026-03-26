SEAT Booking

#include <iostream>
using namespace std;

int main() {
    const int ROWS = 13;
    const int COLS = 6;

    char seats[ROWS][COLS];

    // Initialize all seats as available (*)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = '*';
        }
    }

    char choice;
    int row;
    char col;

    do {
        // Display seat layout
        cout << "\nRows 1 and 2 are First Class (FC)" << endl;
        cout << "Rows 3 through 7 are Business Class (BC)" << endl;
        cout << "Rows 8 through 13 are Economy Class (EC)\n" << endl;

        cout << "   A B C D E F" << endl;

        for (int i = 0; i < ROWS; i++) {
            cout << "Row " << i + 1 << " ";
            for (int j = 0; j < COLS; j++) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }

        // User input
        string type;
        cout << "\nEnter Ticket type (FC, BC, EC): ";
        cin >> type;

        cout << "Enter row number (1-13): ";
        cin >> row;

        cout << "Enter seat letter (A-F): ";
        cin >> col;

        int colIndex = col - 'A';

        // Check class validity
        bool valid = false;

        if (type == "FC" && (row >= 1 && row <= 2))
            valid = true;
        else if (type == "BC" && (row >= 3 && row <= 7))
            valid = true;
        else if (type == "EC" && (row >= 8 && row <= 13))
            valid = true;

        if (!valid) {
            cout << "❌ Invalid seat for selected class!" << endl;
        }
        else if (seats[row - 1][colIndex] == '#') {
            cout << "❌ Seat already occupied!" << endl;
        }
        else {
            seats[row - 1][colIndex] = '#';
            cout << "✅ Seat booked successfully!" << endl;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
