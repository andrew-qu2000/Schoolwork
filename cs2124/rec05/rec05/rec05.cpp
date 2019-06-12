/*
  rec05.cpp
  Model of CS lab record keeping
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Section{
    friend ostream& operator<<(ostream& os, const Section& section);
private:
    //nested class definitions
    class timeSlot{
        friend ostream& operator<<(ostream& os, const timeSlot& time){
            os << "[Day: " << time.weekday << ", Start time: " << time.hour;
            if(time.AM){
                os << "AM" << "]";
            }
            else{
                os << "PM" << "]";
            }
            return os;
        }
    private:
        string weekday;
        unsigned hour;
        bool AM;
    public:
        timeSlot(string newDay, unsigned newHour):
            weekday(newDay),
            hour(newHour % 12),
            AM(newHour < 12)
        {}
    };
    
    class studentRecord{
        friend ostream& operator<<(ostream& os, const studentRecord& record){
            os << "Name: " << record.studentName << "," << " Grades: ";
            for(int grade : record.grades){
                os << grade << " ";
            }
            return os;
        }
    private:
        string studentName;
        vector<int> grades;
    public:
        studentRecord(const string& newStudentName):studentName(newStudentName){
            int labs = 0;
            while(labs < LABS){
                grades.push_back(-1);
                labs += 1;
            }
        }
        
        const string getName() const{
            return studentName;
        }
        
        const vector<int> getGrades() const{
            return grades;
        }
        
        void addGrade(string studentName, int grade, int week){
            grades[week - 1] = grade; //set for zero-index
        }
    };
    //instance variables
    string name;
    timeSlot time;
    vector<studentRecord*> records;
    
public:
    static const int LABS = 14; //number of grade slots in each student record
    Section(const string& secName, const string& weekday, unsigned hour):
        name(secName),
        time( timeSlot(weekday, hour) )
    {}
    //copy constructor
    Section(const Section& section2):name(section2.name),time(section2.time){
        for(size_t i = 0;i < section2.records.size();i++){
            records.push_back(new studentRecord(*section2.records[i]));
        }
    }
    //deconstructor
    ~Section(){
        cout << "Section " << name << " is being deleted" << endl;
        for(studentRecord*& sr : records){
            cout << "Deleting " << sr->getName() << endl;;
            delete sr;
            sr = nullptr;
        }
        records.clear();
    }
    //create studentRecord for new student
    void addStudent(const string& studentName){
        records.push_back(new studentRecord(studentName));
    }
    //find appropriate student record and add a grade
    void addGrade(const string& studentName, int grade, int week){
        for(studentRecord*& sr : records){
            if(sr->getName() == studentName){
                sr->addGrade(studentName, grade, week);
                return;
            }
        }
    }
};

class LabWorker{
    friend ostream& operator<<(ostream& os, const LabWorker& worker){
        os << worker.name;
        if(worker.labSection == nullptr){
            os << " does not have a section";
        }
        else{
            os << " has " << *worker.labSection;
        }
        return os;
    }
private:
    string name;
    Section* labSection = nullptr;
public:
    LabWorker(const string& newName) : name(newName){};
    
    void addSection(Section& newSection){
        labSection = &newSection;
    }
    
    void addGrade(const string& studentName, int grade, int week){
        labSection->addGrade(studentName, grade, week);
    }
};

//overloaded operator<< for Section class
ostream& operator<<(ostream& os, const Section& section){
    //display section number and time
    os << "Section: " << section.name << ", Time slot: "
    << section.time << ", Students: ";
    if(section.records.size() == 0){
        os << "None" << endl;
    }
    else{
        os << section.records.size() << endl;
    }
    //display each student and their grades
    for(size_t i = 0;i < section.records.size();i ++){
        os << *section.records[i] << endl;
    }
    return os;
}

// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {

    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works:\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";

} // main
