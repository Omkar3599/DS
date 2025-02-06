#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int roll_no;
    char grade;
} Student;

void readStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name, roll no, and grade for student %d:\n", i + 1);
        char buffer[100];
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%49s %d %c", students[i].name, &students[i].roll_no, &students[i].grade);
    }
}

void displayStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll No: %d, Grade: %c\n", students[i].name, students[i].roll_no, students[i].grade);
    }
}

void sortByRollNo(Student students[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].roll_no > students[j].roll_no) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar();

    Student students[MAX];

    readStudents(students, n);

    printf("Student information before sorting:\n");
    displayStudents(students, n);

    sortByRollNo(students, n);

    printf("Student information after sorting:\n");
    displayStudents(students, n);

    return 0;
}
