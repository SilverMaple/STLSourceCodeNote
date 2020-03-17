// file: 7functor-arithmetic.cpp

#include <iostream>
#include <functional>

using namespace std;

int main() {
    // 产生仿函数实体
    plus<int> plusobj;
    minus<int> minusobj;
    multiplies<int> multipliesobj;
    divides<int> dividesobj;
    modulus<int> modulusobj;
    negate<int> negateobj;

    // 使用对象完成函数功能
    cout << plusobj(3, 5) << endl;
    cout << minusobj(3, 5) << endl;
    cout << multipliesobj(3, 5) << endl;
    cout << dividesobj(3, 5) << endl;
    cout << modulusobj(3, 5) << endl;
    cout << negateobj(3) << endl;

    // 直接使用仿函数的临时对象完成函数功能
    cout << plus<int>()(3, 5) << endl;
    cout << minus<int>()(3, 5) << endl;
    cout << multiplies<int>()(3, 5) << endl;
    cout << divides<int>()(3, 5) << endl;
    cout << modulus<int>()(3, 5) << endl;
    cout << negate<int>()(3) << endl;
}