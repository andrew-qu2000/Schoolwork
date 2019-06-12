//
//  rec14.cpp
//  cs2124 rec14
//  Andrew Qu
//


#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node(int data = 0, Node* next = nullptr) :
        data(data),
        next(next)
    {}
    int data;
    Node* next;
};

struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

//Problem 1
bool evenOnesBin(int n) {
    //if (n == 0) return true;
    //if (n == 1) return false;
    if (n < 2) return n == 0;
    if (n % 2 == 0) {
        return evenOnesBin(n / 2);
    }
    else {
        return !evenOnesBin(n - (n % 2));
    }
}

//Problem 2
Node* sumLists(Node* L1, Node* L2) {
    int sum = 0;
    if (!L1 && !L2) return nullptr;
    else if (!L1) {
        sum += L2->data;
        return new Node(sum, sumLists(L1,L2->next));
    }
    else if (!L2) {
        sum += L1->data;
        return new Node(sum, sumLists(L1->next,L2));
    }
    else{
        sum += L1->data + L2->data;
        return new Node(sum, sumLists(L1->next,L2->next));
    }
}

//Problem 3
int max(TNode* root) {
    if (!root) throw invalid_argument("Max undefined for empty tree");
    int maxToRet = 0;
    if (root->left) maxToRet = max(maxToRet, max(root->left));
    if (root->right) maxToRet = max(maxToRet, max(root->right));
    maxToRet = max(maxToRet, root->data);
    return maxToRet;
}

//Problem 4
bool palindrome(char* first, int len) {
    if (len < 2) return true;
    return (*first == *(first + len - 1) && palindrome(first + 1, len - 2));
}

//Problem 5
int towers(int discs, char start, char spare, char end) {
    if (discs == 1) return 1;
    /*
    int moves = 0;
    moves += towers(discs - 1, start, end, spare); //move n-1 stack to spare
    moves += 1; //moving largest disk to end
    moves += towers(discs - 1, spare, start, end); //move n-1 stack to end
     */
    int moves = 2 * towers(discs - 1, start, end, spare);
    moves += 1; //moving largest disk
    return moves;
}

//Problem 6
void mystery(int n) {
    if (n > 1) {
        cout << 'a';
        mystery(n / 2);
        cout << 'b';
        mystery(n / 2);
    }
    cout << 'c';
}

int main() {
    //Problem 1
    cout << "====Problem 1====\n";
    for (int i = 0;i <= 20;i++) {
        cout << i << ": ";
        cout << boolalpha;
        cout << evenOnesBin(i) << endl;
    }
    //Problem 2
    cout << "\n====Problem 2====\n";
    Node n4(16), n3(9,&n4), n2(4,&n3), n1(1,&n2);
    Node n7(49), n6(36,&n7), n5(25,&n6);
    Node* head = sumLists(&n1, &n5);
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    //Problem 3
    cout << "\n====Problem 3====\n";
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    cout << max(&f) << endl; //32
    a.data = 99;
    cout << max(&f) << endl; //99
    TNode* tn = nullptr;
    cout << "Running max on empty tree...\n";
    try {
        max(tn);
    }
    catch (const invalid_argument& ia) {
        cerr << "Invalid argument: " << ia.what() << endl;
    }
    //Problem 4
    cout << "\n====Problem 4====\n";
    char s[] = "racecar";
    char t[] = "tacocat";
    char u[] = "abcxzcba";
    char v[] = "v";
    char w[] = "";
    char x[] = "az";
    cout << "s[] palindrome: " << boolalpha << palindrome(s,7) << endl;
    cout << "t[] palindrome: " << boolalpha << palindrome(t,7) << endl;
    cout << "u[] palindrome: " << boolalpha << palindrome(u,8) << endl;
    cout << "v[] palindrome: " << boolalpha << palindrome(v,1) << endl;
    cout << "w[] palindrome: " << boolalpha << palindrome(w,0) << endl;
    cout << "x[] palindrome: " << boolalpha << palindrome(x,2) << endl;
    //Problem 5
    cout << "\n====Problem 5====\n";
    for (int i = 1;i <= 10;i++) {
        cout << "towers(" << i << ", 'a', 'b', 'c'): ";
        cout << towers(i, 'a', 'b', 'c') << endl;
    }
    //Problem 6
    cout << "\n====Problem 6====\n";
    for (int i = 0;i <= 10;i++) {
        cout << "mystery(" << i << "): ";
        mystery(i);
        cout << endl;
    }
    mystery(8);
}

