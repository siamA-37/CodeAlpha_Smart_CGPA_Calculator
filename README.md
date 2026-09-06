# 🎓 Smart CGPA Calculator in C++

A **Smart CGPA Calculator** developed in **C++** as part of my **CodeAlpha Internship**.

This project is designed to calculate **Semester GPA and Overall CGPA** for students across multiple semesters. It includes input validation, grade-point calculation, failed-course detection, performance evaluation, and a detailed academic result summary.

---

## 📌 Project Overview

The **Smart CGPA Calculator** is a console-based C++ application that allows students to enter information for multiple semesters and courses.

For each course, the program takes:

* Course Name
* Credit Hours
* Letter Grade

The application then automatically calculates:

* Total Credits
* Total Grade Points
* Semester GPA
* Overall CGPA
* Academic Performance
* Number of Failed Courses
* Failed Course Details
* Semester-wise GPA Summary
* Final Result Summary

The project focuses on applying **C++ fundamentals, Object-Oriented-style data modeling using structures, STL vectors, functions, loops, conditional statements, input validation, and formatted output** in a practical application.

---

## 🚀 Features

### 1. 📚 Multiple Semester Support

The user can enter data for multiple semesters.

Example:

```text
Enter Number of Semester : 4
```

The program will then collect course information separately for:

```text
SEMESTER 1
SEMESTER 2
SEMESTER 3
SEMESTER 4
```

---

### 2. 📖 Multiple Course Support

For every semester, the user can enter any number of courses.

The program asks:

```text
Enter Number Of Courses :
```

Each course contains:

* Course Name
* Credit Hours
* Grade
* Grade Point

---

### 3. 📝 Course Name Input

The program supports course names containing spaces.

Example:

```text
Course Name: Object Oriented Programming
```

It also prevents empty course names.

If the user enters an empty course name, the program displays an error and asks for the course name again.

---

### 4. ⏱️ Credit Hour Validation

The program validates credit-hour input.

It rejects:

* Non-numeric input
* Zero
* Negative values

Example:

```text
Credit Hours: abc

❌ Invalid input!
Please enter a valid number.
```

It also rejects:

```text
Credit Hours: -3

❌ Credit hours must be greater than 0.
```

---

### 5. 🎯 Automatic Grade Point Calculation

The program automatically converts letter grades into grade points.

| Grade | Grade Point |
| ----- | ----------: |
| A+    |        4.00 |
| A     |        3.75 |
| A-    |        3.50 |
| B+    |        3.25 |
| B     |        3.00 |
| B-    |        2.75 |
| C+    |        2.50 |
| C     |        2.25 |
| D     |        2.00 |
| F     |        0.00 |

The grade point is automatically assigned using the `getGradePoint()` function.

---

### 6. 🔤 Grade Normalization

The program accepts lowercase and mixed-case grade input and converts it to uppercase automatically.

For example:

```text
a+
a
b+
c
f
```

are normalized before validation.

This is handled by:

```cpp
normalizeGrade()
```

---

### 7. ✅ Grade Validation

The program only accepts the following grades:

```text
A+
A
A-
B+
B
B-
C+
C
D
F
```

If an invalid grade is entered, the program displays an error message and asks the user to enter a valid grade.

Example:

```text
❌ Invalid grade!
Valid grades: A+, A, A-, B+, B, B-, C+, C, D, F
```

---

### 8. 🧮 Semester GPA Calculation

The program calculates GPA using the credit-weighted grade point formula:

```text
GPA = Total Grade Points / Total Credits
```

For each course:

```text
Grade Point × Credit Hours
```

is calculated and added to the semester's total grade points.

---

### 9. 📊 Overall CGPA Calculation

After collecting all semester data, the program calculates the final CGPA using:

```text
Final CGPA = Overall Grade Points / Overall Credits
```

This ensures that courses with different credit hours are properly weighted.

---

### 10. 📋 Detailed Semester Result

For every semester, the program displays a formatted table containing:

```text
Course
Credit
Grade
Point
```

Example:

```text
Course                    Credit         Grade     Point
----------------------------------------------------------------
Programming Fundamentals  3.00           A+        4.00
Mathematics                3.00           A         3.75
Physics                    3.00           B+        3.25
```

