#include <iostream> 
using namespace std; 

class X { 
public: 
    X() { cerr << "X()|"; } 
    X(const X&) { cerr << "X(const X&)|"; } 
    ~X() { cerr << "~X()|"; } 
    X& operator=(const X&) { cerr << "X::op=|"; return *this; } 
}; 

class B { 
public: 
    B() { cerr << "B()|"; } 
    B(const B&) { cerr << "B(const B&)|"; } // (*) 
    virtual ~B() { cerr << "~B()|"; } 
    B& operator=(const B&) { cerr << "B::op=|"; return *this; } 
}; 

class D: public B { 
public: 
    D() { cerr << "D()|"; } 
    D(const D& d): B(d), x_(d.x_) { cerr << "D(const D&)|"; } // (**) 
    virtual ~D() { cerr << "~D()|"; } 
    D& operator=(const D& d) { 
        cerr << "D::op=|"; 
        B::operator=(d); 
        x_ = d.x_; 
        return *this; 
    } 
private: 
    X x_; 
}; 

int main() { 
    cerr << 1 << endl; 
    B b[2]; 
    cerr << endl << 2 << endl; 
    B b1(b[0]); 
    cerr << endl << 3 << endl; //create a class D, initialize super,   always initalize members, object default constructor, static, super, initial, then call your own stuff 
    B *pb = new D; 
    cerr << endl << 4 << endl; 
    B b2 = *pb; 
    cerr << endl << 5 << endl; 
    *pb = b[0]; 
    cerr << endl << 6 << endl; 
    delete pb; 

    cerr << endl << 7 << endl; 
    D d1; 
    cerr << endl << 8 << endl; 
    D a[3]; 
    cerr << endl << 9 << endl; 
    D d2(a[0]); 
    cerr << endl << 10 << endl; 
    D d3 = d1; 
    cerr << endl << 11 << endl; 
    D *pd = new D; 
    cerr << endl << 12 << endl; 
    D *p = pd; 
    cerr << endl << 13 << endl; 
    d1 = a[0]; 
    cerr << endl << 14 << endl; 
    delete p; 

    cerr << endl << "exiting" << endl; 
}