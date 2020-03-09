// file: 1qsort.cpp

// c++使用函数对象/仿函数实现一组动作
// c使用函数指针实现一组动作，但是无法存储状态在里面

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int fcmp(const void *elem1, const void *elem2);

int main() {
    int ia[10];
    // int ia[10] = {32, 92, 67, 58, 10, 4, 25, 52, 59, 54};
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++) {
        ia[i] = rand() % 100 + 1;
        cout << ia[i] << " ";
    }
    cout << endl;

    // 快速排序
    qsort(ia, sizeof(ia) / sizeof(int), sizeof(int), fcmp);

    for (int i = 0; i < 10; i++) {
        cout << ia[i] << " ";
    }
}

int fcmp(const void* elem1, const void* elem2) {
    const int *i1 = (const int *)elem1;
    const int *i2 = (const int *)elem2;

    if (*i1 < *i2)
        return -1;
    else if (*i1 == *i2)
        return 0;
    else
        return 1;
}