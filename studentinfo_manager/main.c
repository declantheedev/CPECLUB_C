#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentNode {
    char firstName[50];
    char lastName[50];
    int roll;
    float cgpa;
    int courseId[5];
    struct StudentNode* next;
} Student;

void addStudent(Student** head) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    if (new_student == NULL) {
        printf("System out of memory!\n");
        return;
    }

    printf("First Name: ");
    scanf("%49s", new_student->firstName);
    
    printf("Last Name: ");
    scanf("%49s", new_student->lastName);
    
    printf("Roll Number: ");
    scanf("%d", &new_student->roll);
    
    printf("CGPA: ");
    scanf("%f", &new_student->cgpa);
    
    for (int i = 0; i < 5; i++) {
        printf("Course %d ID: ", i + 1);
        scanf("%d", &new_student->courseId[i]);
    }
    
    new_student->next = NULL;

    if (*head == NULL) {
        *head = new_student;
    } else {
        Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_student;
    }
    printf("Student added successfully.\n");
}

void bulkImport(Student** head) {
    FILE* file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }

    while (!feof(file)) {
        Student* new_student = (Student*)malloc(sizeof(Student));
        if (new_student == NULL) {
            break;
        }

        int read = fscanf(file, "%49s %49s %d %f %d %d %d %d %d",
                          new_student->firstName, new_student->lastName, 
                          &new_student->roll, &new_student->cgpa,
                          &new_student->courseId[0], &new_student->courseId[1], 
                          &new_student->courseId[2], &new_student->courseId[3], 
                          &new_student->courseId[4]);

        if (read == 9) {
            new_student->next = NULL;
            if (*head == NULL) {
                *head = new_student;
            } else {
                Student* temp = *head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new_student;
            }
        } else {
            free(new_student);
            break;
        }
    }
    fclose(file);
    printf("Bulk import completed.\n");
}

void downloadAll(Student* head) {
    FILE* file = fopen("database_backup.txt", "w");
    if (file == NULL) {
        printf("Could not create backup file.\n");
        return;
    }

    Student* temp = head;
    while (temp != NULL) {
        fprintf(file, "%s %s %d %.2f %d %d %d %d %d\n",
                temp->firstName, temp->lastName, temp->roll, temp->cgpa,
                temp->courseId[0], temp->courseId[1], temp->courseId[2],
                temp->courseId[3], temp->courseId[4]);
        temp = temp->next;
    }
    
    fclose(file);
    printf("Database downloaded to database_backup.txt.\n");
}

void findByRoll(Student* head, int targetRoll) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->roll == targetRoll) {
            printf("\nName: %s %s\nCGPA: %.2f\n", temp->firstName, temp->lastName, temp->cgpa);
            return;
        }
        temp = temp->next;
    }
    printf("\nStudent not found.\n");
}

void findByName(Student* head, char* targetName) {
    Student* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->firstName, targetName) == 0) {
            printf("\nRoll: %d | Name: %s %s | CGPA: %.2f\n", temp->roll, temp->firstName, temp->lastName, temp->cgpa);
            found = 1;
        }
        temp = temp->next;
    }
    if (found == 0) {
        printf("\nStudent not found.\n");
    }
}

void deleteByRoll(Student** head, int targetRoll) {
    if (*head == NULL) {
        printf("Database is empty.\n");
        return;
    }

    Student* current = *head;
    Student* previous = NULL;

    if (current != NULL && current->roll == targetRoll) {
        *head = current->next;
        free(current);
        printf("Student deleted.\n");
        return;
    }

    while (current != NULL && current->roll != targetRoll) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student not found.\n");
        return;
    }

    previous->next = current->next;
    free(current);
    printf("Student deleted.\n");
}

void updateByRoll(Student* head, int targetRoll) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->roll == targetRoll) {
            printf("New CGPA: ");
            scanf("%f", &temp->cgpa);
            for (int i = 0; i < 5; i++) {
                printf("New Course %d ID: ", i + 1);
                scanf("%d", &temp->courseId[i]);
            }
            printf("Student updated.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student not found.\n");
}

int main() {
    Student* head = NULL;
    int choice;
    int rollTarget;
    char nameTarget[50];

    while (1) {
        printf("\n1. Add Student\n2. Bulk Import\n3. Download All\n4. Find by Roll\n5. Find by Name\n6. Delete by Roll\n7. Update by Roll\n8. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(&head);
                break;
            case 2:
                bulkImport(&head);
                break;
            case 3:
                downloadAll(head);
                break;
            case 4:
                printf("Target Roll: ");
                scanf("%d", &rollTarget);
                findByRoll(head, rollTarget);
                break;
            case 5:
                printf("Target First Name: ");
                scanf("%49s", nameTarget);
                findByName(head, nameTarget);
                break;
            case 6:
                printf("Target Roll: ");
                scanf("%d", &rollTarget);
                deleteByRoll(&head, rollTarget);
                break;
            case 7:
                printf("Target Roll: ");
                scanf("%d", &rollTarget);
                updateByRoll(head, rollTarget);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
