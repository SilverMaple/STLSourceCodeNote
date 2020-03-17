// file: 6algobase.cpp

#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

template <class T>
struct display {
    void operator() (const T& x) const {
        cout << x << ' ';
    }
};


int main() {
    int ia[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    // int ib = iota(ia, ia + 9, 0); // include numeric

    vector<int> iv1(ia, ia + 5);
    vector<int> iv2(ia, ia + 9);

    // 判断两个序列第一个不匹配点 pair（第一个序列的不匹配点，第二个序列的不匹配点）
    cout << *(mismatch(iv1.begin(), iv1.end(), iv2.begin()).first);
    cout << *(mismatch(iv1.begin(), iv1.end(), iv2.begin()).second);

    // 如果序列在区间内相等，equal返回true
    cout << equal(iv1.begin(), iv1.end(), iv2.begin());
    cout << equal(iv1.begin(), iv1.end(), &ia[3]);
    cout << equal(iv1.begin(), iv1.end(), &ia[3], less<int>());

    fill(iv1.begin(), iv1.end(), 9);
    for_each(iv1.begin(), iv1.end(), display<int>());

    fill_n(iv1.begin(), 3, 7); // 从迭代器开始填3个7
    for_each(iv1.begin(), iv1.end(), display<int>());

    vector<int>::iterator ite1 = iv1.begin();
    vector<int>::iterator ite2 = ite1; // 指向7
    advance(ite2, 3);   // 指向9，前进

    iter_swap(ite1, ite2);
    cout << *ite1 << ' ' << *ite2 << endl;
    for_each(iv1.begin(), iv1.end(), display<int>());

    cout << max(*ite1, *ite2) << endl;
    cout << min(*ite1, *ite2) << endl;

    // 错误写法
    cout << *max(ite1, ite2) << endl;
    cout << *min(ite1, ite2) << endl;

    swap(*iv1.begin(), *iv2.begin());
    for_each(iv1.begin(), iv1.end(), display<int>());
    for_each(iv2.begin(), iv2.end(), display<int>());

    string stra1[] = {"Jamie", "JJHou", "Jason"};
    string stra2[] = {"Jamie", "JJHou", "Jerry"};

    cout << lexicographical_compare(stra1, stra1 + 2, stra2, stra2 + 2);
    cout << lexicographical_compare(stra1, stra1 + 2, stra2, stra2 + 2,
        greater<string>());
        
}