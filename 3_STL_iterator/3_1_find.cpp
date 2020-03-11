#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

// 迭代器是㆒种行为类似指针的对象，对operator*和operator->进行重载

int main() {
    const int arraySize = 7;
    int ia[arraySize] = {0, 1, 2, 3, 4, 5, 6};

    vector<int> ivect(ia, ia + arraySize);
    list<int> ilist(ia, ia + arraySize);
    deque<int> ideque(ia, ia + arraySize);

    vector<int>::iterator it1 = find(ivect.begin(), ivect.end(), 4);
    if (it1!=ivect.end())
        cout << "4 not found." << endl;
    else
        cout << "4 found. " << *it1 << endl;

    list<int>::iterator it2 = find(ilist.begin(), ilist.end(), 6);
    if (it2!=ilist.end())
        cout << "6 not found." << endl;
    else
        cout << "6 found. " << *it2 << endl;

    deque<int>::iterator it3 = find(ideque.begin(), ideque.end(), 8);
    if (it3!=ideque.end())
        cout << "8 not found." << endl;
    else
        cout << "8 found. " << *it3 << endl;
}