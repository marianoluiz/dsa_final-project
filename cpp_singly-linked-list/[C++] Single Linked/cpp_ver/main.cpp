#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

typedef struct Student {
    string studNo;  
    char studName[50];
    char courseYear[10];
    float gwa;
    struct Student* next;
} Student;

void gotoxy(int x, int y);
void createList(Student** START);
void addAtBeginning(Student** START);
void addAtEnd(Student** START);
void displayRecords(Student* START);
void insertBeforeNode(Student** START, string searchStudNo);
void insertAfterNode(Student* START, string searchStudNo);
void deleteNodeAtStart(Student** START);
void deleteNodeAtEnd(Student** START);
void deleteByValue(Student** headRef, string target);

int main() {
    Student* START = NULL;
    int choice;

    do {
        system("cls");
        cout << "\n<@@ STUDENT RECORD MANAGEMENT @@>\n";
        cout << "1. Create record of student\n";
        cout << "2. Add a new student record at the beginning\n";
        cout << "3. Add a new student record at the end\n";
        cout << "4. Display student records\n";
        cout << "5. Insert a new record before a specific student number\n";
        cout << "6. Insert a new record after a specific student number\n";
        cout << "7. Delete a record at the start\n";
        cout << "8. Delete a record at the end\n";
        cout << "9. Delete a record by student number\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createList(&START);
                break;
            case 2:
                addAtBeginning(&START);
                break;
            case 3:
                addAtEnd(&START);
                break;
            case 4:
                displayRecords(START);
                break;
            case 5: {
                string searchStudNo;
                cout << "\nEnter the student number before which you want to insert a new record: ";
                cin >> searchStudNo;
                insertBeforeNode(&START, searchStudNo);
                break;
            }
            case 6: {
                string searchStudNo;
                cout << "\nEnter the student number after which you want to insert a new record: ";
                cin >> searchStudNo;
                insertAfterNode(START, searchStudNo);
                break;
            }
            case 7:
                deleteNodeAtStart(&START);
                break;
            case 8:
                deleteNodeAtEnd(&START);
                break;
            case 9: {
                string target;
                cout << "Enter the student number to delete: ";
                cin >> target;
                deleteByValue(&START, target);
                break;
            }
            case 10:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << "\nPress any key to continue...";
        getch();  
    } while (choice != 10);

    // Cleanup the allocated memory
    while (START != NULL) {
        Student* temp = START;
        START = START->next;
        delete temp;
    }

    return 0;
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void createList(Student** START) {
    if (*START != NULL) {
        cout << "There is already a student list created.\n";
        return;
    }

    char resp;
    do {
        Student* newNode = new Student;
        if (newNode == NULL) {
            cout << "Memory allocation failed.\n";
            return;
        }

        cout << "\nEnter student number: ";
        cin >> newNode->studNo;
        cout << "Enter student name: ";
        cin.ignore();
        cin.getline(newNode->studName, 50);
        cout << "Enter course and year: ";
        cin.getline(newNode->courseYear, 10);
        cout << "Enter GWA: ";
        cin >> newNode->gwa;

        newNode->next = NULL;

        if (*START == NULL) {
            *START = newNode;
        } else {
            Student* temp = *START;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "\nDo you want to add more students [Y/N]? : ";
        cin >> resp;

    } while (resp == 'Y' || resp == 'y');
    cout << "Student(s) added successfully!\n";
}

void addAtBeginning(Student** START) {
    Student* newNode = new Student;
    if (newNode == NULL) {
        cout << "Memory allocation failed.\n";
        return;
    }

    cout << "Enter student number: ";
    cin >> newNode->studNo;
    cout << "Enter student name: ";
    cin.ignore();
    cin.getline(newNode->studName, 50);
    cout << "Enter course and year: ";
    cin.getline(newNode->courseYear, 10);
    cout << "Enter GWA: ";
    cin >> newNode->gwa;

    newNode->next = *START;
    *START = newNode;
    cout << "Student added successfully!\n";
}

void addAtEnd(Student** START) {
    Student* newNode = new Student;
    if (newNode == NULL) {
        cout << "Memory allocation failed.\n";
        return;
    }

    cout << "Enter student number: ";
    cin >> newNode->studNo;
    cout << "Enter student name: ";
    cin.ignore();
    cin.getline(newNode->studName, 50);
    cout << "Enter course and year: ";
    cin.getline(newNode->courseYear, 10);
    cout << "Enter GWA: ";
    cin >> newNode->gwa;

    newNode->next = NULL;
    cout << "Student added successfully!\n";

    if (*START == NULL) {
        *START = newNode;
    } else {
        Student* temp = *START;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayRecords(Student* START) {
    system("cls");
    int ctr = 1;
    cout << "\n\n";
    gotoxy(30, 0);
    cout << "STUDENT'S GWA REPORT\n\n";
    gotoxy(0, 2); cout << "Student No.";
    gotoxy(20, 2); cout << "Student Name";
    gotoxy(50, 2); cout << "Course & Year";
    gotoxy(70, 2); cout << "GWA";
   
    ctr = 1;
    Student* current = START;
    while (current != NULL) {
        gotoxy(0, 2 + ctr);
        cout << setw(15) << left << current->studNo;
        gotoxy(20, 2 + ctr);
        cout << setw(30) << left << current->studName;
        gotoxy(50, 2 + ctr);
        cout << setw(20) << left << current->courseYear;
        gotoxy(70, 2 + ctr);
        cout << fixed << setprecision(2) << current->gwa;  
        current = current->next;
        ctr++;
    }
}

void insertBeforeNode(Student** START, string searchStudNo) {
    Student* newNode = new Student;
    if (newNode == NULL) {
        cout << "Memory allocation failed.\n";
        return;
    }

    Student* current = *START;
    Student* prev = NULL;

    while (current != NULL && current->studNo != searchStudNo) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Student number " << searchStudNo << " not found.\n";
        delete newNode;
        return;
    }

    cout << "Enter student number: ";
    cin >> newNode->studNo;
    cout << "Enter student name: ";
    cin.ignore();
    cin.getline(newNode->studName, 50);
    cout << "Enter course and year: ";
    cin.getline(newNode->courseYear, 10);
    cout << "Enter GWA: ";
    cin >> newNode->gwa;

    if (*START == NULL || (*START)->studNo == searchStudNo) {
        newNode->next = *START;
        *START = newNode;
        cout << "Student added successfully!\n";
        return;
    }

    prev->next = newNode;
    newNode->next = current;
    cout << "Student added successfully!\n";
}

void insertAfterNode(Student* START, string searchStudNo) {
    Student* newNode = new Student;
    if (newNode == NULL) {
        cout << "Memory allocation failed.\n";
        return;
    }

    Student* current = START;
    while (current != NULL && current->studNo != searchStudNo) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Student number " << searchStudNo << " not found.\n";
        delete newNode;
        return;
    }

    cout << "Enter student number: ";
    cin >> newNode->studNo;
    cout << "Enter student name: ";
    cin.ignore();
    cin.getline(newNode->studName, 50);
    cout << "Enter course and year: ";
    cin.getline(newNode->courseYear, 10);
    cout << "Enter GWA: ";
    cin >> newNode->gwa;

    newNode->next = current->next;
    current->next = newNode;
    cout << "Student added successfully!\n";
}

void deleteNodeAtStart(Student** START) {
    if (*START == NULL) {
        cout << "No records to delete.\n";
        return;
    }

    Student* temp = *START;
    *START = (*START)->next;
    delete temp;
    cout << "Record deleted successfully!\n";
}

void deleteNodeAtEnd(Student** START) {
    if (*START == NULL) {
        cout << "No records to delete.\n";
        return;
    }

    Student* current = *START;
    Student* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
    } else {
        *START = NULL;
    }

    delete current;
    cout << "Record deleted successfully!\n";
}

void deleteByValue(Student** headRef, string target) {
    Student* current = *headRef;
    Student* prev = NULL;

    while (current != NULL && current->studNo != target) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Record not found.\n";
        return;
    }

    if (prev == NULL) {
        *headRef = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
    cout << "Record deleted successfully!\n";
}

