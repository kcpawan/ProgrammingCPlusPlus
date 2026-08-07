// StudentManagementSystem.cpp
// Complete Student Management System demonstrating:
// - Inheritance, Template, Polymorphism, STL, Namespace, Exception Handling, File Handling

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <iomanip>
#include <numeric>

// Custom namespace for the entire application
namespace StudentSystem {

    // Template class for generic data storage
    template<typename T>
    class DataStorage {
    private:
        std::vector<T> items;
    public:
        void add(const T& item) { items.push_back(item); }
        void remove(const T& item) {
            auto it = std::find(items.begin(), items.end(), item);
            if (it != items.end()) items.erase(it);
        }
        const std::vector<T>& getItems() const { return items; }
        size_t size() const { return items.size(); }
        bool empty() const { return items.empty(); }
        
        // Template method for searching
        template<typename Predicate>
        std::vector<T> find(Predicate pred) const {
            std::vector<T> result;
            for (const auto& item : items) {
                if (pred(item)) result.push_back(item);
            }
            return result;
        }
    };

    // Base class - Person
    class Person {
    protected:
        std::string name;
        int id;
        std::string email;
        
    public:
        Person() : name(""), id(0), email("") {}
        Person(const std::string& name, int id, const std::string& email): name(name), id(id), email(email) {}
        
        virtual ~Person() = default;
        
        // Virtual functions for polymorphism
        virtual void displayInfo() const {
            std::cout << "Name: " << name << "\nID: " << id << "\nEmail: " << email << std::endl;
        }
        
        virtual std::string serialize() const {
            return name + "|" + std::to_string(id) + "|" + email;
        }
        
        virtual void deserialize(const std::string& data) {
            std::stringstream ss(data);
            std::getline(ss, name, '|');
            std::string idStr;
            std::getline(ss, idStr, '|');
            id = std::stoi(idStr);
            std::getline(ss, email, '|');
        }
        
        // Getters
        std::string getName() const { return name; }
        int getId() const { return id; }
        std::string getEmail() const { return email; }
    };

    // Derived class - Student (Inheritance)
    class Student : public Person {
    private:
        std::vector<std::pair<std::string, int>> courses; // course code, credits
        std::map<std::string, double> grades; // course code -> grade
        double gpa;
        
    public:
        Student() : Person(), gpa(0.0) {}
        Student(const std::string& name, int id, const std::string& email) 
            : Person(name, id, email), gpa(0.0) {}
        
        void addCourse(const std::string& courseCode, int credits) {
            courses.push_back({courseCode, credits});
            grades[courseCode] = 0.0;
        }
        
        void setGrade(const std::string& courseCode, double grade) {
            auto it = grades.find(courseCode);
            if (it != grades.end()) {
                it->second = grade;
                calculateGPA();
            } else {
                throw std::runtime_error("Course not found: " + courseCode);
            }
        }
        
        void calculateGPA() {
            if (courses.empty()) {
                gpa = 0.0;
                return;
            }
            
            double totalPoints = 0.0;
            int totalCredits = 0;
            
            for (const auto& course : courses) {
                double grade = grades[course.first];
                totalPoints += grade * course.second;
                totalCredits += course.second;
            }
            
            gpa = (totalCredits > 0) ? totalPoints / totalCredits : 0.0;
        }
        
        double getGPA() const { return gpa; }
        const std::map<std::string, double>& getGrades() const { return grades; }
        const std::vector<std::pair<std::string, int>>& getCourses() const { return courses; }
        
        // Override virtual functions (Polymorphism)
        void displayInfo() const override {
            Person::displayInfo();
            std::cout << "GPA: " << std::fixed << std::setprecision(2) << gpa << std::endl;
            std::cout << "Courses and Grades:" << std::endl;
            for (const auto& course : courses) {
                auto gradeIt = grades.find(course.first);
                double grade = (gradeIt != grades.end()) ? gradeIt->second : 0.0;
                std::cout << "  " << course.first << " (Credits: " << course.second 
                         << ") Grade: " << grade << std::endl;
            }
        }
        
