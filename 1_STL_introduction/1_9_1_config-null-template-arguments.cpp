// file: 1config-null-template-arguments.cpp 
// test __STL_NULL_TMPL_ARGS in <stl_config.h> 
// ref. C++ Primer 3/e, p.834: bound friend function template 
// vc6[x] cb4[x] gcc[o] 

// 直接理解为若允许**bound friend template(约束模板友元)**
// 则定义为 <> ，否则为空。
// friend bool ooperator== __STL_NULL_TMPL_ARGS(const stack&,const stack&);
// 展开后变成
// friend bool ooperator== <>(const stack&,const stack&);
// 友元类型取决于类被初始化时的类型，但程序必须在类外为友元提供模板定义。

#include <iostream>
#include <cstddef> // for size_t
using namespace std;

class alloc {
};

// BufSiz为非类型参数
template <class T, class Alloc=alloc, size_t BufSiz=0>
class deque {
public:
    deque() {
        cout << "deque" << " ";
    }
};

//以㆘宣告如果不出现，GCC也可以通过。如果出现，GCC也可以通过。这㆒点和
// C++ Primer 3/e p.834的说法有出入。书㆖说㆒定要有这些前置宣告。
template <class T, class Sequence>
class stack;

template <class T, class Sequence>
bool operator==(const stack<T, Sequence> &x,
                const stack<T, Sequence> &y);

template <class T, class Sequence>
bool operator<(const stack<T, Sequence> &x,
               const stack<T, Sequence> &y);

template <class T, class Sequence = deque<T>>
class stack {
    // 以下三种写法都可以，即标注模板的使用
    friend bool operator== <T> (const stack<T> &, const stack<T>&);
    friend bool operator< <T> (const stack<T> &, const stack<T> &);

    friend bool operator== <T> (const stack &, const stack &);
    friend bool operator< <T> (const stack &, const stack &);

    friend bool operator== <> (const stack &, const stack &);
    friend bool operator< <> (const stack &, const stack &);
    
    // 编译报错，提示如下
    // note: (if this is not what you intended, make sure the function template has already been declared and add <> after the function name here)
    // friend bool operator==  (const stack &, const stack &);
    // friend bool operator<  (const stack &, const stack &); 

public:
    stack() {
        cout << "stack" << endl;
    }    
private:
    Sequence c;
};

template <class T, class Sequence>
bool operator==(const stack<T, Sequence> &x, 
                const stack<T, Sequence> &y) {
    // error: cannot convert 'std::basic_ostream<char>' to 'bool' in return
    // return cout << "operator==" << '\t';
    cout << "operator==" << '\t';
    return true;
}

template <class T, class Sequence>
bool operator<(const stack<T, Sequence> &x, 
                const stack<T, Sequence> &y) {
    // return cout << "operator<" << '\t';
    cout << "operator<" << '\t';
    return true;
}

int main() {
    stack<int> x;
    stack<int> y;

    cout << (x == y) << endl;
    cout << (x < y) << endl;

    stack<char> y1;
    // error: no match for 'operator==' (operand types are 'stack<int>' and 'stack<char>')
    // cout << (x == y1) << endl; 
}