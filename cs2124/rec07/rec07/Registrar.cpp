//
//  Registrar.cpp
//  rec07
//
//  Created by Andrew Qu on 3/15/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include "Course.h"
#include "Student.h"
#include "Registrar.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace BrooklynPoly {
    
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
    
}
