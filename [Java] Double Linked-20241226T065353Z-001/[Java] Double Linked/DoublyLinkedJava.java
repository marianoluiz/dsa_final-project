import java.util.Scanner;

class DoublyLinkedJava {
    static class STUDREC {
        String No;
        String Name;
        String Cyr;
        float GWA;
        STUDREC next;
        STUDREC prev;
    }

    static STUDREC head = null;
    static STUDREC tail = null;

    
    public class Node {
        public int value;
        public Node prev;
        public Node next;

        public Node(int value) {
            this.value = value;
            this.prev = null;
            this.next = null;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n\nMain Menu:");
            System.out.println("1. Create a Student Record");

            System.out.println("2. Display Student Records (Top to Bottom)");
            System.out.println("3. Display Student Records (Bottom to Top)");
            System.out.println("4. Add a Student Record at the Head");
            System.out.println("5. Add a Student Record at the End");
            System.out.println("6. Add a Record Before a Specific Student Number");
            System.out.println("7. Add a Record After a Specific Student Number");
            System.out.println("8. Delete a Record at the Head");
            System.out.println("9. Delete a Record at the Tail");
            System.out.println("10. Delete a Record Using a Specific Student Number");
            System.out.println("11. Delete a Record Before a Specific Student Number");
            System.out.println("12. Delete a Record After a Specific Student Number");
            System.out.println("13. Exit");

            System.out.print("Enter your choice: ");
            choice = input.nextInt();

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
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice! Please enter a valid option.");
            }

