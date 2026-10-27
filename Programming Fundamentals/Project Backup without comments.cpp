#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string dob;
    int age;
    char studentClass;
    string course;
};

struct AttendanceRecord {
    string studentName;
    char studentClass;
    char lecturer;
};


Student students[100];
AttendanceRecord attendanceRecords[200];
int studentCount = 0;
int recordCount = 0;

const string COURSES[5] = {
    "Communication Skills",
    "Business French",
    "Scholarly Writing",
    "Public Relations",
    "Accounting"
};

const char VALID_CLASSES[5] = {'A', 'B','C','D','E'};
const char VALID_LECTURERS[10] = {'O','P','Q','R','S','T','U','V','W','X'};


char toUpperCustom(char c) {
    if (c >= 'a' && c <= 'z') return c - 32;
    return c;
}


void clearInputBuffer() {
    cin.clear();
    cin.ignore(10000, '\n');
}

bool isValidClass(char c) {
    for (char v : VALID_CLASSES) {
        if (v == toUpperCustom(c))
            return true;
    }
    return false;
}

bool isValidLecturer(char c) {
    for (char v : VALID_LECTURERS) {
        if (v == toUpperCustom(c))
            return true;
    }
    return false;
}

void displayWelcome() {
    cout<< "=======================================\n";
    cout<<"Welcome to St. Monica's Presbyterian College\n";
    cout<<"       School Management System\n";
    cout<<"========================================\n\n";
}

int displayMainMenu() {
    int choice;
    cout << "\n-------------MAIN MENU --------------\n";
    cout << "1. Register Course\n";
    cout << "2. Record Attendance\n";
    cout << "3. Retrieve Attendance Records\n";
    cout << "4. Exit\n";
    cout << "---------------------------------------\n";
    cout << "Enter Choice: ";
    cin >> choice;

    if (cin.fail()) {
        clearInputBuffer();
        return -1;
    }
    return choice;
}

bool validateStudent(const Student &s) {
    if (s.name.empty()) return false;
    if (s.age < 5 || s.age > 100) return false;
    if (!isValidClass(s.studentClass)) return false;
    return true;
}

string selectCourse() {
    cout << "\nAvailable Courses:\n";
    for (int i = 0; i < 5; i++)
        cout << (i + 1) << ". " << COURSES[i] << "\n";

    int choice;
    cout << "Select a course (1-5): ";
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 5) {
        clearInputBuffer();
        return "";
    }
    return COURSES[choice - 1];
}

void registerCourse() {
    Student s;
    clearInputBuffer();

    cout << "\n---Course Registration---\n";
    cout << "Enter Student Name: ";
    getline(cin, s.name);

    cout << "Enter date of birth (dd/mm/yyyy): ";
    getline(cin, s.dob);

    cout << "Enter age: ";
    cin >> s.age;

    cout << "Enter class (A, B, C, D, E): ";
    cin >> s.studentClass;
    s.studentClass = toUpperCustom(s.studentClass);

    s.course = selectCourse();

    if (validateStudent(s) && !s.course.empty()) {
        students[studentCount++] = s;  // store in array
        cout << "\nRegistration successful!\n";
    } else {
        cout << "\nInvalid Details.\n";
    }
    cout << "Return to Main Menu.\n";
}

void recordAttendance() {
    AttendanceRecord rec;
    clearInputBuffer();

    cout << "\n---Take Attendance ---\n";
    cout << "Select class (A, B, C, D, E): ";
    cin >> rec.studentClass;
    rec.studentClass = toUpperCustom(rec.studentClass);

    if (!isValidClass(rec.studentClass)) {
        cout << "\nInvalid class.\n";
        cout << "Return to Main Menu.\n";
        return;
    }

    cout << "Lecturers available: ";
    for (char lec : VALID_LECTURERS) cout << lec << " ";
    cout << "\nSelect lecturer: ";
    cin >> rec.lecturer;
    rec.lecturer = toUpperCustom(rec.lecturer);

    if (!isValidLecturer(rec.lecturer)) {
        cout << "\nInvalid lecturer.\n";
        cout << "Return to Main Menu.\n";
        return;
    }

    clearInputBuffer();
    cout << "Enter student name: ";
    getline(cin, rec.studentName);

    attendanceRecords[recordCount++] = rec;  // store in array
    cout << "\nAttendance Successful!\n";
    cout << "Return to Main Menu.\n";
}

void retrieveAttendance() {
    clearInputBuffer();
    string name;
    cout << "\n--- Retrieve Attendance Records ---\n";
    cout << "Enter student name: ";
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < recordCount; i++) {
        if (attendanceRecords[i].studentName == name) {
            cout << "Student: " << attendanceRecords[i].studentName
                 << " | Class: " << attendanceRecords[i].studentClass
                 << " | Lecturer: " << attendanceRecords[i].lecturer << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "No attendance record found for \"" << name << "\".\n";

    cout << "Return to Main Menu.\n";
}

int main() {
    displayWelcome();

    int choice;
    do {
        choice = displayMainMenu();

        switch (choice) {
            case 1:
                registerCourse();
                break;
            case 2:
                recordAttendance();
                break;
            case 3:
                retrieveAttendance();
                break;
            case 4:
                cout << "\nThank you for using the School Management System.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
