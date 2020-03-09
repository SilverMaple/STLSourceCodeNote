// file: 1config6.cpp 
// test __STL_FUNCTION_TMPL_PARTIAL_ORDER in <stl_config.h> 
// vc6[x] cb4[o] gcc[o] 

// 如果编译器支持partial ordering of function templates
// 或者说partial specialization of function templates就定义。

#include <iostream>
using namespace std;

class alloc {
};

template <class T, class Alloc=alloc>
class vec {
public: 
    void swap(vec<T, Alloc>&) {
        cout << "swap()" << endl;
    }
};

// inline内联函数，解决一些频繁调用的小函数大量消耗栈空间（栈内存）的问题
// inline只适合函数体内代码简单的函数使用，不能包含复杂的结构控制语句例如 while、switch，并且不能内联函数本身不能是直接递归函数
// 定义在类中的成员函数默认都是内联的，类外实现需加上inline
#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER
template <class T, class Alloc>
inline void swap(vec<T, Alloc>& x, vec<T, Alloc>& y) {
    x.swap(y);
    cout << "inline swap" << endl;
}
#endif

int main() {
    vec<int> x, y;
    swap(x, y);
}