package SinglyLinkedJava;
import java.util.Scanner;

class Student {
    String studNo;
    String studName;
    String courseYear;
    float gwa;
    Student next;

    public Student(String studNo, String studName, String courseYear, float gwa) {
        this.studNo = studNo;
        this.studName = studName;
        this.courseYear = courseYear;
        this.gwa = gwa;
        this.next = null;
    }
}

public class SinglyLinkedJava {
    private Student START = null;

    public static void main(String[] args) {
        SinglyLinkedJava srm = new SinglyLinkedJava();
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            srm.clearScreen();
            System.out.println("\n<@@ STUDENT RECORD MANAGEMENT @@>\n");
            System.out.println("1. Create record of student");
            System.out.println("2. Add a new student record at the beginning");
            System.out.println("3. Add a new student record at the end");
            System.out.println("4. Display student records");
            System.out.println("5. Insert a new record before a specific student number");
            System.out.println("6. Insert a new record after a specific student number");
            System.out.println("7. Delete a record at the start");
            System.out.println("8. Delete a record at the end");
            System.out.println("9. Delete a record by student number");
            System.out.println("10. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    srm.createList();
                    break;
                case 2:
                    srm.addAtBeginning();
                    break;
                case 3:
                    srm.addAtEnd();
                    break;
                case 4:
                    srm.displayRecords();
                    break;
                case 5:
                    System.out.print("\nEnter the student number before which you want to insert a new record: ");
                    String searchStudNoBefore = sc.next();
                    srm.insertBeforeNode(searchStudNoBefore);
                    break;
                case 6:
                    System.out.print("\nEnter the student number after which you want to insert a new record: ");
                    String searchStudNoAfter = sc.next();
                    srm.insertAfterNode(searchStudNoAfter);
                    break;
                case 7:
                    srm.deleteNodeAtStart();
                    break;
                case 8:
                    srm.deleteNodeAtEnd();
                    break;
                case 9:
                    System.out.print("Enter the student number to delete: ");
                    String target = sc.next();
                    srm.deleteByValue(target);
                    break;
                case 10:
                    System.out.println("Exiting program...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }

            if (choice != 10) {
                System.out.println("\nPress any key to continue...");
                try {
                    System.in.read();
                } catch (Exception e) {
                }
            }

        } while (choice != 10);

        sc.close();
    }

    private void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    private void createList() {
        Scanner sc = new Scanner(System.in);
        if (START != null) {
            System.out.println("There is already a student list created.");
            return;
        }

        char resp;
        do {
            System.out.print("\nEnter student number: ");
            String studNo = sc.next();
            sc.nextLine(); 
            System.out.print("Enter student name: ");
            String studName = sc.nextLine();
            System.out.print("Enter course and year: ");
            String courseYear = sc.nextLine();
            System.out.print("Enter GWA: ");
            float gwa = sc.nextFloat();

            Student newNode = new Student(studNo, studName, courseYear, gwa);
            if (START == null) {
                START = newNode;
            } else {
                Student temp = START;
                while (temp.next != null) {
                    temp = temp.next;
                }
                temp.next = newNode;
            }

            System.out.print("\nDo you want to add more students [Y/N]? : ");
            resp = sc.next().charAt(0);

        } while (resp == 'Y' || resp == 'y');
        System.out.println("Student(s) added successfully!");
    }

    private void addAtBeginning() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter student number: ");
        String studNo = sc.next();
        sc.nextLine();
        System.out.print("Enter student name: ");
        String studName = sc.nextLine();
        System.out.print("Enter course and year: ");
        String courseYear = sc.nextLine();
        System.out.print("Enter GWA: ");
        float gwa = sc.nextFloat();

        Student newNode = new Student(studNo, studName, courseYear, gwa);
        newNode.next = START;
        START = newNode;
        System.out.println("Student added successfully!");
    }

    private void addAtEnd() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter student number: ");
        String studNo = sc.next();
        sc.nextLine(); 
        System.out.print("Enter student name: ");
        String studName = sc.nextLine();
        System.out.print("Enter course and year: ");
        String courseYear = sc.nextLine();
        System.out.print("Enter GWA: ");
        float gwa = sc.nextFloat();

