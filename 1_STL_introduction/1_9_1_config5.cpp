// file: 1config5.cpp 
// 测试 class template partial specialization 
// — 在 class template的一般化设计之外，特别针对某些 template参数做特殊设计。
// test __STL_CLASS_PARTIAL_SPECIALIZATION in <stl_config.h> 
// ref. C++ Primer 3/e, p.860 
// vc6[x] cb4[o] gcc[o]

// 如果编译器支持 partial specialization of class templates(模板类偏特化)就定义。
// 在模板类一般化设计之外（全特化），针对某些template做特殊设计。
// “所谓的partial specialization的另一个意思是提供另一份template定义式,而其本身仍是templatized”
// 全特化就是所有的模板都为具体的类。
// T* 特化允许用指针类型匹配的模式（也只能匹配指针类型）。
// const T* 特化允许使用指向const的指针 类型匹配（也只能匹配指向const的指针）。

#include <iostream>
using namespace std;

// 一般化设计
template <class I, class O>
struct TestClass {
    TestClass() {
        cout << "I, O" << endl;
    }
};

// 特殊化设计
template <class T>
struct TestClass<T*, T*> {
    TestClass() {
        cout << "T*, T*" << endl;
    }
};

// 特殊化设计
template <class T>
struct TestClass<const T*, T*> {
    TestClass() {
        cout << "const T*, T*" << endl;
    }
};

int main() {
    TestClass<int, char> obj1;
    TestClass<int *, int *> obj2;
    TestClass<const int *, int *> obj3;
}