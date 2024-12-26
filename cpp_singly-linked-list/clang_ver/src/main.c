#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

typedef struct Student {
    int studNo;
    char studName[50];
    char courseYear[10];
    float gwa;
    struct Student *next;
} Student;

void gotoxy(int x, int y);
void createList(Student **START);
void addAtBeginning(Student **START);
void addAtEnd(Student **START);
void displayRecords(Student *START);
void insertBeforeNode(Student **START, int searchStudNo);
void insertAfterNode(Student *START, int searchStudNo);
void deleteNodeAtStart(Student **START);
void deleteNodeAtEnd(Student **START);
void deleteByValue(Student **headRef, int target);

// gcc *.c -I../include -o main && main

int main() {
    Student *START = NULL;
    int choice;

    do {
        system("cls");
        printf("\n<@@ STUDENT RECORD MANAGEMENT @@>\n");
        printf("1. Create record of student\n");
        printf("2. Add a new student record at the beginning\n");
        printf("3. Add a new student record at the end\n");
        printf("4. Display student records\n");
        printf("5. Insert a new record before a specific student number\n");
        printf("6. Insert a new record after a specific student number\n");
        printf("7. Delete a record at the start\n");
        printf("8. Delete a record at the end\n");
        printf("9. Delete a record by student number\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                int searchStudNo;
                printf("\nEnter the student number before which you want to insert a new record: ");
                scanf("%d", &searchStudNo);
                insertBeforeNode(&START, searchStudNo);
                break;
            }
            case 6: {
                int searchStudNo;
                printf("\nEnter the student number after which you want to insert a new record: ");
                scanf("%d", &searchStudNo);
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
                int target;
                printf("Enter the student number to delete: ");
                scanf("%d", &target);
                deleteByValue(&START, target);
                break;
            }
            case 10:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nPress any key to continue...");
        getch();
    } while (choice != 10);

    while (START != NULL) {
        Student *temp = START;
        START = START->next;
        free(temp);
    }

    return 0;
}