        std::string serialize() const override {
            std::stringstream ss;
            ss << Person::serialize() << "|" << gpa << "|";
            
            // Serialize courses
            ss << courses.size() << "|";
            for (const auto& course : courses) {
                ss << course.first << "|" << course.second << "|";
                auto gradeIt = grades.find(course.first);
                ss << ((gradeIt != grades.end()) ? gradeIt->second : 0.0) << "|";
            }
            
            return ss.str();
        }
        
        void deserialize(const std::string& data) override {
            std::stringstream ss(data);
            std::string name, email, idStr, gpaStr;
            
            std::getline(ss, name, '|');
            std::getline(ss, idStr, '|');
            std::getline(ss, email, '|');
            std::getline(ss, gpaStr, '|');
            
            this->name = name;
            this->id = std::stoi(idStr);
            this->email = email;
            this->gpa = std::stod(gpaStr);
            
            std::string courseCountStr;
            std::getline(ss, courseCountStr, '|');
            int courseCount = std::stoi(courseCountStr);
            
            courses.clear();
            grades.clear();
            
            for (int i = 0; i < courseCount; ++i) {
                std::string courseCode, creditsStr, gradeStr;
                std::getline(ss, courseCode, '|');
                std::getline(ss, creditsStr, '|');
                std::getline(ss, gradeStr, '|');
                
                int credits = std::stoi(creditsStr);
                double grade = std::stod(gradeStr);
                
                courses.push_back({courseCode, credits});
                grades[courseCode] = grade;
            }
        }
    };

    // Exam class
    class Exam {
    private:
        std::string courseCode;
        std::string date;
        double maxMarks;
        std::map<int, double> studentMarks; // studentId -> marks
        
    public:
        Exam() : courseCode(""), date(""), maxMarks(100.0) {}
        Exam(const std::string& courseCode, const std::string& date, double maxMarks) 
            : courseCode(courseCode), date(date), maxMarks(maxMarks) {}
        
        void addStudentMark(int studentId, double marks) {
            if (marks < 0 || marks > maxMarks) {
                throw std::out_of_range("Marks must be between 0 and " + std::to_string(maxMarks));
            }
            studentMarks[studentId] = marks;
        }
        
        double getStudentMark(int studentId) const {
            auto it = studentMarks.find(studentId);
            if (it != studentMarks.end()) {
                return it->second;
            }
            throw std::runtime_error("Student not found in exam");
        }
        
        const std::map<int, double>& getAllMarks() const { return studentMarks; }
        std::string getCourseCode() const { return courseCode; }
        double getMaxMarks() const { return maxMarks; }
        
        void displayExamResults() const {
            std::cout << "Exam Results for " << courseCode << " (Date: " << date << ")" << std::endl;
            std::cout << "Max Marks: " << maxMarks << std::endl;
            for (const auto& mark : studentMarks) {
                std::cout << "Student ID: " << mark.first << " Marks: " << mark.second << std::endl;
            }
        }
    };

    // Custom exception class (Exception Handling)
    class StudentNotFoundException : public std::runtime_error {
    public:
        explicit StudentNotFoundException(const std::string& message) 
            : std::runtime_error(message) {}
    };

    class DuplicateStudentException : public std::runtime_error {
    public:
        explicit DuplicateStudentException(const std::string& message) 
            : std::runtime_error(message) {}
    };

    // Main System class using STL containers
    class StudentManagementSystem {
    private:
        DataStorage<Student> students;
        std::vector<Exam> exams;
        std::map<int, std::vector<int>> studentExamResults; // studentId -> exam indices
        std::string dataFile;
        
    public:
        StudentManagementSystem(const std::string& filename = "student_data.txt") 
            : dataFile(filename) {
            loadFromFile();
        }
        
        ~StudentManagementSystem() {
            saveToFile();
        }
        