        Student newNode = new Student(studNo, studName, courseYear, gwa);
        if (START == null) {
            START = newNode;
        } else {
            Student temp = START;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
        System.out.println("Student added successfully!");
    }

    private void displayRecords() {
        clearScreen();
        System.out.printf("%40s\n\n", "STUDENT'S GWA REPORT");
        System.out.printf("%-15s %-30s %-20s %-10s\n", "Student No.", "Student Name", "Course & Year", "GWA");

        Student current = START;
        while (current != null) {
            System.out.printf("%-15s %-30s %-20s %-10.2f\n", current.studNo, current.studName, current.courseYear, current.gwa);
            current = current.next;
        }
    }

private void insertBeforeNode(String searchStudNo) {
    if (START == null) {
        System.out.println("List is empty. No student record to search.");
        return;
    }

   
    Student current = START;
    Student prev = null;
    while (current != null && !current.studNo.equals(searchStudNo)) {
        prev = current;
        current = current.next;
    }

    if (current == null) {
        System.out.println("Student number " + searchStudNo + " not found.");
        return;
    }

  
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter student number: ");
    String studNo = sc.next();
    sc.nextLine(); 
    System.out.print("Enter student name: ");
    String studName = sc.nextLine();
    System.out.print("Enter course and year: ");
    String courseYear = sc.nextLine();
    System.out.print("Enter GWA: ");
    float gwa = sc.nextFloat();

    Student newNode = new Student(studNo, studName, courseYear, gwa);
    if (prev == null) { 
        newNode.next = START;
        START = newNode;
    } else {
        prev.next = newNode;
        newNode.next = current;
    }
    System.out.println("Student added successfully!");
}

private void insertAfterNode(String searchStudNo) {
    if (START == null) {
        System.out.println("List is empty. No student record to search.");
        return;
    }

  
    Student current = START;
    while (current != null && !current.studNo.equals(searchStudNo)) {
        current = current.next;
    }

    if (current == null) {
        System.out.println("Student number " + searchStudNo + " not found.");
        return;
    }

    
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter student number: ");
    String studNo = sc.next();
    sc.nextLine(); 
    System.out.print("Enter student name: ");
    String studName = sc.nextLine();
    System.out.print("Enter course and year: ");
    String courseYear = sc.nextLine();
    System.out.print("Enter GWA: ");
    float gwa = sc.nextFloat();

    Student newNode = new Student(studNo, studName, courseYear, gwa);
    newNode.next = current.next;
    current.next = newNode;
    System.out.println("Student added successfully!");
}

    private void deleteNodeAtStart() {
        if (START == null) {
            System.out.println("List is empty. No student record to delete.");
            return;
        }

        START = START.next;
        System.out.println("Student record at the start deleted successfully.");
    }

    private void deleteNodeAtEnd() {
        if (START == null) {
            System.out.println("List is empty. No student record to delete.");
            return;
        }

        Student temp = START;
        if (temp.next == null) {
            START = null;
            System.out.println("Deleted the only student record in the list.");
            return;
        }

        while (temp.next.next != null) {
            temp = temp.next;
        }

        temp.next = null;
        System.out.println("Student record at the end deleted successfully.");
    }

    private void deleteByValue(String target) {
        if (START == null) {
            System.out.println("List is empty. No student record to delete.");
            return;
        }

        Student temp = START;
        if (temp != null && temp.studNo.equals(target)) {
            START = temp.next;
            System.out.println("Student record with student number " + target + " deleted successfully.");
            return;
        }

        Student prev = null;
        while (temp != null && !temp.studNo.equals(target)) {
            prev = temp;
            temp = temp.next;
        }

        if (temp == null) {
            System.out.println("Student record with student number " + target + " not found.");
            return;
        }

        prev.next = temp.next;
        System.out.println("Student record with student number " + target + " deleted successfully.");
    }
    
}
