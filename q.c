#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    string indexNumber, grade;
    double marks, gp;

    cout << "Enter Student Index Number: ";
    cin >> indexNumber;

    while (true) {
        cout << "Enter Marks: ";

        if (cin >> marks && marks >= 0 && marks <= 100) {
            break;
        }

        cout << "Invalid marks! Enter a value from 0 to 100.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (marks >= 85) {
        grade = "A+";
        gp = 4.00;
    } else if (marks >= 80) {
        grade = "A";
        gp = 4.00;
    } else if (marks >= 75) {
        grade = "A-";
        gp = 3.70;
    } else if (marks >= 70) {
        grade = "B+";
        gp = 3.30;
    } else if (marks >= 65) {
        grade = "B";
        gp = 3.00;
    } else if (marks >= 60) {
        grade = "B-";
        gp = 2.70;
    } else if (marks >= 55) {
        grade = "C+";
        gp = 2.30;
    } else if (marks >= 50) {
        grade = "C";
        gp = 2.00;
    } else if (marks >= 45) {
        grade = "C-";
        gp = 1.70;
    } else if (marks >= 40) {
        grade = "D+";
        gp = 1.30;
    } else if (marks >= 20) {
        grade = "D";
        gp = 1.00;
    } else {
        grade = "E";
        gp = 0.00;
    }

    cout << "\n---------- RESULT ----------\n";
    cout << "Index Number : " << indexNumber << '\n';
    cout << "Marks        : " << marks << '\n';
    cout << "Grade        : " << grade << '\n';
    cout << fixed << setprecision(2);
    cout << "Grade Point  : " << gp << '\n';

    ofstream file("student_grades.txt", ios::app);

    if (!file) {
        cerr << "Error: Unable to open student_grades.txt\n";
        return 1;
    }

    file << "Index Number : " << indexNumber << '\n';
    file << "Marks        : " << marks << '\n';
    file << "Grade        : " << grade << '\n';
    file << fixed << setprecision(2);
    file << "Grade Point  : " << gp << '\n';
    file << "----------------------------\n";

    file.close();

    if (!file) {
        cerr << "Error: Unable to save the record.\n";
        return 1;
    }

    cout << "\nStudent grade has been saved to student_grades.txt\n";

    return 0;
}

*************************************

#include <iostream>
#include <string>
using namespace std;

int main() {
    string binary;
    string hexadecimal = "";
    const string hexDigits = "0123456789ABCDEF";

    cout << "Enter a binary number: ";
    cin >> binary;

    // Validate every character.
    for (char digit : binary) {
        if (digit != '0' && digit != '1') {
            cout << "Invalid input! Only 0 and 1 are allowed.\n";
            return 1;
        }
    }

    // Add leading zeros to make complete groups of four bits.
    while (binary.length() % 4 != 0) {
        binary = "0" + binary;
    }

    cout << "\nGroup into four bits:\n";

    for (size_t i = 0; i < binary.length(); i += 4) {
        cout << binary.substr(i, 4) << ' ';
    }

    cout << "\n\nConvert each group:\n";

    for (size_t i = 0; i < binary.length(); i += 4) {
        int value = 0;

        for (size_t j = i; j < i + 4; j++) {
            value = value * 2 + (binary[j] - '0');
        }

        char hexDigit = hexDigits[value];
        hexadecimal += hexDigit;

        cout << binary.substr(i, 4)
             << " = " << hexDigit << '\n';
    }

    // Remove unnecessary leading hexadecimal zeros.
    size_t firstNonZero = hexadecimal.find_first_not_of('0');

    if (firstNonZero == string::npos) {
        hexadecimal = "0";
    } else {
        hexadecimal = hexadecimal.substr(firstNonZero);
    }

    cout << "\nHexadecimal = " << hexadecimal << '\n';

    return 0;
}


**********************************

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    const int TOTAL_SEATS = 20;
    char seats[TOTAL_SEATS];
    int choice, seatNumber;

    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i] = '-';
    }

    do {
        cout << "\n===== AIRPLANE SEAT RESERVATION SYSTEM =====\n";
        cout << "1. Display Seat Status\n";
        cout << "2. Reserve a Seat\n";
        cout << "3. Cancel a Reservation\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number from 1 to 4.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "\nSeat Status:\n";

                for (int i = 0; i < TOTAL_SEATS; i++) {
                    cout << setw(2) << i + 1
                         << "[" << seats[i] << "]  ";

                    if ((i + 1) % 5 == 0) {
                        cout << '\n';
                    }
                }
                break;

            case 2:
            case 3:
                cout << "Enter seat number (1-20): ";

                if (!(cin >> seatNumber)) {
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(), '\n'
                    );
                    cout << "Invalid seat number!\n";
                    break;
                }

                if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
                    cout << "Invalid seat number! Enter 1 to 20.\n";
                    break;
                }

                if (choice == 2) {
                    if (seats[seatNumber - 1] == 'X') {
                        cout << "Seat " << seatNumber
                             << " is already reserved.\n";
                    } else {
                        seats[seatNumber - 1] = 'X';
                        cout << "Seat " << seatNumber
                             << " has been successfully reserved.\n";
                    }
                } else {
                    if (seats[seatNumber - 1] == '-') {
                        cout << "Seat " << seatNumber
                             << " has no reservation to cancel.\n";
                    } else {
                        seats[seatNumber - 1] = '-';
                        cout << "Reservation for seat " << seatNumber
                             << " has been cancelled.\n";
                    }
                }
                break;

            case 4:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Enter 1 to 4.\n";
        }

    } while (choice != 4);

    return 0;
}

