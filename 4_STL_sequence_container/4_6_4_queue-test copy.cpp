// file: 4queue-test.cpp

#include <queue>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    queue<int, list<int>> iqueue;
    iqueue.push(1);
    iqueue.push(3);
    iqueue.push(5);
    iqueue.push(7);

    cout << iqueue.size() << endl;
    cout << iqueue.front() << endl;

    iqueue.pop();
    cout << iqueue.front() << endl;
    iqueue.pop();
    cout << iqueue.front() << endl;
    iqueue.pop();
    cout << iqueue.front() << endl;
    cout << iqueue.size() << endl;
}