import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class DoublyLinkedJavaGUI {
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

    public static void main(String[] args) {
        JFrame frame = new JFrame("Student Records");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);

        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new GridLayout(13, 1, 5, 5));

        String[] buttonNames = {
                "Create a Student Record", "Display Student Records (Top to Bottom)", "Display Student Records (Bottom to Top)",
                "Add a Student Record at the Head", "Add a Student Record at the End",
                "Add a Record Before a Specific Student Number", "Add a Record After a Specific Student Number",
                "Delete a Record at the Head", "Delete a Record at the Tail",
                "Delete a Record Using a Specific Student Number", "Delete a Record Before a Specific Student Number",
                "Delete a Record After a Specific Student Number", "Exit"
        };

        for (String buttonName : buttonNames) {
            JButton button = new JButton(buttonName);
            button.setBackground(new Color(216, 191, 216));
            button.addActionListener(new ButtonClickListener());
            mainPanel.add(button);
        }

        frame.add(mainPanel);
        frame.setVisible(true);
    }

    static class ButtonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String command = ((JButton) e.getSource()).getText();
            switch (command) {
                case "Create a Student Record":
                    createStudentRecord();
                    break;
                case "Display Student Records (Top to Bottom)":
                    displayTopToBottom();
                    break;
                case "Display Student Records (Bottom to Top)":
                    displayBottomToTop();
                    break;
                case "Add a Student Record at the Head":
                    addRecordAtHead();
                    break;
                case "Add a Student Record at the End":
                    addRecordAtEnd();
                    break;
                case "Add a Record Before a Specific Student Number":
                    addRecordBeforeSpecific();
                    break;
                case "Add a Record After a Specific Student Number":
                    addRecordAfterSpecific();
                    break;
                case "Delete a Record at the Head":
                    deleteRecordAtHead();
                    break;
                case "Delete a Record at the Tail":
                    deleteRecordAtTail();
                    break;
                case "Delete a Record Using a Specific Student Number":
                    deleteRecordUsingSpecific();
                    break;
                case "Delete a Record Before a Specific Student Number":
                    deleteRecordBeforeSpecific();
                    break;
                case "Delete a Record After a Specific Student Number":
                    deleteRecordAfterSpecific();
                    break;
                case "Exit":
                    System.exit(0);
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Invalid choice! Please enter a valid option.");
                    break;
            }
        }
    }

    static void createStudentRecord() {
        if (head != null) {
            JOptionPane.showMessageDialog(null, "You already have a record created!");
            return;
        }

        while (true) {
            JTextField studentNo = new JTextField();
            JTextField studentName = new JTextField();
            JTextField studentCyr = new JTextField();
            JTextField studentGwa = new JTextField();
            final JComponent[] inputs = new JComponent[]{
                    new JLabel("Student Number"), studentNo,
                    new JLabel("Student Name"), studentName,
                    new JLabel("Student Cyr"), studentCyr,
                    new JLabel("Student GWA"), studentGwa,
            };
            int result = JOptionPane.showConfirmDialog(null, inputs, "Create Student Record", JOptionPane.OK_CANCEL_OPTION);
            if (result == JOptionPane.OK_OPTION) {
                try {
                    STUDREC newStudent = new STUDREC();
                    newStudent.No = studentNo.getText();
                    newStudent.Name = studentName.getText();
                    newStudent.Cyr = studentCyr.getText();
                    newStudent.GWA = Float.parseFloat(studentGwa.getText());
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

                    int continueResult = JOptionPane.showConfirmDialog(null, "Do you want to add more student records?", "Continue?", JOptionPane.YES_NO_OPTION);
                    if (continueResult != JOptionPane.YES_OPTION) {
                        break;
                    }
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Invalid input for GWA. Please enter a valid float value.");
                }
            } else {
                break;
            }
        }
    }

    static void displayTopToBottom() {
        if (head == null) {
            JOptionPane.showMessageDialog(null, "No student records found!");
            return;
        }

        DefaultTableModel model = new DefaultTableModel(new String[]{"Student Number", "Student Name", "Student Cyr", "Student GWA"}, 0);
        STUDREC current = head;
        while (current != null) {
            model.addRow(new Object[]{current.No, current.Name, current.Cyr, current.GWA});
            current = current.next;
        }

        JTable table = new JTable(model);
        JScrollPane scrollPane = new JScrollPane(table);
        JFrame frame = new JFrame("Student Records (Top to Bottom)");
        frame.add(scrollPane);
        frame.setSize(800, 600);
        frame.setVisible(true);
    }

    static void displayBottomToTop() {
        if (tail == null) {
            JOptionPane.showMessageDialog(null, "No student records found!");
            return;
        }

        DefaultTableModel model = new DefaultTableModel(new String[]{"Student Number", "Student Name", "Student Cyr", "Student GWA"}, 0);
        STUDREC current = tail;
        while (current != null) {
            model.addRow(new Object[]{current.No, current.Name, current.Cyr, current.GWA});
            current = current.prev;
        }

        JTable table = new JTable(model);
        JScrollPane scrollPane = new JScrollPane(table);
        JFrame frame = new JFrame("Student Records (Bottom to Top)");
        frame.add(scrollPane);
        frame.setSize(800, 600);
        frame.setVisible(true);
    }

    static void addRecordAtHead() {
        JTextField studentNo = new JTextField();
        JTextField studentName = new JTextField();
        JTextField studentCyr = new JTextField();
        JTextField studentGwa = new JTextField();
        final JComponent[] inputs = new JComponent[]{
                new JLabel("Student Number"), studentNo,
                new JLabel("Student Name"), studentName,
                new JLabel("Student Cyr"), studentCyr,
                new JLabel("Student GWA"), studentGwa,
        };
        int result = JOptionPane.showConfirmDialog(null, inputs, "Add Student Record at Head", JOptionPane.OK_CANCEL_OPTION);
        if (result == JOptionPane.OK_OPTION) {
            try {
                STUDREC newStudent = new STUDREC();
                newStudent.No = studentNo.getText();
                newStudent.Name = studentName.getText();
                newStudent.Cyr = studentCyr.getText();
                newStudent.GWA = Float.parseFloat(studentGwa.getText());

                newStudent.next = head;
                newStudent.prev = null;

                if (head != null) {
                    head.prev = newStudent;
                }

                head = newStudent;

                JOptionPane.showMessageDialog(null, "Student record added at the head.");
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(null, "Invalid input for GWA. Please enter a valid float value.");
            }
        }
    }

    static void addRecordAtEnd() {
        JTextField studentNo = new JTextField();
        JTextField studentName = new JTextField();
        JTextField studentCyr = new JTextField();
        JTextField studentGwa = new JTextField();
        final JComponent[] inputs = new JComponent[]{
                new JLabel("Student Number"), studentNo,
                new JLabel("Student Name"), studentName,
                new JLabel("Student Cyr"), studentCyr,
                new JLabel("Student GWA"), studentGwa,
        };
        int result = JOptionPane.showConfirmDialog(null, inputs, "Add Student Record at End", JOptionPane.OK_CANCEL_OPTION);
        if (result == JOptionPane.OK_OPTION) {
            try {
                STUDREC newStudent = new STUDREC();
                newStudent.No = studentNo.getText();
                newStudent.Name = studentName.getText();
                newStudent.Cyr = studentCyr.getText();
                newStudent.GWA = Float.parseFloat(studentGwa.getText());

                newStudent.next = null;
                newStudent.prev = tail;

                if (tail != null) {
                    tail.next = newStudent;
                }

                tail = newStudent;

                JOptionPane.showMessageDialog(null, "Student record added at the end.");
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(null, "Invalid input for GWA. Please enter a valid float value.");
            }
        }
    }

    static void addRecordBeforeSpecific() {
        JTextField specificNo = new JTextField();
        JTextField studentNo = new JTextField();
        JTextField studentName = new JTextField();
        JTextField studentCyr = new JTextField();
        JTextField studentGwa = new JTextField();
        final JComponent[] inputs = new JComponent[]{
                new JLabel("Specific Student Number to Add Before"), specificNo,
                new JLabel("Student Number"), studentNo,
                new JLabel("Student Name"), studentName,
                new JLabel("Student Cyr"), studentCyr,
                new JLabel("Student GWA"), studentGwa,
        };
        int result = JOptionPane.showConfirmDialog(null, inputs, "Add Record Before Specific Student Number", JOptionPane.OK_CANCEL_OPTION);
        if (result == JOptionPane.OK_OPTION) {
            try {
                String targetNo = specificNo.getText();
                STUDREC current = head;

                while (current != null && !current.No.equals(targetNo)) {
                    current = current.next;
                }

                if (current == null) {
                    JOptionPane.showMessageDialog(null, "Specific student number not found.");
                    return;
                }

                STUDREC newStudent = new STUDREC();
                newStudent.No = studentNo.getText();
                newStudent.Name = studentName.getText();
                newStudent.Cyr = studentCyr.getText();
                newStudent.GWA = Float.parseFloat(studentGwa.getText());

                newStudent.next = current;
                newStudent.prev = current.prev;

                if (current.prev != null) {
                    current.prev.next = newStudent;
                } else {
                    head = newStudent;
                }

                current.prev = newStudent;

                JOptionPane.showMessageDialog(null, "Student record added before specific student number.");
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(null, "Invalid input for GWA. Please enter a valid float value.");
            }
        }
    }

    static void addRecordAfterSpecific() {
        JTextField specificNo = new JTextField();
        JTextField studentNo = new JTextField();
        JTextField studentName = new JTextField();
        JTextField studentCyr = new JTextField();
        JTextField studentGwa = new JTextField();
        final JComponent[] inputs = new JComponent[]{
                new JLabel("Specific Student Number to Add After"), specificNo,
                new JLabel("Student Number"), studentNo,
                new JLabel("Student Name"), studentName,
                new JLabel("Student Cyr"), studentCyr,
                new JLabel("Student GWA"), studentGwa,
        };
        int result = JOptionPane.showConfirmDialog(null, inputs, "Add Record After Specific Student Number", JOptionPane.OK_CANCEL_OPTION);
        if (result == JOptionPane.OK_OPTION) {
            try {
                String targetNo = specificNo.getText();
                STUDREC current = head;

                while (current != null && !current.No.equals(targetNo)) {
                    current = current.next;
                }

                if (current == null) {
                    JOptionPane.showMessageDialog(null, "Specific student number not found.");
                    return;
                }

                STUDREC newStudent = new STUDREC();
                newStudent.No = studentNo.getText();
                newStudent.Name = studentName.getText();
                newStudent.Cyr = studentCyr.getText();
                newStudent.GWA = Float.parseFloat(studentGwa.getText());

                newStudent.prev = current;
                newStudent.next = current.next;

                if (current.next != null) {
                    current.next.prev = newStudent;
                } else {
                    tail = newStudent;
                }

                current.next = newStudent;

                JOptionPane.showMessageDialog(null, "Student record added after specific student number.");
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(null, "Invalid input for GWA. Please enter a valid float value.");
            }
        }
    }

    static void deleteRecordAtHead() {
        if (head == null) {
            JOptionPane.showMessageDialog(null, "No student records found!");
            return;
        }

        head = head.next;
        if (head != null) {
            head.prev = null;
        } else {
            tail = null;
        }

        JOptionPane.showMessageDialog(null, "Record at the head deleted.");
    }

    static void deleteRecordAtTail() {
        if (tail == null) {
            JOptionPane.showMessageDialog(null, "No student records found!");
            return;
        }

        tail = tail.prev;
        if (tail != null) {
            tail.next = null;
        } else {
            head = null;
        }

        JOptionPane.showMessageDialog(null, "Record at the tail deleted.");
    }

    static void deleteRecordUsingSpecific() {
        JTextField specificNo = new JTextField();
        final JComponent[] inputs = new JComponent[]{
                new JLabel("Specific Student Number to Delete"), specificNo,
        };
        int result = JOptionPane.showConfirmDialog(null, inputs, "Delete Record Using Specific Student Number", JOptionPane.OK_CANCEL_OPTION);
        if (result == JOptionPane.OK_OPTION) {
            String targetNo = specificNo.getText();
            STUDREC current = head;

            while (current != null && !current.No.equals(targetNo)) {
                current = current.next;
            }

            if (current == null) {
                JOptionPane.showMessageDialog(null, "Specific student number not found.");
                return;
            }

            if (current.prev != null) {
                current.prev.next = current.next;
            } else {
                head = current.next;
            }

            if (current.next != null) {
                current.next.prev = current.prev;
            } else {
                tail = current.prev;
            }

            JOptionPane.showMessageDialog(null, "Student record deleted using specific student number.");
        }
    }

    static void deleteRecordBeforeSpecific() {
        JTextField specificNo = new JTextField();
        final JComponent[] inputs = new JComponent[]{
                new JLabel("Specific Student Number to Delete Before"), specificNo,
        };
        int result = JOptionPane.showConfirmDialog(null, inputs, "Delete Record Before Specific Student Number", JOptionPane.OK_CANCEL_OPTION);
        if (result == JOptionPane.OK_OPTION) {
            String targetNo = specificNo.getText();
            STUDREC current = head;

            while (current != null && !current.No.equals(targetNo)) {
                current = current.next;
            }

            if (current == null || current.prev == null) {
                JOptionPane.showMessageDialog(null, "No record found before the specific student number.");
                return;
            }

            STUDREC toDelete = current.prev;

            if (toDelete.prev != null) {
                toDelete.prev.next = current;
            } else {
                head = current;
            }

            current.prev = toDelete.prev;

            JOptionPane.showMessageDialog(null, "Record before the specific student number deleted.");
        }
    }

    static void deleteRecordAfterSpecific() {
        JTextField specificNo = new JTextField();
        final JComponent[] inputs = new JComponent[]{
                new JLabel("Specific Student Number to Delete After"), specificNo,
        };
        int result = JOptionPane.showConfirmDialog(null, inputs, "Delete Record After Specific Student Number", JOptionPane.OK_CANCEL_OPTION);
        if (result == JOptionPane.OK_OPTION) {
            String targetNo = specificNo.getText();
            STUDREC current = head;

            while (current != null && !current.No.equals(targetNo)) {
                current = current.next;
            }

            if (current == null || current.next == null) {
                JOptionPane.showMessageDialog(null, "No record found after the specific student number.");
                return;
            }

            STUDREC toDelete = current.next;

            if (toDelete.next != null) {
                toDelete.next.prev = current;
            } else {
                tail = current;
            }

            current.next = toDelete.next;

            JOptionPane.showMessageDialog(null, "Record after the specific student number deleted.");
        }
    }
}
