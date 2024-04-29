#include <iostream>

using namespace std;

void displayGrade(double mark)
{
    if (mark >= 90)
    {
        cout << "A+" << endl;
    }
    else if (mark >= 85)
    {
        cout << "A" << endl;
    }
    else if (mark >= 80)
    {
        cout << "B+" << endl;
    }
    else if (mark >= 75)
    {
        cout << "B" << endl;
    }
    else if (mark >= 70)
    {
        cout << "C+" << endl;
    }
    else if (mark >= 65)
    {
        cout << "C" << endl;
    }
    else if (mark >= 60)
    {
        cout << "D+" << endl;
    }
    else if (mark >= 50)
    {
        cout << "D" << endl;
    }
    else
    {
        cout << "F" << endl;
    }
}

int main() {
    const int numCourses = 6;
    double marks[numCourses];

    cout << "Enter marks for 6 courses:" << endl;
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << (i + 1) << ": ";
        cin >> marks[i];
    }


    cout << "Grades for the 6 courses:" << endl;
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << (i + 1) << ": ";
        displayGrade(marks[i]);
    }

    return 0;
}
