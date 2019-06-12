//
//  rec11
//  Linked Lists
//  Andrew Qu w/ code from jbs
//  April 19th 2019

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Node to be used a part of linked list
struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

// listAddHead: adds a data item to the beginning of a [possibly empty] list
void listAddHead(Node*& headPtr, int entry) {
    headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like.
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listAddHead(result, vals[index-1]);
    }
    return result;
}

void printList(Node* headptr) {
    while(headptr) {
        cout << headptr->data << " ";
        headptr = headptr->next;
    }
    cout << endl;
}

void splice(Node* listToAdd, Node* addingLoc) {
    Node* tailPtr = listToAdd;
    while (tailPtr->next) {
        tailPtr = tailPtr->next;
    }
    tailPtr->next = addingLoc->next;
    addingLoc->next = listToAdd;
}

Node* isSublist(Node* sublist, Node* searchList) {
    cout << "Attempt match: ";
    printList(sublist);
    Node* retPtr = searchList; //possible head of sub within searchlist
    Node* subIter = sublist;
    Node* searchIter = searchList;
    while (searchIter) {
        if (searchIter->data == subIter->data) {
            if(subIter == sublist) { //head of sublist was found
                retPtr = searchIter;
            }
            if(subIter->next) { //some of sublist remains to be found
                subIter = subIter->next;
            }
            else { //entirety of sublist was found
                printList(retPtr);
                return retPtr;
            }
            searchIter = searchIter->next; //continue search
        }
        else { //nodes no longer match
            retPtr = retPtr->next; //try next node in searchlist
            searchIter = retPtr; //restart search from there
            subIter = sublist; //return to start of sublist
        }
    }
    cout << "Failed to match\n";
    return nullptr;
}

Node* sharedListBruteForce(Node* list1, Node* list2) {
    Node* list1Iter = list1;
    Node* list2Iter = list2;
    while (list1Iter) {
        while (list2Iter) {
            if (list1Iter == list2Iter) {
                return list1Iter;
            }
            list2Iter = list2Iter->next;
        }
        list2Iter = list2;
        list1Iter = list1Iter->next;
    }
    return nullptr;
}

Node* sharedListUsingSet(Node* list1, Node* list2) {
    unordered_set<Node*> list1Addresses;
    while (list1) {
        list1Addresses.insert(list1);
        list1 = list1->next;
    }
    while (list2) {
        if (list1Addresses.find(list2) != list1Addresses.end()) {
            return list2;
        }
        list2 = list2->next;
    }
    return nullptr;
}

size_t lenOfList(Node* headptr) {
    size_t ret = 0;
    while (headptr) {
        ret ++;
        headptr = headptr->next;
    }
    return ret;
}

Node* sharedListUsingSetV2(Node* list1, Node* list2) { //O(1) space
    size_t len1 = lenOfList(list1);
    size_t len2 = lenOfList(list2);
    Node* longListIter; Node* shortListIter;
    if (len1 > len2) {
        longListIter = list1;
        shortListIter = list2;
    }
    else {
        longListIter = list2;
        shortListIter = list1;
    }
    for (int i = abs((int)len1 - (int)len2);i > 0;i --) {
        longListIter = longListIter->next;
    }
    while (longListIter) {
        if (longListIter == shortListIter) {
            return longListIter;
        }
        longListIter = longListIter->next;
        shortListIter = shortListIter->next;
    }
    return nullptr;
}

int main() {
    //Task one
    Node* L1 = listBuild({5,7,9,1});
    Node* L2 = listBuild({6,3,2});
    cout << "List L1: ";
    printList(L1);
    cout << "List L2: ";
    printList(L2);
    Node* sevenPtr = L1->next;
    //Node* onePtr = L1->next->next->next; //can also splice to the last node
    cout << "Splicing L2 at 7-node in L1:\n";
    splice(L2,sevenPtr);
    cout << "List L1: ";
    printList(L1);
    cout << "List L2: ";
    printList(L2);
    
    //Task two
    Node* L3 = listBuild({1,2,3,2,3,2,4,5,6});
    cout << "Testing sublists\n";
    cout << "Target: ";
    printList(L3);
    isSublist(listBuild({1}), L3);
    isSublist(listBuild({3,9}), L3);
    isSublist(listBuild({2,3}), L3);
    isSublist(listBuild({2,4,5,6}), L3);
    isSublist(listBuild({2,3,2,4}), L3);
    isSublist(listBuild({5,6,7}), L3);

    //Task three
    cout << "Testing shared lists\n";
    Node* L6 = listBuild({2,3});
    Node* L7 = listBuild({2,3,3});
    Node* L8 = listBuild({4,5});
    Node* L6tailPtr = L6->next;
    Node* L7tailPtr = L7->next->next;
    splice(L8,L6tailPtr);
    splice(L8,L7tailPtr);
    cout << "L6: "; printList(L6);
    cout << "L7: "; printList(L7);

    cout << "brute force: " << sharedListBruteForce(L6, L7)->data << endl;
    cout << "using set: " << sharedListUsingSet(L6, L7)->data << endl;
    cout << "using const space: " << sharedListUsingSetV2(L6, L7) << endl;
    cout << "L8: " << L8 << endl; //should match above lines
    
    cout << "Testing non shared lists L3 and L6\n";
    cout << "L3: "; printList(L3);
    cout << sharedListUsingSetV2(L3, L6) << endl; //should be nullptr 0x0
}
