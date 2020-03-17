// file: 6numeric.cpp

#include <numeric>
#include <vector>
#include <functional> // minus<int>()
#include <iostream>   // ostream_iterator
#include <iterator>

using namespace std;

int main() {
    int ia[5] = {1, 2, 3, 4, 5};
    vector<int> iv(ia, ia + 5);
    // 0+1+2+3...
    cout << accumulate(iv.begin(), iv.end(), 0) << endl;
    
    // 0-1-2-3
    cout << accumulate(iv.begin(), iv.end(), 0, minus<int>()) << endl;

    // 10 + 1*1 + 2*2 + ...
    cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10) << endl;

    // 10 - 1+1 - 2+2 - ...
    cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10,
        minus<int>(), plus<int>()) << endl;

    // 将迭代器绑定到cout，作为输出用
    ostream_iterator<int> oite(cout, " ");

    // 1 3 6 10 15 累计和
    partial_sum(iv.begin(), iv.end(), oite);
    cout << endl;

    // 1 -1 -4 -8 -13 累计差
    partial_sum(iv.begin(), iv.end(), oite, minus<int>());
    cout << endl;

    // 1 1 1 1 1     new #n = #n - #n-1
    adjacent_difference(iv.begin(), iv.end(), oite);
    cout << endl;

    // 1 3 5 7 9      new #n = op(#n, #n-1)
    adjacent_difference(iv.begin(), iv.end(), oite, plus<int>());
    cout << endl;

    // mingw c++ 中stl没有power实现
    // cout << power(10, 3) << endl;
    // cout << power(10, 3, plus<int>()) << endl;

    int n = 3;
    iota(iv.begin(), iv.end(), n); // 填入n, n+1, n+2
    for (int i = 0; i < iv.size(); ++i)
        cout << iv[i] << ' ';
}