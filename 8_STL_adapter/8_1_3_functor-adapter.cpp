// file: 8functor-adapter.cpp

#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

// compose1在mingw中没有，所以把定义搬了过来
template <class _Operation1, class _Operation2>
class unary_compose
  : public unary_function<typename _Operation2::argument_type,
                          typename _Operation1::result_type> 
{
protected:
  _Operation1 _M_fn1;
  _Operation2 _M_fn2;
public:
  unary_compose(const _Operation1& __x, const _Operation2& __y) 
    : _M_fn1(__x), _M_fn2(__y) {}
  typename _Operation1::result_type
  operator()(const typename _Operation2::argument_type& __x) const {
    return _M_fn1(_M_fn2(__x));
  }
};

template <class _Operation1, class _Operation2>
inline unary_compose<_Operation1,_Operation2> 
compose1(const _Operation1& __fn1, const _Operation2& __fn2)
{
  return unary_compose<_Operation1,_Operation2>(__fn1, __fn2);
}


void print(int i) {
    cout << i << " ";
}

class Int {
public: 
    // explicit 只能修改只有一个参数的类构造函数，
    // 或是除了第一个参数外其他参数都有默认值的情况
    // 表明该构造函数是显示的而非隐式的
    // 作用是禁止类构造函数的隐式自动转换
    // implicit 表示隐式，类构造函数默认声明为隐式
    // google c++规范与effective c++都推荐使用explicit声明
    explicit Int(int i) : m_i(i) {}

    void print1() const {
        cout << "[" << m_i << "]";
    }

private:
    int m_i;
};

int main() {
    // 将outite绑定到cout，每次对outite指派一个元素，就后接一个“ ”
    ostream_iterator<int> outite(cout, " ");

    int ia[6] = {2, 21, 12, 7, 19, 23};
    vector<int> iv(ia, ia + 6);

    // 找出不小于12的元素个数
    cout << count_if(iv.begin(), iv.end(),
                     not1(bind2nd(less<int>(), 12)));
    cout << endl;

    // 令每个元素v执行(v+2)*3然后输往outite
    transform(iv.begin(), iv.end(), outite,
              compose1(bind2nd(multiplies<int>(), 3),
                       bind2nd(plus<int>(), 2)));
    cout << endl;

    // 将所有元素拷贝到outite
    copy(iv.begin(), iv.end(), outite);
    cout << endl;
    // 1. 使用函数指针搭配stl算法
    for_each(iv.begin(), iv.end(), print);
    cout << endl;

    // 2. 以修饰过的一般函数搭配stl算法
    for_each(iv.begin(), iv.end(), ptr_fun(print));
    cout << endl;

    Int t1(3), t2(7), t3(20), t4(14), t5(68);
    vector<Int> Iv;
    Iv.push_back(t1);
    Iv.push_back(t2);
    Iv.push_back(t3);
    Iv.push_back(t4);
    Iv.push_back(t5);
    // 3. 以修饰过的成员函数搭配stl算法
    for_each(Iv.begin(), Iv.end(), mem_fun_ref(&Int::print1));
}