---

### 11. 📈 Semester GPA Summary

After displaying all semester results, the program provides a semester-wise GPA summary.

Example:

```text
--------------------------------
       SEMESTER GPA SUMMARY
--------------------------------
Semester 1 GPA : 3.67
Semester 2 GPA : 3.75
Semester 3 GPA : 3.82
```

---

### 12. 🏆 Performance Evaluation

The program automatically evaluates academic performance based on the final CGPA.

| CGPA Range  | Performance        |
| ----------- | ------------------ |
| 3.75 – 4.00 | Excellent!         |
| 3.50 – 3.74 | Very Good!         |
| 3.00 – 3.49 | Good!              |
| 2.50 – 2.99 | Satisfactory!      |
| 2.00 – 2.49 | Needs Improvement! |
| Below 2.00  | Poor!              |

---

### 13. ⚠️ Failed Course Detection

The program automatically detects courses with an `F` grade.

If the student has failed one or more courses, the program displays a warning.

Example:

```text
WARNING!

You have failed in 2 courses.

Failed Course(s):

Course: Mathematics | Semester: 1 | Grade: F
Course: Physics | Semester: 2 | Grade: F
```

This makes it easy for students to identify which courses require improvement.

---

### 14. 🛡️ Input Validation

The program contains validation for different types of user input.

It handles:

* Invalid semester number
* Invalid course number
* Invalid credit hours
* Negative values
* Zero values
* Invalid grades
* Empty course names
* Non-numeric input

The program prevents invalid input from directly affecting the calculations.

---

## 🧱 Project Structure

The project uses C++ structures to organize academic data.

### `Course` Structure

```cpp
struct Course {
    string course_names;
    double credit;
    string grade;
    double gradePoint;
};
```

It stores information about an individual course.

---

### `Semester` Structure

```cpp
struct Semester {
    int semesterNumber;
    vector<Course> courses;
    double totalCredit;
    double totalGradePoints;
    double gpa;
};
```

It stores all information related to a semester, including its courses, total credits, total grade points, and GPA.

---

## ⚙️ Functions Used

### `calculateGPA()`

Calculates the GPA of a semester using course credits and grade points.

```cpp
void calculateGPA(Semester &semester)
```

---

### `getGradePoint()`

Converts a letter grade into its corresponding grade point.

```cpp
double getGradePoint(string grade)
```

---

### `isValidGrade()`

Checks whether the entered grade is valid.

```cpp
bool isValidGrade(string grade)
```

---

### `normalizeGrade()`

Converts the entered grade into uppercase format.

```cpp
string normalizeGrade(string grade)
```

---

## 🧠 C++ Concepts Used

This project demonstrates several important C++ programming concepts:

* Variables
* Data Types
* Strings
* Conditional Statements
* Loops
* Functions
* Structures (`struct`)
* References
* `vector`
* `const`
* String manipulation
* Input validation
* Exception-like input handling using `cin.fail()`
* `numeric_limits`
* Formatted output
* `setw()`
* `setprecision()`
* `fixed`
* File-independent data processing
* Modular programming
* Basic data modeling

---

## 🛠️ Technologies Used

* **Language:** C++
* **Standard Library:** C++ Standard Library
* **Data Structure:** `vector`
* **Interface:** Console / Terminal
* **Compiler:** Any modern C++ compiler supporting standard C++ features

---

## ▶️ How to Run

### Step 1: Clone the Repository

```bash
git clone YOUR_REPOSITORY_LINK
```

### Step 2: Open the Project

Open the project folder in your preferred C++ IDE or code editor.

Recommended editors/IDEs:

* Visual Studio Code
* Code::Blocks
* Dev-C++
* Visual Studio
* CLion

### Step 3: Compile the Program

Using `g++`:

```bash
g++ main.cpp -o cgpa_calculator
```

### Step 4: Run

On Windows:

```bash
cgpa_calculator.exe
```

On Linux/macOS:

```bash
./cgpa_calculator
```

---

## 💻 Sample Input

