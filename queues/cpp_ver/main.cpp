#include <iostream>
#include <string>
#include <queue>
#include <windows.h>

struct STUDREC {
    std::string No;
    std::string Name;
    std::string Cyr;
    float GWA;
};

std::queue<STUDREC> studentQueue;

void createQueue();
void traversalNoRepeating();
void traversalWithRepeating();
void addNode();
void deleteNode();
void gotoxy(short x, short y);

int main() {
    int choice;

    do {
        system("cls");
        std::cout << "Main Menu:\n";
        std::cout << "1. Create Queue\n";
        std::cout << "2. Traversal of Queue (No Repeating Data)\n";
        std::cout << "3. Traversal of Queue (With Repeating Data)\n";
        std::cout << "4. Adding of Node for Queue\n";
        std::cout << "5. Deletion of Node for Queue\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createQueue();
                break;
            case 2:
                traversalNoRepeating();
                break;
            case 3:
                traversalWithRepeating();
                break;
            case 4:
                addNode();
                break;
            case 5:
                deleteNode();
                break;
            case 6:
                exit(0);
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }

        std::cout << "\nPress any key to continue...";
        std::cin.ignore();
        std::cin.get();
    } while (1);

    return 0;
}

void createQueue() {
    if (!studentQueue.empty()) {
        std::cout << "You already have queue/s.\n";
        return;
    }

    char choice;
    do {
        STUDREC newNode;

        std::cout << "\nEnter student No: ";
        std::cin >> newNode.No;
        std::cout << "Enter student Name: ";
        std::cin.ignore();
        std::getline(std::cin, newNode.Name);
        std::cout << "Enter student Course and Year: ";
        std::getline(std::cin, newNode.Cyr);
        std::cout << "Enter student GWA: ";
        std::cin >> newNode.GWA;

        studentQueue.push(newNode);

        std::cout << "\nDo you want to add more records? [Y/N]: ";
        std::cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}

void traversalNoRepeating() {
    if (studentQueue.empty()) {
        std::cout << "The queue is empty!\n";
        return;
    }

    system("cls");

    std::queue<STUDREC> tempQueue = studentQueue;
    int row = 0;
    bool repeated = false;
    std::string Flag;

    std::cout << "Student Records:\n";
    gotoxy(0, 2 + row); std::cout << "Student Number";
    gotoxy(25, 2 + row); std::cout << "Student Name";
    gotoxy(50, 2 + row); std::cout << "Student Cyr";
    gotoxy(75, 2 + row); std::cout << "Student GWA";

    if (!tempQueue.empty()) {
        STUDREC TravNode = tempQueue.front();
        tempQueue.pop();

        gotoxy(0, 3 + row); std::cout << TravNode.No;
        gotoxy(25, 3 + row); std::cout << TravNode.Name;
        gotoxy(50, 3 + row); std::cout << TravNode.Cyr;
        gotoxy(75, 3 + row); std::cout << TravNode.GWA;
        row++;

        Flag = TravNode.No;

        while (!tempQueue.empty() && !repeated) {
            TravNode = tempQueue.front();
            tempQueue.pop();

            if (Flag != TravNode.No) {
                gotoxy(0, 3 + row); std::cout << TravNode.No;
                gotoxy(25, 3 + row); std::cout << TravNode.Name;
                gotoxy(50, 3 + row); std::cout << TravNode.Cyr;
                gotoxy(75, 3 + row); std::cout << TravNode.GWA;
                row++;
            } else {
                repeated = true;
            }
        }
    }

    if (repeated) {
        std::cout << "\nTraversal stopped.\n";
    }
}

void traversalWithRepeating() {
    if (studentQueue.empty()) {
        std::cout << "The queue is empty!\n";
        return;
    }

    system("cls");

    std::queue<STUDREC> tempQueue;
    int row = 0;

    std::cout << "Student Records:\n";
    gotoxy(0, 2 + row); std::cout << "Student Number";
    gotoxy(25, 2 + row); std::cout << "Student Name";
    gotoxy(50, 2 + row); std::cout << "Student Cyr";
    gotoxy(75, 2 + row); std::cout << "Student GWA";

    while (!studentQueue.empty()) {
        STUDREC TravNode = studentQueue.front();
        studentQueue.pop();

        gotoxy(0, 3 + row); std::cout << TravNode.No;
        gotoxy(25, 3 + row); std::cout << TravNode.Name;
        gotoxy(50, 3 + row); std::cout << TravNode.Cyr;
        gotoxy(75, 3 + row); std::cout << TravNode.GWA;
        row++;

        tempQueue.push(TravNode);
    }

    studentQueue = tempQueue;
}

void addNode() {
    STUDREC newNode;

    std::cout << "\nEnter student No: ";
    std::cin >> newNode.No;
    std::cout << "Enter student Name: ";
    std::cin.ignore();
    std::getline(std::cin, newNode.Name);
    std::cout << "Enter student Course and Year: ";
    std::getline(std::cin, newNode.Cyr);
    std::cout << "Enter student GWA: ";
    std::cin >> newNode.GWA;

    studentQueue.push(newNode);
}

void deleteNode() {
    if (studentQueue.empty()) {
        std::cout << "The queue is empty!\n";
        return;
    }

    studentQueue.pop();
    std::cout << "Node deleted successfully.\n";
}

void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

