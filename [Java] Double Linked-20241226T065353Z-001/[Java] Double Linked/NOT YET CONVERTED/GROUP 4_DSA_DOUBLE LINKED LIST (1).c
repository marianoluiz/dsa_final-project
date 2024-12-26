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
    struct STUDREC *prev;
} STUDREC;

STUDREC *head = NULL;
STUDREC *tail = NULL;

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
    char ch;

    do {
        printf("Main Menu:\n");
        printf("1. Create a Student Record\n");
        printf("2. Display Student Records (Top to Bottom)\n");
        printf("3. Display Student Records (Bottom to Top)\n");
        printf("4. Add a Student Record at the Head\n");
        printf("5. Add a Student Record at the End\n");
        printf("6. Add a Record Before a Specific Student Number\n");
        printf("7. Add a Record After a Specific Student Number\n");
        printf("8. Delete a Record at the Head\n");
        printf("9. Delete a Record at the Tail\n");
        printf("10. Delete a Record Using a Specific Student Number\n");
        printf("11. Delete a Record Before a Specific Student Number\n");
        printf("12. Delete a Record After a Specific Student Number\n");
        printf("13. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Invalid choice! Please enter a valid option.\n");
        }

        printf("\nPress any key to continue...");
        getchar();
        getchar();
        system("cls");

    } while (1);

    return 0;
}

