// file: 1config-template-exp-special.cpp 
// 以下测试 class template explicit specialization 
// test __STL_TEMPLATE_NULL in <stl_config.h> 
// ref. C++ Primer 3/e, p.858 
// vc6[o] cb4[x] gcc[o] 

// template <> 显示的模板特化(class template explicit specialization)**
// 即指定一种或多种模板形参的实际值或实际类型，作为特殊情况。（与模板类型偏特化不同！）

#include <iostream>
using namespace std;

#define __STL_TEMPLATE_NULL   /* blank */

template <class Key> struct hashes {
    void operator() () {
        cout << "hashes<T>" << endl;
    }
};

// 以下注释编译不通过，必须遵守c++标准规格，即写出template<>
// error: an explicit specialization must be preceded by 'template <>'

// explicit specialization
// __STL_TEMPLATE_NULL struct hashes<char>{
//     void operator()(){
//         cout << "hashes<char>" << endl;
//     }
// };

// __STL_TEMPLATE_NULL struct hashes<unsigned char>{
//     void operator()(){
//         cout << "hashes<char>" << endl;
//     }
// };

int main() {
    hashes<long> t1;
    hashes<char> t2;
    hashes<unsigned char> t3;

    t1();
    t2();
    t3();
}