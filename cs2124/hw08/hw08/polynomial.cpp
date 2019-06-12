//
//  polynomial.cpp
//  hw08
//  Andrew Qu
//

#include "polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;

//==========LinkedList==========

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(const LinkedList& ll2) : head(nullptr) {
    Node* cursor = ll2.head;
    while (cursor) {
        push_back(cursor->data);
        cursor = cursor->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList &rhs) {
    while (head) pop_back();
    Node* cursor = rhs.head;
    while (cursor) {
        push_back(cursor->data);
        cursor = cursor->next;
    }
    return *this;
}

LinkedList::~LinkedList() {
    while (head) pop_back();
}

int LinkedList::front() const { return head->data; }

int LinkedList::back() const {
    Node* cursor = head;
    while(cursor->next) cursor = cursor->next;
    return cursor->data;
}

void LinkedList::push_front(int n) { head = new Node(n, head); }

void LinkedList::push_back(int n) {
    if(!head) head = new Node(n);
    else {
        Node* cursor = head;
        while(cursor->next) cursor = cursor->next;
        cursor->next = new Node(n);
    }
}

int LinkedList::pop_front() {
    int ret = head->data;
    Node* nextPtr = head->next;
    delete head;
    head = nextPtr;
    return ret;
}

int LinkedList::pop_back() {
    if (!head->next) return pop_front();
    else {
        Node* cursor = head;
        while(cursor->next->next) cursor = cursor->next;
        int ret = cursor->next->data;
        delete cursor->next;
        cursor->next = nullptr;
        return ret;
    }
}

int LinkedList::operator[](size_t ind) const{
    size_t pos = 0;
    Node* cursor = head;
    while (pos < ind) {
        cursor = cursor->next;
        ++pos;
    }
    return cursor->data;
}

//==========Polynomial==========

//default constructor (zero polynomial)
Polynomial::Polynomial() {
    coeffs.push_back(0);
    degree = 0;
}
//vector constructor
Polynomial::Polynomial(const vector<int>& coeffVec) {
    unsigned curr_degree = coeffVec.size() - 1;
    for (int coeff : coeffVec) {
        coeffs.push_front(coeff);
    }
    degree = curr_degree;
    removeLeadingZeros();
}
//copy constructor
Polynomial::Polynomial(const Polynomial& polynomial2) :
    coeffs(polynomial2.coeffs),
    degree(polynomial2.degree)
{}
//assignment operator
Polynomial& Polynomial::operator=(const Polynomial &rhs) {
    coeffs = rhs.coeffs;
    degree = rhs.degree;
    return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial &rhs) {
    int ind =  max(degree, rhs.degree);
    int coeffSum = 0;
    LinkedList coeffSums;
    while (ind >= 0) {
        if (ind <= degree) coeffSum += coeffs[ind];
        if (ind <= rhs.degree) coeffSum += rhs.coeffs[ind];
        coeffSums.push_front(coeffSum);
        coeffSum = 0;
        ind--;
    }
    coeffs = coeffSums;
    degree = max(degree, rhs.degree);
    removeLeadingZeros();
    return *this;
}

int Polynomial::evaluate(int x) const {
    int ret = 0;
    size_t ind = 0;
    while (ind <= degree) {
        ret += coeffs[ind] * pow(x,ind);
        ind++;
    }
    return ret;
}

void Polynomial::removeLeadingZeros() {
    while (coeffs.back() == 0) {
        coeffs.pop_back();
        degree--;
    }
}
//friends
ostream& operator<<(ostream& os, const Polynomial& rhs) {
    int ind = rhs.degree;
    int coeff;
    while (ind >= 0) {
        coeff = rhs.coeffs[ind];
        if ( coeff > 0 && ind != rhs.degree ) os << " + ";
        else if (coeff < 0 && ind != rhs.degree ) os << " ";
        if ( ind == 0 || (coeff != 0 && coeff != 1) ) os << coeff;
        if ( coeff != 0 && ind > 0) os << "x";
        if ( coeff != 0 && ind > 1) os << "^" << ind;
        ind--;
    }
    return os;
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
    if (lhs.degree != rhs.degree) return false;
    for (size_t ind = 0;ind <= lhs.degree;++ind) {
        if (lhs.coeffs[ind] != rhs.coeffs[ind]) return false;
    }
    return true;
}
//non member functions
bool operator!=(const Polynomial& lhs, const Polynomial& rhs) { return !(lhs == rhs); }

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
    Polynomial poly(lhs);
    return poly += rhs;
}

