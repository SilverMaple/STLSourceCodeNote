// file: 1config8.cpp 
// 测试 class template之内可否再有 template (members). 
// test __STL_MEMBER_TEMPLATES in <stl_config.h> 
// ref. C++ Primer 3/e, p.844 
// vc6[o] cb4[o] gcc[o] 

// 如果编译器支持template members of classes（模板类内嵌套模板） 就定义。

#include <iostream>
using namespace std;

class alloc {
};

template <class T, class Alloc=alloc>
class vec {
public:
    typedef T value_type;
    typedef value_type* iterator; // 迭代器为指针
    // typedef T *iterator; // 直接定义也可

    template <class I> // 模板嵌套模板
    void insert(iterator position, I first, I last) {
        cout << "insert()" << endl;
    }
};

int main() {
    int ia[5] = {0, 1, 2, 3, 4};

    vec<int> x;
    vec<int>::iterator ite;
    x.insert(ite, ia, ia + 5);
}