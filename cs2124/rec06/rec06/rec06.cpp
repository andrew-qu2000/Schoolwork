/*
  Recitation 06
  CS2124
  Andrew Qu and John Sterling
  Focus: Dynamic arrays and copy control
 */

#include <string>
#include <iostream>
using namespace std;

const int INIT_CAP = 8;
class Position {
    friend ostream& operator<<(ostream& os, const Position& rhs) {
        os << '[' << rhs.title << ',' << rhs.salary << ']';
        return os;
    }
public:
    Position(const string& aTitle, double aSalary)
        : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
private:
    string title;
    double salary;
}; // class Position

class Entry {
    friend ostream& operator<<(ostream& os, const Entry& rhs) {
        os << rhs.name << ' ' << rhs.room
           << ' ' << rhs.phone << ", " << *rhs.pos;
        return os;
    }
public:
    Entry(const string& name, unsigned room, unsigned phone, Position& position)
        : name(name), room(room), phone(phone), pos(&position) {
    }
    const string& getName() const { return name; }
    unsigned getPhone() const { return phone; }
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory {
    friend ostream& operator<<(ostream& os, const Directory& d){
        os << "Directory: " << endl;
        for(size_t i = 0;i < d.size;i++){
            cout << "   " << *d.entries[i] << endl;
        }
        return os;
    }
public:
    Directory():size(0),capacity(INIT_CAP),entries(new Entry*[INIT_CAP]){}
    
    Directory(const Directory& d2){
        cout << "Entering copy constructor..." << endl;
        copyHelper(d2);
    }//copy constructor
    
    ~Directory(){
        cout << "Destructing..." << endl;
        for(size_t i = 0;i < size;i++){
            delete entries[i];
            entries[i] = nullptr;
        }
        delete [] entries;
    }//destructor
    
    Directory& operator=(const Directory& d2){
        cout << "Entering assignment operator..." << endl;
        //if this and &d2 point to the same thing, copy is unnecessary
        if(this != &d2){
            for(size_t i = 0;i < size;i++){
                delete entries[i];
                entries[i] = nullptr;
            }
            delete [] entries; //release old array
            copyHelper(d2);
        }
        return *this;
    }//assignment operator
    
    //returns phone number of entry with given name
    unsigned operator[](const string& name){
        for(size_t i = 0;i < size;i++){
            if(entries[i]->getName() == name){
                return entries[i]->getPhone();
            }
        }
        //throw invalid_argument("Entry not found");
        cerr << "Entry not found ";
        return 99999999;
    }//index operator
    
    //add an entry
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (size == capacity)    { //resize
            Entry** old_entries = entries;
            entries = new Entry*[capacity * 2]; //double capacity
            for(size_t i = 0;i < size;i++){
                entries[i] = old_entries[i]; //copy old pointers
            }
            capacity *= 2;
            delete [] old_entries; //release old array
        } // if
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } // add
private:	
    Entry** entries;
    size_t size;
    size_t capacity;
    //helper called by copy constructor and operator=
    void copyHelper(const Directory& d2){
        size = d2.size;
        capacity = d2.capacity;
        entries = new Entry*[capacity];
        for(size_t i = 0;i < size;i++){
            entries[i] = new Entry(*d2.entries[i]);
        }
    } // copyHelper
}; // class Directory

void doNothing(Directory dir) { cout << dir << endl; }

int main() {
	
    // Note that the Postion objects are NOT on the heap.
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
	
    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;

    Directory d2 = d;	// Uses copy constructor, d2 did not exist before
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << d << endl; //d is not changed through d2
    
    d.add("Candace", 555, 2227, pointyHair);
    cout << d2 << endl; //d2 is not changed through d
    cout << d << endl;
    /*
    cout << "Calling doNothing\n";
    doNothing(d2);   //Uses copy constructor, doNothing doesn't pass by ref.
    cout << "Back from doNothing\n";
    */
    Directory d3;
    d3.add("Randall", 404, 5585, boss);
    d3.add("Sherbet", 339, 1248, boss);
    d3 = d2;   //Uses assignment operator, d3 was already initialized
    d3 = d2;   //Stress test cause why not
    d3.add("Monroe", 212, 4448, pointyHair);
    cout << d3 << endl; //d3's old entries are gone after d3 = d2
    cout << d2 << endl; //d2 is not changed through d3
    
    cout << d3["Monroe"] << endl;    //Should display 4448
    cout << d3["Carmack"] << endl;   //Should display 1592
    cout << d2["Carmack"] << endl;   //Should display 1592
    cout << d2["Monroe"] << endl;    //Should lead to an error
	
} // main
