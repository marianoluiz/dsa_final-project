package SinglyLinkedJava;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

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

public class SinglyLinkedJavaSwing {
    private Student START = null;
    private DefaultTableModel model;

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            SinglyLinkedJavaSwing srm = new SinglyLinkedJavaSwing();
            srm.createAndShowGUI();
        });
    }

    private void createAndShowGUI() {
        JFrame frame = new JFrame("Student Record Management");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1000, 600);
        frame.setLayout(new BorderLayout());

        model = new DefaultTableModel();
        model.addColumn("Student No.");
        model.addColumn("Student Name");
        model.addColumn("Course & Year");
        model.addColumn("GWA");

        JTable table = new JTable(model);
        table.setFillsViewportHeight(true);
        JScrollPane scrollPane = new JScrollPane(table);
        scrollPane.setBorder(BorderFactory.createTitledBorder("Student Records"));

        JPanel buttonPanel = new JPanel(new GridLayout(10, 1, 10, 10));
        buttonPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JButton createButton = new JButton("Create Record");
        createButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                createList();
            }
        });

        JButton addButton = new JButton("Add at Beginning");
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addAtBeginning();
            }
        });

        JButton addEndButton = new JButton("Add at End");
        addEndButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addAtEnd();
            }
        });

        JButton displayButton = new JButton("Display Records");
        displayButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                displayRecords();
            }
        });

        JButton insertBeforeButton = new JButton("Insert Before");
        insertBeforeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String studNo = JOptionPane.showInputDialog("Enter student number to insert before:");
                insertBeforeNode(studNo);
            }
        });

        JButton insertAfterButton = new JButton("Insert After");
        insertAfterButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String studNo = JOptionPane.showInputDialog("Enter student number to insert after:");
                insertAfterNode(studNo);
            }
        });

        JButton deleteStartButton = new JButton("Delete First");
        deleteStartButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                deleteNodeAtStart();
            }
        });

        JButton deleteEndButton = new JButton("Delete Last");
        deleteEndButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                deleteNodeAtEnd();
            }
        });

        JButton deleteByValueButton = new JButton("Delete by Number");
        deleteByValueButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String studNo = JOptionPane.showInputDialog("Enter student number to delete:");
                deleteByValue(studNo);
            }
        });

        JButton exitButton = new JButton("Exit");
        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        buttonPanel.add(createButton);
        buttonPanel.add(addButton);
        buttonPanel.add(addEndButton);
        buttonPanel.add(displayButton);
        buttonPanel.add(insertBeforeButton);
        buttonPanel.add(insertAfterButton);
        buttonPanel.add(deleteStartButton);
        buttonPanel.add(deleteEndButton);
        buttonPanel.add(deleteByValueButton);
        buttonPanel.add(exitButton);

        frame.add(scrollPane, BorderLayout.CENTER);
        frame.add(buttonPanel, BorderLayout.EAST);

        frame.setVisible(true);
    }

    private void createList() {
    boolean addMore = true;
    
    while (addMore) {
        JTextField studNoField = new JTextField();
        JTextField studNameField = new JTextField();
        JTextField courseYearField = new JTextField();
        JTextField gwaField = new JTextField();

        JPanel inputPanel = new JPanel(new GridLayout(0, 1));
        inputPanel.add(new JLabel("Student No:"));
        inputPanel.add(studNoField);
        inputPanel.add(new JLabel("Student Name:"));
        inputPanel.add(studNameField);
        inputPanel.add(new JLabel("Course & Year:"));
        inputPanel.add(courseYearField);
        inputPanel.add(new JLabel("GWA:"));
        inputPanel.add(gwaField);

        int result = JOptionPane.showConfirmDialog(null, inputPanel, "Create New Student Record", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);
        if (result == JOptionPane.OK_OPTION) {
            String studNo = studNoField.getText();
            String studName = studNameField.getText();
            String courseYear = courseYearField.getText();
            float gwa = Float.parseFloat(gwaField.getText());

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
            JOptionPane.showMessageDialog(null, "Student record created successfully!");
        }

        int moreResult = JOptionPane.showConfirmDialog(null, "Would you like to add more student records?", "Add More?", JOptionPane.YES_NO_OPTION);
        if (moreResult != JOptionPane.YES_OPTION) {
            addMore = false;
        }
    }
}

    private void addAtBeginning() {
        JTextField studNoField = new JTextField();
        JTextField studNameField = new JTextField();
        JTextField courseYearField = new JTextField();
        JTextField gwaField = new JTextField();

        JPanel inputPanel = new JPanel(new GridLayout(0, 1));
        inputPanel.add(new JLabel("Student No:"));
        inputPanel.add(studNoField);
        inputPanel.add(new JLabel("Student Name:"));
        inputPanel.add(studNameField);
        inputPanel.add(new JLabel("Course & Year:"));
        inputPanel.add(courseYearField);
        inputPanel.add(new JLabel("GWA:"));
        inputPanel.add(gwaField);

        int result = JOptionPane.showConfirmDialog(null, inputPanel, "Add Student at Beginning", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);
        if (result == JOptionPane.OK_OPTION) {
            String studNo = studNoField.getText();
            String studName = studNameField.getText();
            String courseYear = courseYearField.getText();
            float gwa = Float.parseFloat(gwaField.getText());

            Student newNode = new Student(studNo, studName, courseYear, gwa);
            newNode.next = START;
            START = newNode;
            JOptionPane.showMessageDialog(null, "Student added successfully at the beginning!");
        }
    }

    private void addAtEnd() {
        JTextField studNoField = new JTextField();
        JTextField studNameField = new JTextField();
        JTextField courseYearField = new JTextField();
        JTextField gwaField = new JTextField();

        JPanel inputPanel = new JPanel(new GridLayout(0, 1));
        inputPanel.add(new JLabel("Student No:"));
        inputPanel.add(studNoField);
        inputPanel.add(new JLabel("Student Name:"));
        inputPanel.add(studNameField);
        inputPanel.add(new JLabel("Course & Year:"));
        inputPanel.add(courseYearField);
        inputPanel.add(new JLabel("GWA:"));
        inputPanel.add(gwaField);

        int result = JOptionPane.showConfirmDialog(null, inputPanel, "Add Student at End", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);
        if (result == JOptionPane.OK_OPTION) {
            String studNo = studNoField.getText();
            String studName = studNameField.getText();
            String courseYear = courseYearField.getText();
            float gwa = Float.parseFloat(gwaField.getText());

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
            JOptionPane.showMessageDialog(null, "Student added successfully at the end!");
        }
    }

    private void displayRecords() {
        model.setRowCount(0); 

        Student current = START;
        while (current != null) {
            model.addRow(new Object[]{current.studNo, current.studName, current.courseYear, current.gwa});
            current = current.next;
        }
    }

    private void insertBeforeNode(String searchStudNo) {
        if (START == null) {
            JOptionPane.showMessageDialog(null, "List is empty. No student record to search.");
            return;
        }

        Student current = START;
        Student prev = null;
        while (current != null && !current.studNo.equals(searchStudNo)) {
            prev = current;
            current = current.next;
        }

        if (current == null) {
            JOptionPane.showMessageDialog(null, "Student number " + searchStudNo + " not found.");
            return;
        }

        JTextField studNoField = new JTextField();
        JTextField studNameField = new JTextField();
        JTextField courseYearField = new JTextField();
        JTextField gwaField = new JTextField();

        JPanel inputPanel = new JPanel(new GridLayout(0, 1));
        inputPanel.add(new JLabel("Student No:"));
        inputPanel.add(studNoField);
        inputPanel.add(new JLabel("Student Name:"));
        inputPanel.add(studNameField);
        inputPanel.add(new JLabel("Course & Year:"));
        inputPanel.add(courseYearField);
        inputPanel.add(new JLabel("GWA:"));
        inputPanel.add(gwaField);

        int result = JOptionPane.showConfirmDialog(null, inputPanel, "Insert Student Before", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);
        if (result == JOptionPane.OK_OPTION) {
            String studNo = studNoField.getText();
            String studName = studNameField.getText();
            String courseYear = courseYearField.getText();
            float gwa = Float.parseFloat(gwaField.getText());

            Student newNode = new Student(studNo, studName, courseYear, gwa);
            if (prev == null) {
                newNode.next = START;
                START = newNode;
            } else {
                prev.next = newNode;
                newNode.next = current;
            }
            JOptionPane.showMessageDialog(null, "Student added successfully!");
        }
    }

    private void insertAfterNode(String searchStudNo) {
        if (START == null) {
            JOptionPane.showMessageDialog(null, "List is empty. No student record to search.");
            return;
        }

        Student current = START;
        while (current != null && !current.studNo.equals(searchStudNo)) {
            current = current.next;
        }

        if (current == null) {
            JOptionPane.showMessageDialog(null, "Student number " + searchStudNo + " not found.");
            return;
        }

        JTextField studNoField = new JTextField();
        JTextField studNameField = new JTextField();
        JTextField courseYearField = new JTextField();
        JTextField gwaField = new JTextField();

        JPanel inputPanel = new JPanel(new GridLayout(0, 1));
        inputPanel.add(new JLabel("Student No:"));
        inputPanel.add(studNoField);
        inputPanel.add(new JLabel("Student Name:"));
        inputPanel.add(studNameField);
        inputPanel.add(new JLabel("Course & Year:"));
        inputPanel.add(courseYearField);
        inputPanel.add(new JLabel("GWA:"));
        inputPanel.add(gwaField);

        int result = JOptionPane.showConfirmDialog(null, inputPanel, "Insert Student After", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);
        if (result == JOptionPane.OK_OPTION) {
            String studNo = studNoField.getText();
            String studName = studNameField.getText();
            String courseYear = courseYearField.getText();
            float gwa = Float.parseFloat(gwaField.getText());

            Student newNode = new Student(studNo, studName, courseYear, gwa);
            newNode.next = current.next;
            current.next = newNode;
            JOptionPane.showMessageDialog(null, "Student added successfully!");
        }
    }

    private void deleteNodeAtStart() {
        if (START == null) {
            JOptionPane.showMessageDialog(null, "List is empty. No student record to delete.");
            return;
        }

        START = START.next;
        JOptionPane.showMessageDialog(null, "Student record at the start deleted successfully.");
    }

    private void deleteNodeAtEnd() {
        if (START == null) {
            JOptionPane.showMessageDialog(null, "List is empty. No student record to delete.");
            return;
        }

        Student temp = START;
        if (temp.next == null) {
            START = null;
            JOptionPane.showMessageDialog(null, "Deleted the only student record in the list.");
            return;
        }

        while (temp.next.next != null) {
            temp = temp.next;
        }

        temp.next = null;
        JOptionPane.showMessageDialog(null, "Student record at the end deleted successfully.");
    }

    private void deleteByValue(String target) {
        if (START == null) {
            JOptionPane.showMessageDialog(null, "List is empty. No student record to delete.");
            return;
        }

        Student temp = START;
        if (temp != null && temp.studNo.equals(target)) {
            START = temp.next;
            JOptionPane.showMessageDialog(null, "Student record with student number " + target + " deleted successfully.");
            return;
        }

        Student prev = null;
        while (temp != null && !temp.studNo.equals(target)) {
            prev = temp;
            temp = temp.next;
        }

        if (temp == null) {
            JOptionPane.showMessageDialog(null, "Student record with student number " + target + " not found.");
            return;
        }

        prev.next = temp.next;
        JOptionPane.showMessageDialog(null, "Student record with student number " + target + " deleted successfully.");
    }
}