        // Add student with exception handling
        void addStudent(const std::string& name, int id, const std::string& email) {
            try {
                // Check for duplicate
                auto existing = students.find([id](const Student& s) { return s.getId() == id; });
                if (!existing.empty()) {
                    throw DuplicateStudentException("Student with ID " + std::to_string(id) + " already exists");
                }
                
                Student newStudent(name, id, email);
                students.add(newStudent);
                std::cout << "Student added successfully!" << std::endl;
                saveToFile();
            } catch (const DuplicateStudentException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                throw;
            } catch (const std::exception& e) {
                std::cerr << "Error adding student: " << e.what() << std::endl;
                throw;
            }
        }
        
        void addCourseToStudent(int studentId, const std::string& courseCode, int credits) {
            try {
                auto studentsList = students.find([studentId](const Student& s) { 
                    return s.getId() == studentId; 
                });
                
                if (studentsList.empty()) {
                    throw StudentNotFoundException("Student with ID " + std::to_string(studentId) + " not found");
                }
                
                // We need to modify the student, so we'll get it and update
                Student modifiedStudent = studentsList[0];
                modifiedStudent.addCourse(courseCode, credits);
                
                // Remove old and add modified
                students.remove(studentsList[0]);
                students.add(modifiedStudent);
                
                std::cout << "Course added successfully!" << std::endl;
                saveToFile();
            } catch (const StudentNotFoundException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                throw;
            }
        }
        
        void setStudentGrade(int studentId, const std::string& courseCode, double grade) {
            try {
                auto studentsList = students.find([studentId](const Student& s) { 
                    return s.getId() == studentId; 
                });
                
                if (studentsList.empty()) {
                    throw StudentNotFoundException("Student with ID " + std::to_string(studentId) + " not found");
                }
                
                Student modifiedStudent = studentsList[0];
                modifiedStudent.setGrade(courseCode, grade);
                
                students.remove(studentsList[0]);
                students.add(modifiedStudent);
                
                std::cout << "Grade set successfully!" << std::endl;
                saveToFile();
            } catch (const std::exception& e) {
                std::cerr << "Error setting grade: " << e.what() << std::endl;
                throw;
            }
        }
        
        void addExam(const std::string& courseCode, const std::string& date, double maxMarks) {
            exams.emplace_back(courseCode, date, maxMarks);
            std::cout << "Exam added successfully!" << std::endl;
            saveToFile();
        }
        
        void addStudentToExam(int studentId, int examIndex, double marks) {
            try {
                if (examIndex < 0 || examIndex >= exams.size()) {
                    throw std::out_of_range("Invalid exam index");
                }
                
                exams[examIndex].addStudentMark(studentId, marks);
                studentExamResults[studentId].push_back(examIndex);
                std::cout << "Student marks added to exam!" << std::endl;
                saveToFile();
            } catch (const std::exception& e) {
                std::cerr << "Error adding student to exam: " << e.what() << std::endl;
                throw;
            }
        }
        
        // Display all students (Polymorphism in action)
        void displayAllStudents() const {
            std::cout << "\n=== ALL STUDENTS ===" << std::endl;
            if (students.empty()) {
                std::cout << "No students in the system." << std::endl;
                return;
            }
            
            for (const auto& student : students.getItems()) {
                student.displayInfo();
                std::cout << "------------------------" << std::endl;
            }
        }
        
        // Student ranking based on GPA (STL algorithms)
        void displayStudentRanking() const {
            std::cout << "\n=== STUDENT RANKING (by GPA) ===" << std::endl;
            
            if (students.empty()) {
                std::cout << "No students to rank." << std::endl;
                return;
            }
            
            std::vector<Student> sortedStudents = students.getItems();
            
            // STL sort with custom comparator
            std::sort(sortedStudents.begin(), sortedStudents.end(),
                     [](const Student& a, const Student& b) {
                         return a.getGPA() > b.getGPA();
                     });
            
            int rank = 1;
            for (const auto& student : sortedStudents) {
                std::cout << rank++ << ". " << student.getName() 
                         << " (ID: " << student.getId() << ") - GPA: " 
                         << std::fixed << std::setprecision(2) << student.getGPA() << std::endl;
            }
        }
        
