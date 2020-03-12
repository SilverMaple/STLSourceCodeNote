// file: 4pqueue-test.cpp

#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // test priority queue
    int ia[9] = {0, 1, 2, 3, 4, 8, 9, 3, 5};
    priority_queue<int> ipq(ia, ia + 9);
    cout << "size=" << ipq.size() << endl;

    for (int i = 0; i < ipq.size(); ++i)
        cout << ipq.top() << ' ';
    cout << endl;

    while(!ipq.empty()) {
        cout << ipq.top() << ' ';
        ipq.pop();
    }
    cout << endl;
}