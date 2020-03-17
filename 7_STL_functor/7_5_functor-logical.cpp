// file: 7functor-logical.cpp

#include <iostream>
#include <functional>

using namespace std;

int main() {
    // 产生仿函数实体
    logical_and<int> and_obj;
    logical_or<int> or_obj;
    logical_not<int> not_obj;

    // 使用对象完成函数功能
    cout << and_obj(true, true) << endl;
    cout << or_obj(true, false) << endl;
    cout << not_obj(true) << endl;

    // 直接使用仿函数的临时对象完成函数功能
    cout << logical_and<int>()(true, true) << endl;
    cout << logical_or<int>()(true, false) << endl;
    cout << logical_not<int>()(true) << endl;
}