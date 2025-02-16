#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10

typedef struct {
    char name[50];
    int roll;
    char teleph[20];
    char adrs[50];
} student;

typedef struct {
    int count;
    student s[MAX_STUDENTS];
} sreg;

int add(sreg *sr, const student *s) {
    if (sr->count >= MAX_STUDENTS) return 0;
    for (int i = 0; i < sr->count; ++i) {
        if (sr->s[i].roll == s->roll) {
            return 0;
        }
    }
    sr->s[sr->count] = *s;
    sr->count++;
    return 1;
}

student get(sreg *sr, int r) {
    for (int i = 0; i < sr->count; ++i) {
        if (sr->s[i].roll == r) {
            return sr->s[i];
        }
    }
    student empty = {"", 0, "", ""};
    return empty;
}

int deletestud(sreg *sr, int r) {
    int p = -1;
    for (int i = 0; i < sr->count; i++) {
        if (sr->s[i].roll == r) {
            p = i;
            break;
        }
    }
    if (p == -1) {
        return 0;
    }
    for (int i = p; i < sr->count - 1; i++) {
        sr->s[i] = sr->s[i + 1];
    }
    sr->count--;
    return 1;
}

int modify(sreg *sr, const student *s) {
    for (int i = 0; i < sr->count; ++i) {
        if (sr->s[i].roll == s->roll) {
            sr->s[i] = *s;
            return 1;
        }
    }
    return 0;
}

int compare(const void *a, const void *b) {
    return strcmp(((student *)a)->name, ((student *)b)->name);
}

void sortStudents(sreg *sr) {
    qsort(sr->s, sr->count, sizeof(student), compare);
}

int getCount(const sreg *sr) {
    return sr->count;
}

void exportToFile(const sreg *sr, const char *fname) {
    FILE *file = fopen(fname, "w");
    for (int i = 0; i < sr->count; ++i) {
        fprintf(file, "%s\n%d\n%s\n%s\n", sr->s[i].name, sr->s[i].roll, sr->s[i].teleph, sr->s[i].adrs);
    }
    fclose(file);
}

void loadFromFile(sreg *sr, const char *fname) {
    FILE *file = fopen(fname, "r");
    sr->count = 0;
    while (file && sr->count < MAX_STUDENTS) {
        student s;
        fgets(s.name, sizeof(s.name), file);
        s.name[strcspn(s.name, "\n")] = 0; // Remove newline character
        fscanf(file, "%d\n", &s.roll);
        fgets(s.teleph, sizeof(s.teleph), file);
        s.teleph[strcspn(s.teleph, "\n")] = 0; // Remove newline character
        fgets(s.adrs, sizeof(s.adrs), file);
        s.adrs[strcspn(s.adrs, "\n")] = 0; // Remove newline character
        sr->s[sr->count++] = s;
    }
    fclose(file);
}

int main() {
    sreg sr;
    sr.count = 0;
    int choice;

    do {
        printf("1. Add Student\n2. Delete Student\n3. Get Student\n4. Modify Student\n5. Sort Students\n6. Get Count\n7. Export to File\n8. Load from File\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to ignore the newline character left in the buffer

        if (choice == 1) {
            student s;
            printf("Enter name (Last, First): ");
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = 0; // Remove newline character
            printf("Enter roll number: ");
            scanf("%d", &s.roll);
            getchar();
            printf("Enter telephone: ");
            fgets(s.teleph, sizeof(s.teleph), stdin);
            s.teleph[strcspn(s.teleph, "\n")] = 0; // Remove newline character
            printf("Enter address: ");
            fgets(s.adrs, sizeof(s.adrs), stdin);
            s.adrs[strcspn(s.adrs, "\n")] = 0; // Remove newline character
            if (add(&sr, &s)) {
                printf("Student added successfully.\n");
            } else {
                printf("Failed to add student. Roll number might already exist or register is full.\n");
            }
        } else if (choice == 2) {
            int roll;
            printf("Enter roll number: ");
            scanf("%d", &roll);
            if (deletestud(&sr, roll)) {
                printf("Student deleted successfully.\n");
            } else {
                printf("Student not found.\n");
            }
        } else if (choice == 3) {
            int roll;
            printf("Enter roll number: ");
            scanf("%d", &roll);
            student s = get(&sr, roll);
            if (s.roll != 0) {
                printf("Student found: %s, %s, %s\n", s.name, s.teleph, s.adrs);
            } else {
                printf("Student not found.\n");
            }
        } else if (choice == 4) {
            student s;
            printf("Enter roll number of student to modify: ");
            scanf("%d", &s.roll);
            getchar();
            printf("Enter new name (Last, First): ");
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = 0; // Remove newline character
            printf("Enter new telephone: ");
            fgets(s.teleph, sizeof(s.teleph), stdin);
            s.teleph[strcspn(s.teleph, "\n")] = 0; // Remove newline character
            printf("Enter new address: ");
            fgets(s.adrs, sizeof(s.adrs), stdin);
            s.adrs[strcspn(s.adrs, "\n")] = 0; // Remove newline character
            if (modify(&sr, &s)) {
                printf("Student modified successfully.\n");
            } else {
                printf("Student not found.\n");
            }
        } else if (choice == 5) {
            sortStudents(&sr);
            printf("Students sorted successfully.\n");
        } else if (choice == 6) {
            printf("Total number of students: %d\n", getCount(&sr));
        } else if (choice == 7) {
            char fname[50];
            printf("Enter file name to export: ");
            fgets(fname, sizeof(fname), stdin);
            fname[strcspn(fname, "\n")] = 0; // Remove newline character
            exportToFile(&sr, fname);
            printf("Students exported successfully.\n");
        } else if (choice == 8) {
            char fname[50];
            printf("Enter file name to load: ");
            fgets(fname, sizeof(fname), stdin);
            fname[strcspn(fname, "\n")] = 0; // Remove newline character
            loadFromFile(&sr, fname);
            printf("Students loaded successfully.\n");
        }
    } while (choice != 9);

    return 0;
}