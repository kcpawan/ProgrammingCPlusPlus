#include<iostream>
#include<iomanip>
using namespace std;

class Student
{
private:
    int roll;
    string name;

    int noOfSubjects;

    string subject[10];
    int fullMarks[10];
    int passMarks[10];
    int obtainedMarks[10];

    int totalObtained;
    int totalFull;

    char grade;

    static int studentCount;

public:

    Student()
    {
        totalObtained = 0;
        totalFull = 0;

        studentCount++;
    }

    void getData()
    {
        cout << "\nEnter Roll Number: ";
        cin >> roll;

        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Number of Subjects: ";
        cin >> noOfSubjects;

        for(int i=0;i<noOfSubjects;i++)
        {
            cout << "\nSubject " << i+1 << " Name: ";
            cin >> subject[i];

            cout << "Full Marks: ";
            cin >> fullMarks[i];

            cout << "Pass Marks: ";
            cin >> passMarks[i];

            cout << "Obtained Marks: ";
            cin >> obtainedMarks[i];

            totalObtained += obtainedMarks[i];
            totalFull += fullMarks[i];
        }

        this->calculateGrade();
    }

    void calculateGrade()
    {
        float percentage;

        percentage =
            ((float)totalObtained / totalFull) * 100;

        if(percentage >= 80)
            grade = 'A';
        else if(percentage >= 60)
            grade = 'B';
        else if(percentage >= 50)
            grade = 'C';
        else if(percentage >= 40)
            grade = 'D';
        else
            grade = 'F';
    }

    void displayReport()
    {
        cout << "\n===================================";
        cout << "\nSTUDENT REPORT";
        cout << "\n===================================";

        cout << "\nRoll No : " << roll;
        cout << "\nName    : " << name;

        cout << "\n\nSubject Details";

        cout << "\n-----------------------------------";

        for(int i=0;i<noOfSubjects;i++)
        {
            cout << "\n"
                 << subject[i]
                 << "  FM:"
                 << fullMarks[i]
                 << "  PM:"
                 << passMarks[i]
                 << "  OM:"
                 << obtainedMarks[i];
        }

        float percentage =
        ((float)totalObtained / totalFull) * 100;

        cout << "\n-----------------------------------";

        cout << "\nTotal Obtained : "
             << totalObtained;

        cout << "\nTotal Full Marks : "
             << totalFull;

        cout << "\nPercentage : "
             << fixed
             << setprecision(2)
             << percentage
             << "%";

        cout << "\nGrade : "
             << grade;

        cout << "\n===================================\n";
    }

    static void showStudentCount()
    {
        cout << "\nTotal Students = "
             << studentCount
             << endl;
    }
};

int Student::studentCount = 0;

int main()
{
    int n;

    cout << "Enter Number of Students: ";
    cin >> n;

    Student s[100];

    for(int i=0;i<n;i++)
    {
        cout << "\n\nEnter Details of Student "
             << i+1
             << endl;

        s[i].getData();
    }

    cout << "\n\n******** REPORTS ********\n";

    for(int i=0;i<n;i++)
    {
        s[i].displayReport();
    }

    Student::showStudentCount();

    return 0;
}