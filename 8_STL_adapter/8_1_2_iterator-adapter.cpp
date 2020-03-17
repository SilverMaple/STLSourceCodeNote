// file: 8iterator-adapter.cpp

#include <iterator> // for iterator adapters
#include <deque>
#include <algorithm> // for copy()
#include <iostream>

using namespace std;

int main() {
    // 将outite绑定到cout，每次对outite指派一个元素，就后接一个“ ”
    ostream_iterator<int> outite(cout, " ");

    int ia[] = {0, 1, 2, 3, 4, 5};
    deque<int> id(ia, ia + 6);

    // 将所有元素拷贝到outite，即cout
    copy(id.begin(), id.end(), outite);
    cout << endl;

    // 将ia[]的部分元素拷贝到id内，使用front_insert_iterator
    // front_insert_iterator会将assign操作给push_front操作
    // vector不支持push_front操作，所以不以vector做示范对象
    copy(ia + 1, ia + 2, front_inserter(id));
    copy(id.begin(), id.end(), outite);
    cout << endl;

    // 将ia[]的部分元素拷贝到id内，使用back_insert_iterator
    copy(ia + 1, ia + 2, back_inserter(id));
    copy(id.begin(), id.end(), outite);
    cout << endl;

    // 搜寻元素5所在位置
    deque<int>::iterator ite = find(id.begin(), id.end(), 5);
    // 将ia[]的部分元素拷贝到id内，使用insert_iterator
    copy(ia + 1, ia + 2, inserter(id, ite));
    copy(id.begin(), id.end(), outite);
    cout << endl;

    // 将所有元素逆向拷贝到outite
    // rbegin()和rend()与reverse_iterator有关
    copy(id.rbegin(), id.rend(), outite);
    cout << endl;

    // 将inite绑定到cin，将元素拷贝到inite，知道eos出现
    istream_iterator<int> inite(cin), eos; // eos: end-of-stream
    copy(inite, eos, inserter(id, id.begin()));
    // 输入数字，停止时可以输入任意字符

    copy(id.begin(), id.end(), outite);
}
