// file: 3mylist-iter-test.cpp
#include "3_2_algorithm.h"
#include "3_2_mylist-iter.h"
#include "3_2_mylist.h"
using namespace std;

//为了完成一个针对 List而设计的迭代器，我们无可避免曝露了太多 List细节：
// 在 main()为了制作 begin和 end两个迭代器，我们曝露了 ListItem；
// 在 ListIter class 为了达成 operator++的目的，我们曝露了 ListItem的操作函式 next()。
// 如果不是为了迭代器，ListItem 原本应该完全隐藏起来不曝光的。
// 换句话说，要设计出 ListIter，首先必须对 List 的细节有非常丰富的了解。
// 既然这无可避免，干脆就把迭代器的开发工作交给 List的设计者好了，
// 如此一来所有细节反而得以封装起来不被使用者看到。
// 这正是为什么每一种  STL  容器都提供有专属迭代器的缘故。

// 如果不写全局比较函数，则需要更改find函数判定
template <typename T> bool operator!=(const ListItem<T>& item, T n) { 
    return item.value() != n; 
} 

int main() {
    List<int> mylist;
    

    for (int i = 0; i < 5; ++i) {
        mylist.insert_front(i);
        mylist.insert_end(i + 2);
    }

    mylist.display();

    ListIter<ListItem<int>> begin(mylist.front());
    ListIter<ListItem<int>> end;
    ListIter<ListItem<int>> iter;
    iter = find(begin, end, 3);
    if (iter == end)
        cout << "not found" << endl;
    else
        cout << "found. " << iter->value() << endl;

    iter = find(begin, end, 7);
    if (iter == end)
        cout << "not found" << endl;
    else
        cout << "found. " << iter->value() << endl;
}