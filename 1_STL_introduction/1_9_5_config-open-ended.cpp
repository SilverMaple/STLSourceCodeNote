// 自己实现并测试for_each 与 find

#include <iostream>
#include <vector>
using namespace std;

namespace sil{
    template <class InputIterator, class T>
    InputIterator find(InputIterator first, InputIterator last, const T& value) {
        while (first!=last && *first!=value)
            ++first;
        return first;
    }

    template <class InputIterator, class Function>
    InputIterator for_each(InputIterator first, InputIterator last, Function f) {
        for (; first != last; ++first)
            f(*first);
        return first;
    }
}

// 函数对象/仿函数
template <class T>
class MyPrint {
public:
    void operator() (const T& t) {
        cout << t << " ";
    }
};

int main() {
    vector<int> ia = {0, 1, 2, 3, 4};
    vector<int>::iterator it = sil::find(ia.begin(), ia.end(), 4);
    if (it!= ia.end()) {
        cout << "Found value." << endl;
    }
    else {
        cout << "Not found." << endl;
    }

    sil::for_each(ia.begin(), ia.end(), MyPrint<int>());
}