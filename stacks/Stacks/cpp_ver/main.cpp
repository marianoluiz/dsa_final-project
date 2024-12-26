#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

struct STUDREC {
    std::string No;
    std::string Name;
    std::string Cyr;
    float GWA;
    STUDREC *next;
};

STUDREC *TOP = NULL;
char Resp;

void clearScreen() {
    system("cls");
}

void push(STUDREC **stack, STUDREC *node) {
    node->next = *stack;
    *stack = node;
}

void deleteTop() {
    if (TOP == NULL) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }
    STUDREC *temp = TOP;
    TOP = TOP->next;
    delete temp;
    std::cout << "Top node deleted successfully!" << std::endl;
}

void traverseStack() {
    STUDREC *current = TOP;
    if (current == NULL) {
        std::cout << "The Student Record is Empty!" << std::endl;
    } else {
        clearScreen();
        std::cout << "\t\t\t\tStudent Record" << std::endl;
        std::cout << "_________________________________________________________________\n";
        std::cout << "| " << std::setw(12) << "Number" << " | " << std::setw(25) << "Name" << " | " 
                  << std::setw(10) << "Crs & Yr" << " | " << "GWA   |" << std::endl;
        std::cout << "_________________________________________________________________\n";

        while (current != NULL) {
            std::cout << "| " << std::setw(12) << current->No << " | " << std::setw(25) << current->Name 
                      << " | " << std::setw(10) << current->Cyr << " | " << std::fixed 
                      << std::setprecision(2) << current->GWA << "  |" << std::endl;
            current = current->next;
        }

        std::cout << "_________________________________________________________________\n";
    }
}

void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    Resp = 'Y';

    do {
        clearScreen();
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Create Student Record Stack\n";
        std::cout << "2. Add Student Record\n";
        std::cout << "3. Delete Top Student Record\n";
        std::cout << "4. Display Student Records\n";
        std::cout << "5. Exit\n";
        std::cout << "\nEnter your choice: ";
        int choice;
        std::cin >> choice;

        switch(choice) {
            case 1: {
                clearScreen();
                if (TOP == NULL) {
                    std::cout << "\nCreating Student Stack...\n";

                    do {
                        STUDREC *NewNode = new STUDREC;
                        std::cin.ignore();

                        std::cout << "\nEnter Student Number: ";
                        std::getline(std::cin, NewNode->No);
                        std::cout << "Enter Student Name: ";
                        std::getline(std::cin, NewNode->Name);
                        std::cout << "Enter Student Course & Year: ";
                        std::getline(std::cin, NewNode->Cyr);
                        std::cout << "Enter Student GWA: ";
                        std::cin >> NewNode->GWA;

                        push(&TOP, NewNode);

                        std::cout << "\nAdd Another Record [Y/N]?: ";
                        std::cin >> Resp;
                    } while (toupper(Resp) == 'Y');
                } else {
                    std::cout << "\nStudent Stack already exists.\n";
                }
                break;
            }
            case 2: {
                if (TOP == NULL) {
                    std::cout << "\nPlease create the Student Stack first!\n";
                } else {
                    clearScreen();
                    do {
                        STUDREC *NewNode = new STUDREC;
                        std::cin.ignore();

                        std::cout << "\nEnter Student Number: ";
                        std::getline(std::cin, NewNode->No);
                        std::cout << "Enter Student Name: ";
                        std::getline(std::cin, NewNode->Name);
                        std::cout << "Enter Student Course & Year: ";
                        std::getline(std::cin, NewNode->Cyr);
                        std::cout << "Enter Student GWA: ";
                        std::cin >> NewNode->GWA;

                        push(&TOP, NewNode);

                        std::cout << "\nAdd Another Record [Y/N]?: ";
                        std::cin >> Resp;
                    } while (toupper(Resp) == 'Y');
                }
                break;
            }
            case 3: {
                if (TOP == NULL) {
                    std::cout << "\nPlease create the Student Stack first!\n";
                } else {
                    deleteTop();
                }
                break;
            }
            case 4: {
                if (TOP == NULL) {
                    std::cout << "\nPlease create the Student Stack first!\n";
                } else {
                    traverseStack();
                }
                break;
            }
            case 5: {
                std::cout << "Exiting program...";
                return 0;
            }
            default: {
                std::cout << "Invalid choice! Please try again.";
                break;
            }
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(); 
        std::cin.get(); 

    } while (true);

    return 0;
}

