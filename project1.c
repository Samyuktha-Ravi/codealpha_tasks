#include <iostream>
#include <map>

using namespace std;

// Function to convert letter grade to grade points
float gradeToPoint(char grade) {
    map<char, float> gradeMap = {
        {'A', 4.0}, {'B', 3.0}, {'C', 2.0}, {'D', 1.0}, {'F', 0.0}
    };
    return gradeMap[toupper(grade)];
}

int main() {
    int numCourses;
    float totalGradePoints = 0.0, totalCredits = 0.0;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; i++) {
        char grade;
        float credits;

        cout << "Enter grade for course " << i + 1 << " (A/B/C/D/F): ";
        cin >> grade;
        cout << "Enter credit hours for course " << i + 1 << ": ";
        cin >> credits;

        float gradePoint = gradeToPoint(grade);
        totalGradePoints += gradePoint * credits;
        totalCredits += credits;
    }

    if (totalCredits == 0) {
        cout << "Total credits cannot be zero. CGPA calculation failed!" << endl;
    } else {
        float cgpa = totalGradePoints / totalCredits;
        cout << "Your CGPA is: " << cgpa << endl;
    }

    return 0;
}
