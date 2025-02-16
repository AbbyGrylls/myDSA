#include <bits/stdc++.h>
using namespace std;
#define MAX_STUDENTS 10

struct student {
    string name;
    int roll;
    string teleph;
    string adrs;
    student() : name(""), roll(0), teleph(""), adrs("") {}
};

struct sreg {
    int count = 0;
    student s[MAX_STUDENTS];
};

int add(sreg &sr, const student &s) {
    if (sr.count >= MAX_STUDENTS) return 0;
    for (int i = 0; i < sr.count; ++i) {
        if (sr.s[i].roll == s.roll) {
            return 0;
        }
    }
    sr.s[sr.count] = s;
    sr.count++;
    return 1;
}

student get(sreg &sr, int r) {
    for (int i = 0; i < sr.count; ++i) {
        if (sr.s[i].roll == r) {
            return sr.s[i];
        }
    }
    return student();
}

int deletestud(sreg &sr, int r) {
    int p = -1;
    for (int i = 0; i < sr.count; i++) {
        if (sr.s[i].roll == r) {
            p = i;
            break;
        }
    }
    if (p == -1) {
        return 0;
    }
    for (int i = p; i < sr.count - 1; i++) {
        sr.s[i] = sr.s[i + 1];
    }
    sr.count--;
    return 1;
}

int modify(sreg &sr, const student &s) {
    for (int i = 0; i < sr.count; ++i) {
        if (sr.s[i].roll == s.roll) {
            sr.s[i] = s;
            return 1;
        }
    }
    return 0;
}

void sortStudents(sreg &sr) {
    sort(sr.s, sr.s + sr.count,  {
        return a.name < b.name;
    });
}

int getCount(const sreg &sr) {
    return sr.count;
}

void exportToFile(const sreg &sr, const string &fname) {
    ofstream file(fname);
    for (int i = 0; i < sr.count; ++i) {
        file << sr.s[i].name << "\n" << sr.s[i].roll << "\n" << sr.s[i].teleph << "\n" << sr.s[i].adrs << "\n";
    }
    file.close();
}

void loadFromFile(sreg &sr, const string &fname) {
    ifstream file(fname);
    sr.count = 0;
    while (file && sr.count < MAX_STUDENTS) {
        student s;
        getline(file, s.name);
        file >> s.roll;
        file.ignore();
        getline(file, s.teleph);
        getline(file, s.adrs);
        sr.s[sr.count++] = s;
    }
    file.close();
}

int main() {
    sreg sr;
    sr.count = 0;
    int choice;

    do {
        cout << "1. Add Student\n2. Delete Student\n3. Get Student\n4. Modify Student\n5. Sort Students\n6. Get Count\n7. Export to File\n8. Load from File\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to ignore the newline character left in the buffer

        if (choice == 1) {
            student s;
            cout << "Enter name (Last, First): ";
            getline(cin, s.name);
            cout << "Enter roll number: ";
            cin >> s.roll;
            cin.ignore();
            cout << "Enter telephone: ";
            getline(cin, s.teleph);
            cout << "Enter address: ";
            getline(cin, s.adrs);
            if (add(sr, s)) {
                cout << "Student added successfully.\n";
            } else {
                cout << "Failed to add student. Roll number might already exist or register is full.\n";
            }
        } else if (choice == 2) {
            int roll;
            cout << "Enter roll number: ";
            cin >> roll;
            if (deletestud(sr, roll)) {
                cout << "Student deleted successfully.\n";
            } else {
                cout << "Student not found.\n";
            }
        } else if (choice == 3) {
            int roll;
            cout << "Enter roll number: ";
            cin >> roll;
            student s = get(sr, roll);
            if (s.roll != 0) {
                cout << "Student found: " << s.name << ", " << s.teleph << ", " << s.adrs << "\n";
            } else {
                cout << "Student not found.\n";
            }
        } else if (choice == 4) {
            student s;
            cout << "Enter roll number of student to modify: ";
            cin >> s.roll;
            cin.ignore();
            cout << "Enter new name (Last, First): ";
            getline(cin, s.name);
            cout << "Enter new telephone: ";
            getline(cin, s.teleph);
            cout << "Enter new address: ";
            getline(cin, s.adrs);
            if (modify(sr, s)) {
                cout << "Student modified successfully.\n";
            } else {
                cout << "Student not found.\n";
            }
        } else if (choice == 5) {
            sortStudents(sr);
            cout << "Students sorted successfully.\n";
        } else if (choice == 6) {
            cout << "Total number of students: " << getCount(sr) << "\n";
        } else if (choice == 7) {
            string fname;
            cout << "Enter file name to export: ";
            getline(cin, fname);
            exportToFile(sr, fname);
            cout << "Students exported successfully.\n";
        } else if (choice == 8) {
            string fname;
            cout << "Enter file name to load: ";
            getline(cin, fname);
            loadFromFile(sr, fname);
            cout << "Students loaded successfully.\n";
        }
    } while (choice != 9);

    return 0;
