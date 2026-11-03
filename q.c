#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string passengerName;
    int passengerAge;
    int numTickets;
    int flightChoice;
    int classChoice;

    double economyFare = 0.0;
    double pricePerTicket = 0.0;
    double totalAmount = 0.0;

    string flightName = "";
    string className = "";

    cout << "--- Air Ticket Reservation System ---\n";

    cout << "Enter Passenger Name: ";
    getline(cin, passengerName);

    cout << "Enter Passenger Age: ";
    cin >> passengerAge;

    cout << "Enter Number of Tickets Required: ";
    cin >> numTickets;

    if (passengerAge <= 0 || numTickets <= 0) {
        cout << "Invalid passenger age or ticket count!";
        return 0;
    }

    cout << "\nSelect a Flight Option:\n";

    cout << "1 - Colombo -> Chennai - Rs. 25000\n";
    cout << "2 - Colombo -> Dubai - Rs. 85000\n";
    cout << "3 - Colombo -> Singapore - Rs. 70000\n";
    cout << "4 - Colombo -> London - Rs. 180000\n";

    cout << "Enter your flight choice (1-4): ";
    cin >> flightChoice;

    switch (flightChoice) {

        case 1:
            flightName = "Colombo -> Chennai";
            economyFare = 25000;
            break;

        case 2:
            flightName = "Colombo -> Dubai";
            economyFare = 85000;
            break;

        case 3:
            flightName = "Colombo -> Singapore";
            economyFare = 70000;
            break;

        case 4:
            flightName = "Colombo -> London";
            economyFare = 180000;
            break;

        default:
            cout << "Invalid flight choice!";
            return 0;
    }

    cout << "\nSelect Travel Class:\n";

    cout << "1 - Economy Class\n";
    cout << "2 - Business Class\n";

    cout << "Enter your class choice (1-2): ";
    cin >> classChoice;

    if (classChoice == 1) {

        className = "Economy Class";
        pricePerTicket = economyFare;

    }

    else if (classChoice == 2) {

        className = "Business Class";
        pricePerTicket = economyFare * 1.75;

    }

    else {

        cout << "Invalid travel class choice!";
        return 0;

    }

    totalAmount = pricePerTicket * numTickets;

    cout << fixed << setprecision(2);

    cout << "\n====================================\n";

    cout << "   TICKET RESERVED SUCCESSFULLY!\n";

    cout << "====================================\n";

    cout << "Passenger Name   : " << passengerName << endl;
    cout << "Passenger Age    : " << passengerAge << endl;
    cout << "Selected Flight  : " << flightName << endl;
    cout << "Travel Class     : " << className << endl;
    cout << "Number of Tickets: " << numTickets << endl;
    cout << "Price per Ticket : Rs. " << pricePerTicket << endl;
    cout << "Total Amount     : Rs. " << totalAmount << endl;

    cout << "====================================\n";

    return 0;
}
  
