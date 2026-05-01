# Student Result Management System (C++)

## Overview

The Student Result Management System is a console-based application developed in C++ that helps manage student academic records efficiently. The system uses file handling to store and retrieve data, ensuring persistence across sessions.

It allows users to perform core operations such as adding, viewing, searching, updating, and deleting student records, along with automatic calculation of total marks, percentage, result status, and grade.

---

## Features

* Add new student records
* View all student data
* Search student by roll number
* Update existing student details
* Delete student records
* Automatic calculation of:

  * Total marks
  * Percentage
  * Pass/Fail result
  * Grade system (A+ to F)
* File-based data storage (data.txt)

---

## Grade System

| Percentage | Grade |
| ---------- | ----- |
| 90+        | A+    |
| 80–89      | A     |
| 70–79      | B     |
| 60–69      | C     |
| 50–59      | D     |
| Below 50   | F     |

---

## Technologies Used

* C++
* File Handling (fstream)
* Object-Oriented Programming (OOP)

---

## Project Structure

* `main.cpp` → Contains the full implementation
* `data.txt` → Stores student records

---

## How It Works

Each student record is stored in a text file using a structured format:
RollNo | Name | Marks | Total | Percentage | Result | Grade

The system reads and writes this data using string parsing and file streams.

---

## How to Run

1. Clone the repository:

   ```
   git clone https://github.com/samruddhi2210/student-result-management.git
   ```

2. Navigate to the project folder:

   ```
   cd student-result-management
   ```

3. Compile the program:

   ```
   g++ main.cpp -o result
   ```

4. Run the program:

   ```
   ./result
   ```

---

## Sample Functionalities

* Add student details including marks
* Automatically calculates performance metrics
* Displays structured result output
* Persistent storage using files

---

## Future Improvements

* Add GUI (using Qt or other frameworks)
* Add subject-wise grading
* Implement ranking system
* Export results to CSV/Excel
* Add login/authentication system

---

## Author

Samruddhi
