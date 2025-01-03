#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 50

// Structure for student records
typedef struct {
    int id;
    char name[NAME_LEN];
    float cgpa;
} Student;

// Global array of students and a count of total records
Student students[MAX];
int studentCount = 0;

// Function prototypes
void addStudent();
void viewStudents();
void editStudent();
void deleteStudent();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    do {
        printf("\n*** Student Record Management System ***\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Edit Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                editStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

void addStudent() {
    if (studentCount >= MAX) {
        printf("\nError: Maximum student limit reached!\n");
        return;
    }

    Student newStudent;
    printf("\nEnter Student ID: ");
    scanf("%d", &newStudent.id);
    getchar();

    printf("Enter Student Name: ");
    fgets(newStudent.name, NAME_LEN, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Student CGPA: ");
    scanf("%f", &newStudent.cgpa);

    students[studentCount++] = newStudent;
    printf("\nStudent added successfully!\n");
}

void viewStudents() {
    if (studentCount == 0) {
        printf("\nNo records to display!\n");
        return;
    }

    printf("\n%-10s%-30s%-10s\n", "ID", "Name", "CGPA");
    printf("---------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("%-10d%-30s%-10.2f\n", students[i].id, students[i].name, students[i].cgpa);
    }
}

void editStudent() {
    if (studentCount == 0) {
        printf("\nNo records to edit!\n");
        return;
    }

    int id;
    printf("\nEnter Student ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("\nEditing record for ID %d\n", id);

            printf("Enter new name: ");
            getchar();
            fgets(students[i].name, NAME_LEN, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter new CGPA: ");
            scanf("%f", &students[i].cgpa);

            printf("\nRecord updated successfully!\n");
            return;
        }
    }

    printf("\nError: Student with ID %d not found!\n", id);
}

void deleteStudent() {
    if (studentCount == 0) {
        printf("\nNo records to delete!\n");
        return;
    }

    int id;
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("\nRecord deleted successfully!\n");
            return;
        }
    }

    printf("\nError: Student with ID %d not found!\n", id);
}