void createStudentRecord() {
		if (head!=NULL) {
			printf("You already have a record created!");
			return;
		}
	
    char choice;
    do {
        STUDREC *newStudent = (STUDREC *)malloc(sizeof(STUDREC));
        printf("\nEnter Student Number: ");
        scanf("%12s", newStudent->No);
        printf("Enter Student Name: ");
        getchar();
        fgets(newStudent->Name, sizeof(newStudent->Name), stdin);
        newStudent->Name[strcspn(newStudent->Name, "\n")] = '\0';
        printf("Enter Student Cyr: ");
        fgets(newStudent->Cyr, sizeof(newStudent->Name), stdin);
        newStudent->Cyr[strcspn(newStudent->Name, "\n")] = '\0';
        printf("Enter Student GWA: ");
        scanf("%f", &newStudent->GWA);

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

        printf("\nDo you want to add more student records? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');
}

void displayTopToBottom() {
    if (head == NULL) {
        printf("\nNo student records found!\n");
        return;
    }
		system("cls");
    int row = 0;
		
    STUDREC *current = head;
    printf("Student Records (Top to Bottom): ");
    gotoxy(0,2+row);	printf("Student Number");
    gotoxy(30,2+row);	printf("Student Name");
    gotoxy(60,2+row);	printf("Student Cyr");
    gotoxy(90,2+row);	printf("Student GWA");
    
    while (current != NULL) {
        gotoxy(0,3+row); printf("%s", current->No);
        gotoxy(30,3+row); printf("%s", current->Name);
        gotoxy(60,3+row); printf("%s", current->Cyr);
        gotoxy(90,3+row); printf("%.2f", current->GWA);
				row++;
        current = current->next;
    }
}

void displayBottomToTop() {
    if (tail == NULL) {
        printf("\nNo student records found!\n");
        return;
    }
    system("cls");
		int row = 0;
		
    STUDREC *current = tail;
    
    printf("Student Records (Bottom to Top):");
    gotoxy(0,2+row);	printf("Student Number");
    gotoxy(30,2+row);	printf("Student Name");
    gotoxy(60,2+row);	printf("Student Cyr");
    gotoxy(90,2+row);	printf("Student GWA");
    
    while (current != NULL) {
        gotoxy(0,3+row); printf("%s", current->No);
        gotoxy(30,3+row); printf("%s", current->Name);
        gotoxy(60,3+row); printf("%s", current->Cyr);
        gotoxy(90,3+row); printf("%.2f", current->GWA);
				row++;
        current = current->prev;
    }
}

void addRecordAtHead() {
	  STUDREC *newStudent = (STUDREC *)malloc(sizeof(STUDREC));
	  printf("\nEnter Student Number: ");
	  scanf("%12s", newStudent->No);
	  printf("Enter Student Name: ");
	  getchar();
	  fgets(newStudent->Name, sizeof(newStudent->Name), stdin);
	  newStudent->Name[strcspn(newStudent->Name, "\n")] = '\0';
	  printf("Enter Student Cyr: ");
	  fgets(newStudent->Cyr, sizeof(newStudent->Name), stdin);
	  newStudent->Cyr[strcspn(newStudent->Name, "\n")] = '\0';
	  printf("Enter Student GWA: ");
	  scanf("%f", &newStudent->GWA);

    newStudent->next = head;
    newStudent->prev = NULL;

    if (head != NULL) {
        head->prev = newStudent;
    }

    head = newStudent;

    printf("\nStudent record added at the head.\n");
}

void addRecordAtEnd() {
    STUDREC *newStudent = (STUDREC *)malloc(sizeof(STUDREC));
    printf("\nEnter Student Number: ");
    scanf("%12s", newStudent->No);
    printf("Enter Student Name: ");
    getchar();
    fgets(newStudent->Name, sizeof(newStudent->Name), stdin);
    newStudent->Name[strcspn(newStudent->Name, "\n")] = '\0';
    printf("Enter Student Cyr: ");
    fgets(newStudent->Cyr, sizeof(newStudent->Name), stdin);
    newStudent->Cyr[strcspn(newStudent->Name, "\n")] = '\0';
    printf("Enter Student GWA: ");
    scanf("%f", &newStudent->GWA);

    newStudent->next = NULL;
    newStudent->prev = tail;

    if (tail != NULL) {
        tail->next = newStudent;
    }

    tail = newStudent;

    if (head == NULL) {
        head = tail;
    }

    printf("\nStudent record added at the end.\n");
}

void addRecordBeforeSpecific() {
    char studentNo[13];
    printf("\nEnter the student number before which you want to add a record: ");
    scanf("%s", studentNo);

    STUDREC *current = head;
    while (current != NULL) {
        if (strcmp(current->No, studentNo) == 0) {
            STUDREC *newStudent = (STUDREC *)malloc(sizeof(STUDREC));
            printf("\nEnter Student Number: ");
				    scanf("%12s", newStudent->No);
				    printf("Enter Student Name: ");
				    getchar();
				    fgets(newStudent->Name, sizeof(newStudent->Name), stdin);
				    newStudent->Name[strcspn(newStudent->Name, "\n")] = '\0';
				    printf("Enter Student Cyr: ");
				    fgets(newStudent->Cyr, sizeof(newStudent->Name), stdin);
				    newStudent->Cyr[strcspn(newStudent->Name, "\n")] = '\0';
				    printf("Enter Student GWA: ");
				    scanf("%f", &newStudent->GWA);

            newStudent->next = current;
            newStudent->prev = current->prev;

            if (current->prev != NULL) {
                current->prev->next = newStudent;
            } else {
                head = newStudent;
            }

            current->prev = newStudent;

            printf("\nStudent record added before student number %s.\n", studentNo);
            return;
        }
        current = current->next;
    }

    printf("\nStudent number %s not found!\n", studentNo);
}

void addRecordAfterSpecific() {
    char studentNo[13];
    printf("\nEnter the student number after which you want to add a record: ");
    scanf("%s", studentNo);

    STUDREC *current = head;
    while (current != NULL) {
        if (strcmp(current->No, studentNo) == 0) {
            STUDREC *newStudent = (STUDREC *)malloc(sizeof(STUDREC));
            printf("\nEnter Student Number: ");
				    scanf("%12s", newStudent->No);
				    printf("Enter Student Name: ");
				    getchar();
				    fgets(newStudent->Name, sizeof(newStudent->Name), stdin);
				    newStudent->Name[strcspn(newStudent->Name, "\n")] = '\0';
				    printf("Enter Student Cyr: ");
				    fgets(newStudent->Cyr, sizeof(newStudent->Name), stdin);
				    newStudent->Cyr[strcspn(newStudent->Name, "\n")] = '\0';
				    printf("Enter Student GWA: ");
				    scanf("%f", &newStudent->GWA);

            newStudent->next = current->next;
            newStudent->prev = current;

            if (current->next != NULL) {
                current->next->prev = newStudent;
            } else {
                tail = newStudent;
            }

            current->next = newStudent;

            printf("\nStudent record added after student number %s.\n", studentNo);
            return;
        }
        current = current->next;
    }

    printf("\nStudent number %s not found!\n", studentNo);
}

void deleteRecordAtHead() {
    if (head == NULL) {
        printf("\nNo student records found!\n");
        return;
    }

    STUDREC *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
    free(temp);

    printf("\nRecord at the head deleted.\n");
}

void deleteRecordAtTail() {
    if (tail == NULL) {
        printf("\nNo student records found!\n");
        return;
    }

    STUDREC *temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);

    printf("\nRecord at the tail deleted.\n");
}

void deleteRecordUsingSpecific() {
    char studentNo[13];
    printf("\nEnter the student number you want to delete: ");
    scanf("%s", studentNo);

    STUDREC *current = head;
    while (current != NULL) {
        if (strcmp(current->No, studentNo) == 0) {
            if (current == head) {
                deleteRecordAtHead();
                printf("\nRecord with student number %s deleted.\n", studentNo);
                return;
            } else if (current == tail) {
                deleteRecordAtTail();
                printf("\nRecord with student number %s deleted.\n", studentNo);
                return;
            } else {
                current->prev->next = current->next;
                current-> next->prev = current->prev;
                free(current);
                printf("\nRecord with student number %s deleted.\n", studentNo);
                return;
            }
        }
        current = current->next;
    }

    printf("\nStudent number %s not found!\n", studentNo);
}

void deleteRecordBeforeSpecific() {
    char studentNo[13];
    printf("\nEnter the student number before which you want to delete a record: ");
    scanf("%s", studentNo);

    STUDREC *current = head;
    while (current != NULL) {
        if (strcmp(current->No, studentNo) == 0) {
            if (current->prev == NULL) {
                printf("\nNo record found before student number %s.\n", studentNo);
                return;
            } else {
                STUDREC *temp = current->prev;
                if (temp == head) {
                    deleteRecordAtHead();
                    printf("\nRecord before student number %s deleted.\n", studentNo);
                    return;
                } else {
                    current->prev = temp->prev;
                    temp->prev->next = current;
                    free(temp);
                    printf("\nRecord before student number %s deleted.\n", studentNo);
                    return;
                }
            }
        }
        current = current->next;
    }

    printf("\nStudent number %s not found!\n", studentNo);
}

void deleteRecordAfterSpecific() {
    char studentNo[13];
    printf("\nEnter the student number after which you want to delete a record: ");
    scanf("%s", studentNo);

    STUDREC *current = head;
    while (current != NULL) {
        if (strcmp(current->No, studentNo) == 0) {
            if (current->next == NULL) {
                printf("\nNo record found after student number %s.\n", studentNo);
                return;
            } else {
                STUDREC *temp = current->next;
                if (temp == tail) {
                    deleteRecordAtTail();
                    printf("\nRecord after student number %s deleted.\n", studentNo);
                    return;
                } else {
                    current->next = temp->next;
                    temp->next->prev = current;
                    free(temp);
                    printf("\nRecord after student number %s deleted.\n", studentNo);
                    return;
                }
            }
        }
        current = current->next;
    }

    printf("\nStudent number %s not found!\n", studentNo);
}

void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

