//
// rec13 - STL
// CS2124
// Andrew Qu
// w/ test code by J Sterling

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

template <typename T>
void print_vector(const vector<T>& v) { //for tasks 1, 3, 21
    for (T i : v) cout << i << " ";
}
void iter_print_list(const list<int>& lst) { //for task 9
    for (list<int>::const_iterator iter = lst.begin();iter != lst.end();++iter) cout << *iter << " ";
}
void ranged_iter_print_list(const list<int>& lst) { //for task 10
    for (int i : lst) cout << i << " ";
}
void print_every_other(const list<int>& lst) { //for task 11
    for (auto i = lst.begin();i != lst.end();++ ++ i) cout << *i << " ";
}
list<int>::const_iterator find_in_list(const list<int>& lst, int target) { //for task 12
    for (list<int>::const_iterator cursor = lst.begin();cursor != lst.end();++cursor) {
        if (*cursor == target) {
            cout << "Target found!\n";
            return cursor;
        }
    }
    cout << "Target not found!\n";
    return lst.end();
}
auto find_in_list_auto(const list<int>& lst, int target) { //for task 13
    for (auto cursor = lst.begin();cursor != lst.end();++cursor) {
        if (*cursor == target) {
            cout << "Target found!\n";
            return cursor;
        }
    }
    cout << "Target not found!\n";
    return lst.end();
}
bool isEven(int x) { return x % 2 == 0; } //for task 15

class bestClass { //for task 16
public:
    bool operator()(int x) { return x % 2 == 0; } //for task 16
};

auto ourFind(list<int>::const_iterator begin, list<int>::const_iterator end, int target) { //for task 19
    cout << "Inside ourFind\n";
    while (begin != end) {
        if (*begin == target) {
            return begin;
        }
        ++begin;
    }
    return end;
}

template <typename InputIterator, typename T>
auto ourFind(InputIterator begin, InputIterator end, T target) { //for task 20
    cout << "Inside template ourFind\n";
    while (begin != end) {
        if (*begin == target) {
            return begin;
        }
        ++ begin;
    }
    return end;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> int_vector = {3,5,4,1,2,7,8,15,4,12,19,10};
    print_vector(int_vector);
    cout << "\n=======\n";
    
    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> int_list(int_vector.begin(), int_vector.end());
    for (int i : int_list) cout << i << " ";
    cout << "\n=======\n";
    
    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(int_vector.begin(), int_vector.end());
    print_vector(int_vector);
    cout << endl;
    for (int i : int_list) cout << i << " ";
    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (int i = 0;i < int_vector.size();++ ++i) cout << int_vector[i] << " ";
    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    //fails because list has no operator[]
    //for (int i = 0;i < int_list.size();++ ++i) cout << int_list[i] << " ";
    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator iter = int_vector.begin();iter != int_vector.end();++ ++iter) {
        cout << *iter << " ";
    }
    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for (list<int>::iterator iter = int_list.begin();iter != int_list.end();++ ++iter) {
        cout << *iter << " ";
    }
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    cout << "Unsorted int list: ";
    for (int i : int_list) cout << i << " ";
    int_list.sort();
    cout << "\nNow sorted: ";
    for (int i : int_list) cout << i << " ";
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    iter_print_list(int_list);
    cout << "\n=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    ranged_iter_print_list(int_list);
    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    print_every_other(int_list);
    cout << "\n=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    list<int>::const_iterator citer = find_in_list(int_list, 4);
    cout << *citer << endl; //found
    citer = find_in_list(int_list, 15);
    cout << *citer << endl; //found
    citer = find_in_list(int_list, 9);
    cout << *citer; //not found
    cout << "\n=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    citer = find_in_list_auto(int_list, 4);
    cout << *citer << endl;
    citer = find_in_list_auto(int_list, 9);
    cout << *citer;
    cout << "\n=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    citer = find(int_list.begin(), int_list.end(), 12);
    if (citer != int_list.end()) cout << *citer << endl;
    citer = find(int_list.begin(), int_list.end(), 917);
    if (citer != int_list.end()) cout << *citer;
    cout << "\n=======\n";
    
    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    citer = find_if(int_list.begin(), int_list.end(), isEven);
    if (citer != int_list.end()) cout << *citer;
    cout << "\n=======\n";
    
    // 16. Functor
    cout << "Task 16:\n";
    citer = find_if(int_list.begin(), int_list.end(), bestClass());
    if (citer != int_list.end()) cout << *citer;
    cout << "\n=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    citer = find_if(int_list.begin(), int_list.end(), [](int x){return x % 2 == 0;});
    if (citer != int_list.end()) cout << *citer;
    cout << "\n=======\n";
    
    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int arr[12];
    copy(int_list.begin(), int_list.end(), arr);
    for(int i : arr) cout << i << " ";
    cout << endl;
    auto arr_iter = find(arr, arr + 12, 7);
    if (arr_iter != arr + 12) cout << *arr_iter;
    cout << "\n=======\n";
    
    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    auto ourFindIter = ourFind(int_list.begin(), int_list.end(), 8);
    if (ourFindIter != int_list.end()) cout << *ourFindIter;
    cout << "\n=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    auto ourFindVecIter = ourFind(int_vector.begin(), int_vector.end(), 19);
    if (ourFindVecIter != int_vector.end()) cout << *ourFindVecIter << endl;
    auto ourFindListIter = ourFind(int_list.begin(), int_list.end(), 19);
    if (ourFindListIter != int_list.end()) cout << *ourFindListIter;
    cout << "\n=======\n";
    
    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    vector<string> unique_words_vec;
    ifstream sampleText("pooh-nopunc.txt");
    if (!sampleText) {
        cout << "could not read file pooh-nopunc.txt";
        exit(1);
    }
    string word;
    bool unique = true;
    while (sampleText >> word) {
        for (const string& uword : unique_words_vec) {
            if (uword == word) {
                unique = false;
                break;
            }
        }
        if (unique) unique_words_vec.push_back(word);
        unique = true;
    }
    cout << unique_words_vec.size() << endl;
    print_vector(unique_words_vec);
    cout << "\n=======\n";
    
    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    sampleText.clear();
    sampleText.seekg(0);
    set<string> unique_words_set;
    while (sampleText >> word) {
        unique_words_set.insert(word);
    }
    cout << unique_words_set.size() << endl;
    for (const string& uword : unique_words_set) cout << uword << " ";
    cout << "\n=======\n";
    
    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    sampleText.clear();
    sampleText.seekg(0);
    map<string, vector<int>> wordsMap;
    int pos = 0;
    while (sampleText >> word) {
        wordsMap[word].push_back(pos);
        ++ pos;
    }
    for (const auto& pair : wordsMap) {
        cout << pair.first << ": ";
        for (int pos : pair.second) {
            cout << pos << " ";
        }
        cout << endl;
    }
    cout << "\n=======\n";
    
}
