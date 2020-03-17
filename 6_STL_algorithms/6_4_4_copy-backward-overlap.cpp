// file: 6copy-backward-overlap.cpp

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

template <class T>
struct display {
    void operator() (const T& x) {
        cout << x << " ";
    }
};

int main() {
    {
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

        // 输出区间终点与输入区间重叠
        copy_backward(ia + 2, ia + 7, ia+9);
        for_each(ia, ia + 9, display<int>());
        cout << endl;
    }

    {
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

        // 输出区间起点与输入区间重叠
        copy_backward(ia + 2, ia + 7, ia+5);
        for_each(ia, ia + 9, display<int>());
        cout << endl;
        // 本例正确，是因为copy_backward使用memmove执行实际复制
    }

    {
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        deque<int> id(ia, ia + 9);

        auto first = id.begin();
        auto last = id.end();
        ++++first; // advance(first, 2);
        cout << *first << endl;
        ----last;
        cout << *last << endl;

        auto result = id.end();
        cout << *result << endl;

        // 输出区间终点与输入区间重叠
        copy_backward(first, last, result);
        for_each(id.begin(), id.end(), display<int>());
        cout << endl;
    }

    {
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        deque<int> id(ia, ia + 9);

        auto first = id.begin();
        auto last = id.end();
        ++++first; // advance(first, 2);
        cout << *first << endl;
        ----last;
        cout << *last << endl;

        auto result = id.begin();
        advance(result, 5);
        cout << *result << endl;

        // 输出区间起点与输入区间重叠
        copy_backward(first, last, result);
        for_each(id.begin(), id.end(), display<int>());
        cout << endl;
        // 本例结果错误，是因为copy不再使用memmove执行实际复制

        // 如果换成vector结果正确，是因为vector迭代器时原生指针，
        // copy_backward算法可以调用memmove执行实际复制
    }
}