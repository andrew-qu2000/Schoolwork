//
//  Student.cpp
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
}
