//
//  polynomial.h
//  hw08
//  Andrew Qu
//

#ifndef polynomial_h
#define polynomial_h

#include <vector>
#include <iostream>

class LinkedList {
    struct Node {
        Node(int num, Node* nPtr = nullptr) : data(num), next(nPtr) {}
        int data;
        Node* next;
    };
public:
    LinkedList();
    LinkedList(const LinkedList& ll2);
    LinkedList& operator=(const LinkedList& rhs);
    ~LinkedList();
    int front() const;
    int back() const;
    void push_front(int n);
    void push_back(int n);
    int pop_front();
    int pop_back();
    int operator[](size_t ind) const;
private:
    Node* head;
};

class Polynomial {
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);
    friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
public:
    //constructors
    Polynomial();
    Polynomial(const std::vector<int>& coeffVec);
    Polynomial(const Polynomial& polynomial2);
    //operators
    Polynomial& operator=(const Polynomial& rhs);
    Polynomial& operator+=(const Polynomial& rhs);
    //returns value of polynomial for x values
    int evaluate(int x) const;
    
private:
    LinkedList coeffs;
    unsigned degree;
    //remove zeros from right side of LinkedList,
    //until highest degree has nonzero coefficient
    void removeLeadingZeros();
};
//non member functions
bool operator!=(const Polynomial& lhs, const Polynomial& rhs);
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
#endif /* polynomial_h */
