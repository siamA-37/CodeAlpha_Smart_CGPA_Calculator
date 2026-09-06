#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;

struct Course{
    string course_names;
    double credit;
    string grade;
    double gradePoint;
};
struct Semester{
    int semesterNumber;
    vector<Course>courses;
    double totalCredit;
    double totalGradePoints;
    double gpa;
};
void calculateGPA(Semester &semester){
    semester.totalCredit = 0.0;
    semester.totalGradePoints = 0.0;
    for(const Course &course : semester.courses){
        semester.totalCredit += course.credit;
        semester.totalGradePoints += course.gradePoint * course.credit;
    }
    semester.gpa = semester.totalGradePoints / semester.totalCredit;
}
double getGradePoint(string grade){
    if(grade == "A+"){
        return 4.00;
    }
    if(grade == "A"){
        return 3.75;
    }
    if(grade == "A-"){
        return 3.50;
    }
    if(grade == "B+"){
        return 3.25;
    }
    if(grade == "B"){
        return 3.00;
    }
    if(grade == "B-"){
        return 2.75;
    }
    if(grade == "C+"){
        return 2.50;
    }
    if(grade == "C"){
        return 2.25;
    }
    if(grade == "D"){
        return 2.00;
    }
    if(grade == "F"){
        return 0.00;
    }
    return 0.00;
}
bool isValidGrade(string grade){
    if(grade == "A+" || grade == "A" || grade == "A-" || grade == "B+" || grade == "B" || grade == "B-" || grade == "C+" || grade == "C" || grade == "D" || grade == "F"){
        return true;
    }
    return false;
}

