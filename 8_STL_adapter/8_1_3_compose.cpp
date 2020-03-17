// file: 8compose.cpp

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

int main() {
    // 将outite绑定到cout，每次对outite指派一个元素，就后接一个“ ”
    ostream_iterator<int> outite(cout, " ");

    int ia[6] = {2, 21, 12, 7, 19, 23};
    vector<int> iv(ia, ia + 6);

    // 想执行v = (v+2)*3
    // for_each是non-mutating algorithm，元素内容不能更改
    // 所以执行后iv内容不变
    for_each(iv.begin(), iv.end(),
             compose1(bind2nd(multiplies<int>(), 3),
                      bind2nd(plus<int>(), 2)));
    copy(iv.begin(), iv.end(), outite);
    cout << endl;

    transform(iv.begin(), iv.end(), outite,
             compose1(bind2nd(multiplies<int>(), 3),
                      bind2nd(plus<int>(), 2)));
    cout << endl;
}