#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct STUDREC {
    char No[13];
    char Name[25];
    char Cyr[10];
    float GWA;
    struct STUDREC *next;
} STUDREC;

STUDREC *FRONT = NULL;
STUDREC *REAR = NULL;

void createQueue();
void traversalNoRepeating();
void traversalWithRepeating();
void addNode();
void deleteNode();
void gotoxy(short x, short y);

int main() {
    int choice;
    char ch;

    do {
        system("cls");
        printf("Main Menu:\n");
        printf("1. Create Queue\n");
        printf("2. Traversal of Queue (No Repeating Data)\n");
        printf("3. Traversal of Queue (With Repeating Data)\n");
        printf("4. Adding of Node for Queue\n");
        printf("5. Deletion of Node for Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Invalid choice! Please try again.\n");
        }

        printf("\nPress any key to continue...");
        getchar(); 
        getchar();
    } while (1);

    return 0;
}

void createQueue() {
    if (FRONT != NULL) {
        printf("You already have queue/s.\n");
        return;
    }

    char choice;
    do {
        STUDREC *newNode = (STUDREC*)malloc(sizeof(STUDREC));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            STUDREC *temp = FRONT;
            while (temp != NULL) {
                STUDREC *next = temp->next;
                free(temp);
                temp = next;
            }
            exit(1);
        }

        printf("\nEnter student No: ");
        scanf("%s", newNode->No);
        printf("Enter student Name: ");
        scanf(" %[^\n]", newNode->Name);
        printf("Enter student Course and Year: ");
        scanf(" %[^\n]", newNode->Cyr);
        printf("Enter student GWA: ");
        scanf("%f", &newNode->GWA);

        newNode->next = NULL;

        if (FRONT == NULL) {
            FRONT = REAR = newNode;
        } else {
            REAR->next = newNode;
            REAR = newNode;
        }

        printf("\nDo you want to add more records? [Y/N]: ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
}

void traversalNoRepeating() {
    if (FRONT == NULL) {
        printf("The queue is empty!\n");
        return;
    }

    system("cls");

    STUDREC *TravNode = FRONT;
    int row = 0;
    int repeated = 0; 
    printf("Student Records:");
    gotoxy(0, 2 + row); printf("Student Number");
    gotoxy(25, 2 + row); printf("Student Name");
    gotoxy(50, 2 + row); printf("Student Cyr");
    gotoxy(75, 2 + row); printf("Student GWA");


    gotoxy(0, 3 + row); printf("%s", TravNode->No);
    gotoxy(25, 3 + row); printf("%s", TravNode->Name);
    gotoxy(50, 3 + row); printf("%s", TravNode->Cyr);
    gotoxy(75, 3 + row); printf("%.2f", TravNode->GWA);
    row++;

    char Flag[13];
    strcpy(Flag, TravNode->No); 

    TravNode = TravNode->next;

    while (TravNode != NULL && !repeated) {

        if (strcmp(Flag, TravNode->No) != 0) {
            gotoxy(0, 3 + row); printf("%s", TravNode->No);
            gotoxy(25, 3 + row); printf("%s", TravNode->Name);
            gotoxy(50, 3 + row); printf("%s", TravNode->Cyr);
            gotoxy(75, 3 + row); printf("%.2f", TravNode->GWA);
            row++;
        } else {
            repeated = 1; 
        }

        TravNode = TravNode->next;
    }

    if (repeated) {
        printf("\nTraversal stopped.\n");
    }
}

void traversalWithRepeating() {
    if (FRONT == NULL) {
        printf("The queue is empty!\n");
        return;
    }

    system("cls");

    STUDREC *TravNode = FRONT;
    STUDREC *TempQueue = NULL;
    STUDREC *TempQueueTail = NULL; 

    int row = 0;

    printf("Student Records:");
    gotoxy(0,2+row);	printf("Student Number");
    gotoxy(25,2+row);	printf("Student Name");
    gotoxy(50,2+row);	printf("Student Cyr");
    gotoxy(75,2+row);	printf("Student GWA");

    while (TravNode != NULL) {
        gotoxy(0,3+row); printf("%s", TravNode->No);
        gotoxy(25,3+row); printf("%s", TravNode->Name);
        gotoxy(50,3+row); printf("%s", TravNode->Cyr);
        gotoxy(75,3+row); printf("%.2f", TravNode->GWA);
        row++;


        STUDREC *newNode = (STUDREC*)malloc(sizeof(STUDREC));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        strcpy(newNode->No, TravNode->No);
        strcpy(newNode->Name, TravNode->Name);
        strcpy(newNode->Cyr, TravNode->Cyr);
        newNode->GWA = TravNode->GWA;
        newNode->next = NULL;

        if (TempQueue == NULL) {
            TempQueue = newNode;
            TempQueueTail = newNode;
        } else {
            TempQueueTail->next = newNode;
            TempQueueTail = newNode;
        }

   
        TravNode = TravNode->next;
    }


    while (FRONT != NULL) {
        STUDREC *temp = FRONT;
        FRONT = FRONT->next;
        free(temp);
    }
    REAR = NULL; 

    FRONT = TempQueue;
    REAR = TempQueueTail;
}


void addNode() {
    STUDREC *newNode = (STUDREC*)malloc(sizeof(STUDREC));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
    
        STUDREC *temp = FRONT;
        while (temp != NULL) {
            STUDREC *next = temp->next;
            free(temp);
            temp = next;
        }
        exit(1);
    }

    printf("\nEnter student No: ");
    scanf("%s", newNode->No);
    printf("Enter student Name: ");
    scanf(" %[^\n]", newNode->Name);
    printf("Enter student Course and Year: ");
    scanf(" %[^\n]", newNode->Cyr);
    printf("Enter student GWA: ");
    scanf("%f", &newNode->GWA);

    newNode->next = NULL;

    if (FRONT == NULL) {
        FRONT = REAR = newNode;
    } else {
        REAR->next = newNode;
        REAR = newNode;
    }
}

void deleteNode() {
    if (FRONT == NULL) {
        printf("The queue is empty!\n");
        return;
    }

    STUDREC *temp = FRONT;
    FRONT = FRONT->next;
    free(temp);
    printf("Node deleted successfully.\n");
}

void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
