// file: 5map-test.cpp

#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {
    map<string, int> simap;
    simap[string("jjhou")] = 1;
    simap[string("jerry")] = 2;
    simap[string("jason")] = 3;
    simap[string("jimmy")] = 4;

    pair<string, int> value(string("david"), 5);
    simap.insert(value);

    map<string, int>::iterator simap_iter = simap.begin();
    for (; simap_iter != simap.end(); ++simap_iter)
        cout << simap_iter->first << ' '
             << simap_iter->second << endl;

    int number = simap[string("jjhou")];
    cout << number << endl;

    map<string, int>::iterator ite1;
    // 对于关联式容器，专用find函数比STL算法find效率更高
    ite1 = simap.find(string("mchen"));
    if (ite1 == simap.end())
        cout << "mchen not found" << endl;

    ite1 = simap.find(string("jerry"));
    if (ite1 != simap.end())
        cout << "jerry found" << endl;

    ite1->second = 9; // 可以修改value
    int number2 = simap[string("jerry")];
    cout << number2 << endl;
}