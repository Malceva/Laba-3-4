#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <cstring>
#include "Array.h"
#include "library.h"



using namespace std;


int main() {

    Array b(4);
    try {
        b.get(2);
        cout << b.get(2) << endl;
    }
    catch (Myexception &ex) {
        ex.what();
    }
    try {
        b.set(2, 8);
        cout << b.cStr() << endl;
    }
    catch (Myexception &ex) {
        ex.what();
    }
    try {
        b.remove(1);
        cout << b.cStr() << endl;
    }
    catch (Myexception &ex) {
        ex.what();
    }
    try {
        b.insert(2, 9);
        cout << b.cStr() << endl;
    }
    catch (Myexception &ex) {
        ex.what();
    }
    cout << "---------" << endl;
    Array a(2);

    Array c(3);
    Array f(5);

    a + 4;
    --c;
    f(3);
    f * 6;
    Array d;
    d = a + c;
    cout << "Array A" << endl;
    cout << a.cStr() << endl;
    cout << "Array C" << endl;
    cout << c.cStr() << endl;
    cout << "Array F" << endl;
    cout << f.cStr() << endl;
    cout << "Array D" << endl;
    cout << d.cStr() << endl;
    Matrix A(3);
    Matrix B(3);
    Matrix C(2);
    C();

    
    try {
        Matrix m(-3);
        cout << "It's okay" << endl;
    }
    catch (exception &ex) {
        cout << ex.what() << endl;
    }
    try {
        Matrix k(3);
        k.setMatrix(5, 6, 56);
        cout << "It's okay" << endl;
    }
    catch (exception &ex) {
        cout << ex.what() << endl;
    }
    try{
        Matrix l(3);
        l.getMatrix(6,6);
    }
    catch (exception &ex) {
        cout << ex.what() << endl;
    }

//cout<<C.toString()<<endl;
}