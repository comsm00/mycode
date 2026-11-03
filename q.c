#include <iostream>
#include <string>
using namespace std;

int main()
{
    int marks;
    string grade;
    float gpa;

    cout << "Enter the Marks: ";
    cin >> marks;

    if (marks < 0 || marks > 100)
    {
        cout << "Invalid Marks";
        return 0;
    }

    switch (marks / 5)
    {
        case 20:
        case 19:
            grade = "A+";
            gpa = 4.5;
            break;

        case 18:
            grade = "A";
            gpa = 4.0;
            break;

        case 17:
            grade = "B+";
            gpa = 3.5;
            break;

        case 16:
            grade = "B";
            gpa = 3.0;
            break;

        case 15:
            grade = "C+";
            gpa = 2.5;
            break;

        case 14:
            grade = "C";
            gpa = 2.0;
            break;

        case 13:
            grade = "D+";
            gpa = 1.5;
            break;

        case 12:
            grade = "D";
            gpa = 1.0;
            break;

        default:
            grade = "F";
            gpa = 0.0;
    }

    cout << "Grade is: " << grade << endl;
    cout << "Grade point average is: " << gpa << endl;

    return 0;
}

*********************************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    string nic;
    int year, days, day, month;
    string gender;

    cout << "Enter New NIC Number: ";
    cin >> nic;

    if (nic.length() != 12)
    {
        cout << "Invalid NIC Number";
        return 0;
    }

    year = atoi(nic.substr(0, 4).c_str());
    days = atoi(nic.substr(4, 3).c_str());

    if (days > 500)
    {
        gender = "Female";
        days = days - 500;
    }
    else
    {
        gender = "Male";
    }

    if (days < 1 || days > 366)
    {
        cout << "Invalid NIC Number";
        return 0;
    }

    int monthDays[] = {
        31, 29, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if ((year % 4 == 0 && year % 100 != 0) ||
        (year % 400 == 0))
    {
        monthDays[1] = 29;
    }

    month = 0;

    while (month < 12 && days > monthDays[month])
    {
        days = days - monthDays[month];
        month++;
    }

    if (month == 12)
    {
        cout << "Invalid Date";
        return 0;
    }

    day = days;

    cout << "\nYear of Birth: " << year;
    cout << "\nDate of Birth: " << day << "/" << month + 1 << "/" << year;
    cout << "\nGender: " << gender;

    return 0;
}

******************************************************************************************************************************

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

********************************************************************************************************************

#include <iostream>
using namespace std;

int main() {
    double prev_reading, curr_reading;
    double unit, total_amount = 0.0;

    cout << "Enter previous meter reading: ";
    cin >> prev_reading;
    cout << "Enter current meter unit: ";
    cin >> curr_reading;

    unit = curr_reading - prev_reading;
    cout << "Total units consumed = " << curr_reading << " - " << prev_reading << " = " << unit << endl;

    if (unit <= 30) {
        total_amount = unit * 25;
    } 
    else if (unit <= 60) {
        total_amount = (30 * 25) + (unit - 30) * 35;
    } 
    else if (unit <= 90) {
        total_amount = (30 * 25) + (30 * 35) + (unit - 60) * 45;
    } 
    else if (unit <= 120) {
        total_amount = (30 * 25) + (30 * 35) + (30 * 45) + (unit - 90) * 55;
    } 
    else {
        total_amount = (30 * 25) + (30 * 35) + (30 * 45) + (30 * 55) + (unit - 120) * 65;
    }

    cout << "Charge for the month: Rs. " << total_amount << "/=" << endl;

    return 0;
}

************************************************************************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

char seats[13][6] = {
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'}
};

