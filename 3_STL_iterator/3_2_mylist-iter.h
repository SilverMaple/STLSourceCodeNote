// file: 3mylist-iter.h

// #include "3_2_mylist.h"

template <class Item>
struct ListIter {
    Item *ptr; // 保持与容器的联系

    // default ctor
    ListIter(Item* p =0) : ptr(p) {}

    // 解引用 dereference
    Item& operator*() const {
        return *ptr;
    }

    // member access
    Item* operator->() const {
        return ptr;
    }

    // prefix increment, 返回对象
    ListIter& operator++() {
        ptr = ptr->next();
        return *this;
    }

    // postfix increment, 返回值（新对象）
    // int为占位符，提示编译器这是后自增
    ListIter operator++(int) {
        ListIter temp = *this;
        ++*this; // 调用前面的前自增
        return temp;
    }

    bool operator==(const ListIter& i) const {
        return ptr == i.ptr;
    }

    bool operator!=(const ListIter& i) const {
        return ptr != i.ptr;
    }
};