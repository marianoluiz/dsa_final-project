#include <iostream>
#include <string>
#include <windows.h>

// g++ "GROUP 4_DSA_DOUBLE LINKED LIST.cpp" -o "GROUP 4_DSA_DOUBLE LINKED LIST.exe"
// "GROUP 4_DSA_DOUBLE LINKED LIST.exe"
struct STUDREC {
    char No[13];
    char Name[25];
    char Cyr[10];
    float GWA;
    struct STUDREC* next;
    struct STUDREC* prev;
};

STUDREC* head = NULL;
STUDREC* tail = NULL;

void gotoxy(short x, short y);
void createStudentRecord();
void displayTopToBottom();
void displayBottomToTop();
void addRecordAtHead();
void addRecordAtEnd();
void addRecordBeforeSpecific();
void addRecordAfterSpecific();
void deleteRecordAtHead();
void deleteRecordAtTail();
void deleteRecordUsingSpecific();
void deleteRecordBeforeSpecific();
void deleteRecordAfterSpecific();

int main() {
    int choice;

    do {
        std::cout << "Main Menu:\n";
        std::cout << "1. Create a Student Record\n";
        std::cout << "2. Display Student Records (Top to Bottom)\n";
        std::cout << "3. Display Student Records (Bottom to Top)\n";
        std::cout << "4. Add a Student Record at the Head\n";
        std::cout << "5. Add a Student Record at the End\n";
        std::cout << "6. Add a Record Before a Specific Student Number\n";
        std::cout << "7. Add a Record After a Specific Student Number\n";
        std::cout << "8. Delete a Record at the Head\n";
        std::cout << "9. Delete a Record at the Tail\n";
        std::cout << "10. Delete a Record Using a Specific Student Number\n";
        std::cout << "11. Delete a Record Before a Specific Student Number\n";
        std::cout << "12. Delete a Record After a Specific Student Number\n";
        std::cout << "13. Exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createStudentRecord();
                break;
            case 2:
                displayTopToBottom();
                break;
            case 3:
                displayBottomToTop();
                break;
            case 4:
                addRecordAtHead();
                break;
            case 5:
                addRecordAtEnd();
                break;
            case 6:
                addRecordBeforeSpecific();
                break;
            case 7:
                addRecordAfterSpecific();
                break;
            case 8:
                deleteRecordAtHead();
                break;
            case 9:
                deleteRecordAtTail();
                break;
            case 10:
                deleteRecordUsingSpecific();
                break;
            case 11:
                deleteRecordBeforeSpecific();
                break;
            case 12:
                deleteRecordAfterSpecific();
                break;
            case 13:
                exit(0);
                break;
            default:
                std::cout << "Invalid choice! Please enter a valid option.\n";
        }

        std::cout << "\nPress any key to continue...";
        std::cin.ignore();
        std::cin.get();
        system("cls");

    } while (true);

    return 0;
}

