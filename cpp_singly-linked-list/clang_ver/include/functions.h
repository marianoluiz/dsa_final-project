#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student
{
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

#endif // STUDENT_H