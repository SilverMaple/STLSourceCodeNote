// file: 7functor-rational.cpp

#include <iostream>
#include <functional>

using namespace std;

int main() {
    // 产生仿函数实体
    equal_to<int> equal_to_obj;
    not_equal_to<int> not_equal_to_obj;
    greater<int> greater_obj;
    greater_equal<int> greater_equal_obj;
    less<int> less_obj;
    less_equal<int> less_equal_obj;

    // 使用对象完成函数功能
    cout << equal_to_obj(3, 5) << endl;
    cout << not_equal_to_obj(3, 5) << endl;
    cout << greater_obj(3, 5) << endl;
    cout << greater_equal_obj(3, 5) << endl;
    cout << less_obj(3, 5) << endl;
    cout << less_equal_obj(3, 5) << endl;

    // 直接使用仿函数的临时对象完成函数功能
    cout << equal_to<int>()(3, 5) << endl;
    cout << not_equal_to<int>()(3, 5) << endl;
    cout << greater<int>()(3, 5) << endl;
    cout << greater_equal<int>()(3, 5) << endl;
    cout << less<int>()(3, 5) << endl;
    cout << less_equal<int>()(3, 5) << endl;
}