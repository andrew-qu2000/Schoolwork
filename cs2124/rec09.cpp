//
//  rec09.cpp
//  Inheritance tutorial
//
//  Created by Andrew Qu on 4/5/19.
//

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
    friend ostream& operator<<(ostream& os, const PrintedMaterial& rhs){
        os << rhs.numOfPages;
        return os;
    }
public:
    PrintedMaterial(unsigned pages)
            :numOfPages(pages)
    {}
    virtual void displayNumPages() const = 0;
    //virtual void displayNumPages() const{ cout << numOfPages << endl; }
protected:
private:
    unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const{
    cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned pages)
            :PrintedMaterial(pages)
    {}
    void displayNumPages() const{
        cout << "Magazine pages: ";
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned pages)
            :PrintedMaterial(pages)
    {}
    virtual void displayNumPages() const{
        cout << "Book pages: ";
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned pages, unsigned indexPages)
            :Book(pages),
             numOfIndexPages(indexPages)
    {}
    void displayNumPages() const{
        cout << "Textbook Pages: ";
        PrintedMaterial::displayNumPages();
        cout << "Textbook Index pages: " << numOfIndexPages << endl;
    }
protected:
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned pages)
            :Book(pages)
    {}
protected:
private:
};

void displayNumberOfPages(const PrintedMaterial& pm){
    //(&pm)->displayNumPages();
    pm.displayNumPages();
}
// tester/modeler code
int main()
{
    TextBook t(900,12);
    Novel n(550);
    Magazine m(75);
    cout << "Using displayNumPages()" << endl;
    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();
    /*
    cout << "Copying a textbook to a printedmaterial" << endl;
    PrintedMaterial pm(2048);
    pm.displayNumPages();
    pm = t;
    pm.displayNumPages();
     */
    cout << "Using a PrinterMaterial* to get at textbook display" << endl;
    PrintedMaterial* pmPtr;
    pmPtr = &t;
    pmPtr->displayNumPages();
    
    cout << "Using standalone display function" << endl;
    displayNumberOfPages(t);
    displayNumberOfPages(n);
    displayNumberOfPages(m);
    //displayNumberOfPages(pm);
    cout << "Looping through a vector" << endl;
    vector<PrintedMaterial*> materials;
    materials.push_back(&t);
    materials.push_back(&n);
    materials.push_back(&m);
    for(PrintedMaterial* pmPtr : materials){
        pmPtr->displayNumPages();
    }
}
