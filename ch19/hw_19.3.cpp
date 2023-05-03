#include <bits/stdc++.h>

using namespace std;

class A{
    public:
    A() = default;
    virtual ~A() = default;
};

class B:public A{
   public:
    B() = default;
    virtual ~B() = default;
};

class C:public B{
   public:
    C() = default;
    virtual ~C() = default;
};

class D:public B, public A{
   public:
    D() = default;
    virtual ~D() = default;
};

int main(){

    A * pa = new C;
    
    B* pb = static_cast<B*> (pa);
    cout << pb << endl;

    pb = dynamic_cast<B*> (pa);
    cout << pb << endl;
    // yes

    B* pb2 = new B;
    C* pc = dynamic_cast<C*> (pb2);
    cout << pc << endl;
   
    pc = static_cast<C*> (pb2);
    cout << pc << endl;
    // no

    // A* pa2 = new D;
    // B* pb3 = dynamic_cast<B*> (pa2);
    // cout << pb3 << endl;
    //yes;
    getchar();


}