string normalizeGrade(string grade){
    //transform(grade.begin(),grade.end(),grade.begin(),::toupper);
    for(char &c:grade){
        c = toupper(c);
    }
    return grade;
}
int main()
{
    
    cout<<"====================================================="<<endl;
    cout<<"                SMART CGPA CALCULATOR                "<<endl;
    cout<<"====================================================="<<endl;
    
    int num_of_courses;
    int totalSemester;
    vector<Semester> semesters;
    while (true){
        /* code */
        cout<<"Enter Number of Semester : ";
        cin>> totalSemester;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n❌ Invalid input!"<<"\nPlease ener a valid number.\n"<<endl;
            continue;
        }
        if(totalSemester <= 0){
            cout<<"\n❌ Number of semester must be greater than 0.\n"<<endl;
            continue;
        }
        break;
    }
    
    for(int semesterNumber = 1;semesterNumber <= totalSemester;semesterNumber++){
        cout<<"\n========================================"<<endl;
        cout<<"               SEMESTER "<<semesterNumber<<endl;
        cout<<"\n========================================"<<endl;

        while(true){
            cout<<"Enter Number Of Courses : ";
            cin>>num_of_courses;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "\n❌ Invalid input!"<< "\nPlease enter a valid number.\n" << endl;
                continue;
            }
            if(num_of_courses <= 0){
                cout << "\n❌ Number of courses must be greater than 0.\n"<< endl;
                continue;
            }
            break;
        }

        vector<Course>courses(num_of_courses);
         //start taking input 

        for(int i=0;i<num_of_courses;i++){
            cout<<"Course "<<i+1<<endl;
            cout<<"Course Name: ";

            getline(cin>>ws,courses[i].course_names);

            while(courses[i].course_names.empty()){
            cout<<"\n❌ Error: Course name cannot be empty! Please try again.\n"<<endl;
            cout<<"Course Name: ";
            getline(cin>>ws,courses[i].course_names);
        }
        //credit hours all case implementation
        
        while(true){
            cout<<"Credit Hours: ";
            cin>>courses[i].credit;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"\n❌ Invalid input!\nPlease enter a valid number.\n"<<endl;
                continue;
            }
            if(courses[i].credit <= 0){
                 cout << "\n❌ Credit hours must be greater than 0.\n" << endl;
                 continue;
            }
            break;
        }
        //grade is okay for all!
        cout<<"Grade: ";
        cin>>courses[i].grade;
        courses[i].grade = normalizeGrade(courses[i].grade);
        while(!isValidGrade(courses[i].grade)){
            cout<<"\n❌ Invalid grade!\nValid grades: A+, A, A-, B+, B, B-, C+, C, D, F\n\nGrade:";
            cin>>courses[i].grade;
            courses[i].grade = normalizeGrade(courses[i].grade);
        }

            courses[i].gradePoint = getGradePoint(courses[i].grade);
            cout<<endl;
        }
        Semester semester;

        semester.semesterNumber = semesterNumber;
        semester.courses = courses;

        calculateGPA(semester);

        semesters.push_back(semester);
    }

    cout << "\n\n======================================================" << endl;
    cout << "                 ALL SEMESTER RESULTS                " << endl;
    cout << "======================================================" << endl;

    for(const Semester &semester : semesters){
    cout << "\n------------------------------------------------------" << endl;
    cout << "                    SEMESTER "<< semester.semesterNumber << endl;
    cout << "------------------------------------------------------" << endl;

    cout << left<< setw(25) << "Course"<<setw(15) <<"Credit"<<setw(10)<<"Grade"<< setw(10) << "Point"<< endl;

    for(const Course &course : semester.courses){
        cout << left<< setw(25) << course.course_names<< fixed << setprecision(2)<< setw(15) << course.credit<< setw(10) << course.grade<< course.gradePoint<< endl;
    }
    cout << "\nTotal Credits      : "<< semester.totalCredit << endl;
    cout << "Total Grade Points : " << semester.totalGradePoints << endl;
    cout << "Semester GPA       : "<< fixed << setprecision(2)<< semester.gpa << endl;
    }

    double overallCredits = 0.0;
    double overallGradePoints = 0.0;
    for(const Semester &semester : semesters){
        overallCredits += semester.totalCredit;
        overallGradePoints += semester.totalGradePoints;
    }  
    double finalCGPA = overallGradePoints / overallCredits;

    //  PERFORMANCE 

    string performance;

    if(finalCGPA >= 3.75){
        performance = "Excellent!";
    }
    else if(finalCGPA >= 3.50){
        performance = "Very Good!";
    }
    else if(finalCGPA >= 3.00){
        performance = "Good!";
    }
    else if(finalCGPA >= 2.50){
        performance = "Satisfactory!";
    }
    else if(finalCGPA >= 2.00){
        performance = "Needs Improvement!";
    }
    else{
        performance = "Poor!";
    }

    int failedCourses = 0;

    for(const Semester &semester : semesters){
        for(const Course &course : semester.courses){

            if(course.grade == "F"){
                failedCourses++;
            }

        }
    }

    if(failedCourses > 0){

        cout << "\n\n WARNING!" << endl;
        cout << "You have failed in "<< failedCourses << " course";

        if(failedCourses > 1){
            cout << "s";
        }
        cout << "." << endl;
        cout << "\nFailed Course(s):" << endl;
        for(const Semester &semester : semesters){
            for(const Course &course : semester.courses){
             if(course.grade == "F"){
                    cout << "Course: "<< course.course_names<< " | Semester: "<< semester.semesterNumber<< " | Grade: F"<< endl;
                }
            }
        }
    }


    cout << "\n\n--------------------------------" << endl;
    cout << "       SEMESTER GPA SUMMARY" << endl;
    cout << "--------------------------------" << endl;

    for(const Semester &semester : semesters){
        cout << "Semester " << semester.semesterNumber<< " GPA : "<< fixed << setprecision(2)<< semester.gpa << endl;
    }

    cout << "\n--------------------------------" << endl;
    cout << "Final CGPA : " << fixed << setprecision(2) << finalCGPA << endl;
    cout << "Performance : " << performance << endl;
    cout << "--------------------------------" << endl;

    cout << "\n\n======================================================" << endl;
    cout << "                    FINAL RESULT                     " << endl;
    cout << "======================================================" << endl;
    cout << left << setw(25) << "Total Credits" << ": " << overallCredits << endl;
    cout << left << setw(25) << "Total Grade Points" << ": " << overallGradePoints << endl;
    cout << left << setw(25) << "Final CGPA"<< ": " << fixed << setprecision(2) << finalCGPA << endl;

    return 0;
}
