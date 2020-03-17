// file: 6-7-n.cpp

#include <algorithm>
#include <vector>
#include <functional>
#include <iterator>
#include <iostream>

using namespace std;

struct even {
    bool operator() (int x) const {
        return x % 2 ? false : true;
    }
};

int main() {
    int ia[] = {12, 17, 20, 22, 23, 30, 33, 40};
    vector<int> iv(ia, ia + sizeof(ia) / sizeof(int));

    cout << *lower_bound(iv.begin(), iv.end(), 21) << endl; // 22
    cout << *upper_bound(iv.begin(), iv.end(), 21) << endl; // 22
    cout << *lower_bound(iv.begin(), iv.end(), 22) << endl; // 22
    cout << *upper_bound(iv.begin(), iv.end(), 22) << endl; // 23

    // 有序区间可以二分查找
    cout << binary_search(iv.begin(), iv.end(), 33) << endl;
    cout << binary_search(iv.begin(), iv.end(), 34) << endl;

    // 下一个排列组合
    next_permutation(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // 上一个排列组合
    prev_permutation(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // 随机重排
    random_shuffle(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // 部分排序
    partial_sort(iv.begin(), iv.begin() + 4, iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // 排序，默认递增
    sort(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // 排序，指定递减
    sort(iv.begin(), iv.end(), greater<int>());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    iv.push_back(22);
    iv.push_back(30);
    iv.push_back(17);

    // 排序，保持原相对位置
    stable_sort(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // 对有序区间，找出一个区间，每个元素都等于特定元素值，返回头尾迭代器
    // 找不到则返回可插入特定元素的头尾迭代器
    pair<vector<int>::iterator, vector<int>::iterator> pairIte;
    pairIte = equal_range(iv.begin(), iv.end(), 22);
    cout << *(pairIte.first) << endl; // 22 lower_bound
    cout << *(pairIte.second) << endl; // 23 upper_bound

    pairIte = equal_range(iv.begin(), iv.end(), 25);
    cout << *(pairIte.first) << endl; // 30 lower_bound
    cout << *(pairIte.second) << endl; // 30 upper_bound

    random_shuffle(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // 将小于40的元素放左边，其他放右边，不稳定算法
    nth_element(iv.begin(), iv.begin() + 5, iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // 符合条件放左边，否则放右边，稳定算法
    stable_partition(iv.begin(), iv.end(), even());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}