#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Student {
private:
    int roll;
    string name;
    int marks[5];
    int total;
    float per;
    string result;
    string grade;   

public:
    void input() {
        cout << "\nEnter Roll Number: ";
        cin >> roll;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        total = 0;
        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
            total += marks[i];
        }

        per = total / 5.0;

      
        result = "Pass";
        for (int i = 0; i < 5; i++) {
            if (marks[i] < 40) {
                result = "Fail";
                break;
            }
        }

       
        if (per >= 90) grade = "A+";
        else if (per >= 80) grade = "A";
        else if (per >= 70) grade = "B";
        else if (per >= 60) grade = "C";
        else if (per >= 50) grade = "D";
        else grade = "F";
    }

    void display() {
        cout << "\n--------------------------\n";
        cout << "Roll No: " << roll << endl;
        cout << "Name: " << name << endl;

        cout << "Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }

        cout << "\nTotal: " << total;
        cout << "\nPercentage: " << per << "%";
        cout << "\nResult: " << result;
        cout << "\nGrade: " << grade << endl; 
    }

    int getRoll() {
        return roll;
    }

    string toString() {
        stringstream ss;
        ss << roll << "|" << name;
        for (int i = 0; i < 5; i++) {
            ss << "|" << marks[i];
        }
        ss << "|" << total << "|" << per << "|" << result << "|" << grade; 
        return ss.str();
    }

    void fromString(string line) {
        stringstream ss(line);
        string temp;

        getline(ss, temp, '|');
        roll = stoi(temp);

        getline(ss, name, '|');

        for (int i = 0; i < 5; i++) {
            getline(ss, temp, '|');
            marks[i] = stoi(temp);
        }

        getline(ss, temp, '|');
        total = stoi(temp);

        getline(ss, temp, '|');
        per = stof(temp);

        getline(ss, result, '|');
        getline(ss, grade, '|'); 
    }
};

// Add Student
void addStudent() {
    Student s;
    s.input();

    ofstream file("data.txt", ios::app);
    file << s.toString() << endl;
    file.close();

    cout << "\nRecord saved successfully!\n";
}

// Display All
void displayAll() {
    ifstream file("data.txt");
    string line;

    if (!file) {
        cout << "\nNo records found.\n";
        return;
    }

    while (getline(file, line)) {
        Student s;
        s.fromString(line);
        s.display();
    }

    file.close();
}

// Search Student
void searchStudent() {
    int roll;
    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    ifstream file("data.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        Student s;
        s.fromString(line);

        if (s.getRoll() == roll) {
            s.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nRecord not found.\n";
    }

    file.close();
}

// Update Student
void updatedata() {
    int roll;

    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    ifstream file("data.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while (getline(file, line)) {
        Student s;
        s.fromString(line);

        if (s.getRoll() == roll) {
            cout << "\nEnter new details:\n";
            s.input();
            found = true;
        }

        temp << s.toString() << endl;
    }

    file.close();
    temp.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found)
        cout << "\nRecord updated successfully!\n";
    else
        cout << "\nRecord not found.\n";
}

// Delete Student
void deletedata() {
    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    ifstream file("data.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while (getline(file, line)) {
        Student s;
        s.fromString(line);

        if (s.getRoll() == roll) {
            found = true;
            continue;
        }

        temp << s.toString() << endl;
    }

    file.close();
    temp.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found)
        cout << "\nRecord deleted successfully!\n";
    else
        cout << "\nRecord not found.\n";
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n===== Result Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Data\n";
        cout << "5. Delete Data\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updatedata(); break;
            case 5: deletedata(); break;
            case 6: cout << "\nExiting...\n"; break;
            default: cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}