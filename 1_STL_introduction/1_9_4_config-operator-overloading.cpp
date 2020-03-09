// file: 1config-operator-overloading.cpp 
// vc6[x] cb4[o] gcc[o]
// vc6的 friend机制搭配 C++标准链接库，有bug

// increment ++ 前进
// decrement -- 后退
// prefix 前置 与 postfix 后置
// dereference * 解引用
// reference & 取地址 引用

#include <iostream>
using namespace std;

class INT {
    friend ostream &operator<<(ostream &os, const INT &i);

public:
    INT(int i) : m_i(i){};
    
    // 前置返回原对象，后置返回值（新创建）

    // prefix increment
    INT& operator++() {
        ++(this->m_i);
        return *this;
    }

    // postfix increment 需要占位符int
    INT operator++(int) {
        INT temp = *this;
        ++(*this); // 调用前置++
        return temp;
    }

    // prefix decrement
    INT& operator--() {
        --(this->m_i);
        return *this;
    }

    // postfix increment 需要占位符int
    INT operator--(int) {
        INT temp = *this;
        --(*this); // 调用前置--
        return temp;
    }

    // dereference   
    // const后置修饰函数表示为常函数，不能修改成员变量
    // 但能修改mutable修饰的成员变量
    int& operator*() const {
        // error: binding reference of type 'int&' to 'const int' discards qualifiers
        // return m_i;

        return (int &)m_i;
        //以上转换动作告诉编译器，你确实要将 const int转为 non-const lvalue. 
        // 如果没有这样明白㆞转型，有些编译器会给你警告，有些更严格的编译器会视为错误
    }

private:
    int m_i;
};

ostream& operator<< (ostream& os, const INT& i) {
    os << '[' << i.m_i << ']';
    return os;
}

int main() {
    INT I(5);
    cout << I++;
    cout << ++I;
    cout << I--;
    cout << --I;
    cout << *I;
}