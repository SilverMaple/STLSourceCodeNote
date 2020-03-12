// file: 4heap-test.cpp

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    {
        // test heap (以vector完成)
        int ia[9] = {0, 1, 2, 3, 4, 8, 9, 3, 5};
        vector<int> ivec(ia, ia + 9);

        make_heap(ivec.begin(), ivec.end());
        for (int i = 0; i < ivec.size(); ++i) {
            cout << ivec[i] << " ";
        }
        cout << endl;

        ivec.push_back(7);
        push_heap(ivec.begin(), ivec.end());
        for (int i = 0; i < ivec.size(); ++i) {
            cout << ivec[i] << " ";
        }
        cout << endl;

        pop_heap(ivec.begin(), ivec.end());
        cout << ivec.back() << endl;
        ivec.pop_back();

        for (int i = 0; i < ivec.size(); ++i) {
            cout << ivec[i] << " ";
        }
        cout << endl;

        sort_heap(ivec.begin(), ivec.end());
        for (int i = 0; i < ivec.size(); ++i) {
            cout << ivec[i] << " ";
        }
        cout << endl;
    }

    {
        // test heap (以array完成)
        int ia[9] = {0, 1, 2, 3, 4, 8, 9, 3, 5};

        make_heap(ia, ia+9);
        // array无法动态改变大小，因此不可以对满载的 array做 push_heap()动作。
        //因为那得先在 array尾端增加㆒个元素。

        sort_heap(ia, ia+9);
        for (int i = 0; i < 9; ++i) {
            cout << ia[i] << " ";
        }
        cout << endl;

        make_heap(ia, ia+9);
        pop_heap(ia, ia+9); 
        cout << ia[8] << endl; 
    }

    { 
        // test heap (底层以 array完成) 
        int ia[6] = {4,1,7,6,2,5}; 
        make_heap(ia, ia+6); 
        for(int i=0; i<6; ++i) 
            cout << ia[i] << ' '; 
        cout << endl; 
    } 
}