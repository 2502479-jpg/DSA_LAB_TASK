#include <iostream>
using namespace std;

int main()
{
    const int STUDENTS = 6;
    const int SUBJECTS = 4;
    string subjectNames[SUBJECTS] = {"English", "Mathematics", "Programming", "AI"};

    int marks[STUDENTS][SUBJECTS] = {
        {78, 85, 90, 88},
        {60, 55, 70, 65},
        {95, 92, 89, 97},
        {40, 50, 45, 60},
        {70, 75, 80, 78},
        {88, 91, 85, 90}
    };

    // Display marks table
    cout << "Marks Table:" << endl;
    cout << "Student\t";
    for (int j = 0; j < SUBJECTS; j++)
        cout << subjectNames[j] << "\t";
    cout << endl;

    int total[STUDENTS] = {0};
    for (int i = 0; i < STUDENTS; i++)
    {
        cout << "S" << (i + 1) << "\t";
        for (int j = 0; j < SUBJECTS; j++)
        {
            cout << marks[i][j] << "\t";
            total[i] += marks[i][j];
        }
        cout << endl;
    }

    // Total and average marks per student
    cout << "\nTotal and Average Marks:" << endl;
    for (int i = 0; i < STUDENTS; i++)
    {
        double avg = total[i] / (double)SUBJECTS;
        cout << "S" << (i + 1) << " -> Total: " << total[i]
             << ", Average: " << avg << endl;
    }

    // Highest marks in each subject
    cout << "\nHighest Marks in Each Subject:" << endl;
    for (int j = 0; j < SUBJECTS; j++)
    {
        int highest = marks[0][j];
        for (int i = 1; i < STUDENTS; i++)
            if (marks[i][j] > highest)
                highest = marks[i][j];
        cout << subjectNames[j] << ": " << highest << endl;
    }

    // Student with highest total marks
    int topStudent = 0;
    for (int i = 1; i < STUDENTS; i++)
        if (total[i] > total[topStudent])
            topStudent = i;

    cout << "\nStudent with Highest Total Marks: S" << (topStudent + 1)
         << " (" << total[topStudent] << ")" << endl;

    return 0;
}
