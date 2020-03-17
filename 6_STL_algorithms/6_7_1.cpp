// file: 6-7-1.cpp

#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

// 仿函数
template <class T>
struct display { 
    void operator() (const T& x) const {
        cout << x << ' ';
    }
};

// 仿函数，一元谓词
struct even {
    bool operator() (int x) const {
        return x % 2 ? false : true;
    }
};

// 还是一个仿函数
class even_by_two {
public:
    int operator() () const {
        return _x += 2;
    }

private:
    static int _x;
};

int even_by_two::_x = 0; // 类内声明类外初始化

int main() {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8};
    vector<int> iv(ia, ia + sizeof(ia) / sizeof(int));

    // 找出相邻元素值相等的第一个元素
    cout << *adjacent_find(iv.begin(), iv.end()) << endl;
    // 找出相邻元素值相等的第一个元素
    cout << *adjacent_find(iv.begin(), iv.end(), equal_to<int>()) << endl;
    
    // 找出元素值为6的元素个数
    cout << count(iv.begin(), iv.end(), 6) << endl;
    // 找出元素值小于7的元素个数
    cout << count_if(iv.begin(), iv.end(), bind2nd(less<int>(), 7)) << endl;

    // 找出元素值为4的元素所在位置
    cout << *find(iv.begin(), iv.end(), 4) << endl;
    // 找出元素值大于2的第一个元素所在位置
    cout << *find_if(iv.begin(), iv.end(), bind2nd(greater<int>(), 2)) << endl;

    // 找出子序列所出现的最后一个位置，加3
    vector<int> iv2(ia + 6, ia + 8);
    cout << *(find_end(iv.begin(), iv.end(), iv2.begin(), iv2.end()) + 3) << endl;

    // 找出子序列所出现的第一个位置，加3
    cout << *(find_first_of(iv.begin(), iv.end(), iv2.begin(), iv2.end()) + 3) << endl;

    // 迭代iv 每个元素进行display
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;

    // 以下写法错误，generate的第三个参数是仿函数，本身不得有任何参数
    // generate(iv.begin(), iv.end(), bind2nd(plus<int>(), 3)); // error

    // 迭代iv2，对每个元素进行even_by_two
    generate(iv2.begin(), iv2.end(), even_by_two());
    for_each(iv2.begin(), iv2.end(), display<int>());
    cout << endl;
    // 迭代指定区间，对每个元素进行even_by_two
    generate_n(iv2.begin(), 3, even_by_two());
    for_each(iv2.begin(), iv2.end(), display<int>());
    cout << endl;

    // 删除（但不删除）元素6，尾端可能有残余数据（可以使用erase）
    remove(iv.begin(), iv.end(), 6);
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;

    // 删除（但不删除）元素6，结果置于另一区间
    vector<int> iv3(12);
    remove_copy(iv.begin(), iv.end(), iv3.begin(), 6);
    for_each(iv3.begin(), iv3.end(), display<int>());
    cout << endl;

    // 删除（但不删除）元素6，尾端可能有残余数据
    remove_if(iv.begin(), iv.end(), bind2nd(less<int>(), 6));
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;

    // 删除（但不删除）小于7的元素，结果置于另一区间
    remove_copy_if(iv.begin(), iv.end(), iv3.begin(), bind2nd(less<int>(), 7));
    for_each(iv3.begin(), iv3.end(), display<int>());
    cout << endl;

    // 将所有的元素值6，改为元素值3
    replace(iv.begin(), iv.end(), 6, 3);
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl; 

    // 将所有的元素值3，改为元素值5，结果置于另一区间
    replace_copy(iv.begin(), iv.end(), iv3.begin(), 3, 5);
    for_each(iv3.begin(), iv3.end(), display<int>());
    cout << endl; 

    // 将所有小于5的元素值，改为元素值2
    replace_if(iv.begin(), iv.end(), bind2nd(less<int>(), 5), 2);
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl; 

    // 将所有等于8的元素值，改为元素值9，结果置于另一区间
    replace_copy_if(iv.begin(), iv.end(), iv3.begin(), bind2nd(equal_to<int>(), 8), 9);
    for_each(iv3.begin(), iv3.end(), display<int>());
    cout << endl; 

    // 逆向重排每一个元素
    reverse(iv.begin(), iv.end());
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl; 
    // 逆向重排每一个元素，结果置于另一区间
    reverse_copy(iv.begin(), iv.end(), iv3.begin());
    for_each(iv3.begin(), iv3.end(), display<int>());
    cout << endl; 

    // 旋转（互换元素）[first, middle]和[middle, last]
    rotate(iv.begin(), iv.begin() + 4, iv.end());
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl; 
    // 旋转（互换元素）[first, middle]和[middle, last]
    // 结果置于另一区间
    rotate_copy(iv.begin(), iv.begin() + 5, iv.end(), iv3.begin());
    for_each(iv3.begin(), iv3.end(), display<int>());
    cout << endl; 

    // 查找某个子序列的第一次出现地点
    int ia2[3] = {2, 8};
    vector<int> iv4(ia2, ia2 + 2);
    cout << *search(iv.begin(), iv.end(), iv4.begin(), iv4.end()) << endl;
    // 查找连续出现2个8的子序列起点
    cout << *search_n(iv.begin(), iv.end(), 2, 8) << endl;
    // 查找连续出现3个小于8的子序列起点
    cout << *search_n(iv.begin(), iv.end(), 3, 8, less<int>()) << endl;

    // 将区间元素互换，第二区间个数不应小于第一区间个数
    swap_ranges(iv4.begin(), iv4.end(), iv.begin());
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl; 
    for_each(iv4.begin(), iv4.end(), display<int>());
    cout << endl; 

    // 改变区间的值，全部减2，原地搬运
    transform(iv.begin(), iv.end(), iv.begin(), bind2nd(minus<int>(), 2));
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl; 

    // 改变区间的值，令 第二区间的元素值加到第一区间上
    transform(iv.begin(), iv.end(), iv.begin(), iv.begin(), plus<int>());
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl; 

    // *******************************************

    vector<int> iv5(ia, ia + sizeof(ia) / sizeof(int));
    vector<int> iv6(ia + 4, ia + 8);
    vector<int> iv7(15);
    for_each(iv5.begin(), iv5.end(), display<int>());
    cout << endl; 
    for_each(iv6.begin(), iv6.end(), display<int>());
    cout << endl;

    cout << *max_element(iv5.begin(), iv5.end()) << endl;
    cout << *min_element(iv5.begin(), iv5.end()) << endl;

    // 判断是否iv6内的所有元素都出现于iv5中
    cout << includes(iv5.begin(), iv5.end(), iv6.begin(), iv6.end()) << endl;

    // 将两个序列合并，必须有序
    merge(iv5.begin(), iv5.end(), iv6.begin(), iv6.end(), iv7.begin());
    for_each(iv7.begin(), iv7.end(), display<int>());
    cout << endl; 

    // 符合条件的元素放在容器前端，其他放后端
    partition(iv7.begin(), iv7.end(), even());
    for_each(iv7.begin(), iv7.end(), display<int>());
    cout << endl;

    // 去除连续重复元素
    unique(iv5.begin(), iv5.end());
    for_each(iv5.begin(), iv5.end(), display<int>());
    cout << endl; 
    // 去除连续重复元素，结果置于另一区间
    unique_copy(iv5.begin(), iv5.end(), iv7.begin());
    for_each(iv7.begin(), iv7.end(), display<int>());
    cout << endl;

    // 累死我了~
}