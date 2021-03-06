#include <iostream>
#include <vector>
using namespace std;

int func(int a, int b) {
    cout << "func is called" << endl;
}

int add(int a, int b) {
    return a + b;
}

int substract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return b != 0 ? a / b : 0;
}

int main() {
    
    using pFunc1 = decltype(func) *;    
    vector<pFunc1> v1{add, substract, multiply, divide};
//
//    typedef decltype(func) *pFunc2;
//    vector<pFunc2> v2;
//    
//    using pFunc3 = int(int, int);
//    vector<pFunc3*> v3;
//    
//    using pFunc4 = int(*)(int, int);
//    vector<pFunc4> v4;
//    
//    typedef int (*pFunc5)(int, int);    
//    vector<pFunc5> v5;
//    
//    using pFunc6 = decltype(func);
//    vector<pFunc6*> v6;
    
    for (auto v : v1) {
        cout << (*v)(8, 4) << endl;
    }    
    return 0;
}