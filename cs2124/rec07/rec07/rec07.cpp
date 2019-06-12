/*
  rec07 - Registrar for students and courses
  Andrew Qu w/ John Sterling
 */

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Student.h"
#include "Registrar.h"
using namespace std;
using namespace BrooklynPoly;

/*
class Student;

class Course {
    friend ostream& operator<<(ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
    Course(const string& courseName);
    const string& getName() const;
    bool addStudent(Student*);
    void removeStudentsFromCourse(); 

private:
    string name;
    vector<Student*> students;
};
*/
/*
class Student {
    friend ostream& operator<<(ostream& os, const Student& rhs);
public:
    // Student methods needed by Registrar
    Student(const string& name);
    const string& getName() const;
    bool addCourse(Course*);

    // Student method needed by Course
    void removedFromCourse(Course*);

private:
    string name;
    vector<Course*> courses;
};
*/
/*
class Registrar {
    friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
    Registrar();
    bool addCourse(const string&);
    bool addStudent(const string&);
    bool enrollStudentInCourse(const string& studentName,
                               const string& courseName);
    bool cancelCourse(const string& courseName);
    void purge();

private:
    size_t findStudent(const string&) const;
    size_t findCourse(const string&) const;

    vector<Course*> courses;
    vector<Student*> students;
};
*/
int main() {

    Registrar registrar;

    cout << "No courses or students added yet\n";
    cout << registrar << endl;
     
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout << "Should fail, i.e. do nothing, "
         << "since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;
   
    /*
    // [OPTIONAL - do later if time]
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    cout << registrar << endl;  

    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    cout << registrar << endl;  

    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    cout << registrar << endl;  
    */

    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;
}

//Overloaded << operators
/*
ostream& operator<<(ostream& os, const Course& rhs){
    os << rhs.getName() << ": ";
    if(rhs.students.size() == 0){
        os << "No Students";
    }
    else{
        for(Student* sp : rhs.students){
            os << sp->getName() << " ";
        }
    }
    return os;
}
 */
/*
ostream& operator<<(ostream& os, const Student& rhs){
    os << rhs.getName() << ": ";
    if(rhs.courses.size() == 0){
        os << "No Courses";
    }
    else{
        for(Course* cp : rhs.courses){
            os << cp->getName() << " ";
        }
    }
    return os;
}
 */
/*
ostream& operator<<(ostream& os, const Registrar& rhs){
    os << "Registrar's Report" << endl;
    os << "Courses:" << endl;
    for(Course* cp : rhs.courses){
        os << *cp << endl;
    }
    os << "Students:" << endl;
    for(Student* sp : rhs.students){
        os << *sp << endl;
    }
    return os;
}
 */
/*
// Course methods needed by Registrar----------------------
Course::Course(const string& courseName):name(courseName){}
const string& Course::getName() const{
    return name;
}
bool Course::addStudent(Student* studentP){
    //if student is already registered, do nothing
    for(Student* sp : students){
        if(sp == studentP){
            return false;
        }
    }
    students.push_back(studentP);
    return true;
}
void Course::removeStudentsFromCourse(){
    for(Student* sp : students){
        sp->removedFromCourse(this);
    }
}
*/
/*
// Student methods needed by Registrar---------------------
Student::Student(const string& name):name(name){}
const string& Student::getName() const{
    return name;
}
bool Student::addCourse(Course* courseP){
    //if course is already enrolled in, do nothing
    for(Course* cp : courses){
        if(cp == courseP){
            return false;
        }
    }
    courses.push_back(courseP);
    return true;
}
// Student method needed by Course
void Student::removedFromCourse(Course* courseP){
    for(size_t i = 0;i < courses.size();i ++){
        if(courses[i] == courseP){
            for(size_t j = i;j < courses.size() - 1;j ++){
                courses[j] = courses[j+1];
            }
            courses.pop_back();
        }
    }
}
*/
/*
//Registrar methods-------------------------------------
Registrar::Registrar(){};
bool Registrar::addCourse(const string& courseName){
    //if course already exists, do nothing
    if( findCourse(courseName) < courses.size() ){
        return false;
    }
    courses.push_back( new Course(courseName) );
    return true;
}
bool Registrar::addStudent(const string& studentName){
    //if student already exists, do nothing
    if( findStudent(studentName) < students.size()){
        return false;
    }
    students.push_back( new Student(studentName) );
    return true;
}
bool Registrar::enrollStudentInCourse(const string& studentName,
                           const string& courseName){
    if(findStudent(studentName) >= students.size()
        || findCourse(courseName) >= courses.size()){
        return false; //either course or student DNE
    }
    Student* sp = students[findStudent(studentName)];
    Course* cp = courses[findCourse(courseName)];
    sp->addCourse(cp);
    cp->addStudent(sp);
    return true;
}
bool Registrar::cancelCourse(const string& courseName){
    size_t course_ind = findCourse(courseName);
    //if course DNE, do nothing
    if(course_ind == courses.size()){
        return false;
    }
    courses[course_ind]->removeStudentsFromCourse();
    delete courses[course_ind];
    for(size_t i = course_ind;i < courses.size() - 1;i ++){
        courses[i] = courses[i+1];
    }
    courses.pop_back();
    return true;
}
void Registrar::purge(){
    for(Course*& cp : courses){
        cp->removeStudentsFromCourse();
        delete cp;
        cp = nullptr;
    }
    courses.clear();
    for(Student*& sp : students){
        delete sp;
        sp = nullptr;
    }
    students.clear();
};
//Private registrar methods
size_t Registrar::findStudent(const string& studentName) const{
    for(size_t i = 0;i < students.size();i ++){
        if(students[i]->getName() == studentName){
            return i;
        }
    }
    return students.size() ;
}
size_t Registrar::findCourse(const string& courseName) const{
    for(size_t i = 0;i < courses.size();i ++){
        if(courses[i]->getName() == courseName){
            return i;
        }
    }
    return courses.size() ;
}
*/