        // Display exam details
        void displayAllExams() const {
            std::cout << "\n=== ALL EXAMS ===" << std::endl;
            if (exams.empty()) {
                std::cout << "No exams in the system." << std::endl;
                return;
            }
            
            for (size_t i = 0; i < exams.size(); ++i) {
                std::cout << "Exam " << i << ": " << std::endl;
                exams[i].displayExamResults();
                std::cout << "------------------------" << std::endl;
            }
        }
        
        // Search student by name (STL algorithms)
        void searchStudentByName(const std::string& name) const {
            std::cout << "\n=== SEARCH RESULTS ===" << std::endl;
            
            auto results = students.find([&name](const Student& s) {
                return s.getName().find(name) != std::string::npos;
            });
            
            if (results.empty()) {
                std::cout << "No students found with name containing: " << name << std::endl;
                return;
            }
            
            for (const auto& student : results) {
                student.displayInfo();
                std::cout << "------------------------" << std::endl;
            }
        }
        
        // Get student by ID
        Student getStudent(int id) const {
            auto results = students.find([id](const Student& s) {
                return s.getId() == id;
            });
            
            if (results.empty()) {
                throw StudentNotFoundException("Student with ID " + std::to_string(id) + " not found");
            }
            
            return results[0];
        }
        
        // File handling - Save data
        void saveToFile() {
            try {
                std::ofstream outFile(dataFile);
                if (!outFile.is_open()) {
                    throw std::runtime_error("Cannot open file for writing: " + dataFile);
                }
                
                // Save students
                outFile << students.size() << std::endl;
                for (const auto& student : students.getItems()) {
                    outFile << student.serialize() << std::endl;
                }
                
                // Save exams
                outFile << exams.size() << std::endl;
                for (const auto& exam : exams) {
                    outFile << exam.getCourseCode() << "|" 
                           << "2024-01-01" << "|" // Placeholder date
                           << exam.getMaxMarks() << "|";
                    
                    const auto& marks = exam.getAllMarks();
                    outFile << marks.size() << "|";
                    for (const auto& mark : marks) {
                        outFile << mark.first << "|" << mark.second << "|";
                    }
                    outFile << std::endl;
                }
                
                outFile.close();
                std::cout << "Data saved to " << dataFile << std::endl;
                
            } catch (const std::exception& e) {
                std::cerr << "Error saving data: " << e.what() << std::endl;
                throw;
            }
        }
        
        // File handling - Load data
        void loadFromFile() {
            try {
                std::ifstream inFile(dataFile);
                if (!inFile.is_open()) {
                    std::cout << "No existing data file found. Starting fresh." << std::endl;
                    return;
                }
                
                // Clear existing data
                students = DataStorage<Student>();
                exams.clear();
                studentExamResults.clear();
                
                // Load students
                size_t studentCount;
                inFile >> studentCount;
                inFile.ignore(); // consume newline
                
                for (size_t i = 0; i < studentCount; ++i) {
                    std::string line;
                    std::getline(inFile, line);
                    if (!line.empty()) {
                        Student student;
                        student.deserialize(line);
                        students.add(student);
                    }
                }
                
                // Load exams
                size_t examCount;
                inFile >> examCount;
                inFile.ignore(); // consume newline
                
                for (size_t i = 0; i < examCount; ++i) {
                    std::string line;
                    std::getline(inFile, line);
                    if (!line.empty()) {
                        // Parse exam data
                        std::stringstream ss(line);
                        std::string courseCode, date, maxMarksStr;
                        std::getline(ss, courseCode, '|');
                        std::getline(ss, date, '|');
                        std::getline(ss, maxMarksStr, '|');
                        
                        double maxMarks = std::stod(maxMarksStr);
                        Exam exam(courseCode, date, maxMarks);
                        
                        std::string markCountStr;
                        std::getline(ss, markCountStr, '|');
                        int markCount = std::stoi(markCountStr);
                        
                        for (int j = 0; j < markCount; ++j) {
                            std::string studentIdStr, marksStr;
                            std::getline(ss, studentIdStr, '|');
                            std::getline(ss, marksStr, '|');
                            
                            int studentId = std::stoi(studentIdStr);
                            double marks = std::stod(marksStr);
                            exam.addStudentMark(studentId, marks);
                            studentExamResults[studentId].push_back(exams.size());
                        }
                        
                        exams.push_back(exam);
                    }
                }
                
                inFile.close();
                std::cout << "Data loaded from " << dataFile << std::endl;
                
            } catch (const std::exception& e) {
                std::cerr << "Error loading data: " << e.what() << std::endl;
                std::cout << "Starting with empty system." << std::endl;
                students = DataStorage<Student>();
                exams.clear();
                studentExamResults.clear();
            }
        }
    };

} // namespace StudentSystem

