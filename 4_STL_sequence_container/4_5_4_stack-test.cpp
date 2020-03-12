// file: 4stack-test.cpp

#include <stack>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    stack<int, list<int>> istack;
    istack.push(1);
    istack.push(3);
    istack.push(5);
    istack.push(7);

    cout << istack.size() << endl;
    cout << istack.top() << endl;

    istack.pop();
    cout << istack.top() << endl;
    istack.pop();
    cout << istack.top() << endl;
    istack.pop();
    cout << istack.top() << endl;
    cout << istack.size() << endl;
}