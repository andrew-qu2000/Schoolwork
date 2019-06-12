//
//  Student.h
//  rec07
//
//  Created by Andrew Qu on 3/15/19.
//  Copyright © 2019 Andrew Qu. All rights reserved.
//

#ifndef Student_h
#define Student_h
#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly {

class Course;
class Student {
    friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
public:
    // Student methods needed by Registrar
    Student(const std::string& name);
    const std::string& getName() const;
    bool addCourse(Course*);
    
    // Student method needed by Course
    void removedFromCourse(Course*);
    
private:
    std::string name;
    std::vector<Course*> courses;
};

}//namespace BrooklynPoly
#endif /* Student_h */
