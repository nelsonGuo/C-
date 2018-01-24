#include <iostream>

using namespace std;

class A {
public:
    void f();
    virtual void g();
    void h();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m(int = 1);
    virtual void n();
};

class B: public A {
public:
    void f();
    virtual void g();
    void i();
    void k();
    virtual void l(int);
    virtual void m(int = 2);
private:
    virtual void n();
};

class C: public B {
public:
    virtual void g();
    void h();
    virtual void j();
    void k();
};

int main() {
	A a;
	B b;
	C c;
	A& rab = b;
	A& rac = c;
	B& rbc = c;
	rab.j(); //compiles, late binding, calls A::j()
	rbc.j(); //compiles (j() inherited from A), late binding, calls C::j()
	rbc.k(); //compiles, late binding (k() is automatically virtual), calls C::k()
	//rbc.l(); //doesn't compile, the inherited l() is hidden by l(int)
	rab.m(); //compiles, rewritten to rab.m(1), late binding, calls B::m(1)
	rab.n(); //compiler looks in A for n() so it compiles, late binding, B::n()



}