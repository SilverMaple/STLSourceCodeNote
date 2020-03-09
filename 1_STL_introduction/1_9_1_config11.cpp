// file: 1config11.cpp 
// 测试 class template可否拥有 non-type template参数。
// test __STL_NON_TYPE_TMPL_PARAM_BUG in <stl_config.h> 
// ref. C++ Primer 3/e, p.825 
// vc6[o] cb4[o] gcc[o] 

// 测试类模板是否使用非类型模板参数（non-type template parameters） 。
// 当以类型 (type)作为模板参数的时候，代码中未决定的是类型；
// 当以一般的数字(non-type)作为模板参数的时候，代码中待定的内容便是某些数值。使用者这种模板必须要显示指定数值，模板才能实例化。
// 通常它们只能是常数整数（constant integral values ）包括枚举，或者是指向外部链接的指针。
// 不能把float，class-type类型的对象，内部链接(internal linkage )对象,作为非类型模板参数。

#include <iostream>
#include <cstddef> // for size_t
using namespace std;

class alloc {
};

inline size_t __deque_buf_size(size_t n, size_t sz) {
    return n != 0 ? n : (sz < 512 ? size_t(512 / sz) : size_t(1));
}

template <class T, class Ref, class Ptr, size_t BufSiz> 
struct __deque_iterator { 
    typedef __deque_iterator<T, T&, T*, BufSiz> iterator; 
    typedef __deque_iterator<T, const T&, const T*, BufSiz> const_iterator; 
    static size_t buffer_size() {
        return __deque_buf_size(BufSiz, sizeof(T)); 
    } 
}; 

// BufSiz为非类型参数
template <class T, class Alloc=alloc, size_t BufSiz=0>
class deque {
public:
    typedef __deque_iterator<T, T &, T *, BufSiz> iterator;
};

int main() {
    cout << deque<int>::iterator::buffer_size() << endl;
    // 非类型参数64
    cout << deque<int, alloc, 64>::iterator::buffer_size() << endl;
}