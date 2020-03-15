// file: 5set-test.cpp

#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int i;
    int ia[5] = {0, 1, 2, 3, 4};
    set<int> iset{ia, ia + 5};

    cout << "size=" << iset.size() << endl;
    cout << "3 count =" << iset.count(3) << endl;
    iset.insert(3);
    cout << "size=" << iset.size() << endl;
    cout << "3 count =" << iset.count(3) << endl;

    iset.insert(5);
    cout << "size=" << iset.size() << endl;
    cout << "3 count =" << iset.count(3) << endl;

    iset.erase(1);
    cout << "size=" << iset.size() << endl;
    cout << "3 count =" << iset.count(3) << endl;
    cout << "1 count =" << iset.count(3) << endl;

    set<int>::iterator ite1 = iset.begin();
    set<int>::iterator ite2 = iset.end();
    for (; ite1 != ite2; ++ite1) {
        cout << *ite1;
    }
    cout << endl;

    // 使用STL算法find可以搜索元素，但不推荐
    ite1 = find(iset.begin(), iset.end(), 3);
    if (ite1 != iset.end())
        cout << "3 found" << endl;

    ite1 = find(iset.begin(), iset.end(), 1);
    if (ite1 == iset.end())
        cout << "1 not found" << endl;

    // 关联式容器应使用专用的find函数搜索更有效率
    ite1 = iset.find(3);
    if (ite1 != iset.end())
        cout << "3 found" << endl;

    ite1 = iset.find(1);
    if (ite1 == iset.end())
        cout << "1 not found" << endl;

    // *ite1 = 9; // 修改失败
}