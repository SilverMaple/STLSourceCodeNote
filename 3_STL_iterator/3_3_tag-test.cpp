// file: 3tag-test.cpp

#include <iostream>
using namespace std;

struct B { // 类比InputIterator
};
struct D1 : public B { // 类比ForwardIterator
};
struct D2 : public D1 { // 类比BidirectionalIterator
};

template <class I> 
void func(I& p, B) {
    cout << "B version" << endl;
}

template <class I> 
void func(I& p, D2) {
    cout << "D2 version" << endl;
}

int main() {
    int * p;
    func(p, B());
    func(p, D1());
    func(p, D2());
}