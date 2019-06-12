//
//  Registrar.h
//  rec07
//
//  Created by Andrew Qu on 3/15/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#ifndef Registrar_h
#define Registrar_h
#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly {

class Course;
class Student;
class Registrar {
    friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);
public:
    Registrar();
    bool addCourse(const std::string&);
    bool addStudent(const std::string&);
    bool enrollStudentInCourse(const std::string& studentName,
                               const std::string& courseName);
    bool cancelCourse(const std::string& courseName);
    void purge();
    
private:
    size_t findStudent(const std::string&) const;
    size_t findCourse(const std::string&) const;
    
    std::vector<Course*> courses;
    std::vector<Student*> students;
};
    
}//namespace Brooklyn Poly
#endif /* Registrar_h */
