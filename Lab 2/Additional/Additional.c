#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int roll_no;
    char grade;
    char branch[50];
} Student;

void writeRecordsToFile(const char *filename, Student students[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Unable to open file");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %d %c %s\n", students[i].name, students[i].roll_no, students[i].grade, students[i].branch);
    }
    fclose(file);
}

void readRecordsAndWriteBranchFiles(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(1);
    }

    char line[MAX];
    while (fgets(line, sizeof(line), file)) {
        Student student;
        sscanf(line, "%s %d %c %s", student.name, &student.roll_no, &student.grade, student.branch);

        char branchFile[MAX];
        snprintf(branchFile, sizeof(branchFile), "%s.txt", student.branch);

        FILE *branchFilePtr = fopen(branchFile, "a");
        if (branchFilePtr == NULL) {
            perror("Unable to open branch file");
            exit(1);
        }
        fprintf(branchFilePtr, "%s %d %c %s\n", student.name, student.roll_no, student.grade, student.branch);
        fclose(branchFilePtr);
    }
    fclose(file);
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar(); // Consume newline character

    Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Enter name, roll no, grade, and branch for student %d:\n", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove newline character
        scanf("%d %c", &students[i].roll_no, &students[i].grade);
        getchar(); // Consume newline character
        fgets(students[i].branch, sizeof(students[i].branch), stdin);
        students[i].branch[strcspn(students[i].branch, "\n")] = '\0'; // Remove newline character
    }

    writeRecordsToFile("students.txt", students, n);
    readRecordsAndWriteBranchFiles("students.txt");

    return 0;
}

