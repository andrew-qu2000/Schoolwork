//
//  Course.cpp
//  rec07
//
//  Created by Andrew Qu on 3/15/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace BrooklynPoly {
    
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
    
}