// Main application
int main() {
    using namespace StudentSystem;
    
    std::cout << "=== STUDENT MANAGEMENT SYSTEM ===" << std::endl;
    std::cout << "Developed with C++ using Inheritance, Templates, Polymorphism," << std::endl;
    std::cout << "STL, Namespaces, Exception Handling, and File Handling" << std::endl;
    std::cout << "=====================================" << std::endl << std::endl;
    
    StudentManagementSystem system("student_data.txt");
    
    int choice = 0;
    do {
        std::cout << "\n===== MENU =====" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Add Course to Student" << std::endl;
        std::cout << "3. Set Student Grade" << std::endl;
        std::cout << "4. Add Exam" << std::endl;
        std::cout << "5. Add Student to Exam" << std::endl;
        std::cout << "6. Display All Students" << std::endl;
        std::cout << "7. Display Student Ranking" << std::endl;
        std::cout << "8. Display All Exams" << std::endl;
        std::cout << "9. Search Student by Name" << std::endl;
        std::cout << "10. Save and Exit" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;
        
        try {
            switch (choice) {
                case 1: {
                    std::string name, email;
                    int id;
                    std::cout << "Enter student name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    std::cout << "Enter student ID: ";
                    std::cin >> id;
                    std::cout << "Enter student email: ";
                    std::cin >> email;
                    system.addStudent(name, id, email);
                    break;
                }
                case 2: {
                    int id;
                    std::string courseCode;
                    int credits;
                    std::cout << "Enter student ID: ";
                    std::cin >> id;
                    std::cout << "Enter course code: ";
                    std::cin >> courseCode;
                    std::cout << "Enter credits: ";
                    std::cin >> credits;
                    system.addCourseToStudent(id, courseCode, credits);
                    break;
                }
                case 3: {
                    int id;
                    std::string courseCode;
                    double grade;
                    std::cout << "Enter student ID: ";
                    std::cin >> id;
                    std::cout << "Enter course code: ";
                    std::cin >> courseCode;
                    std::cout << "Enter grade (0-100): ";
                    std::cin >> grade;
                    system.setStudentGrade(id, courseCode, grade);
                    break;
                }
                case 4: {
                    std::string courseCode, date;
                    double maxMarks;
                    std::cout << "Enter course code: ";
                    std::cin >> courseCode;
                    std::cout << "Enter exam date (YYYY-MM-DD): ";
                    std::cin >> date;
                    std::cout << "Enter maximum marks: ";
                    std::cin >> maxMarks;
                    system.addExam(courseCode, date, maxMarks);
                    break;
                }
                case 5: {
                    int studentId, examIndex;
                    double marks;
                    std::cout << "Enter student ID: ";
                    std::cin >> studentId;
                    std::cout << "Enter exam index: ";
                    std::cin >> examIndex;
                    std::cout << "Enter marks: ";
                    std::cin >> marks;
                    system.addStudentToExam(studentId, examIndex, marks);
                    break;
                }
                case 6:
                    system.displayAllStudents();
                    break;
                case 7:
                    system.displayStudentRanking();
                    break;
                case 8:
                    system.displayAllExams();
                    break;
                case 9: {
                    std::string name;
                    std::cout << "Enter name to search: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    system.searchStudentByName(name);
                    break;
                }
                case 10:
                    std::cout << "Saving data and exiting..." << std::endl;
                    system.saveToFile();
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Operation failed: " << e.what() << std::endl;
        }
        
    } while (choice != 10);
    
    std::cout << "\nThank you for using the Student Management System!" << std::endl;
    return 0;
}