```text
=====================================================
                SMART CGPA CALCULATOR
=====================================================

Enter Number of Semester : 2

========================================
               SEMESTER 1

========================================

Enter Number Of Courses : 3

Course 1
Course Name: Programming Fundamentals
Credit Hours: 3
Grade: A+

Course 2
Course Name: Mathematics
Credit Hours: 3
Grade: A

Course 3
Course Name: Physics
Credit Hours: 3
Grade: B+
```

---

## 📊 Sample Output

```text
======================================================
                 ALL SEMESTER RESULTS
======================================================

------------------------------------------------------
                    SEMESTER 1
------------------------------------------------------

Course                    Credit         Grade     Point
Programming Fundamentals  3.00           A+        4.00
Mathematics               3.00           A         3.75
Physics                   3.00           B+        3.25

Total Credits       : 9.00
Total Grade Points  : 33.00
Semester GPA        : 3.67

--------------------------------
       SEMESTER GPA SUMMARY
--------------------------------
Semester 1 GPA : 3.67
Semester 2 GPA : 3.75

--------------------------------
Final CGPA : 3.71
Performance : Very Good!
--------------------------------

======================================================
                    FINAL RESULT
======================================================

Total Credits           : 18.00
Total Grade Points      : 66.75
Final CGPA              : 3.71
```

*The above output is an example and may vary depending on the user's input.*

---

## 📐 GPA Calculation Example

Suppose a semester contains three courses:

| Course   | Credit | Grade | Grade Point |
| -------- | -----: | ----- | ----------: |
| Course 1 |      3 | A+    |        4.00 |
| Course 2 |      3 | A     |        3.75 |
| Course 3 |      3 | B+    |        3.25 |

Grade points:

```text
Course 1 = 3 × 4.00 = 12.00
Course 2 = 3 × 3.75 = 11.25
Course 3 = 3 × 3.25 = 9.75
```

Total:

```text
Total Credits = 9.00
Total Grade Points = 33.00
```

Therefore:

```text
GPA = 33.00 / 9.00
    = 3.67
```

---

## 🎯 Purpose of the Project

This project was developed as part of my **CodeAlpha Internship** to apply C++ programming concepts to a practical real-world problem.

The main objectives were to:

* Practice C++ programming fundamentals
* Work with structured data
* Implement functions and modular logic
* Use STL containers
* Implement input validation
* Perform mathematical calculations
* Build a practical console-based application
* Improve problem-solving and programming skills

---

## 🔐 Data & Security

This version of the project does **not** store student information permanently in a database or external file.

All information is processed during program execution and is stored temporarily in memory using C++ data structures.

---

## 🔮 Future Improvements

The project can be further improved with the following features:

* [ ] Save student results to files
* [ ] Load previously saved results
* [ ] Student profile system
* [ ] Student ID support
* [ ] Multiple student support
* [ ] Overall CGPA tracking
* [ ] Semester result editing
* [ ] Course result editing
* [ ] Result search functionality
* [ ] Result export to PDF
* [ ] Database integration
* [ ] GUI version
* [ ] Web-based version
* [ ] More detailed academic analytics
* [ ] Academic warning system
* [ ] Course-wise performance tracking

---

## 📚 Learning Outcomes

Through this project, I strengthened my understanding of:

```text
C++ Fundamentals
        ↓
Functions
        ↓
Structures
        ↓
STL Vector
        ↓
Data Validation
        ↓
Mathematical Calculation
        ↓
Modular Programming
        ↓
Real-World Problem Solving
```

---

## 👨‍💻 Developer

**Md Siam Hossain**

**Role:** C++ Programmer | Competitive Programmer | Mathematics Student

Hajee Muhammad Danesh Science and Technology University,Dinajpur-5200,BD

This project was developed as part of my **CodeAlpha Internship**.

---

## 🏢 Internship

**CodeAlpha Internship**

Project: **Smart CGPA Calculator in C++**

The project demonstrates practical implementation of C++ programming concepts through a student-focused academic management application.

---

## ⭐ Acknowledgment

Thanks to **CodeAlpha** for providing the internship opportunity and project-based learning environment that encouraged me to apply programming concepts to a practical application.

---

## 📄 License

This project is created for **educational and internship purposes**.

You are welcome to study and modify the source code for learning purposes.
