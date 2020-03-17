// file: mem-fun-test.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Shape {
public:
    virtual void display() = 0;
};

class Rect : public Shape {
public:
    virtual void display() {
        cout << "Rect: ";
    }
};

class Circle : public Shape {
public:
    virtual void display() {
        cout << "Circle: ";
    }
};

class Square : public Shape {
public:
    virtual void display() {
        cout << "Square: ";
    }
};

int main() {
    // STL容器只支持value semantic，不支持reference semantics
    // vector<Shape&> V; 无法通过编译
    vector<Shape *> V;
    V.push_back(new Rect);
    V.push_back(new Circle);
    V.push_back(new Square);
    V.push_back(new Circle);
    V.push_back(new Rect);

    // polymorphically
    for (int i = 0; i < V.size(); ++i)
        V[i]->display();
    cout << endl;

    // polymorphically
    for_each(V.begin(), V.end(), mem_fun(&Shape::display));
    cout << endl;
}