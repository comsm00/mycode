01)

#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Node structure
struct Node {
    int studentID;
    string studentName;
    Node* next;
};

// Head pointer
Node* head = NULL;

// Check whether Student ID already exists
bool idExists(int id) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->studentID == id) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Create a new student node
Node* createNode() {
    int id;
    string name;

    cout << "Enter Student ID: ";
    cin >> id;

    if (idExists(id)) {
        cout << "Student ID already exists!\n";
        return NULL;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Student Name: ";
    getline(cin, name);

    Node* newNode = new Node;
    newNode->studentID = id;
    newNode->studentName = name;
    newNode->next = NULL;

    return newNode;
}

// 1. Insert at beginning
void insertBeginning() {
    Node* newNode = createNode();

    if (newNode == NULL) {
        return;
    }

    newNode->next = head;
    head = newNode;

    cout << "Student inserted at beginning successfully!\n";
}

// 2. Insert at end
void insertEnd() {
    Node* newNode = createNode();

    if (newNode == NULL) {
        return;
    }

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Student inserted at end successfully!\n";
}

// 3. Insert after given Student ID
void insertAfter() {
    int id;

    cout << "Enter Student ID to insert after: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL && temp->studentID != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Student ID not found!\n";
        return;
    }

    Node* newNode = createNode();

    if (newNode == NULL) {
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Student inserted successfully!\n";
}

// 4. Delete student
void deleteStudent() {
    int id;

    cout << "Enter Student ID to delete: ";
    cin >> id;

    if (head == NULL) {
        cout << "Student list is empty!\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->studentID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Student ID not found!\n";
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;

    cout << "Student deleted successfully!\n";
}

// 5. Search student
void searchStudent() {
    int id;

    cout << "Enter Student ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->studentID == id) {
            cout << "Student found!\n";
            cout << "Student ID: " << temp->studentID << endl;
            cout << "Student Name: " << temp->studentName << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student not found!\n";
}

// 6. Display all students
void displayStudents() {
    if (head == NULL) {
        cout << "Student list is empty!\n";
        return;
    }

    Node* temp = head;

    cout << "\n--- STUDENT LIST ---\n";

    while (temp != NULL) {
        cout << "Student ID: " << temp->studentID << endl;
        cout << "Student Name: " << temp->studentName << endl;
        cout << "--------------------\n";

        temp = temp->next;
    }
}

// Free allocated memory
void clearList() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== STUDENT LINKED LIST =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Student ID\n";
        cout << "4. Delete Student\n";
        cout << "5. Search Student\n";
        cout << "6. Display Students\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertAfter();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                searchStudent();
                break;

            case 6:
                displayStudents();
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    clearList();
    return 0;
}


................................................................................................
    ithu java illedaa c++ la saiyye solli irukku.... athea maari destop la table la ikuretheum paakkeeddam.. ithuhale delete panni vidu
.................................................................................................................

    02)
    
#include <iostream>
#include <limits>
using namespace std;

#define MAX 10

// Stack implementation using array
class Stack {
private:
    int arr[MAX];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Check whether stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check whether stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // 1. Push element
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Stack is full.\n";
        } else {
            top++;
            arr[top] = value;

            cout << value << " pushed successfully!\n";
        }
    }

    // 2. Pop element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty.\n";
        } else {
            cout << arr[top] << " popped successfully!\n";
            top--;
        }
    }

    // 3. Peek top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element.\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // 4. Display top to bottom
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        } else {
            cout << "\nStack elements (TOP to BOTTOM):\n";

            for (int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }
    }

    // 5. Check empty
    void checkEmpty() {
        if (isEmpty()) {
            cout << "Stack is EMPTY.\n";
        } else {
            cout << "Stack is NOT empty.\n";
        }
    }

    // 6. Check full
    void checkFull() {
        if (isFull()) {
            cout << "Stack is FULL.\n";
        } else {
            cout << "Stack is NOT full.\n";
        }
    }
};

// Main function
int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n========== STACK MENU ==========\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                if (s.isFull()) {
                    cout << "Stack Overflow! Stack is full.\n";
                } else {
                    cout << "Enter value to push: ";

                    if (cin >> value) {
                        s.push(value);
                    } else {
                        cout << "Invalid value!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                s.checkEmpty();
                break;

            case 6:
                s.checkFull();
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
