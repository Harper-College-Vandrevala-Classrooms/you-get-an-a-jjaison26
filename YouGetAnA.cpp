#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

class GradeBook {
        private:
                struct assignment{
                        string name;
                        int totalPoints;
                };
                struct grade{
                        string name;
                        int score;
                };
                struct student{
                        string fName;
                        string lName;
                        string ID;
                        vector<grade> grades;
                };
                vector<student> students;
                vector<assignment> assignments;


        public:
                void addAssignment(string name, int maxPoints) {
                        assignment newAssignment = {name, maxPoints};
                        assignments.push_back(newAssignment);
                }

                void addStudent(string name, string id) {
                        istringstream iss(name);
                        string fName, lName;
                        iss >> fName >> lName;
                        student newStudent = {fName, lName, id};
                        students.push_back(newStudent);

                }

                void enterGrade(string name, string assignmentName, int points) {
                        string firstName, lastName;
                        istringstream isS(name);
                        isS >> firstName >> lastName;
                        bool flag = false;
                        bool studentFound = false;
                        bool assignmentFound = false;
                        for(int i = 0; i < students.size(); i++) {
                                if(students[i].fName == firstName && students[i].lName == lastName) {
                                        studentFound = true;
                                        for(int j = 0; j < assignments.size(); j++) {
                                                if(assignments[j].name == assignmentName) {
                                                        assignmentFound = true;
                                                        for(int k = 0; k < students[i].grades.size(); k++) {
                                                                if(students[i].grades[k].name == assignmentName) {
                                                                        students[i].grades[k].score = points;
                                                                        flag = true;
                                                                }

                                                        }
                                                }
                                                students[i].grades.push_back({assignmentName, points});
                                        }
                                        if(assignmentFound == false) {
                                                cout << "Assignment not found" << endl;
                                        }
                                }
                        }
                        if(studentFound == false) {
                                cout << "Student not found" << endl;
                        }

                }


                void report() {
                        cout << "First Name | Last Name | Student ID | ";
                        for(int i = 0; i < assignments.size(); i++) {
                                cout << assignments[i].name << " | ";
                        }
                        cout << endl;

                        for(int i = 0; i < students.size(); i++) {
                                cout << students[i].fName << " | ";
                                cout << students[i].lName << " | ";
                                cout << students[i].ID << " | ";
                                for(int j = 0; j < assignments.size(); j++) {
                                        for(int k = 0; k < students[i].grades.size(); k++) {
                                                if(students[i].grades[k].name == assignments[j].name) {
                                                        cout << students[i].grades[k].score << " | ";
							break;
                                                }
                                        }
                                }
                                cout << endl;
                        }
                }


};

int main() {
        GradeBook gradebook;
        gradebook.addStudent("Bob Bobberson", "ABC123");
        gradebook.addStudent("Sam Sammerson", "DEF456");
        gradebook.addStudent("Jess Jesserson", "GHI789");

        gradebook.addAssignment("Quiz 1", 100);
        gradebook.addAssignment("Lab 1", 50);

        gradebook.enterGrade("Sam Sammerson", "Quiz 1", 95);
        gradebook.enterGrade("Bob Bobberson", "Quiz 1", 85);
        gradebook.enterGrade("Jess Jesserson", "Lab 1", 49);
        gradebook.enterGrade("Jess Jesserson", "Quiz 1", 93);
        gradebook.enterGrade("Bob Bobberson", "Lab 1", 0);

        gradebook.report();

	
        string name, assignment, ID;
        int total_score, score;
        string tScore, iScore;
        string input1, input2, input3;
        GradeBook grades;
        do {
                cout << "Enter the name of the student: " << endl;
                getline(cin, name);
                cout << "Enter the ID of the student: " << endl;
                getline(cin, ID);
                grades.addStudent(name, ID);
                cout << "Would you like to input another student?" << endl;
                getline(cin, input1);
        }while(input1 == "Yes" || input1 == "Y" || input1 == "y" || input1 == "yes");


        do{
                cout << "Enter the name of the assignment: " << endl;
                getline(cin, assignment);
                do {
                cout << "Enter the total points available for the assignment: " << endl;
                getline(cin, tScore);
                if(!isdigit(tScore[0])) {
                        cout << "That is not a valid score!" << endl;
                }
                }while(!isdigit(tScore[0]));
                total_score = stoi(tScore);
                grades.addAssignment(assignment, total_score);

                cout << "Would you like to input another assignment?" << endl;
                getline(cin, input2);

        }while(input2 == "Yes" || input2 == "Y" || input2 == "y" || input2 == "yes");

        do{
                cout << "Now, we will be assigning grades to students. Enter the name of the student: " << endl;
                getline(cin, name);
                cout << "Enter the name of the assignment: " << endl;
                getline(cin, assignment);
                do{
                cout << "Enter the score the student received on this assignment: " << endl;
                getline(cin, iScore);
                if(!isdigit(iScore[0])) {
                        cout << "That is not a valid score!" << endl;
                }
                }while(!isdigit(iScore[0]));
                score = stoi(iScore);
                grades.enterGrade(name, assignment, score);
                cout << "Would you like to enter another grade?" << endl;
                getline(cin, input3);


        }while(input3 == "Yes" || input3 == "Y" || input3 == "y" || input3 == "yes");
        cout << "Here is the gradebook report: " << endl;
        grades.report();

        return 0;
        }
