// file: 3mylist.h
#include <iostream>

// 先声明
template <typename T>
class ListItem;

template <typename T>
class List {
// 定义public以供访问
public:
    void insert_front(T value);
    void insert_end(T value);
    void display(std::ostream &os = std::cout) const;
    ListItem<T> * front() {
        return _front;
    }
    List();

private:
    ListItem<T> *_end;
    ListItem<T> *_front;
    long _size;
};

// 自己实现
template <typename T>
List<T>::List() {
    _size = 0;
    _front = NULL;
    _end = NULL;
}

template <typename T>
void List<T>::insert_front(T value) {
    ListItem<T>* temp = new ListItem<T>(value);
    temp->set_next(_front);
    _front = temp;
    _size++;
}

template <typename T>
void List<T>::insert_end(T value) {
    ListItem<T>* temp = new ListItem<T>(value);
    ListItem<T> *last = _front;
    while (last->next() != _end)
        last = last->next();
    last->set_next(temp);
    _end = temp->next();
    _size++;
}

// 声明写了默认参数后定义不能重写
template <typename T>
void List<T>::display(std::ostream &os) const {
    ListItem<T> *temp = _front;
    while (temp!= _end) {
        std::cout << temp->value() << " ";
        temp = temp->next();
    }
    std::cout << std::endl;
}

template <typename T>
class ListItem {
public:
    T value() const {
        return _value;
    }

    ListItem* next() const {
        return _next;
    }

    void set_next(ListItem* i) {
        _next = i;
    }

    ListItem(T value) : _value(value) {
        _next = NULL;
    }

private:
    T _value;
    ListItem *_next;
};