void createStudentRecord() {
    if (head != NULL) {
        std::cout << "You already have a record created!";
        return;
    }

    char choice;
    do {
        STUDREC* newStudent = new STUDREC();
        std::cout << "\nEnter Student Number: ";
        std::cin >> newStudent->No;
        std::cout << "Enter Student Name: ";
        std::cin.ignore();
        std::cin.getline(newStudent->Name, sizeof(newStudent->Name));
        std::cout << "Enter Student Cyr: ";
        std::cin.getline(newStudent->Cyr, sizeof(newStudent->Cyr));
        std::cout << "Enter Student GWA: ";
        std::cin >> newStudent->GWA;

        newStudent->next = NULL;
        newStudent->prev = NULL;

        if (head == NULL) {
            head = newStudent;
            tail = newStudent;
        } else {
            tail->next = newStudent;
            newStudent->prev = tail;
            tail = newStudent;
        }

        std::cout << "\nDo you want to add more student records? (Y/N): ";
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');
}

void displayTopToBottom() {
    if (head == NULL) {
        std::cout << "\nNo student records found!\n";
        return;
    }
    system("cls");
    int row = 0;

    STUDREC* current = head;
    std::cout << "Student Records (Top to Bottom): ";
    gotoxy(0, 2 + row); std::cout << "Student Number";
    gotoxy(30, 2 + row); std::cout << "Student Name";
    gotoxy(60, 2 + row); std::cout << "Student Cyr";
    gotoxy(90, 2 + row); std::cout << "Student GWA";

    while (current != NULL) {
        gotoxy(0, 3 + row); std::cout << current->No;
        gotoxy(30, 3 + row); std::cout << current->Name;
        gotoxy(60, 3 + row); std::cout << current->Cyr;
        gotoxy(90, 3 + row); std::cout << current->GWA;
        row++;
        current = current->next;
    }
}

void displayBottomToTop() {
    if (tail == NULL) {
        std::cout << "\nNo student records found!\n";
        return;
    }
    system("cls");
    int row = 0;

    STUDREC* current = tail;

    std::cout << "Student Records (Bottom to Top):";
    gotoxy(0, 2 + row); std::cout << "Student Number";
    gotoxy(30, 2 + row); std::cout << "Student Name";
    gotoxy(60, 2 + row); std::cout << "Student Cyr";
    gotoxy(90, 2 + row); std::cout << "Student GWA";

    while (current != NULL) {
        gotoxy(0, 3 + row); std::cout << current->No;
        gotoxy(30, 3 + row); std::cout << current->Name;
        gotoxy(60, 3 + row); std::cout << current->Cyr;
        gotoxy(90, 3 + row); std::cout << current->GWA;
        row++;
        current = current->prev;
    }
}

void addRecordAtHead() {
    STUDREC* newStudent = new STUDREC();
    std::cout << "\nEnter Student Number: ";
    std::cin >> newStudent->No;
    std::cout << "Enter Student Name: ";
    std::cin.ignore();
    std::cin.getline(newStudent->Name, sizeof(newStudent->Name));
    std::cout << "Enter Student Cyr: ";
    std::cin.getline(newStudent->Cyr, sizeof(newStudent->Cyr));
    std::cout << "Enter Student GWA: ";
    std::cin >> newStudent->GWA;

    newStudent->next = head;
    newStudent->prev = NULL;

    if (head != NULL) {
        head->prev = newStudent;
    }

    head = newStudent;

    std::cout << "\nStudent record added at the head.\n";
}

void addRecordAtEnd() {
    STUDREC* newStudent = new STUDREC();
    std::cout << "\nEnter Student Number: ";
    std::cin >> newStudent->No;
    std::cout << "Enter Student Name: ";
    std::cin.ignore();
    std::cin.getline(newStudent->Name, sizeof(newStudent->Name));
    std::cout << "Enter Student Cyr: ";
    std::cin.getline(newStudent->Cyr, sizeof(newStudent->Cyr));
    std::cout << "Enter Student GWA: ";
    std::cin >> newStudent->GWA;

    newStudent->next = NULL;
    newStudent->prev = tail;

    if (tail != NULL) {
        tail->next = newStudent;
    }

    tail = newStudent;

    if (head == NULL) {
        head = tail;
    }

    std::cout << "\nStudent record added at the end.\n";
}

void addRecordBeforeSpecific() {
    std::string studentNo;
    std::cout << "\nEnter the student number before which you want to add a record: ";
    std::cin >> studentNo;

    STUDREC* current = head;
    while (current != NULL) {
        if (studentNo == current->No) {
            STUDREC* newStudent = new STUDREC();
            std::cout << "\nEnter Student Number: ";
            std::cin >> newStudent->No;
            std::cout << "Enter Student Name: ";
            std::cin.ignore();
            std::cin.getline(newStudent->Name, sizeof(newStudent->Name));
            std::cout << "Enter Student Cyr: ";
            std::cin.getline(newStudent->Cyr, sizeof(newStudent->Cyr));
            std::cout << "Enter Student GWA: ";
            std::cin >> newStudent->GWA;

            newStudent->next = current;
            newStudent->prev = current->prev;

            if (current->prev != NULL) {
                current->prev->next = newStudent;
            } else {
                head = newStudent;
            }

            current->prev = newStudent;

            std::cout << "\nStudent record added before student number " << studentNo << ".\n";
            return;
        }
        current = current->next;
    }

    std::cout << "\nStudent number " << studentNo << " not found!\n";
}

void addRecordAfterSpecific() {
    std::string studentNo;
    std::cout << "\nEnter the student number after which you want to add a record: ";
    std::cin >> studentNo;

    STUDREC* current = head;
    while (current != NULL) {
        if (studentNo == current->No) {
            STUDREC* newStudent = new STUDREC();
            std::cout << "\nEnter Student Number: ";
            std::cin >> newStudent->No;
            std::cout << "Enter Student Name: ";
            std::cin.ignore();
            std::cin.getline(newStudent->Name, sizeof(newStudent->Name));
            std::cout << "Enter Student Cyr: ";
            std::cin.getline(newStudent->Cyr, sizeof(newStudent->Cyr));
            std::cout << "Enter Student GWA: ";
            std::cin >> newStudent->GWA;

            newStudent->next = current->next;
            newStudent->prev = current;

            if (current->next != NULL) {
                current->next->prev = newStudent;
            } else {
                tail = newStudent;
            }

            current->next = newStudent;

            std::cout << "\nStudent record added after student number " << studentNo << ".\n";
            return;
        }
        current = current->next;
    }

    std::cout << "\nStudent number " << studentNo << " not found!\n";
}

void deleteRecordAtHead() {
    if (head == NULL) {
        std::cout << "\nNo student records found!\n";
        return;
    }

    STUDREC* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
    delete temp;

    std::cout << "\nRecord at the head deleted.\n";
}

void deleteRecordAtTail() {
    if (tail == NULL) {
        std::cout << "\nNo student records found!\n";
        return;
    }

    STUDREC* temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    delete temp;

    std::cout << "\nRecord at the tail deleted.\n";
}

void deleteRecordUsingSpecific() {
    std::string studentNo;
    std::cout << "\nEnter the student number you want to delete: ";
    std::cin >> studentNo;

    STUDREC* current = head;
    while (current != NULL) {
        if (studentNo == current->No) {
            if (current == head) {
                deleteRecordAtHead();
                std::cout << "\nRecord with student number " << studentNo << " deleted.\n";
                return;
            } else if (current == tail) {
                deleteRecordAtTail();
                std::cout << "\nRecord with student number " << studentNo << " deleted.\n";
                return;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                std::cout << "\nRecord with student number " << studentNo << " deleted.\n";
                return;
            }
        }
        current = current->next;
    }

    std::cout << "\nStudent number " << studentNo << " not found!\n";
}

void deleteRecordBeforeSpecific() {
    std::string studentNo;
    std::cout << "\nEnter the student number before which you want to delete a record: ";
    std::cin >> studentNo;

    STUDREC* current = head;
    while (current != NULL) {
        if (studentNo == current->No) {
            if (current->prev == NULL) {
                std::cout << "\nNo record found before student number " << studentNo << ".\n";
                return;
            } else {
                STUDREC* temp = current->prev;
                if (temp == head) {
                    deleteRecordAtHead();
                    std::cout << "\nRecord before student number " << studentNo << " deleted.\n";
                    return;
                } else {
                    current->prev = temp->prev;
                    temp->prev->next = current;
                    delete temp;
                    std::cout << "\nRecord before student number " << studentNo << " deleted.\n";
                    return;
                }
            }
        }
        current = current->next;
    }

    std::cout << "\nStudent number " << studentNo << " not found!\n";
}

void deleteRecordAfterSpecific() {
    std::string studentNo;
    std::cout << "\nEnter the student number after which you want to delete a record: ";
    std::cin >> studentNo;

    STUDREC* current = head;
    while (current != NULL) {
        if (studentNo == current->No) {
            if (current->next == NULL) {
                std::cout << "\nNo record found after student number " << studentNo << ".\n";
                return;
            } else {
                STUDREC* temp = current->next;
                if (temp == tail) {
                    deleteRecordAtTail();
                    std::cout << "\nRecord after student number " << studentNo << " deleted.\n";
                    return;
                } else {
                    current->next = temp->next;
                    temp->next->prev = current;
                    delete temp;
                    std::cout << "\nRecord after student number " << studentNo << " deleted.\n";
                    return;
                }
            }
        }
        current = current->next;
    }

    std::cout << "\nStudent number " << studentNo << " not found!\n";
}

void gotoxy(short x, short y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