            System.out.println("\nPress any key to continue...");
            input.nextLine();
            input.nextLine();
            clearScreen();

        } while (true);

    }

    static void createStudentRecord() {
        Scanner input = new Scanner(System.in);
        if (head != null) {
            System.out.println("You already have a record created!");
            return;
        }

        char choice;
        do {
            STUDREC newStudent = new STUDREC();
            System.out.print("\nEnter Student Number: ");
            newStudent.No = input.nextLine();
            System.out.print("Enter Student Name: ");
            newStudent.Name = input.nextLine();
            System.out.print("Enter Student Cyr: ");
            newStudent.Cyr = input.nextLine();
            System.out.print("Enter Student GWA: ");
            newStudent.GWA = input.nextFloat();

            newStudent.next = null;
            newStudent.prev = null;

            if (head == null) {
                head = newStudent;
                tail = newStudent;
            } else {
                tail.next = newStudent;
                newStudent.prev = tail;
                tail = newStudent;
            }

            System.out.print("\nDo you want to add more student records? (Y/N): ");
            choice = input.next().charAt(0);
            input.nextLine();

        } while (choice == 'Y' || choice == 'y');
    }

    static void displayTopToBottom() {
        if (head == null) {
            System.out.println("\nNo student records found!");
            return;
        }
        clearScreen();
        int row = 0;

        STUDREC current = head;
        System.out.println("Student Records (Top to Bottom): ");
        gotoxy((short) 0, (short) (2 + row));
        System.out.println("Student Number");
        gotoxy((short) 30, (short) (2 + row));
        System.out.println("Student Name");
        gotoxy((short) 60, (short) (2 + row));
        System.out.println("Student Cyr");
        gotoxy((short) 90, (short) (2 + row));
        System.out.println("Student GWA");

        while (current != null) {
            gotoxy((short) 0, (short) (3 + row));
            System.out.println(current.No);
            gotoxy((short) 30, (short) (3 + row));
            System.out.println(current.Name);
            gotoxy((short) 60, (short) (3 + row));
            System.out.println(current.Cyr);
            gotoxy((short) 90, (short) (3 + row));
            System.out.println(current.GWA);
            row++;
            current = current.next;
        }
    }

    static void displayBottomToTop() {
        if (tail == null) {
            System.out.println("\nNo student records found!");
            return;
        }
        clearScreen();
        int row = 0;

        STUDREC current = tail;

        System.out.println("Student Records (Bottom to Top):");
        gotoxy((short) 0, (short) (2 + row));
        System.out.println("Student Number");
        gotoxy((short) 30, (short) (2 + row));
        System.out.println("Student Name");
        gotoxy((short) 60, (short) (2 + row));
        System.out.println("Student Cyr");
        gotoxy((short) 90, (short) (2 + row));
        System.out.println("Student GWA");

        while (current != null) {
            gotoxy((short) 0, (short) (3 + row));
            System.out.println(current.No);
            gotoxy((short) 30, (short) (3 + row));
            System.out.println(current.Name);
            gotoxy((short) 60, (short) (3 + row));
            System.out.println(current.Cyr);
            gotoxy((short) 90, (short) (3 + row));
            System.out.printf("%.2f", current.GWA);
            row++;
            current = current.prev;
        }
    }

    static void addRecordAtHead() {
        Scanner input = new Scanner(System.in);
        STUDREC newStudent = new STUDREC();
        System.out.print("\nEnter Student Number: ");
        newStudent.No = input.nextLine();
        System.out.print("Enter Student Name: ");
        newStudent.Name = input.nextLine();
        System.out.print("Enter Student Cyr: ");
        newStudent.Cyr = input.nextLine();
        System.out.print("Enter Student GWA: ");
        newStudent.GWA = input.nextFloat();

        newStudent.next = head;
        newStudent.prev = null;

        if (head != null) {
            head.prev = newStudent;
        }

        head = newStudent;

        System.out.println("\nStudent record added at the head.");
    }

    static void addRecordAtEnd() {
        Scanner input = new Scanner(System.in);
        STUDREC newStudent = new STUDREC();
        System.out.print("\nEnter Student Number: ");
        newStudent.No = input.nextLine();
        System.out.print("Enter Student Name: ");
        newStudent.Name = input.nextLine();
        System.out.print("Enter Student Cyr: ");
        newStudent.Cyr = input.nextLine();
        System.out.print("Enter Student GWA: ");
        newStudent.GWA = input.nextFloat();

        newStudent.next = null;
        newStudent.prev = tail;

        if (tail != null) {
            tail.next = newStudent;
        }

        tail = newStudent;

        if (head == null) {
            head = tail;
        }

        System.out.println("\nStudent record added at the end.");
    }

    static void addRecordBeforeSpecific() {
        Scanner input = new Scanner(System.in);
        String studentNo;
        System.out.print("\nEnter the student number before which you want to add a record: ");
        studentNo = input.nextLine();

        STUDREC current = head;
        while (current != null) {
            if (current.No.equals(studentNo)) {
                STUDREC newStudent = new STUDREC();
                System.out.print("\nEnter Student Number: ");
                newStudent.No = input.nextLine();
                System.out.print("Enter Student Name: ");
                newStudent.Name = input.nextLine();
                System.out.print("Enter Student Cyr: ");
                newStudent.Cyr = input.nextLine();
                System.out.print("Enter Student GWA: ");
                newStudent.GWA = input.nextFloat();

                newStudent.next = current;
                newStudent.prev = current.prev;

                if (current.prev != null) {
                    current.prev.next = newStudent;
                } else {
                    head = newStudent;
                }

                current.prev = newStudent;

                System.out.printf("\nStudent record added before student number %s.\n", studentNo);
                return;
            }
            current = current.next;
        }

        System.out.printf("\nStudent number %s not found!\n", studentNo);
    }

    static void addRecordAfterSpecific() {
        Scanner input = new Scanner(System.in);
        String studentNo;
        System.out.print("\nEnter the student number after which you want to add a record: ");
        studentNo = input.nextLine();

        STUDREC current = head;
        while (current != null) {
            if (current.No.equals(studentNo)) {
                STUDREC newStudent = new STUDREC();
                System.out.print("\nEnter Student Number: ");
                newStudent.No = input.nextLine();
                System.out.print("Enter Student Name: ");
                newStudent.Name = input.nextLine();
                System.out.print("Enter Student Cyr: ");
                newStudent.Cyr = input.nextLine();
                System.out.print("Enter Student GWA: ");
                newStudent.GWA = input.nextFloat();

                newStudent.next = current.next;
                newStudent.prev = current;

                if (current.next != null) {
                    current.next.prev = newStudent;
                } else {
                    tail = newStudent;
                }

                current.next = newStudent;

                System.out.printf("\nStudent record added after student number %s.\n", studentNo);
                return;
            }
            current = current.next;
        }

        System.out.printf("\nStudent number %s not found!\n", studentNo);
    }

    static void deleteRecordAtHead() {
        if (head == null) {
            System.out.println("\nNo student records found!");
            return;
        }

        STUDREC temp = head;
        head = head.next;
        if (head != null) {
            head.prev = null;
        } else {
            tail = null;
        }
        temp = null;

        System.out.println("\nRecord at the head deleted.");
    }

    static void deleteRecordAtTail() {
        if (tail == null) {
            System.out.println("\nNo student records found!");
            return;
        }

        STUDREC temp = tail;
        tail = tail.prev;
        if (tail != null) {
            tail.next = null;
        } else {
            head = null;
        }
        temp = null;

        System.out.println("\nRecord at the tail deleted.");
    }

    static void deleteRecordUsingSpecific() {
        Scanner input = new Scanner(System.in);
        String studentNo;
        System.out.print("\nEnter the student number you want to delete: ");
        studentNo = input.nextLine();

        STUDREC current = head;
        while (current != null) {
            if (current.No.equals(studentNo)) {
                if (current == head) {
                    deleteRecordAtHead();
                    System.out.printf("\nRecord with student number %s deleted.\n", studentNo);
                    return;
                } else if (current == tail) {
                    deleteRecordAtTail();
                    System.out.printf("\nRecord with student number %s deleted.\n", studentNo);
                    return;
                } else {
                    current.prev.next = current.next;
                    current.next.prev = current.prev;
                    current = null;
                    System.out.printf("\nRecord with student number %s deleted.\n", studentNo);
                    return;
                }
            }
            current = current.next;
        }

        System.out.printf("\nStudent number %s not found!\n", studentNo);
    }

    static void deleteRecordBeforeSpecific() {
        Scanner input = new Scanner(System.in);
        String studentNo;
        System.out.print("\nEnter the student number before which you want to delete a record: ");
        studentNo = input.nextLine();

        STUDREC current = head;
        while (current != null) {
            if (current.No.equals(studentNo)) {
                if (current.prev == null) {
                    System.out.printf("\nNo record found before student number %s.\n", studentNo);
                    return;
                } else {
                    STUDREC temp = current.prev;
                    if (temp == head) {
                        deleteRecordAtHead();
                        System.out.printf("\nRecord before student number %s deleted.\n", studentNo);
                        return;
                    } else {
                        current.prev = temp.prev;
                        temp.prev.next = current;
                        temp = null;
                        System.out.printf("\nRecord before student number %s deleted.\n", studentNo);
                        return;
                    }
                }
            }
            current = current.next;
        }

        System.out.printf("\nStudent number %s not found!\n", studentNo);
    }

    static void deleteRecordAfterSpecific() {
        Scanner input = new Scanner(System.in);
        String studentNo;
        System.out.print("\nEnter the student number after which you want to delete a record: ");
        studentNo = input.nextLine();

        STUDREC current = head;
        while (current != null) {
            if (current.No.equals(studentNo)) {
                if (current.next == null) {
                    System.out.printf("\nNo record found after student number %s.\n", studentNo);
                    return;
                } else {
                    STUDREC temp = current.next;
                    if (temp == tail) {
                        deleteRecordAtTail();
                        System.out.printf("\nRecord after student number %s deleted.\n", studentNo);
                        return;
                    } else {
                        current.next = temp.next;
                        temp.next.prev = current;
                        temp = null;
                        System.out.printf("\nRecord after student number %s deleted.\n", studentNo);
                        return;
                    }
                }
            }
            current = current.next;
        }

        System.out.printf("\nStudent number %s not found!\n", studentNo);
    }

    static void gotoxy(short x, short y) {
        System.out.print("\033[" + y + ";" + x + "H");
    }

    static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
}


