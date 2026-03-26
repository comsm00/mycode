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

-------------------------------------------
DECIMAL TO BINARY

#include <iostream>
using namespace std;

int main() {
    int num;
    
    cout << "Enter a decimal number: ";
    cin >> num;

    int binary[32]; // array to store binary digits
    int i = 0;

    // Convert to binary
    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    // Print binary in reverse order
    cout << "Binary equivalent: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << binary[j];
    }

    return 0;
}



ROMAN -----------


    #include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to get the decimal value of a single Roman character
int getDecimalValue(char r) {
    switch (toupper(r)) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1; // Returns -1 for invalid characters
    }
}

int main() {
    string ROMAN;
    cout << "Enter a Roman numeral: ";
    cin >> ROMAN;

    // Validation and Normalization
    for (int i = 0; i < ROMAN.length(); i++) {
        if (getDecimalValue(ROMAN[i]) == -1) {
            cout << "Error: Unwanted characters detected. Only Roman letters are allowed." << endl;
            return 1;
        }
        ROMAN[i] = toupper(ROMAN[i]); // Allow both upper and lower case
    }

    // ALGORITHM Implementation
    // Assume ROMAN is a string of Roman numbers
    int DECIMAL = getDecimalValue(ROMAN[0]);
    int I = 1;

    // While (Roman [I] != Null character)
    while (I < ROMAN.length()) {
        int currentVal = getDecimalValue(ROMAN[I]);
        int prevVal = getDecimalValue(ROMAN[I - 1]);

        // DECIMAL = DECIMAL + decimal equivalent of ROMAN [I]
        DECIMAL = DECIMAL + currentVal;

        // If (ROMAN [I] > ROMAN [I-1] ) then
        // Note: The logic compares the VALUES of the characters as per the example
        if (currentVal > prevVal) {
            // DECIMAL = DECIMAL - 2 x decimal equivalent of ROMAN [I-1]
            DECIMAL = DECIMAL - (2 * prevVal);
        }
        I++;
    }

    cout << "Decimal equivalent: " << DECIMAL << endl;

    return 0;
}







NIC---------------------

#include <iostream>
#include <string>
using namespace std;

int main() {
    string nic;
    cout << "Enter your NIC number: ";
    cin >> nic;
    int birth_year = (nic[0] - '0') * 1000 + (nic[1] - '0') * 100 + (nic[2] - '0') * 10 + (nic[3] - '0');
    int days = (nic[4] - '0') * 100 + (nic[5] - '0') * 10 + (nic[6] - '0');
    string gender;
    if (days > 500) {
        days -= 500;
        gender = "Female";
    } else {
        gender = "Male";
    }
    int day;
    string month;
    switch(days){
    	case 0 ... 31:
    		month = "January";
    		day = days;
			break;
		
		case 32 ... 60:
			month = "February";
    		day = days - 31;
			break;
		
		case 61 ... 91:
			month = "March";
    		day = days - 60;
			break;
		
		case 92 ... 121:
			month = "April";
    		day = days - 91;
			break;
		
		case 122 ... 152:
			month = "May";
    		day = days - 121;
			break;
		
		case 153 ... 182:
			month = "June";
    		day = days - 152;
			break;
		
		case 183 ... 213:
			month = "July";
    		day = days - 182;
			break;
		
		case 214 ... 244:
			month = "August";
    		day = days - 213;
			break;
		
		case 245 ... 274:
			month = "September";
    		day = days - 244;
			break;
		
		case 275 ... 305:
			month = "October";
    		day = days - 274;
			break;
		
		case 306 ... 335:
			month = "November";
    		day = days - 305;
			break;
		
		case 336 ... 366:
			month = "December";
    		day = days - 335;
			break;
		
		default:
			cout << "Invalid days in NIC number";
	}
//    if (days <= 31) {
//        month = "January";
//        day = days;
//    } else if (days <= 60) {
//        month = "February";
//        day = days - 31;
//    } else if (days <= 91) {
//        month = "March";
//        day = days - 60;
//    } else if (days <= 121) {
//        month = "April";
//        day = days - 91;
//    } else if (days <= 152) {
//        month = "May";
//        day = days - 121;
//    } else if (days <= 182) {
//        month = "June";
//        day = days - 152;
//    } else if (days <= 213) {
//        month = "July";
//        day = days - 182;
//    } else if (days <= 244) {
//        month = "August";
//        day = days - 213;
//    } else if (days <= 274) {
//        month = "September";
//        day = days - 244;
//    } else if (days <= 305) {
//        month = "October";
//        day = days - 274;
//    } else if (days <= 335) {
//        month = "November";
//        day = days - 305;
//    } else if (days <= 366) {
//        month = "December";
//        day = days - 335;
//    } else {
//        cout << "Invalid days value in NIC number." << endl;
//        return 1;
//    }
    cout << "Your Birthday is " << birth_year << " " << month << " " << day << endl;
    cout << "Gender: " << gender << endl;

    return 0;
}
