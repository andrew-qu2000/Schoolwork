//
//  Course.h
//  rec07
//
//  Created by Andrew Qu on 3/15/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#ifndef Course_h
#define Course_h
#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly {
    
class Student;
class Course {
    friend std::ostream& operator<<(std::ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
    Course(const std::string& courseName);
    const std::string& getName() const;
    bool addStudent(Student*);
    void removeStudentsFromCourse();
    
private:
    std::string name;
    std::vector<Student*> students;
};

}
#endif /* Course_h */
