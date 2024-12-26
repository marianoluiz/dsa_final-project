#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "functions.h"

// Go to the position
void gotoxy(int x, int y)
{
  printf("\033[%d;%dH", y, x);
}

void createList(Student **START)
{
  if (*START != NULL)
  {
    printf("There is already a student list created.\n");
    return;
  }

  char resp;
  do
  {
    Student *newNode = (Student *)malloc(sizeof(Student));
    if (newNode == NULL)
    {
      printf("Memory allocation failed.\n");
      return;
    }

    printf("\nEnter student number: ");
    scanf("%d", &newNode->studNo);
    printf("Enter student name: ");
    scanf(" %[^\n]", newNode->studName);
    printf("Enter course and year: ");
    scanf(" %[^\n]", newNode->courseYear);
    printf("Enter GWA: ");
    scanf("%f", &newNode->gwa);

    newNode->next = NULL;

    if (*START == NULL)
    {
      *START = newNode;
    }
    else
    {
      Student *temp = *START;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    }

    printf("\nDo you want to add more students [Y/N]? : ");
    scanf(" %c", &resp);

  } while (resp == 'Y' || resp == 'y');
  printf("Student(s) added successfully!\n");
}

void addAtBeginning(Student **START)
{
  Student *newNode = (Student *)malloc(sizeof(Student));
  if (newNode == NULL)
  {
    printf("Memory allocation failed.\n");
    return;
  }

  printf("Enter student number: ");
  scanf("%d", &newNode->studNo);
  printf("Enter student name: ");
  scanf(" %[^\n]", newNode->studName);
  printf("Enter course and year: ");
  scanf(" %[^\n]", newNode->courseYear);
  printf("Enter GWA: ");
  scanf("%f", &newNode->gwa);

  newNode->next = *START;
  *START = newNode;
  printf("Student added successfully!\n");
}

void addAtEnd(Student **START)
{
  Student *newNode = (Student *)malloc(sizeof(Student));
  if (newNode == NULL)
  {
    printf("Memory allocation failed.\n");
    return;
  }

  printf("Enter student number: ");
  scanf("%d", &newNode->studNo);
  printf("Enter student name: ");
  scanf(" %[^\n]", newNode->studName);
  printf("Enter course and year: ");
  scanf(" %[^\n]", newNode->courseYear);
  printf("Enter GWA: ");
  scanf("%f", &newNode->gwa);

  newNode->next = NULL;
  printf("Student added successfully!\n");

  if (*START == NULL)
  {
    *START = newNode;
  }
  else
  {
    Student *temp = *START;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void displayRecords(Student *START)
{
  system("cls");
  int ctr = 1;
  printf("\n\n");
  gotoxy(40, 0);
  printf("STUDENT'S GWA REPORT\n\n");
  gotoxy(5, 2);
  printf("Student No.");
  gotoxy(25, 2);
  printf("Student Name");
  gotoxy(55, 2);
  printf("Course & Year");
  gotoxy(85, 2);
  printf("GWA");

  ctr = 1;
  Student *current = START;
  while (current != NULL)
  {
    gotoxy(5, 2 + ctr);
    printf("%-20d", current->studNo);
    gotoxy(25, 2 + ctr);
    printf("%-30s", current->studName);
    gotoxy(55, 2 + ctr);
    printf("%-20s", current->courseYear);
    gotoxy(85, 2 + ctr);
    printf("%.2f", current->gwa);
    current = current->next;
    ctr++;
  }
}

void insertBeforeNode(Student **START, int searchStudNo)
{
  Student *newNode = (Student *)malloc(sizeof(Student));
  if (newNode == NULL)
  {
    printf("Memory allocation failed.\n");
    return;
  }

  Student *current = *START;
  Student *prev = NULL;

  while (current != NULL && current->studNo != searchStudNo)
  {
    prev = current;
    current = current->next;
  }

  if (current == NULL)
  {
    printf("Student number %d not found.\n", searchStudNo);
    free(newNode);
    return;
  }

  printf("Enter student number: ");
  scanf("%d", &newNode->studNo);
  printf("Enter student name: ");
  scanf(" %[^\n]", newNode->studName);
  printf("Enter course and year: ");
  scanf(" %[^\n]", newNode->courseYear);
  printf("Enter GWA: ");
  scanf("%f", &newNode->gwa);

  if (*START == NULL || (*START)->studNo == searchStudNo)
  {
    newNode->next = *START;
    *START = newNode;
    printf("Student added successfully!\n");
    return;
  }

  prev->next = newNode;
  newNode->next = current;
  printf("Student added successfully!\n");
}

void insertAfterNode(Student *START, int searchStudNo)
{
  Student *newNode = (Student *)malloc(sizeof(Student));
  if (newNode == NULL)
  {
    printf("Memory allocation failed.\n");
    return;
  }

  while (START != NULL && START->studNo != searchStudNo)
  {
    START = START->next;
  }

  if (START == NULL)
  {
    printf("Student number %d not found.\n", searchStudNo);
    return;
  }

  printf("Enter student number: ");
  scanf("%d", &newNode->studNo);
  printf("Enter student name: ");
  scanf(" %[^\n]", newNode->studName);
  printf("Enter course and year: ");
  scanf(" %[^\n]", newNode->courseYear);
  printf("Enter GWA: ");
  scanf("%f", &newNode->gwa);

  newNode->next = START->next;
  START->next = newNode;
}

void deleteNodeAtStart(Student **START)
{
  if (*START == NULL)
  {
    printf("List is empty. No student record to delete.\n");
    return;
  }

  Student *temp = *START;
  *START = (*START)->next;
  free(temp);
  printf("Student record at the start deleted successfully.\n");
}

void deleteNodeAtEnd(Student **START)
{
  if (*START == NULL)
  {
    printf("List is empty. No student record to delete.\n");
    return;
  }

  Student *temp = *START;
  if (temp->next == NULL)
  {
    free(temp);
    *START = NULL;
    printf("Deleted the only student record in the list.\n");
    return;
  }

  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }

  free(temp->next);
  temp->next = NULL;
  printf("Student record at the end deleted successfully.\n");
}

void deleteByValue(Student **headRef, int target)
{
  Student *temp = *headRef;
  Student *prev = NULL;

  if (temp != NULL && temp->studNo == target)
  {
    *headRef = temp->next;
    free(temp);
    printf("Student record with student number %d deleted successfully.\n", target);
    return;
  }

  while (temp != NULL && temp->studNo != target)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
  {
    printf("Student record with student number %d not found.\n", target);
    return;
  }

  prev->next = temp->next;
  free(temp);
  printf("Student record with student number %d deleted successfully.\n", target);
}
