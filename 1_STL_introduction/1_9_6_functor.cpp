// file: 1functor.cpp

#include <iostream>
using namespace std;

namespace sil{
    // 重载了函数调用符()的类或结构体，为仿函数
    template <class T>
    struct plus {
        // const 后置修饰为常函数
        T operator() (const T& x, const T& y) const {
            return x + y;
        }
    };

    template <class T>
    struct minus {
        // const 后置修饰为常函数
        T operator() (const T& x, const T& y) const {
            return x - y;
        }
    };
}

int main() {
    // 生成仿函数对象
    sil::plus<int> plusobj;
    sil::minus<int> minusobj;

    cout << plusobj(3, 5) << endl;
    cout << minusobj(3, 5) << endl;

    // 使用匿名对象
    cout << sil::plus<int>()(3, 5) << endl;
    cout << sil::minus<int>()(3, 5) << endl;
}