void displayChart() {
    cout << "\nRows 1 and 2 are first class (FC)\n";
    cout << "Rows 3 through 7 are business class (BC)\n";
    cout << "Rows 8 through 13 are economy class (EC)\n\n";
    cout << "* - Available\n";
    cout << "X - Occupied\n\n";
    
    cout << "\tA\tB\tC\tD\tE\tF\n";
    for (int i = 0; i < 13; i++) {
        cout << "Row " << (i + 1) << "\t";
        for (int j = 0; j < 6; j++) {
            cout << seats[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    char choice;
    do {
        displayChart();

        string ticketType;
        cout << "\nEnter Ticket type (FC, BC, or EC): ";
        cin >> ticketType;

        int startRow = 0, endRow = 0;
        if (ticketType == "FC" || ticketType == "fc") {
            startRow = 0; 
            endRow = 1;  
        } else if (ticketType == "BC" || ticketType == "bc") {
            startRow = 2; 
            endRow = 6;  
        } else if (ticketType == "EC" || ticketType == "ec") {
            startRow = 7; 
            endRow = 12;  
        } else {
            cout << "Invalid ticket type! Try again.\n";
            continue;
        }

        int rowNum;
        char seatLetter;
        cout << "Enter desired row number (" << (startRow + 1) << " to " << (endRow + 1) << "): ";
        cin >> rowNum;

        if (rowNum < (startRow + 1) || rowNum > (endRow + 1)) {
            cout << "Invalid row for the chosen ticket type!\n";
            continue;
        }

        cout << "Enter desired seat letter (A-F): ";
        cin >> seatLetter;

        int colNum = -1;
        if (seatLetter == 'A' || seatLetter == 'a') colNum = 0;
        else if (seatLetter == 'B' || seatLetter == 'b') colNum = 1;
        else if (seatLetter == 'C' || seatLetter == 'c') colNum = 2;
        else if (seatLetter == 'D' || seatLetter == 'd') colNum = 3;
        else if (seatLetter == 'E' || seatLetter == 'e') colNum = 4;
        else if (seatLetter == 'F' || seatLetter == 'f') colNum = 5;
        else {
            cout << "Invalid seat letter!\n";
            continue;
        }

        int rIndex = rowNum - 1;
        if (seats[rIndex][colNum] == '*') {
            seats[rIndex][colNum] = 'X';
            cout << "Seat successfully reserved!\n";
        } else {
            cout << "Sorry, that seat is already occupied (X).\n";
        }

        cout << "Do you want to book another seat? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

*************************************************************************************************************************

#include <iostream>
using namespace std;

char* SUBSTRING(char NIC[], int S, int E) {
    static char sub[100];
    int j = 0;
    for (int i = S; i <= E; i++) {
        sub[j++] = NIC[i];
    }
    sub[j] = '\0';
    return sub;
}

int LEN(char STR[]) {
    int length = 0;
    while (STR[length] != '\0') {
        length++;
    }
    return length;
}

int TextTOValue(char TEX[]) {
    int value = 0;
    int i = 0;
    while (TEX[i] != '\0') {
        if (TEX[i] >= '0' && TEX[i] <= '9') {
            value = value * 10 + (TEX[i] - '0');
        }
        i++;
    }
    return value;
}

int MonthDAYS(int month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    } else if (month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
        return 30;
    } else if (month == 2) {
        return 29;
    }
    return 0;
}

int main() {
    char nic[20];
    cout << "Enter new format NIC Number (e.g., 196504504243): ";
    cin >> nic;

    char* yearStr = SUBSTRING(nic, 0, 3);
    int year = TextTOValue(yearStr);

    char* daysStr = SUBSTRING(nic, 4, 6);
    int totalDays = TextTOValue(daysStr);

    string gender = "Male";
    if (totalDays > 500) {
        gender = "Female";
        totalDays -= 500; 
    }

    int month = 1;
    while (true) {
        int daysInCurrentMonth = MonthDAYS(month);
        if (totalDays <= daysInCurrentMonth) {
            break;
        }
        totalDays -= daysInCurrentMonth;
        month++;
    }

    int day = totalDays;

    cout << "\n--- NIC Details ---" << endl;
    cout << "Year: " << year << endl;
    cout << "Month: " << month << endl;
    cout << "Day: " << day << endl;
    cout << "Date of Birth: " << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day << endl;
    cout << "Gender: " << gender << endl;

    return 0;
}

********************************************************************************************************************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNUM(int X, int Y) {
    return X + rand() % (Y - X + 1);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int X, Y;
    cout << "Enter lower bound (X): ";
    cin >> X;
    cout << "Enter upper bound (Y): ";
    cin >> Y;

    if ((Y - X + 1) < 5) {
        cout << "Error: The range between X and Y must contain at least 5 numbers!" << endl;
        return 1;
    }

    int tickets[100][5];

    for (int i = 0; i < 100; i++) {
        int count = 0;
        while (count < 5) {
            int num = RandomNUM(X, Y);
            
            bool isDuplicate = false;
            for (int j = 0; j < count; j++) {
                if (tickets[i][j] == num) {
                    isDuplicate = true;
                    break;
                }
            }

            if (!isDuplicate) {
                tickets[i][count] = num;
                count++;
            }
        }
    }

    cout << "\n--- Generated 100 Lottery Tickets ---" << endl;
    for (int i = 0; i < 100; i++) {
        cout << "Ticket " << (i + 1) << ": ";
        for (int j = 0; j < 5; j++) {
            cout << tickets[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

**************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

string decitobin(int n) {
    if (n == 0) return "0";
    string binary = "";
    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    return binary;
}

int main() {
    int decimalInput;
    cout << "Enter a decimal number (maximum 3 digits): ";
    cin >> decimalInput;

    if (decimalInput < 0 || decimalInput > 999) {
        cout << "Error: Please enter a number with a maximum of 3 digits (0 - 999)." << endl;
        return 1;
    }

    string binaryResult = decitobin(decimalInput);
    cout << "Sample input: " << decimalInput << " (Decimal)" << endl;
    cout << "Sample output: " << binaryResult << " (Binary)" << endl;

    return 0;
}

*******************************************************************************************************************************************

#include <iostream>
using namespace std;

int main() {
    double mark;
    cout << "Enter the marks (0-100): ";
    cin >> mark;

    if (mark < 0 || mark > 100) {
        cout << "Invalid marks entered! Please enter a value between 0 and 100." << endl;
        return 1;
    }

    string grade;
    double gpa;

    if (mark >= 80) {
        grade = "A+";
        gpa = 4.0;
    } else if (mark >= 70) {
        grade = "A";
        gpa = 3.6;
    } else if (mark >= 65) {
        grade = "B+";
        gpa = 3.2;
    } else if (mark >= 60) {
        grade = "B";
        gpa = 2.8;
    } else if (mark >= 55) {
        grade = "C+";
        gpa = 2.4;
    } else if (mark >= 50) {
        grade = "C";
        gpa = 2.0;
    } else if (mark >= 45) {
        grade = "D";
        gpa = 2.0;
    } else if (mark >= 40) {
        grade = "E";
        gpa = 1.6;
    } else {
        grade = "F";
        gpa = 0.8;
    }

    cout << "Grade: " << grade << endl;
    cout << "GPA: " << gpa << endl;

    return 0;
}

*****************************************************************************

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int getRomanValue(char r) {
    switch (toupper(r)) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;
    }
}

int main() {
    string roman;
    cout << "Enter a Roman number: ";
    cin >> roman;

    for (char c : roman) {
        char upperC = toupper(c);
        if (upperC != 'I' && upperC != 'V' && upperC != 'X' && 
            upperC != 'L' && upperC != 'C' && upperC != 'D' && upperC != 'M') {
            cout << "Error: Unwanted characters detected. Only Roman letters are allowed." << endl;
            return 1;
        }
    }

    if (roman.empty()) {
        cout << "Error: Empty string provided." << endl;
        return 1;
    }

    int decimal = getRomanValue(roman[0]);
    int i = 1;

    while (i < roman.length()) {
        int currentVal = getRomanValue(roman[i]);
        int prevVal = getRomanValue(roman[i - 1]);

        decimal = decimal + currentVal;

        if (currentVal > prevVal) {
            decimal = decimal - 2 * prevVal;
        }
        
        i++;
    }

    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
}

*****************************************************************************************************

Jnr da batch Q1 diamond shape
#include <iostream>
using namespace std;

void printDiamond(int n) {
    int spaces, stars;
    
    for (int i = 1; i <= (n / 2) + 1; i++) {
        spaces = (n / 2) + 1 - i;
        stars = 2 * i - 1;
        
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }

        for (int j = 0; j < stars; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    for (int i = (n / 2); i >= 1; i--) {
        spaces = (n / 2) + 1 - i;
        stars = 2 * i - 1;
        
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }

        for (int j = 0; j < stars; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    
    do {
        cout << "Enter a positive odd integer (at least 3): ";
        cin >> n;
        
        if (n < 3 || n % 2 == 0) {
            cout << "Invalid input! The number must be odd and >= 3. Please try again.\n";
        }
    } while (n < 3 || n % 2 == 0);
    
    cout << "\nOutput:\n";
    printDiamond(n);
    
    return 0;
}

*******************************************************************************************************************************

Jnr da batch Q2 
#include <iostream>
#include <iomanip>
using namespace std;

double calculateAverage(double prices[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += prices[i];
    }
    return sum / size;
}

void findHighest(double prices[], string days[], int size, double &highest, string &highestDay) {
    highest = prices[0];
    highestDay = days[0];
    for (int i = 1; i < size; i++) {
        if (prices[i] > highest) {
            highest = prices[i];
            highestDay = days[i];
        }
    }
}

void findLowest(double prices[], string days[], int size, double &lowest, string &lowestDay) {
    lowest = prices[0];
    lowestDay = days[0];
    for (int i = 1; i < size; i++) {
        if (prices[i] < lowest) {
            lowest = prices[i];
            lowestDay = days[i];
        }
    }
}

int countDaysAboveAverage(double prices[], int size, double average) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (prices[i] > average) {
            count++;
        }
    }
    return count;
}

int main() {
    const int SIZE = 7;
    double prices[SIZE];
    string days[SIZE] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    cout << "Enter fish prices for 7 days (Monday to Sunday):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << days[i] << ": ";
        cin >> prices[i];
    }
    
    double avg = calculateAverage(prices, SIZE);
    double highest, lowest;
    string highestDay, lowestDay;
    
    findHighest(prices, days, SIZE, highest, highestDay);
    findLowest(prices, days, SIZE, lowest, lowestDay);
    int aboveAvgCount = countDaysAboveAverage(prices, SIZE, avg);
    
    cout << fixed << setprecision(2);
    cout << "\nAverage price = " << avg << endl;
    cout << "Highest price = " << highest << " (" << highestDay << ")" << endl;
    cout << "Lowest price = " << lowest << " (" << lowestDay << ")" << endl;
    cout << "Days above average = " << aboveAvgCount << endl;
    
    return 0;
}

*********************************************************************************************************************************

Jnr da batch Q3 
#include <iostream>
using namespace std;

int LEN(char STR[]) {
    int length = 0;
    while (STR[length] != '\0') {
        length++;
    }
    return length;
}

void SUBSTRING(char STR[], int start, int end, char result[]) {
    int j = 0;
    for (int i = start; i <= end; i++) {
        result[j] = STR[i];
        j++;
    }
    result[j] = '\0';
}

bool isAlphabet(char STR[]) {
    int len = LEN(STR);
    if (len == 0) return false;
    for (int i = 0; i < len; i++) {
        char c = STR[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            return false;
        }
    }
    return true;
}

int TextToValue(char STR[]) {
    int value = 0;
    int len = LEN(STR);
    for (int i = 0; i < len; i++) {
        if (STR[i] >= '0' && STR[i] <= '9') {
            value = value * 10 + (STR[i] - '0');
        } else {
            return -1;
        }
    }
    return value;
}

void toUpperCase(char STR[]) {
    int len = LEN(STR);
    for (int i = 0; i < len; i++) {
        if (STR[i] >= 'a' && STR[i] <= 'z') {
            STR[i] = STR[i] - 32;
        }
    }
}

int main() {
    char regNo[100];
    cout << "Please enter the registration number: ";
    cin >> regNo;
    
    char partEUSL[10], partTC[10], partIS[10], partYear[10], partDept[10], partNum[10];
    int i = 0, idx = 0;
    
    idx = 0;
    while (regNo[i] != '/' && regNo[i] != '\0') { partEUSL[idx++] = regNo[i++]; }
    partEUSL[idx] = '\0';
    if (regNo[i] == '/') i++; else { cout << "Error: Invalid format.\nStatus : Invalid\n"; return 0; }
    
    idx = 0;
    while (regNo[i] != '/' && regNo[i] != '\0') { partTC[idx++] = regNo[i++]; }
    partTC[idx] = '\0';
    if (regNo[i] == '/') i++; else { cout << "Error: Invalid format.\nStatus : Invalid\n"; return 0; }
    
    idx = 0;
    while (regNo[i] != '/' && regNo[i] != '\0') { partIS[idx++] = regNo[i++]; }
    partIS[idx] = '\0';
    if (regNo[i] == '/') i++; else { cout << "Error: Invalid format.\nStatus : Invalid\n"; return 0; }
    
    idx = 0;
    while (regNo[i] != '/' && regNo[i] != '\0') { partYear[idx++] = regNo[i++]; }
    partYear[idx] = '\0';
    if (regNo[i] == '/') i++; else { cout << "Error: Invalid format.\nStatus : Invalid\n"; return 0; }
    
    idx = 0;
    while (regNo[i] != '/' && regNo[i] != '\0') { partDept[idx++] = regNo[i++]; }
    partDept[idx] = '\0';
    if (regNo[i] == '/') i++; else { cout << "Error: Invalid format.\nStatus : Invalid\n"; return 0; }
    
    idx = 0;
    while (regNo[i] != '\0') { partNum[idx++] = regNo[i++]; }
    partNum[idx] = '\0';
    
    bool matchEUSL = (LEN(partEUSL) == 4 && partEUSL[0]=='E' && partEUSL[1]=='U' && partEUSL[2]=='S' && partEUSL[3]=='L');
    if (!matchEUSL) {
        cout << "Error: University prefix must be EUSL.\nStatus : Invalid\n";
        return 0;
    }
    
    bool matchTC = (LEN(partTC) == 2 && partTC[0]=='T' && partTC[1]=='C');
    if (!matchTC) {
        cout << "Error: Campus code must be TC.\nStatus : Invalid\n";
        return 0;
    }
    
    bool matchIS = (LEN(partIS) == 2 && partIS[0]=='I' && partIS[1]=='S');
    if (!matchIS) {
        cout << "Error: Student type must be IS.\nStatus : Invalid\n";
        return 0;
    }
    
    if (LEN(partYear) != 4) {
        cout << "Error: Academic year must be exactly 4 digits.\nStatus : Invalid\n";
        return 0;
    }
    int yearVal = TextToValue(partYear);
    if (yearVal < 2000 || yearVal > 2099) {
        cout << "Error: Academic year must be between 2000 and 2099.\nStatus : Invalid\n";
        return 0;
    }
    
    int deptLen = LEN(partDept);
    if (deptLen < 2 || deptLen > 4 || !isAlphabet(partDept)) {
        cout << "Error: Department code must contain letters only (2-4 characters).\nStatus : Invalid\n";
        return 0;
    }
    toUpperCase(partDept);
    
    int studentNum = TextToValue(partNum);
    if (studentNum < 1 || studentNum > 99) {
        cout << "Error: Student number must be between 1 and 99.\nStatus : Invalid\n";
        return 0;
    }
    
    cout << "Registration Number: EUSL/TC/IS/" << partYear << "/" << partDept << "/" << partNum << endl;
    cout << "University         : Eastern University of Sri Lanka\n";
    cout << "Campus             : Trincomalee Campus\n";
    cout << "Student Type       : Internal Student\n";
    cout << "Academic Year      : " << partYear << endl;
    cout << "Department         : " << partDept << endl;
    cout << "Student Number     : " << studentNum << endl;
    cout << "Status             : Valid\n";
    
    return 0;
}
